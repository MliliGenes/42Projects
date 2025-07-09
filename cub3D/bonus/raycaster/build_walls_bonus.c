/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_walls_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 02:39:42 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/07/08 17:48:34 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game_bonus.h"

t_wall_render	calculate_wall_height(t_game *game, double distance)
{
	t_wall_render	render;

	render.line_h = (SCREEN_HEIGHT_DEFAULT * 1.2) / distance;
	render.start_y = (game->screen_height - (int)render.line_h) / 2;
	render.end_y = render.start_y + (int)render.line_h;
	if (render.start_y < 0)
		render.start_y = 0;
	if (render.end_y >= game->screen_height)
		render.end_y = game->screen_height - 1;
	return (render);
}

int	calculate_texture_x(double texture_x_coord, int tex_width)
{
	int	tex_x;

	tex_x = (int)(texture_x_coord * (double)tex_width);
	if (tex_x < 0)
		tex_x = 0;
	if (tex_x >= tex_width)
		tex_x = tex_width - 1;
	return (tex_x);
}

void	calculate_texture_stepping(t_wall_render *render, t_game *game,
		int tex_height)
{
	render->step = (double)tex_height / render->line_h;
	render->tex_pos = (render->start_y - game->screen_height / 2.0
			+ render->line_h / 2.0) * render->step;
}

void	draw_wall_column(t_game *game, t_wall_render *render, t_texture *tex,
		int column_x)
{
	int			y;
	int			tex_y;
	uint32_t	color;

	y = render->start_y;
	while (y <= render->end_y)
	{
		tex_y = (int)render->tex_pos;
		if (tex_y < 0)
			tex_y = 0;
		if (tex_y >= (int)tex->height)
			tex_y = tex->height - 1;
		color = tex->arr[tex_y][render->tex_x];
		mlx_put_pixel(game->img_scene, column_x, y, color);
		render->tex_pos += render->step;
		y++;
	}
}

void	render_walls(t_game *game)
{
	int				i;
	t_wall_hit		*walls;
	t_wall_hit		hit;
	t_texture		*tex;
	t_wall_render	render;

	i = 0;
	walls = game->walls;
	render_floor_cell(game);
	while (i < game->screen_width)
	{
		hit = walls[i];
		tex = &game->walls_textures[hit.texture_id];
		render = calculate_wall_height(game, hit.distance);
		render.tex_x = calculate_texture_x(hit.texture_x_coord, tex->width);
		calculate_texture_stepping(&render, game, tex->height);
		draw_wall_column(game, &render, tex, i);
		i++;
	}
}
