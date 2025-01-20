/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 21:34:25 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/20 12:17:27 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

static int	checker(char **grid, t_position i_j, int mx, int my)
{
	return (grid[i_j.y][i_j.x] == '1' && (i_j.x == 0 || i_j.y == 0
			|| i_j.x == mx || i_j.y == my));
}

void	draw_map(t_game **game, int mx, int my)
{
	t_position	pos;
	t_position	i_j;
	char		**grid;

	(void)mx;
	(void)my;
	pos.y = 0;
	i_j.y = 0;
	grid = (*game)->map->pixels;
	while (grid[i_j.y])
	{
		pos.x = 0;
		i_j.x = 0;
		while (grid[i_j.y][i_j.x])
		{
			if (checker(grid, i_j, mx, my))
				put_image((*game)->mlx, (*game)->assets->wall, pos.x, pos.y);
			else if (grid[i_j.y][i_j.x] == '1')
				put_image((*game)->mlx, (*game)->assets->rock, pos.x, pos.y);
			else
				put_image((*game)->mlx, (*game)->assets->tile, pos.x, pos.y);
			pos.x += TILE_SIZE;
			i_j.x++;
		}
		pos.y += TILE_SIZE;
		i_j.y++;
	}
}
