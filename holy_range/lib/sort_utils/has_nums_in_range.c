/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_nums_in_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 05:54:37 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/05 22:24:36 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	has_nums_in_range(t_item *stack_a, int range_start, int range_end)
{
    while (stack_a)
    {
        if (stack_a->index >= range_start && stack_a->index <= range_end)
            return (1);
        stack_a = stack_a->next;
    }
    return (0);
}
