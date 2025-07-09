/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 16:30:39 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/07/08 17:48:34 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game_bonus.h"

void	reset_minimap(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < MINIMAP_HEIGHT)
	{
		x = 0;
		while (x < MINIMAP_WIDTH)
		{
			mlx_put_pixel(game->img_minimap, x, y, 0x000000FF);
			x++;
		}
		y++;
	}
}

static void	world_pixel(t_game *game, t_vec2i w, t_vec2i i, t_vec2i map)
{
	uint32_t	color;
	char		**grid;
	mlx_image_t	*img;

	grid = game->map_data->map;
	img = game->img_minimap;
	color = 0x1A140FFF;
	if (w.x >= 0 && w.x < map.x && w.y >= 0 && w.y < map.y)
	{
		if (grid[w.y][w.x] == '1')
			color = 0x6A4F3FFF;
		else if (grid[w.y][w.x] == ' ')
			color = 0x1A140FFF;
		else if (grid[w.y][w.x] == 'D')
			color = 0x6B3E2FFF;
		else if (grid[w.y][w.x] == 'O')
			color = 0x8E6E4FFF;
		else if (grid[w.y][w.x] == '0')
			color = 0x2F1F17FF;
		else if (grid[w.y][w.x] == 'N' || grid[w.y][w.x] == 'E'
			|| grid[w.y][w.x] == 'S' || grid[w.y][w.x] == 'W')
			color = 0xAA885FFF;
	}
	mlx_put_pixel(img, i.x, i.y, color);
}

void	render_world_on_minimap(t_game *game)
{
	t_player	*p;
	t_vec2i		c;
	t_vec2i		w;
	t_vec2i		i;

	p = game->player_data;
	c = (t_vec2i){MINIMAP_WIDTH / 2, MINIMAP_HEIGHT / 2};
	i.y = 0;
	while (i.y < MINIMAP_HEIGHT)
	{
		i.x = 0;
		while (i.x < MINIMAP_WIDTH)
		{
			w.x = (p->pos.x + ((i.x - c.x) / SCALE)) / TILE_SIZE;
			w.y = (p->pos.y + ((i.y - c.y) / SCALE)) / TILE_SIZE;
			world_pixel(game, w, i, (t_vec2i){game->map_data->width,
				game->map_data->height});
			i.x++;
		}
		i.y++;
	}
}

void	draw_player(mlx_image_t *minimap)
{
	t_vec2i	px_pos;
	int		y;
	int		x;

	y = -2;
	while (y <= 2)
	{
		x = -2;
		while (x <= 2)
		{
			px_pos = (t_vec2i){MINIMAP_WIDTH / 2 + x, MINIMAP_HEIGHT / 2 + y};
			mlx_put_pixel(minimap, px_pos.x, px_pos.y, 0xE9CD92FF);
			x++;
		}
		y++;
	}
}

void	draw_dir(mlx_image_t *minimap, t_player *p, t_vec2i pos)
{
	int		i;
	t_vec2i	line;
	double	direction_length;

	i = 0;
	direction_length = 15;
	while (i < 10)
	{
		line.x = pos.x + (cos(p->angle) * direction_length * i) / 10;
		line.y = pos.y + (sin(p->angle) * direction_length * i) / 10;
		mlx_put_pixel(minimap, line.x, line.y, 0xE9CD92FF);
		i++;
	}
}
