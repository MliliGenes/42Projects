/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 22:21:25 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/03 08:25:35 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void sort_three(t_item **stack_a)
{
	if ()
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
		sa(stack_a);
	else if (stack_a_size == 3)
	// else if (stack_a_size > 3)
	// 	return ; // sort 3
	else
	{
		push_to_b(stack_a, stack_b);
		push_back_to_a(stack_a, stack_b);
	}
}
