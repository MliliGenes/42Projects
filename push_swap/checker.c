/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 18:00:56 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/05 09:57:53 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/checker.h"

int	main(int argc, char **argv)
{
	t_item *stack_a;
	t_item *stack_b;
	char *move;

	(void)argc;
	stack_a = NULL;
	stack_b = NULL;
	move = NULL;
	if (!parser(argv, &stack_a))
		error();
	else
	{
		while (!(move = get_next_line(0)))
		{
			execution(&stack_a, &stack_b, move);
			free(move);
		}
	}
    if (is_sorted(stack_a) && !stack_b)
        ok();
    else
        ko();
	clear_list(stack_a);
	return (0);
}