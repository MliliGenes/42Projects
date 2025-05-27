/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 02:44:31 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/05/18 00:50:30 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execution.h"

void	cleanup_fds(t_cmd *cmd)
{
	if (cmd->fds[0] != STDIN_FILENO)
		close(cmd->fds[0]);
	if (cmd->fds[1] != STDOUT_FILENO)
		close(cmd->fds[1]);
}

void	save_std_fds(int *saved_stdin, int *saved_stdout)
{
	*saved_stdin = dup(STDIN_FILENO);
	*saved_stdout = dup(STDOUT_FILENO);
}

void	restore_std_fds(int saved_stdin, int saved_stdout)
{
	dup2(saved_stdin, STDIN_FILENO);
	dup2(saved_stdout, STDOUT_FILENO);
	close(saved_stdin);
	close(saved_stdout);
}

void	apply_fds(t_cmd *cmd)
{
	if (cmd->fds[0] != STDIN_FILENO)
	{
		dup2(cmd->fds[0], STDIN_FILENO);
		close(cmd->fds[0]);
	}
	if (cmd->fds[1] != STDOUT_FILENO)
	{
		dup2(cmd->fds[1], STDOUT_FILENO);
		close(cmd->fds[1]);
	}
}
