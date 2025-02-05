/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_max_by_index.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 02:53:52 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/05 23:57:55 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib.h"

int	find_max_by_index(t_item *head)
{
	int		max_index;
	int		i;
	int		max_pos;
	t_item	*current;

	if (!head)
		return (0);
	max_index = head->index;
	max_pos = 0;
	i = 0;
	current = head;
	while (current)
	{
		if (current->index > max_index)
		{
			max_index = current->index;
			max_pos = i;
		}
		i++;
		current = current->next;
	}
	return (max_pos);
}
