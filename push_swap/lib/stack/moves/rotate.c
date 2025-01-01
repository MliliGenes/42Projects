/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 20:23:59 by sel-mlil          #+#    #+#             */
/*   Updated: 2024/12/31 13:19:46 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "moves.h"

static void	rotate(t_item **head)
{
	t_item	*new_head;
	t_item	*tmp;

	if (!*head || !(*head)->next)
		return ;
	tmp = *head;
	new_head = (*head)->next;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = tmp;
	new_head->prev = NULL;
	*head = new_head;
}

void	ra(t_item **head_a)
{
	rotate(head_a);
}

void	rb(t_item **head_b)
{
	rotate(head_b);
}

void	rr(t_item **head_a, t_item **head_b)
{
	rotate(head_a);
	rotate(head_b);
}
