/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_to_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 22:28:21 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/12 00:10:50 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib.h"

int	ft_int_to_stack(int *arr, t_item **stack, int size)
{
	int		i;
	int		j;
	t_item	*new_node;

	i = 0;
	while (i < size)
	{
		new_node = create_item(arr[i]);
		if (!new_node)
			return (0);
		j = 0;
		while (j < size)
		{
			if (arr[i] > arr[j++])
				new_node->index++;
		}
		if (!*stack)
			*stack = new_node;
		else
			add_back(*stack, new_node);
		i++;
	}
	return (free(arr), 1);
}
