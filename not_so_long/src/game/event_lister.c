/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_lister.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 08:11:31 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/23 22:07:57 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

static void	update_coordinates(mlx_t *win, t_position *new_pos,
		t_player *player)
{
	if (mlx_is_key_down(win, MLX_KEY_D))
	{
		new_pos->x += SPEED;
		player->state = MOVING_RIGHT;
	}
	if (mlx_is_key_down(win, MLX_KEY_A))
	{
		new_pos->x -= SPEED;
		player->state = MOVING_LEFT;
	}
	if (mlx_is_key_down(win, MLX_KEY_W))
	{
		new_pos->y -= SPEED;
		player->state = MOVING_UP;
	}
	if (mlx_is_key_down(win, MLX_KEY_S))
	{
		new_pos->y += SPEED;
		player->state = MOVING_DOWN;
	}
}

static int	check_x_movement(char **map, t_position *curr, t_position *new_pos)
{
	if (check_collision(map, new_pos->x, curr->y, '1'))
	{
		if (curr->x != new_pos->x)
			return (1);
		curr->x = new_pos->x;
	}
	return (0);
}

static int	check_y_movement(char **map, t_position *curr, t_position *new_pos)
{
	if (check_collision(map, curr->x, new_pos->y, '1'))
	{
		if (curr->y != new_pos->y)
			return (1);
		curr->y = new_pos->y;
	}
	return (0);
}

static void	movement(mlx_t *win, char **map, t_player *player, int *count)
{
	t_position	new_pos;
	t_position	curr;

	curr.x = player->player->instances->x;
	curr.y = player->player->instances->y;
	new_pos.x = curr.x;
	new_pos.y = curr.y;
	update_coordinates(win, &new_pos, player);
	if (check_x_movement(map, &curr, &new_pos))
	{
		(*count)++;
			print_moves(*count);
		player->player->instances->x = new_pos.x;
	}
	if (check_y_movement(map, &curr, &new_pos))
	{
		(*count)++;
			print_moves(*count);
		player->player->instances->y = new_pos.y;
	}
	if (!mlx_is_key_down(win, MLX_KEY_D) && !mlx_is_key_down(win, MLX_KEY_A)
		&& !mlx_is_key_down(win, MLX_KEY_W) && !mlx_is_key_down(win, MLX_KEY_S))
		player->state = IDLE;
}

void	event_listener(void *game)
{
	t_game	*game_instance;

	game_instance = (t_game *)game;
	movement(game_instance->mlx, game_instance->map->pixels,
		game_instance->player, &(game_instance->moves));
	check_coins(game_instance, game_instance->coins,
		game_instance->player->player->instances->x,
		game_instance->player->player->instances->y);
	update_player(game_instance);
	// if (game_instance->coins_count == 0)
	// {
	// 	mlx_close_window(game_instance->mlx);
	// 	clean_exit(&game_instance);
	// 	exit(EXIT_SUCCESS);
	// }
}
