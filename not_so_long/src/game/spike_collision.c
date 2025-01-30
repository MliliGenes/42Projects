/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spike_collision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 22:19:54 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/30 22:30:46 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

void	check_spike(t_game *game, int x, int y)
{
	t_position	positions[4];
	int			i;

	check_player_positions(positions, x, y);
	i = 0;
	while (i < 4)
	{
		if (game->map->pixels[positions[i].y][positions[i].x] == 'S'
			&& game->spike_state == SPIKE_UP)
		{
			write(1, "DEAD MEAT\n", 10);
			clean_exit(&game);
		}
		i++;
	}
}
