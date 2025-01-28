/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_coins.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:30:14 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/25 23:50:15 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

static void	set_coin(t_game **game, mlx_image_t **coin, t_position pos)
{
	(*coin) = put_image((*game)->mlx, (*game)->assets->collectible, pos.x,
			pos.y);
}

void	draw_coins(t_game **game)
{
	t_position	pos;
	t_position	i_j;
	int			i;
	char		**grid;

	pos.y = 0;
	i_j.y = 0;
	grid = (*game)->map->pixels;
	i = 0;
	while (grid[i_j.y])
	{
		pos.x = 0;
		i_j.x = 0;
		while (grid[i_j.y][i_j.x])
		{
			if (grid[i_j.y][i_j.x] == 'C')
				set_coin(game, &((*game)->coins[i++]), pos);
			pos.x += TILE_SIZE;
			i_j.x++;
		}
		pos.y += TILE_SIZE;
		i_j.y++;
	}
}
