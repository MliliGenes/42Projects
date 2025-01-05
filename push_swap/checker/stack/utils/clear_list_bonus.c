/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 05:38:30 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/03 05:41:33 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap.h"

void	clear_list(t_item *stack)
{
	t_item	*tmp;

	while (stack)
	{
		tmp = stack;
		stack = (stack)->next;
		free(tmp);
	}
}
