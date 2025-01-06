/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 17:24:07 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/06 03:03:25 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib.h"

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

void	sa(t_item **head_a, int print)
{
	swap_first_two(head_a);
	if (print)
		write(1, "sa\n", 3);
}

void	sb(t_item **head_b, int print)
{
	swap_first_two(head_b);
	if (print)
		write(1, "sb\n", 3);
}

void	ss(t_item **head_a, t_item **head_b, int print)
{
	swap_first_two(head_a);
	swap_first_two(head_b);
	if (print)
		write(1, "ss\n", 3);
}
