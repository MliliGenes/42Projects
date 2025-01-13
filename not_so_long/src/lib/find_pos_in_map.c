/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pos_in_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 06:35:17 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/12 07:09:12 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib.h"

void	find_pos_in_map(list_t *map, play_pos_t *pos)
{
	int	x;

	while (map)
	{
		x = 0;
		while (map->line[x])
		{
			if (map->line[x] == 'P')
			{
				(*pos).line = map;
				(*pos).x = x;
			}
			x++;
		}
		map = map->next;
	}
}
