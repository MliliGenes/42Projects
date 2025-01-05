/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 00:06:00 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/06 00:07:22 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib.h"

static void	dd(void)
{
	error();
	exit(1);
}

void	execution(t_item **stack_a, t_item **stack_b, char *move)
{
	if (!ft_strcmp(move, "pa\n"))
		pa(stack_a, stack_b);
	else if (!ft_strcmp(move, "pb\n"))
		pb(stack_a, stack_b);
	else if (!ft_strcmp(move, "sa\n"))
		sa(stack_a);
	else if (!ft_strcmp(move, "sb\n"))
		sb(stack_b);
	else if (!ft_strcmp(move, "ss\n"))
		ss(stack_a, stack_b);
	else if (!ft_strcmp(move, "ra\n"))
		ra(stack_a);
	else if (!ft_strcmp(move, "rb\n"))
		rb(stack_b);
	else if (!ft_strcmp(move, "rr\n"))
		rr(stack_a, stack_b);
	else if (!ft_strcmp(move, "rra\n"))
		rra(stack_a);
	else if (!ft_strcmp(move, "rrb\n"))
		rrb(stack_b);
	else if (!ft_strcmp(move, "rrr\n"))
		rrr(stack_a, stack_a);
	else
		dd();
}
