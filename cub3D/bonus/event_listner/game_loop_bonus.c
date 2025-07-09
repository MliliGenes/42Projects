/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 12:12:31 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/07/08 17:50:00 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game_bonus.h"

void	load_frames(t_game *game, t_main_menu *param)
{
	mlx_texture_t	*tmp;
	mlx_texture_t	*tmp2;

	tmp = mlx_load_png("imgs/stats.png");
	tmp2 = mlx_load_png("imgs/borders.png");
	game->img_stats = mlx_texture_to_image(game->mlx, tmp);
	game->img_borders = mlx_texture_to_image(game->mlx, tmp2);
	mlx_delete_texture(tmp);
	mlx_delete_texture(tmp2);
	param->frames[0] = mlx_load_png("imgs/main_menu/frame_1.png");
	param->frames[1] = mlx_load_png("imgs/main_menu/frame_2.png");
	param->frames[2] = mlx_load_png("imgs/main_menu/frame_3.png");
	param->frames[3] = mlx_load_png("imgs/main_menu/frame_4.png");
	param->frames[4] = mlx_load_png("imgs/main_menu/frame_5.png");
	param->img = NULL;
}

void	free_frames(t_main_menu *frames)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		mlx_delete_texture(frames->frames[i]);
		frames->frames[i] = NULL;
		i++;
	}
}

void	game_loop(t_game *game)
{
	t_main_menu	frames;
	t_vec2i		pos;

	load_frames(game, &frames);
	game->frames = &frames;
	pos = (t_vec2i){MINIMAP_PADDING, SCREEN_HEIGHT_DEFAULT
		- game->img_stats->height - MINIMAP_PADDING};
	mlx_image_to_window(game->mlx, game->img_scene, 0, 0);
	mlx_image_to_window(game->mlx, game->img_minimap, MINIMAP_PADDING + 10,
		MINIMAP_PADDING + 10);
	mlx_image_to_window(game->mlx, game->img_stats, pos.x, pos.y);
	mlx_image_to_window(game->mlx, game->img_borders, MINIMAP_PADDING,
		MINIMAP_PADDING);
	mlx_set_cursor_mode(game->mlx, MLX_MOUSE_HIDDEN);
	mlx_set_mouse_pos(game->mlx, SCREEN_WIDTH_DEFAULT / 2, SCREEN_HEIGHT_DEFAULT
		/ 2);
	game->start_game = false;
	mlx_loop_hook(game->mlx, event_listner, game);
	mlx_loop(game->mlx);
	free_frames(&frames);
}
