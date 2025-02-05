/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back_to_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 07:47:05 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/12 01:27:39 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib.h"

void	push_back_to_a(t_item **stack_a, t_item **stack_b)
{
	int	max_pos;
	int	size;

	while (*stack_b)
	{
		max_pos = find_max_by_index(*stack_b);
		size = list_size(*stack_b);
		if (max_pos <= size / 2)
		{
			while (max_pos--)
				rb(stack_b, 1);
		}
		else
		{
			while (max_pos++ < size)
				rrb(stack_b, 1);
		}
		pa(stack_a, stack_b, 1);
	}
}
