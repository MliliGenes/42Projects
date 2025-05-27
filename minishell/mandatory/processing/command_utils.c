/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 01:11:13 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/04/25 13:52:57 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

t_cmd	*create_cmd_node(char **args, t_redir *redirs)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->args = args;
	cmd->cmd = NULL;
	if (args)
		cmd->cmd = args[0];
	cmd->redirs = redirs;
	cmd->fds[0] = 0;
	cmd->fds[1] = 1;
	return (cmd);
}

t_cmd	*extract_cmd_data(t_token *start, t_token *end)
{
	t_cmd	*cmd;
	char	**args;
	t_redir	*redirs;

	cmd = NULL;
	args = NULL;
	redirs = NULL;
	if (!start || start->type == TOKEN_EOF)
		return (NULL);
	redirs = get_redirs(start, end);
	args = get_args(start, end);
	if (!args && !redirs)
		return (NULL);
	cmd = create_cmd_node(args, redirs);
	if (!cmd)
	{
		free_args_array(args, count_args_in_cmd(args));
		free_redirs(redirs);
	}
	return (cmd);
}

bool	process_command_segment(t_token *start, t_token *end,
		t_ready_token **head)
{
	t_cmd			*cmd;
	t_ready_token	*cmd_token;

	cmd = extract_cmd_data(start, end);
	if (!cmd)
		return (false);
	cmd_token = create_ready_token_node(cmd, CMD);
	if (!cmd_token)
	{
		if (cmd->args)
			free_args_array(cmd->args, count_args_in_cmd(cmd->args));
		if (cmd->redirs)
			free_redirs(cmd->redirs);
		free(cmd);
		return (false);
	}
	add_back_ready_token(head, cmd_token);
	return (true);
}
