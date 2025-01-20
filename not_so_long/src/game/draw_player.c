/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 01:33:45 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/19 00:07:47 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

static void	where_is_the_player(t_list *map, t_position *pos)
{
	int	i;
	int	found;

	found = 0;
	pos->y = 0;
	while (map)
	{
		pos->x = 0;
		i = 0;
		while (map->line[i])
		{
			if (map->line[i] == 'P')
				return ;
			pos->x += TILE_SIZE;
			i++;
		}
		pos->y += TILE_SIZE;
		map = map->next;
	}
}

void	draw_player(t_game **game)
{
	t_position	pos;

	where_is_the_player((*game)->map->grid, &pos);
	(*game)->player->player = put_image((*game)->mlx, (*game)->assets->player,
			pos.x, pos.y);
}
