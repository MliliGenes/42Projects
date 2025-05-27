/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shunting_yard.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 01:16:09 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/04/25 13:53:02 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

void	add_front_ops_stack(t_ready_token **head, t_ready_token *node)
{
	if (!head || !node)
		return ;
	node->prev = NULL;
	node->next = *head;
	if (*head)
		(*head)->prev = node;
	*head = node;
}

void	push_to_postfix(t_ready_token **head, t_ready_token *node)
{
	node->next = NULL;
	node->prev = NULL;
	add_back_ready_token(head, node);
}

t_ready_token	*pop_infix_note(t_parser *parser)
{
	t_ready_token	*popped_node;

	if (!parser || !parser->infix_note)
		return (NULL);
	popped_node = parser->infix_note;
	parser->infix_note = parser->infix_note->next;
	if (parser->infix_note)
		parser->infix_note->prev = NULL;
	popped_node->next = NULL;
	return (popped_node);
}

t_ready_token	*pop_op_stack_note(t_parser *parser)
{
	t_ready_token	*popped_node;

	if (!parser || !parser->ops_stack)
		return (NULL);
	popped_node = parser->ops_stack;
	parser->ops_stack = parser->ops_stack->next;
	if (parser->ops_stack)
		parser->ops_stack->prev = NULL;
	popped_node->next = NULL;
	return (popped_node);
}

void	op_to_postfix(t_ready_token *op, t_parser *parser)
{
	if (((t_op *)op->p_token)->type == OP_PAREN_L)
	{
		add_front_ops_stack(&parser->ops_stack, op);
		return ;
	}
	if (((t_op *)op->p_token)->type == OP_PAREN_R)
	{
		free_ready_tokens_list(op);
		while (parser->ops_stack
			&& ((t_op *)parser->ops_stack->p_token)->type != OP_PAREN_L)
			push_to_postfix(&parser->postfix_note, pop_op_stack_note(parser));
		if (parser->ops_stack)
			free_ready_tokens_list(pop_op_stack_note(parser));
		return ;
	}
	while (parser->ops_stack
		&& get_op_precedence(parser->ops_stack) >= get_op_precedence(op))
		push_to_postfix(&parser->postfix_note, pop_op_stack_note(parser));
	add_front_ops_stack(&parser->ops_stack, op);
}
