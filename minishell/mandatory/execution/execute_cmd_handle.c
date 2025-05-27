/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd_handle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 01:14:29 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/05/19 10:19:37 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"
#include "../include/parsing.h"
#include "../include/signals.h"

int	handle_builtin(t_cmd *cmd, t_shell *shell)
{
	int	status;
	int	saved_stdin;
	int	saved_stdout;

	save_std_fds(&saved_stdin, &saved_stdout);
	if (cmd->fds[0] != STDIN_FILENO)
		dup2(cmd->fds[0], STDIN_FILENO);
	if (cmd->fds[1] != STDOUT_FILENO)
		dup2(cmd->fds[1], STDOUT_FILENO);
	status = execute_builtin(cmd, shell);
	restore_std_fds(saved_stdin, saved_stdout);
	cleanup_fds(cmd);
	return (status);
}

static int	handle_child_process(t_cmd *cmd, char *cmd_path, char **tmp_env)
{
	reset_signals_for_child();
	apply_fds(cmd);
	execve(cmd_path, cmd->args, tmp_env);
	perror("execve");
	free(cmd_path);
	free_2d(tmp_env);
	exit(126);
}

static int	handle_fork_error(char *cmd_path, char **tmp_env, t_cmd *cmd)
{
	perror("fork");
	free(cmd_path);
	free_2d(tmp_env);
	cleanup_fds(cmd);
	return (1);
}

int	handle_exec(t_cmd *cmd, t_shell *shell)
{
	pid_t	pid;
	char	*cmd_path;
	char	**tmp_env;
	int		status;

	free_2d(shell->path);
	shell->path = ft_split(get_env_value(shell->env, "PATH"), ':');
	cmd_path = get_cmd_path(cmd, shell->path);
	if (!cmd_path)
	{
		status = check_path(cmd);
		if (status)
			return (status);
	}
	tmp_env = env_to_array(shell->env);
	pid = fork();
	if (pid < 0)
		return (handle_fork_error(cmd_path, tmp_env, cmd));
	if (pid == 0)
		handle_child_process(cmd, cmd_path, tmp_env);
	cleanup_fds(cmd);
	waitpid(pid, &status, 0);
	get_child_status(&status);
	return (free(cmd_path), free_2d(tmp_env), status);
}

int	execute_command(t_cmd *cmd, t_shell *shell)
{
	if (!cmd)
		return (1);
	update_cmd_node(cmd, shell);
	if (cmd->redirs && apply_redirections(cmd, shell))
		return (1);
	if (!cmd->cmd)
	{
		cleanup_fds(cmd);
		return (0);
	}
	if (is_builtin(cmd->cmd))
		return (handle_builtin(cmd, shell));
	return (handle_exec(cmd, shell));
}
