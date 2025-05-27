/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_construction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: le-saad <le-saad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:52:53 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/05/13 04:10:02 by le-saad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing_bonus.h"

void	free_ast(t_ast *root)
{
	if (!root)
		return ;
	free_ast(root->left);
	free_ast(root->right);
	free(root);
}

t_ast	*ast_recursive(t_ready_token **postfix_tail)
{
	t_ready_token	*current;
	t_ast			*wrapper;

	current = *postfix_tail;
	if (!current)
		return (NULL);
	*postfix_tail = current->prev;
	wrapper = malloc(sizeof(t_ast));
	if (!wrapper)
		return (NULL);
	wrapper->node = current;
	wrapper->right = NULL;
	wrapper->left = NULL;
	if (current->type == OP)
	{
		wrapper->right = ast_recursive(postfix_tail);
		wrapper->left = ast_recursive(postfix_tail);
	}
	return (wrapper);
}

t_ast	*post_to_tree(t_ready_token *postfix)
{
	while (postfix && postfix->next)
		postfix = postfix->next;
	return (ast_recursive(&postfix));
}
