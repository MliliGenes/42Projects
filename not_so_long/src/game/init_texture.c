/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:05:31 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/18 22:01:46 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

static void free_walk_textures(t_assets *assets)
{
    int i = 0;

    // Freeing walk textures for all directions using a while loop
    while (i < 4)
    {
        if (assets->walk_up[i])
            mlx_delete_texture(assets->walk_up[i]);
        if (assets->walk_down[i])
            mlx_delete_texture(assets->walk_down[i]);
        if (assets->walk_left[i])
            mlx_delete_texture(assets->walk_left[i]);
        if (assets->walk_right[i])
            mlx_delete_texture(assets->walk_right[i]);
        
        i++;
    }
}


void *free_assets(t_assets *assets)
{
    if (assets->player)
        mlx_delete_texture(assets->player);
    if (assets->wall)
        mlx_delete_texture(assets->wall);
    if (assets->tile)
        mlx_delete_texture(assets->tile);
    if (assets->collectible)
        mlx_delete_texture(assets->collectible);
    if (assets->exit[0])
        mlx_delete_texture(assets->exit[0]);
    if (assets->exit[1])
        mlx_delete_texture(assets->exit[1]);

    free_walk_textures(assets);

    free(assets);
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
	if (!assets->collectible)
		return (free_assets(assets));
	// assets->exit[0] = mlx_load_png("textures/exit/exit1.png");
	// if (!assets->exit[0])
	// 	return (free_assets(assets));
	// assets->exit[1] = mlx_load_png("textures/exit/exit2.png");
	// if (!assets->exit[1])
	// 	return (free_assets(assets));
	return (assets);
}



