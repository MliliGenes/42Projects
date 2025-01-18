/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_animations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 22:00:10 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/18 22:34:58 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

int	init_assets_animations_up(t_assets **assets)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (i == 0)
			(*assets)->walk_up[i] = mlx_load_png("textures/up/up1.png");
		else if (i == 1)
			(*assets)->walk_up[i] = mlx_load_png("textures/up/up2.png");
		else if (i == 2)
			(*assets)->walk_up[i] = mlx_load_png("textures/up/up3.png");
		else if (i == 3)
			(*assets)->walk_up[i] = mlx_load_png("textures/up/up4.png");
		if (!(*assets)->walk_up[i])
			return (0);
		i++;
	}
	return (1);
}

int	init_assets_animations_down(t_assets **assets)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (i == 0)
			(*assets)->walk_down[i] = mlx_load_png("textures/down/down1.png");
		else if (i == 1)
			(*assets)->walk_down[i] = mlx_load_png("textures/down/down2.png");
		else if (i == 2)
			(*assets)->walk_down[i] = mlx_load_png("textures/down/down3.png");
		else if (i == 3)
			(*assets)->walk_down[i] = mlx_load_png("textures/down/down4.png");
		if (!(*assets)->walk_down[i])
			return (0);
		i++;
	}
	return (1);
}

int	init_assets_animations_left(t_assets **assets)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (i == 0)
			(*assets)->walk_left[i] = mlx_load_png("textures/left/left1.png");
		else if (i == 1)
			(*assets)->walk_left[i] = mlx_load_png("textures/left/left2.png");
		else if (i == 2)
			(*assets)->walk_left[i] = mlx_load_png("textures/left/left3.png");
		else if (i == 3)
			(*assets)->walk_left[i] = mlx_load_png("textures/left/left4.png");
		if (!(*assets)->walk_left[i])
			return (0);
		i++;
	}
	return (1);
}

int	init_assets_animations_right(t_assets **assets)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (i == 0)
			(*assets)->walk_right[i] = mlx_load_png("textures/right/right1.png");
		else if (i == 1)
			(*assets)->walk_right[i] = mlx_load_png("textures/right/right2.png");
		else if (i == 2)
			(*assets)->walk_right[i] = mlx_load_png("textures/right/right3.png");
		else if (i == 3)
			(*assets)->walk_right[i] = mlx_load_png("textures/right/right4.png");
		if (!(*assets)->walk_right[i])
			return (0);
		i++;
	}
	return (1);
}
