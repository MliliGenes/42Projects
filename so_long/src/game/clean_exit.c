/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:26:39 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/30 21:32:07 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

void	clean_exit(t_game **game)
{
	free_expanded_map((*game)->map->pixels, (*game)->map->height / TILE_SIZE);
	clear_t_list_list((*game)->map->grid);
	if ((*game)->coins)
		free((*game)->coins);
	if ((*game)->spikes)
		free((*game)->spikes);
	if ((*game)->player)
		free((*game)->player);
	free_assets((*game)->assets);
	if ((*game)->map)
		free((*game)->map);
	if ((*game)->animations)
		free((*game)->animations);
	if ((*game)->mlx)
	{
		mlx_close_window((*game)->mlx);
		mlx_terminate((*game)->mlx);
	}
	free(*game);
	exit(EXIT_SUCCESS);
}
