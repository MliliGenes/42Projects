/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 01:12:02 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/04/25 13:52:53 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing_bonus.h"

t_op_type	token_to_op_type(t_token_type type)
{
	if (type == TOKEN_PL)
		return (OP_PAREN_L);
	if (type == TOKEN_PR)
		return (OP_PAREN_R);
	if (type == TOKEN_PIPE)
		return (OP_PIPE);
	if (type == TOKEN_AND)
		return (OP_AND);
	if (type == TOKEN_OR)
		return (OP_OR);
	return (-1);
}

t_redir_type	token_to_redir_type(t_token_type type)
{
	if (type == TOKEN_REDIR_IN)
		return (REDIR_IN);
	else if (type == TOKEN_REDIR_OUT)
		return (REDIR_OUT);
	else if (type == TOKEN_APPEND)
		return (REDIR_APPEND);
	else if (type == TOKEN_HEREDOC)
		return (REDIR_HEREDOC);
	return (-1);
}

t_op	*create_op_node(t_op_type type)
{
	t_op	*op;

	op = malloc(sizeof(t_cmd));
	if (!op)
		return (NULL);
	op->type = type;
	return (op);
}

bool	add_operator_to_list(t_token *current, t_ready_token **head)
{
	t_op			*op_node;
	t_ready_token	*op_token;

	op_node = create_op_node(token_to_op_type(current->type));
	if (!op_node)
		return (false);
	op_token = create_ready_token_node(op_node, OP);
	if (!op_token)
		return (free(op_node), false);
	add_back_ready_token(head, op_token);
	return (true);
}
