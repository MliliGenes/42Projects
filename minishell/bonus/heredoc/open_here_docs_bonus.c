/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_here_docs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 06:17:40 by le-saad           #+#    #+#             */
/*   Updated: 2025/05/19 10:10:43 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution_bonus.h"
#include <termios.h>

int	pipe_fork_write(t_redir *redirs)
{
	int		fd[2];
	pid_t	pid;
	int		status;
	char	*limiter;

	limiter = remove_quotes(mark_quotes(redirs->file_or_limiter));
	if (setup_pipe(fd) != 0)
		return (1);
	pid = create_heredoc_process(fd, limiter);
	if (pid == -1)
	{
		free(limiter);
		return (1);
	}
	free(limiter);
	close(fd[1]);
	status = wait_for_heredoc_process(pid);
	if (status != 0)
	{
		close(fd[0]);
		return (status);
	}
	redirs->here_doc_read = fd[0];
	return (status);
}

int	here_docs_loop(t_cmd *cmd)
{
	t_redir	*redirs;
	int		status;

	redirs = cmd->redirs;
	status = 0;
	while (redirs)
	{
		if (redirs->type == REDIR_HEREDOC)
			status = pipe_fork_write(redirs);
		if (status != 0)
			return (status);
		redirs = redirs->next;
	}
	return (status);
}

int	open_here_docs(t_ready_token *tokens)
{
	t_ready_token	*curret;
	t_cmd			*cmd;
	int				status;
	struct termios	term;

	curret = tokens;
	status = 0;
	while (curret)
	{
		if (curret->type == CMD)
		{
			cmd = (t_cmd *)curret->p_token;
			status = here_docs_loop(cmd);
		}
		if (status != 0)
			return (status);
		curret = curret->next;
	}
	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag |= (ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
	return (status);
}
