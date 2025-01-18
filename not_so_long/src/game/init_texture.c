/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:05:31 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/18 15:48:35 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

void	*free_assets(t_assets *assets)
{
	if (assets->player)
		mlx_delete_texture(assets->player);
	if (assets->wall)
		mlx_delete_texture(assets->wall);
	if (assets->tile)
		mlx_delete_texture(assets->tile);
	if (assets->collectible)
		mlx_delete_texture(assets->tile);
	return (NULL);
}

t_assets	*init_assets(void)
{
	t_assets	*assets;

	assets = malloc(sizeof(t_assets));
	if (!assets)
		return (NULL);
	assets->player = mlx_load_png("textures/idle/xsa.png");
	if (!assets->player)
		return (NULL);
	assets->wall = mlx_load_png("textures/tiles/wall.png");
	if (!assets->wall)
		return (free_assets(assets));
	assets->tile = mlx_load_png("textures/tiles/tile.png");
	if (!assets->tile)
		return (free_assets(assets));
	assets->collectible = mlx_load_png("textures/collectible/collectible.png");
	if (!assets->tile)
		return (free_assets(assets));
	return (assets);
}
