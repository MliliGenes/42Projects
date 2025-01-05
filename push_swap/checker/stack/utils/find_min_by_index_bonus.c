/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_by_index.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 01:07:47 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/05 04:14:59 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap.h"

int	find_min_by_index(t_item *stack)
{
	int		min_value;
	int		min_pos;
	int		i;
	t_item	*current;

	min_value = stack->value;
	min_pos = 0;
	i = 0;
	current = stack;
	while (current)
	{
		if (current->value < min_value)
		{
			min_value = current->value;
			min_pos = i;
		}
		current = current->next;
		i++;
	}
	return (min_pos);
}
