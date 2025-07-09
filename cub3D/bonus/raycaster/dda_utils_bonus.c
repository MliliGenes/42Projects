/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 16:43:39 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/07/08 17:48:34 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game_bonus.h"

static int	is_wall_hit(t_game *game, int x, int y, bool door)
{
	if (y < 0 || x < 0)
		return (1);
	if (y >= game->map_data->height || x >= game->map_data->width)
		return (1);
	if (door && game->map_data->map[y][x] == 'O')
		return (3);
	if (game->map_data->map[y][x] == 'D')
		return (2);
	if (game->map_data->map[y][x] == '1')
		return (1);
	else
		return (0);
}

static void	calculate_wall_hit_distance(t_ray *ray)
{
	if (ray->side_hit == 0)
		ray->distance = (ray->map_grid_pos.x - ray->map_pixel_pos.x + (double)(1
					- ray->steps.x) / 2) / ray->dir.x;
	else
		ray->distance = (ray->map_grid_pos.y - ray->map_pixel_pos.y + (double)(1
					- ray->steps.y) / 2) / ray->dir.y;
	ray->distance = fabs(ray->distance);
}

static void	advance_ray(t_ray *ray)
{
	if (ray->side_dist.x < ray->side_dist.y)
	{
		ray->distance = ray->side_dist.x;
		ray->side_dist.x += ray->delta_dist.x;
		ray->map_grid_pos.x += ray->steps.x;
		ray->side_hit = 0;
	}
	else
	{
		ray->distance = ray->side_dist.y;
		ray->side_dist.y += ray->delta_dist.y;
		ray->map_grid_pos.y += ray->steps.y;
		ray->side_hit = 1;
	}
}

void	dda_loop(t_game *game, t_ray *ray, bool door)
{
	int	type;

	type = 0;
	while (true && ray)
	{
		advance_ray(ray);
		type = is_wall_hit(game, ray->map_grid_pos.x, ray->map_grid_pos.y,
				door);
		if (type)
		{
			if (type == 1)
				ray->collision_type = 'W';
			else if (type == 2)
				ray->collision_type = 'D';
			else if (type == 3)
				ray->collision_type = 'O';
			calculate_wall_hit_distance(ray);
			break ;
		}
	}
}
