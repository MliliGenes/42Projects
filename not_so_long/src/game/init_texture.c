/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:05:31 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/16 15:19:24 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

int	free_textures(t_assets *assets)
{
	if (assets->player)
		mlx_delete_texture(assets->player);
	if (assets->wall)
		mlx_delete_texture(assets->wall);
	if (assets->tile)
		mlx_delete_texture(assets->tile);
	return (0);
}

int	init_textures(t_assets **assets)
{
	(*assets)->player = mlx_load_png("../../textures/idle/xsa.png");
	if (!(*assets)->player)
		return (0);
	(*assets)->wall = mlx_load_png("../../textures/tiles/wall.png");
	if (!(*assets)->wall)
		return (free_textures(*assets));
	(*assets)->tile = mlx_load_png("../../textures/tiles/tile.png");
	if (!(*assets)->tile)
		return (free_textures(*assets));
	return (1);
}

