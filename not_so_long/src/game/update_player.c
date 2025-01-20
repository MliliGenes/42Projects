/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 23:04:05 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/20 10:54:03 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

void	update_animation(t_game *game, bool animate)
{
	if (!animate)
		return ;
	if (game->animations->frame_duration == 8)
	{
		if (game->animations->current_frame == 3)
			game->animations->current_frame = 0;
		else
			game->animations->current_frame++;
		game->animations->frame_duration = 0;
	}
	else
	{
		game->animations->frame_duration++;
	}
}

void	get_player_texture(t_game *game, t_state state, t_position pos)
{
	if (state == IDLE)
		game->player->player = put_image(game->mlx, game->assets->player, pos.x,
				pos.y);
	else if (state == MOVING_UP)
		game->player->player = put_image(game->mlx,
				game->assets->walk_up[game->animations->current_frame], pos.x,
				pos.y);
	else if (state == MOVING_RIGHT)
		game->player->player = put_image(game->mlx,
				game->assets->walk_right[game->animations->current_frame],
				pos.x, pos.y);
	else if (state == MOVING_DOWN)
		game->player->player = put_image(game->mlx,
				game->assets->walk_down[game->animations->current_frame], pos.x,
				pos.y);
	else if (state == MOVING_LEFT)
		game->player->player = put_image(game->mlx,
				game->assets->walk_left[game->animations->current_frame], pos.x,
				pos.y);
}

void	update_player(t_game *game)
{
	t_position	pos;
	t_state		state;

	pos.x = game->player->player->instances->x;
	pos.y = game->player->player->instances->y;
	state = game->player->state;
	mlx_delete_image(game->mlx, game->player->player);
	game->player->player = NULL;
	update_animation(game, ANIMATE);
	get_player_texture(game, state, pos);
}
