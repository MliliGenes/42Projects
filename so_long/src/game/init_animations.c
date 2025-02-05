/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_animations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 22:00:10 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/23 16:59:36 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

int	init_assets_animations_up(t_assets **assets)
{
	(*assets)->walk_up[0] = mlx_load_png("textures/up/up1.png");
	if (!(*assets)->walk_up[0])
		return (0);
	(*assets)->walk_up[1] = mlx_load_png("textures/up/up2.png");
	if (!(*assets)->walk_up[1])
		return (0);
	(*assets)->walk_up[2] = mlx_load_png("textures/up/up3.png");
	if (!(*assets)->walk_up[2])
		return (0);
	(*assets)->walk_up[3] = mlx_load_png("textures/up/up4.png");
	if (!(*assets)->walk_up[3])
		return (0);
	return (1);
}

int	init_assets_animations_down(t_assets **assets)
{
	(*assets)->walk_down[0] = mlx_load_png("textures/down/down1.png");
	if (!(*assets)->walk_down[0])
		return (0);
	(*assets)->walk_down[1] = mlx_load_png("textures/down/down2.png");
	if (!(*assets)->walk_down[1])
		return (0);
	(*assets)->walk_down[2] = mlx_load_png("textures/down/down3.png");
	if (!(*assets)->walk_down[2])
		return (0);
	(*assets)->walk_down[3] = mlx_load_png("textures/down/down4.png");
	if (!(*assets)->walk_down[3])
		return (0);
	return (1);
}

int	init_assets_animations_left(t_assets **assets)
{
	(*assets)->walk_left[0] = mlx_load_png("textures/left/left1.png");
	if (!(*assets)->walk_left[0])
		return (0);
	(*assets)->walk_left[1] = mlx_load_png("textures/left/left2.png");
	if (!(*assets)->walk_left[1])
		return (0);
	(*assets)->walk_left[2] = mlx_load_png("textures/left/left3.png");
	if (!(*assets)->walk_left[2])
		return (0);
	(*assets)->walk_left[3] = mlx_load_png("textures/left/left4.png");
	if (!(*assets)->walk_left[3])
		return (0);
	return (1);
}

int	init_assets_animations_right(t_assets **assets)
{
	(*assets)->walk_right[0] = mlx_load_png("textures/right/right1.png");
	if (!(*assets)->walk_right[0])
		return (0);
	(*assets)->walk_right[1] = mlx_load_png("textures/right/right2.png");
	if (!(*assets)->walk_right[1])
		return (0);
	(*assets)->walk_right[2] = mlx_load_png("textures/right/right3.png");
	if (!(*assets)->walk_right[2])
		return (0);
	(*assets)->walk_right[3] = mlx_load_png("textures/right/right4.png");
	if (!(*assets)->walk_right[3])
		return (0);
	return (1);
}
