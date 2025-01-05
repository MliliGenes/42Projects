/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 04:57:24 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/03 08:07:34 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	push_to_b(t_item **stack_a, t_item **stack_b)
{
	int	start;
	int	end;
	int	size;

	size = list_size(*stack_a);
	start = 0;
	if (size <= 100)
		end = 15;
	else
		end = 30;
	while (*stack_a)
	{
		if ((*stack_a)->index <= end)
		{
			pb(stack_b, stack_a);
			if ((*stack_b)->index < start)
				rb(stack_b);
			start++;
			end++;
		}
		else if ((*stack_a)->index > end)
			ra(stack_a);
	}
}

// while (*stack_a)
// {
// 	if ((*stack_a)->index >= start && (*stack_a)->index <= end)
// 	{
// 		pb(stack_b, stack_a);
// 		if ((*stack_b)->index < (start + end) / 2)
// 			rb(stack_b);
// 	}
// 	else
// 		ra(stack_a);
// 	if (!has_nums_in_range(*stack_a, start, end))
// 	{
// 		start++;
// 		end++;
// 	}
// }