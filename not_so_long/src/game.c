/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:15:14 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/20 10:30:52 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void	start_game(t_game **game)
{
	(*game)->mlx = mlx_init((*game)->map->width, (*game)->map->height,
			(*game)->title, false);
	(*game)->mlx->delta_time = 60;
	draw_map(game, ((*game)->map->width / TILE_SIZE) - 1, ((*game)->map->height / TILE_SIZE) - 1);
	draw_player(game);
	mlx_loop_hook((*game)->mlx, event_listener, (*game));
	mlx_loop((*game)->mlx);
	mlx_terminate((*game)->mlx);
}
