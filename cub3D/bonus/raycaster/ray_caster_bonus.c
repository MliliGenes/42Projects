/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_caster_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 21:28:35 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/07/08 17:48:33 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game_bonus.h"

static void	set_angles(t_ray *rays, double fov_rad, double pov_angle)
{
	double	angle_step;
	double	start_angle;
	int		i;

	i = 0;
	angle_step = fov_rad / (SCREEN_WIDTH_DEFAULT - 1);
	start_angle = pov_angle - (fov_rad / 2);
	while (rays && i < SCREEN_WIDTH_DEFAULT)
	{
		rays[i].distance = 0.0;
		rays[i].angle = normalize_angle(start_angle + (i * angle_step));
		rays[i].dir = (t_vec2d){cos(rays[i].angle), sin(rays[i].angle)};
		rays[i].delta_dist.x = fabs(1 / rays[i].dir.x);
		rays[i].delta_dist.y = fabs(1 / rays[i].dir.y);
		i++;
	}
}

void	cast_single_ray(t_game *game, t_ray *ray, bool door)
{
	if (ray->dir.x < 0)
	{
		ray->steps.x = -1;
		ray->side_dist.x = (ray->map_pixel_pos.x - ray->map_grid_pos.x)
			* ray->delta_dist.x;
	}
	else
	{
		ray->steps.x = 1;
		ray->side_dist.x = (ray->map_grid_pos.x + 1 - ray->map_pixel_pos.x)
			* ray->delta_dist.x;
	}
	if (ray->dir.y < 0)
	{
		ray->steps.y = -1;
		ray->side_dist.y = (ray->map_pixel_pos.y - ray->map_grid_pos.y)
			* ray->delta_dist.y;
	}
	else
	{
		ray->steps.y = 1;
		ray->side_dist.y = (ray->map_grid_pos.y + 1 - ray->map_pixel_pos.y)
			* ray->delta_dist.y;
	}
	dda_loop(game, ray, door);
}

void	cast_rays(t_game *game)
{
	t_ray	*r;
	int		i;

	i = 0;
	r = game->rays;
	set_angles(r, game->fov_rad, game->player_data->angle);
	while (r && i < SCREEN_WIDTH_DEFAULT)
	{
		r[i].map_pixel_pos = (t_vec2d){(double)game->player_data->pos.x
			/ (double)TILE_SIZE, (double)game->player_data->pos.y
			/ (double)TILE_SIZE};
		r[i].map_grid_pos = (t_vec2i){(int)r[i].map_pixel_pos.x,
			(int)r[i].map_pixel_pos.y};
		cast_single_ray(game, &r[i], false);
		r[i].hit_point = (t_vec2d){game->player_data->pos.x + r[i].dir.x
			* r[i].distance, game->player_data->pos.y + r[i].dir.y
			* r[i].distance};
		if (r[i].side_hit == 0)
			r[i].wall_x = r[i].map_pixel_pos.y + r[i].distance * r[i].dir.y;
		else
			r[i].wall_x = r[i].map_pixel_pos.x + r[i].distance * r[i].dir.x;
		r[i].wall_x -= floor(r[i].wall_x);
		i++;
	}
}
