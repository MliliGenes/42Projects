/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_lister.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 08:11:31 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/30 22:27:33 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

static void	release(mlx_t *win, t_player *player)
{
	if (!mlx_is_key_down(win, MLX_KEY_D) && !mlx_is_key_down(win, MLX_KEY_A)
		&& !mlx_is_key_down(win, MLX_KEY_W) && !mlx_is_key_down(win, MLX_KEY_S)
		&& !mlx_is_key_down(win, MLX_KEY_RIGHT) && !mlx_is_key_down(win,
			MLX_KEY_LEFT) && !mlx_is_key_down(win, MLX_KEY_UP)
		&& !mlx_is_key_down(win, MLX_KEY_DOWN))
		player->state = IDLE;
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

static void	movement(mlx_t *win, char **map, t_player *player, float *count)
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
		player->player->instances->x = new_pos.x;
		if ((curr.x + 32) / 64 != (new_pos.x + 32) / 64)
			print_moves((int *)count);
	}
	if (check_y_movement(map, &curr, &new_pos))
	{
		player->player->instances->y = new_pos.y;
		if ((curr.y + 32) / 64 != (new_pos.y + 32) / 64)
			print_moves((int *)count);
	}
	release(win, player);
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
	check_spike(game_instance, game_instance->player->player->instances->x,
		game_instance->player->player->instances->y);
	update_player(game_instance);
	if (ANIMATE)
		update_spikes(game_instance);
	exit_game(&game_instance);
	if (!(game_instance->can_exit) && !game_instance->coins_count)
	{
		game_instance->can_exit = true;
		draw_exit(&game_instance);
	}
	if (game_instance->can_exit)
		check_exit(game_instance, game_instance->player->player->instances->x,
			game_instance->player->player->instances->y);
}
