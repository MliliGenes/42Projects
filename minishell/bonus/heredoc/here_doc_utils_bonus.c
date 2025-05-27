/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 03:33:27 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/05/23 19:17:59 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution_bonus.h"
#include "../include/signals_bonus.h"

int	setup_pipe(int fd[2])
{
	if (pipe(fd) == -1)
	{
		perror("pipe");
		return (1);
	}
	return (0);
}

void	handle_heredoc_child_process(int fd[2], char *limiter)
{
	char	*line;

	reset_signals_for_heredoc();
	close(fd[0]);
	while (true)
	{
		line = readline("sel-doc > ");
		if (!line || ft_strcmp(line, limiter) == 0)
		{
			free(line);
			break ;
		}
		write(fd[1], line, ft_strlen(line));
		write(fd[1], "\n", 1);
		free(line);
	}
	close(fd[1]);
	exit(0);
}

pid_t	create_heredoc_process(int fd[2], char *limiter)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		close(fd[0]);
		close(fd[1]);
		return (-1);
	}
	if (pid == 0)
		handle_heredoc_child_process(fd, limiter);
	return (pid);
}

int	wait_for_heredoc_process(pid_t pid)
{
	int	status;

	waitpid(pid, &status, 0);
	if (WIFSIGNALED(status))
		return (1);
	return (WEXITSTATUS(status));
}

int	update_heredoc_pipe(t_redir *redir, t_shell *shell)
{
	char	*line;
	char	*tmp;
	int		fd[2];

	if (pipe(fd) == -1)
	{
		perror("pipe");
		return (1);
	}
	while (true)
	{
		line = get_line(redir->here_doc_read);
		if (!line)
			break ;
		tmp = line;
		line = expand_vars(tmp, shell);
		free(tmp);
		write(fd[1], line, ft_strlen(line));
		free(line);
	}
	close(fd[1]);
	close(redir->here_doc_read);
	redir->here_doc_read = fd[0];
	return (0);
}
