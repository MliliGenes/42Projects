/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 01:33:45 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/17 01:50:01 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

static void	where_is_the_player(t_list *map)
{
	t_position	pos;
	int			i;
	int			found;

    found = 0;
	pos.y = 0;
	while (map)
	{
		pos.x = 0;
		i = 0;
		while (map->line[i])
		{
			if (map->line[i] == 'P')
			{
                found = 1;
                break;
            }
			pos.x += TILE_SIZE;
			i++;
		}
        if ()
		pos.y += TILE_SIZE;
		map = map->next;
	}
}

void	draw_player(t_game *game)
{
}