/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back_to_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 07:47:05 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/05 22:24:41 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



void	push_back_to_a(t_item **stack_a, t_item **stack_b)
{
	while (*stack_b)
	{
		int max_pos = find_max_by_index(*stack_b);
		int size = list_size(*stack_b);

		if (max_pos <= size / 2)
		{
			while (max_pos--)
				rb(stack_b);
		}
		else
		{
			while (max_pos++ < size)
				rrb(stack_b);
		}
		pa(stack_a, stack_b);
	}
}