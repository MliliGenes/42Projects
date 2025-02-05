/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:15:14 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/30 22:02:23 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

int	calc_coins(t_game **game)
{
	int	i;

	i = 0;
	(*game)->coins_count = search_in_map((*game)->map->grid, 'C');
	(*game)->coins = malloc(sizeof(mlx_image_t *) * ((*game)->coins_count + 1));
	if (!(*game)->coins)
		return (0);
	(*game)->coins[(*game)->coins_count] = NULL;
	return (1);
}

int	calc_spikes(t_game **game)
{
	int	i;

	i = 0;
	(*game)->spikes = malloc(sizeof(mlx_image_t *)
			* (search_in_map((*game)->map->grid, 'S') + 1));
	if (!(*game)->spikes)
		return (0);
	(*game)->spikes[search_in_map((*game)->map->grid, 'S')] = NULL;
	return (1);
}

void	start_game(t_game **game)
{
	(*game)->mlx = mlx_init((*game)->map->width, (*game)->map->height,
			(*game)->title, false);
	(*game)->mlx->delta_time = 0;
	if (!calc_coins(game) || !calc_spikes(game))
		return (clean_exit(game));
	draw_map(game, ((*game)->map->width / TILE_SIZE) - 1, ((*game)->map->height
			/ TILE_SIZE) - 1);
	draw_player(game);
	draw_coins(game);
	if (ANIMATE)
		draw_spikes(game);
	mlx_loop_hook((*game)->mlx, event_listener, (*game));
	mlx_loop((*game)->mlx);
	clean_exit(game);
}
