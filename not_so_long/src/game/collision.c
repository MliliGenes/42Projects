/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 21:43:56 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/25 20:14:28 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

int	check_collision(char **map, int x, int y, char end)
{
	t_position	positions[4];
	int			i;

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

void	check_player_positions(t_position *positions, int x, int y)
{
	positions[0] = (t_position){(x + 19) / TILE_SIZE, (y + 45) / TILE_SIZE};
	positions[1] = (t_position){(x + TILE_SIZE - 1 - 18) / TILE_SIZE, (y + 45)
		/ TILE_SIZE};
	positions[2] = (t_position){(x + 19) / TILE_SIZE, (y + TILE_SIZE - 1)
		/ TILE_SIZE};
	positions[3] = (t_position){(x + TILE_SIZE - 1 - 18) / TILE_SIZE, (y
			+ TILE_SIZE - 1) / TILE_SIZE};
}

void	update_coin_state(t_game *game, mlx_image_t **coins,
		t_position position)
{
	int	j;

	j = 0;
	while (coins[j])
	{
		if (position.x * TILE_SIZE == coins[j]->instances->x && position.y
			* TILE_SIZE == coins[j]->instances->y)
		{
			coins[j]->instances->x = -TILE_SIZE;
			coins[j]->instances->y = -TILE_SIZE;
			(*game).coins_count--;
			break ;
		}
		j++;
	}
}

void	check_coins(t_game *game, mlx_image_t **coins, int x, int y)
{
	t_position	positions[4];
	int			i;

	check_player_positions(positions, x, y);
	i = 0;
	while (i < 4)
	{
		if (game->map->pixels[positions[i].y][positions[i].x] == 'C')
			update_coin_state(game, coins, positions[i]);
		i++;
	}
}

void	update_coordinates(mlx_t *win, t_position *new_pos, t_player *player)
{
	if (mlx_is_key_down(win, MLX_KEY_D) || mlx_is_key_down(win, MLX_KEY_RIGHT))
	{
		new_pos->x += SPEED;
		player->state = MOVING_RIGHT;
	}
	if (mlx_is_key_down(win, MLX_KEY_A) || mlx_is_key_down(win, MLX_KEY_LEFT))
	{
		new_pos->x -= SPEED;
		player->state = MOVING_LEFT;
	}
	if (mlx_is_key_down(win, MLX_KEY_W) || mlx_is_key_down(win, MLX_KEY_UP))
	{
		new_pos->y -= SPEED;
		player->state = MOVING_UP;
	}
	if (mlx_is_key_down(win, MLX_KEY_S) || mlx_is_key_down(win, MLX_KEY_DOWN))
	{
		new_pos->y += SPEED;
		player->state = MOVING_DOWN;
	}
}