/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 20:23:59 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/05 23:52:39 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib.h"

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
	write(1, "ra\n", 3);
}

void	rb(t_item **head_b)
{
	rotate(head_b);
	write(1, "rb\n", 3);
}

void	rr(t_item **head_a, t_item **head_b)
{
	rotate(head_a);
	rotate(head_b);
	write(1, "rr\n", 3);
}
