/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_door.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 16:38:12 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/07/04 16:26:00 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

void	handle_door_interaction(t_game *game)
{
	t_ray	r;
	double	player_angle;

	player_angle = game->player_data->angle;
	r.angle = player_angle;
	r.dir.x = cos(player_angle);
	r.dir.y = sin(player_angle);
	r.delta_dist.x = fabs(1 / r.dir.x);
	r.delta_dist.y = fabs(1 / r.dir.y);
	r.map_pixel_pos.x = (double)game->player_data->pos.x / TILE_SIZE;
	r.map_pixel_pos.y = (double)game->player_data->pos.y / TILE_SIZE;
	r.map_grid_pos.x = (int)r.map_pixel_pos.x;
	r.map_grid_pos.y = (int)r.map_pixel_pos.y;
	cast_single_ray(game, &r, true);
	if ((r.collision_type == 'D' || r.collision_type == 'O') && r.distance < 2)
	{
		if (game->map_data->map[r.map_grid_pos.y][r.map_grid_pos.x] == 'D')
			game->map_data->map[r.map_grid_pos.y][r.map_grid_pos.x] = 'O';
		else if (game->map_data->map[r.map_grid_pos.y][r.map_grid_pos.x] == 'O')
			game->map_data->map[r.map_grid_pos.y][r.map_grid_pos.x] = 'D';
	}
}
