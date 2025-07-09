/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_to_walls_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 16:44:11 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/07/08 17:48:33 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game_bonus.h"

void	set_texture_id(t_ray *ray, t_wall_hit *wall)
{
	if (ray->collision_type == 'D')
	{
		wall->texture_id = 4;
		return ;
	}
	if (ray->side_hit == 0)
	{
		if (ray->steps.x < 0)
			wall->texture_id = 2;
		else
			wall->texture_id = 3;
	}
	else
	{
		if (ray->steps.y < 0)
			wall->texture_id = 1;
		else
			wall->texture_id = 0;
	}
}

void	rays_to_walls(t_game *game)
{
	t_ray		*rays;
	t_wall_hit	*walls;
	int			i;

	rays = game->rays;
	walls = game->walls;
	i = 0;
	while (i < SCREEN_WIDTH_DEFAULT)
	{
		walls[i].distance = rays[i].distance * cos(rays[i].angle
				- game->player_data->angle);
		walls[i].side = rays[i].side_hit;
		walls[i].hit_point = rays[i].hit_point;
		set_texture_id(&rays[i], &walls[i]);
		walls[i].texture_x_coord = rays[i].wall_x;
		if ((rays[i].side_hit == 0 && rays[i].dir.x < 0)
			|| (rays[i].side_hit == 1 && rays[i].dir.y > 0))
			walls[i].texture_x_coord = 1.0 - walls[i].texture_x_coord;
		i++;
	}
}
