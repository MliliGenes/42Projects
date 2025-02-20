/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:15:33 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/02/18 18:56:24 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

void	redirect_io(t_pipe *pipe_x, int cmd_index)
{
	if (cmd_index == 0)
	{
		dup2(pipe_x->infile_fd, STDIN_FILENO);
		close(pipe_x->infile_fd);
	}
	else
	{
		dup2(pipe_x->prev_pipe, STDIN_FILENO);
		close(pipe_x->prev_pipe);
	}
	if (cmd_index == pipe_x->cmds_count - 1)
	{
		dup2(pipe_x->outfile_fd, STDOUT_FILENO);
		close(pipe_x->outfile_fd);
	}
	else
	{
		dup2(pipe_x->pipe_fd[1], STDOUT_FILENO);
		close(pipe_x->pipe_fd[1]);
		close(pipe_x->pipe_fd[0]);
	}
}

void	execute_command(t_pipe *pipe_x, int cmd_index)
{
	t_cmd	cmd;

	cmd = pipe_x->cmds[cmd_index];
	if (!cmd.valid || !cmd.cmd)
	{
		write(2, "command not found: ", 19);
		write(2, ">> ", 3);
		while (cmd.cmd && *cmd.cmd)
			write(2, cmd.cmd++, 1);
		write(2, " <<\n", 4);
	}
	execve(cmd.path, cmd.args, pipe_x->envp);
	exit(EXIT_FAILURE);
}

static bool	handle_child_process(t_pipe *pipe_x, int i)
{
	if (i < pipe_x->cmds_count - 1)
		if (pipe(pipe_x->pipe_fd) < 0)
			return (cleanup(pipe_x, 3));
	pipe_x->pid = fork();
	if (pipe_x->pid < 0)
		return (cleanup(pipe_x, 3));
	if (pipe_x->pid == 0)
	{
		if ((pipe_x->infile_fd == -1 && i == 0) || (pipe_x->outfile_fd == -1
				&& i == pipe_x->cmds_count - 1))
			exit(EXIT_FAILURE);
		redirect_io(pipe_x, i);
		execute_command(pipe_x, i);
	}
	if (i > 0)
		close(pipe_x->prev_pipe);
	if (i < pipe_x->cmds_count - 1)
	{
		close(pipe_x->pipe_fd[1]);
		pipe_x->prev_pipe = pipe_x->pipe_fd[0];
	}
	return (true);
}

bool	executor(t_pipe *pipe_x)
{
	int	i;

	i = 0;
	while (i < pipe_x->cmds_count)
	{
		if (!handle_child_process(pipe_x, i))
			return (false);
		i++;
	}
	if (waitpid(pipe_x->pid, &pipe_x->exit_code, 0) > 0)
		pipe_x->exit_code = WEXITSTATUS(pipe_x->exit_code);
	while (wait(NULL) > 0)
		;
	return (true);
}
