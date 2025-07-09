/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 16:26:19 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/07/08 17:49:50 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/init_bonus.h"

bool	init_game(t_game *game)
{
	game->e_key_was_up = true;
	game->fov_rad = deg_to_radian(FOV);
	game->screen_width = SCREEN_WIDTH_DEFAULT;
	game->screen_height = SCREEN_HEIGHT_DEFAULT;
	game->mlx = mlx_init(game->screen_width, game->screen_height, GAME_TITLE,
			false);
	if (!game->mlx)
		return (false);
	game->img_scene = mlx_new_image(game->mlx, game->mlx->width,
			game->mlx->height);
	game->img_minimap = mlx_new_image(game->mlx, MINIMAP_WIDTH, MINIMAP_HEIGHT);
	game->rays = init_rays();
	if (!game->rays)
		return (false);
	game->walls = init_walls();
	if (!game->rays)
		return (false);
	return (true);
}
