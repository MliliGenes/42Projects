/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 21:43:56 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/23 21:44:30 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

int	check_collision(char **map, int x, int y, char end)
{
	t_position	positions[4];
	int			i;

	positions[2] = (t_position){x / TILE_SIZE, (y + TILE_SIZE - 1) / TILE_SIZE};
	positions[3] = (t_position){(x + TILE_SIZE - 1) / TILE_SIZE, (y + TILE_SIZE
			- 1) / TILE_SIZE};
	positions[0] = (t_position){(x + 19) / TILE_SIZE, (y + 45) / TILE_SIZE};
	positions[1] = (t_position){(x + TILE_SIZE - 1 - 18) / TILE_SIZE, (y + 45)
		/ TILE_SIZE};
	positions[2] = (t_position){(x + 19) / TILE_SIZE, (y + TILE_SIZE - 1)
		/ TILE_SIZE};
	positions[3] = (t_position){(x + TILE_SIZE - 1 - 18) / TILE_SIZE, (y
			+ TILE_SIZE - 1) / TILE_SIZE};
	i = 0;
	while (i < 4)
	{
		if (map[positions[i].y][positions[i].x] == end)
			return (0);
		i++;
	}
	return (1);
}

void	check_coins(t_game *game, mlx_image_t **coins, int x, int y)
{
	t_position	positions[4];
	int			i;
	int			j;

	positions[2] = (t_position){x / TILE_SIZE, (y + TILE_SIZE - 1) / TILE_SIZE};
	positions[3] = (t_position){(x + TILE_SIZE - 1) / TILE_SIZE, (y + TILE_SIZE
			- 1) / TILE_SIZE};
	positions[0] = (t_position){(x + 19) / TILE_SIZE, (y + 45) / TILE_SIZE};
	positions[1] = (t_position){(x + TILE_SIZE - 1 - 18) / TILE_SIZE, (y + 45)
		/ TILE_SIZE};
	positions[2] = (t_position){(x + 19) / TILE_SIZE, (y + TILE_SIZE - 1)
		/ TILE_SIZE};
	positions[3] = (t_position){(x + TILE_SIZE - 1 - 18) / TILE_SIZE, (y
			+ TILE_SIZE - 1) / TILE_SIZE};
	i = 0;
	while (i < 4)
	{
		j = 0;
		if (game->map->pixels[positions[i].y][positions[i].x] == 'C')
		{
			while (coins[j])
			{
				if (positions[i].x * TILE_SIZE == coins[j]->instances->x
					&& positions[i].y * TILE_SIZE == coins[j]->instances->y)
				{
					coins[j]->instances->x = -64;
					coins[j]->instances->y = -64;
					(*game).coins_count--;
				}
				j++;
			}
		}
		i++;
	}
}