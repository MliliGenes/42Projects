/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 22:21:25 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/12 00:57:53 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib.h"

static void	sort_three(t_item **stack_a)
{
	if ((*stack_a)->index > (*stack_a)->next->index
		&& (*stack_a)->index > (*stack_a)->next->next->index)
		ra(stack_a, 1);
	if ((*stack_a)->index < (*stack_a)->next->index
		&& (*stack_a)->next->index > (*stack_a)->next->next->index)
		rra(stack_a, 1);
	if ((*stack_a)->index > (*stack_a)->next->index)
		sa(stack_a, 1);
}

static void	sort_four_and_five(int size, t_item **stack_a, t_item **stack_b)
{
	int	min_pos;

	min_pos = find_min_by_index(*stack_a);
	while (size > 3)
	{
		if (min_pos <= size / 2)
		{
			while (min_pos--)
				ra(stack_a, 1);
		}
		else
		{
			while (min_pos++ < size)
				rra(stack_a, 1);
		}
		pb(stack_b, stack_a, 1);
		size--;
		min_pos = find_min_by_index(*stack_a);
	}
	if (!is_sorted(*stack_a))
		sort_three(stack_a);
	pa(stack_a, stack_b, 1);
	if (*stack_b)
		pa(stack_a, stack_b, 1);
}

void	sort(t_item **stack_a, t_item **stack_b)
{
	int	stack_a_size;

	if (!*stack_a)
		return ;
	if (is_sorted(*stack_a))
		return ;
	stack_a_size = list_size(*stack_a);
	if (stack_a_size == 2)
		sa(stack_a, 1);
	else if (stack_a_size == 3)
		sort_three(stack_a);
	else if (stack_a_size <= 5)
		sort_four_and_five(stack_a_size, stack_a, stack_b);
	else
	{
		push_to_b(stack_a, stack_b);
		push_back_to_a(stack_a, stack_b);
	}
}
