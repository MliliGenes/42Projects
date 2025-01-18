/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_lister.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 08:11:31 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/18 20:34:24 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"
#include <stdio.h>

int	check_collision(char **map, int x, int y)
{
	t_position	positions[4];
	int			i;

	positions[0] = (t_position){x / TILE_SIZE, y / TILE_SIZE};
	positions[1] = (t_position){(x + TILE_SIZE - 1) / TILE_SIZE, y / TILE_SIZE};
	positions[2] = (t_position){x / TILE_SIZE, (y + TILE_SIZE - 1) / TILE_SIZE};
	positions[3] = (t_position){(x + TILE_SIZE - 1) / TILE_SIZE, (y + TILE_SIZE
			- 1) / TILE_SIZE};
	i = 0;
	while (i < 4)
	{
		if (map[positions[i].y][positions[i].x] == '1')
			return (0);
		i++;
	}
	return (1);
}

void	movement(mlx_t *win, char **map, t_player *player)
{
	int	new_x;
	int	new_y;
	int	x_moved;
	int	y_moved;

	new_x = player->player->instances->x;
	new_y = player->player->instances->y;
	x_moved = 0;
	y_moved = 0;
	if (mlx_is_key_down(win, MLX_KEY_D))
	{
		new_x += SPEED;
		player->state = MOVING_RIGHT;
		x_moved = 1;
	}
	if (mlx_is_key_down(win, MLX_KEY_A))
	{
		new_x -= SPEED;
		player->state = MOVING_LEFT;
		x_moved = 1;
	}
	if (mlx_is_key_down(win, MLX_KEY_W))
	{
		new_y -= SPEED;
		if (!x_moved) // Prioritize horizontal states
			player->state = MOVING_UP;
		y_moved = 1;
	}
	if (mlx_is_key_down(win, MLX_KEY_S))
	{
		new_y += SPEED;
		if (!x_moved) // Prioritize horizontal states
			player->state = MOVING_DOWN;
		y_moved = 1;
	}
	if (check_collision(map, new_x, player->player->instances->y))
		player->player->instances->x = new_x;
	if (check_collision(map, player->player->instances->x, new_y))
		player->player->instances->y = new_y;
	if (!mlx_is_key_down(win, MLX_KEY_D) && !mlx_is_key_down(win, MLX_KEY_A)
		&& !mlx_is_key_down(win, MLX_KEY_W) && !mlx_is_key_down(win, MLX_KEY_S))
	{
		player->state = IDLE;
	}
}

void	event_listener(void *game)
{
	t_game	*game_instance;

	game_instance = (t_game *)game;
	dprintf(2, "%d", game_instance->player->state);
	movement(game_instance->mlx, game_instance->map->pixels,
		game_instance->player);
}
