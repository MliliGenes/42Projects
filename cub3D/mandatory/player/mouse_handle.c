/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 23:15:33 by le-saad           #+#    #+#             */
/*   Updated: 2025/07/04 16:28:54 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

void	mouse_eventlistner(t_game *game)
{
	t_vec2i		mouse;
	t_vec2i		center;
	static int	start = 2;

	game->player_data->forward_backward = 0;
	game->player_data->left_right = 0;
	center.x = game->mlx->width / 2;
	center.y = game->mlx->height / 2;
	mouse.x = game->mlx->width / 2;
	mouse.y = game->mlx->height / 2;
	if (!start)
		mlx_get_mouse_pos(game->mlx, &(mouse.x), &(mouse.y));
	else
		start--;
	game->player_data->angle += (mouse.x - center.x)
		* game->player_data->rot_speed * 0.02;
	mlx_set_mouse_pos(game->mlx, center.x, center.y);
}
