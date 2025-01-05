/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 20:23:59 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/05 23:52:36 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib.h"

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
	write(1, "rra\n", 4);
}

void	rrb(t_item **head_b)
{
	reverse_rotate(head_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_item **head_a, t_item **head_b)
{
	reverse_rotate(head_a);
	reverse_rotate(head_b);
	write(1, "rrr\n", 4);
}
