/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 21:34:25 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/18 10:43:05 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

void	draw_map(t_game **game)
{
	t_position	pos;
	int			i;
	t_list		*grid;

	pos.y = 0;
	grid = (*game)->map->grid;
	while (grid)
	{
		pos.x = 0;
		i = 0;
		while (grid->line[i])
		{
			if (grid->line[i] == '1')
				put_image((*game)->mlx, (*game)->assets->wall, pos.x, pos.y);
			else
				put_image((*game)->mlx, (*game)->assets->tile, pos.x, pos.y);
			pos.x += TILE_SIZE;
			i++;
		}
		pos.y += TILE_SIZE;
		grid = grid->next;
	}
	mlx_delete_texture((*game)->assets->wall);
	mlx_delete_texture((*game)->assets->tile);
}
