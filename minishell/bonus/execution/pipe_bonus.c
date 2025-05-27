/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: le-saad <le-saad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 04:49:14 by le-saad           #+#    #+#             */
/*   Updated: 2025/05/14 10:47:32 by le-saad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution_bonus.h"

void	close_fds(int fds[2])
{
	close(fds[0]);
	close(fds[1]);
}

static int	create_pipe(int pipefd[2])
{
	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		return (0);
	}
	return (1);
}

static void	setup_pipe_side(int pipefd[2], int fd_to_replace)
{
	dup2(pipefd[fd_to_replace], fd_to_replace);
	close(pipefd[0]);
	close(pipefd[1]);
}

static pid_t	launch_process(int pipefd[2], int fd_to_replace, t_ast *node,
		t_shell *shell)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		setup_pipe_side(pipefd, fd_to_replace);
		exit(execute_ast_node(node, shell));
	}
	else if (pid == -1)
		perror("fork");
	return (pid);
}

int	handle_pipe(t_ast *node, t_shell *shell)
{
	int		fds[2];
	int		status;
	pid_t	left_pid;
	pid_t	right_pid;

	if (!create_pipe(fds))
		return (1);
	left_pid = launch_process(fds, STDOUT_FILENO, node->left, shell);
	if (left_pid == -1)
	{
		close_fds(fds);
		return (1);
	}
	right_pid = launch_process(fds, STDIN_FILENO, node->right, shell);
	if (right_pid == -1)
	{
		close_fds(fds);
		waitpid(left_pid, NULL, 0);
		return (1);
	}
	close_fds(fds);
	waitpid(left_pid, NULL, 0);
	waitpid(right_pid, &status, 0);
	return (WEXITSTATUS(status));
}
