/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: le-saad <le-saad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 23:15:27 by le-saad           #+#    #+#             */
/*   Updated: 2025/07/07 10:55:43 by le-saad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

static bool	is_wall(t_map *map, int x, int y)
{
	return (map->map[y / TILE_SIZE][x / TILE_SIZE] == '1' || map->map[y
		/ TILE_SIZE][x / TILE_SIZE] == 'D');
}

static bool	check_collision(t_map *map, t_vec2i pos)
{
	int	half;

	half = PLAYER_SIZE;
	return (is_wall(map, pos.x - half, pos.y - half) || is_wall(map, pos.x
			+ half, pos.y - half) || is_wall(map, pos.x - half, pos.y + half)
		|| is_wall(map, pos.x + half, pos.y + half));
}

static void	update_player_data(mlx_t *mlx, t_player *player)
{
	if (mlx_is_key_down(mlx, MLX_KEY_W) || mlx_is_key_down(mlx, MLX_KEY_UP))
		player->forward_backward = player->move_speed;
	if (mlx_is_key_down(mlx, MLX_KEY_S) || mlx_is_key_down(mlx, MLX_KEY_DOWN))
		player->forward_backward = -player->move_speed;
	if (mlx_is_key_down(mlx, MLX_KEY_D))
		player->left_right = player->move_speed;
	if (mlx_is_key_down(mlx, MLX_KEY_A))
		player->left_right = -player->move_speed;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		player->angle -= player->rot_speed;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		player->angle += player->rot_speed;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT_SHIFT))
		player->move_speed = 52;
	else
		player->move_speed = 32;
	player->angle = normalize_angle(player->angle);
}

static t_vec2d	calc_target_pos(t_player *player)
{
	t_vec2d	total;

	player->forward = (t_vec2d){cos(player->angle) * player->forward_backward,
		sin(player->angle) * player->forward_backward};
	player->strafe = (t_vec2d){cos(player->angle + M_PI / 2.0)
		* player->left_right, sin(player->angle + M_PI / 2.0)
		* player->left_right};
	total = (t_vec2d){player->forward.x + player->strafe.x + player->reminder.x,
		player->forward.y + player->strafe.y + player->reminder.y};
	return (total);
}

void	update_player(t_game *game)
{
	t_player	*player;
	t_vec2d		total;
	t_vec2i		move;
	t_vec2i		target;

	player = game->player_data;
	mouse_eventlistner(game);
	update_player_data(game->mlx, game->player_data);
	total = calc_target_pos(game->player_data);
	move = (t_vec2i){round(total.x), round(total.y)};
	target = (t_vec2i){player->pos.x + move.x, player->pos.y + move.y};
	if (!check_collision(game->map_data, (t_vec2i){target.x, player->pos.y}))
	{
		player->pos.x = target.x;
		player->reminder.x = total.x - move.x;
	}
	else
		player->reminder.x = 0;
	if (!check_collision(game->map_data, (t_vec2i){player->pos.x, target.y}))
	{
		player->pos.y = target.y;
		player->reminder.y = total.y - move.y;
	}
	else
		player->reminder.y = 0;
}
