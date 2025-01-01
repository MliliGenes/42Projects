/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 17:24:07 by sel-mlil          #+#    #+#             */
/*   Updated: 2024/12/29 20:50:06 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "moves.h"

static void	swap_first_two(t_item **head)
{
	t_item	*tmp;

	if (!*head || !(*head)->next)
		return ;
	tmp = (*head)->next;
	(*head)->next = tmp->next;
	tmp->prev = NULL;
	(*head)->prev = tmp;
	tmp->next = *head;
	if ((*head)->next)
		(*head)->next->prev = *head;
	*head = tmp;
}

void	sa(t_item **head_a)
{
	swap_first_two(head_a);
}

void	sb(t_item **head_b)
{
	swap_first_two(head_b);
}

void	ss(t_item **head_a, t_item **head_b)
{
	swap_first_two(head_a);
	swap_first_two(head_b);
}
