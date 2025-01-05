/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 05:27:56 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/03 05:36:21 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	is_sorted(t_item *stack_a)
{
	if (!stack_a)
		return (0);
    while (stack_a->next)
    {
        if (stack_a->value > stack_a->next->value)
            return (0);
        stack_a = stack_a->next;
    }
	return (1);
}
