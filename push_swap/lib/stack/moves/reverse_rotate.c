/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 20:23:59 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/02 21:21:53 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap.h"

static void	reverse_rotate(t_item **head)
{
	t_item	*tmp;

	if (!*head || !(*head)->next)
		return ;
	tmp = (*head);
	while (tmp->next)
		tmp = tmp->next;
	tmp->prev->next = NULL;
	tmp->next = (*head);
	(*head)->prev = tmp;
	tmp->prev = NULL;
	*head = tmp;
}

void	rra(t_item **head_a)
{
	reverse_rotate(head_a);
}

void	rrb(t_item **head_b)
{
	reverse_rotate(head_b);
}

void	rrr(t_item **head_a, t_item **head_b)
{
	reverse_rotate(head_a);
	reverse_rotate(head_b);
}
