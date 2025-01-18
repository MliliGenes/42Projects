/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:15:14 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/18 21:07:01 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void	start_game(t_game **game)
{
	(*game)->mlx = mlx_init((*game)->map->width, (*game)->map->height,
			(*game)->title, false);
	(*game)->mlx->delta_time = 10;
	draw_map(game);
	draw_player(game);
	mlx_loop_hook((*game)->mlx, event_listener, (*game));
	mlx_loop((*game)->mlx);
	mlx_terminate((*game)->mlx);
}
