/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 18:00:56 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/06 04:39:17 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/checker.h"
#include "./includes/get_next_line.h"
#include "includes/lib.h"
#include <stdio.h>

static void	dd(void)
{
	error();
	exit(1);
}

static void	check_sort(t_item *stack_a, t_item *stack_b)
{
	if (is_sorted(stack_a) && !stack_b)
		ok();
	else
		ko();
}

int	main(int argc, char **argv)
{
	t_item	*stack_a;
	t_item	*stack_b;
	char	*move;

	(void)argc;
	stack_a = NULL;
	stack_b = NULL;
	move = NULL;
	if (!parser(argv, &stack_a))
		dd();
	while (1)
	{
		move = get_next_line(0);
		if (!move)
			break ;
		execution(&stack_a, &stack_b, move);
		free(move);
	}
	check_sort(stack_a, stack_b);
	clear_list(stack_a);
	return (0);
}
