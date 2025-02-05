/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 14:06:51 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/12 00:39:34 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_item	*stack_a;
	t_item	*stack_b;

	(void)argc;
	stack_a = NULL;
	stack_b = NULL;
	if (!parser(argv, &stack_a))
		error();
	else
		sort(&stack_a, &stack_b);
	clear_list(stack_a);
	return (0);
}
