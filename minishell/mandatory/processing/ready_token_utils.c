/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ready_token_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 01:12:45 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/04/25 13:52:36 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

t_ready_token	*create_ready_token_node(void *token, int type)
{
	t_ready_token	*r_token;

	r_token = malloc(sizeof(t_ready_token));
	if (!r_token || !token)
		return (NULL);
	r_token->p_token = token;
	r_token->type = type;
	r_token->next = NULL;
	r_token->prev = NULL;
	return (r_token);
}

void	add_back_ready_token(t_ready_token **head, t_ready_token *node)
{
	t_ready_token	*tmp;

	if (!*head)
	{
		*head = node;
		return ;
	}
	tmp = (*head);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
	node->prev = tmp;
}

void	free_ready_tokens_list(t_ready_token *head)
{
	t_ready_token	*next;
	t_cmd			*cmd;

	while (head)
	{
		next = head->next;
		if (head->type == CMD && head->p_token)
		{
			cmd = head->p_token;
			if (cmd->args)
				free_args_array(cmd->args, count_args_in_cmd(cmd->args));
			if (cmd->redirs)
				free_redirs(cmd->redirs);
			free(cmd);
		}
		else if (head->type == OP && head->p_token)
			free(head->p_token);
		free(head);
		head = next;
	}
}
