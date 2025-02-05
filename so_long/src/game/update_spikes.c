/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_spikes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 21:36:34 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/30 22:32:08 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

void	update_state(t_game *game)
{
	static int	delay;

	if (delay == 60)
	{
		if (game->spike_state == SPIKE_UP)
			game->spike_state = SPIKE_DOWN;
		else
			game->spike_state = SPIKE_UP;
		delay = 0;
	}
	else
		delay++;
}

void	update_spikes(t_game *game)
{
	t_position				pos;
	int						i;
	static t_spike_state	state;

	state = game->spike_state;
	i = 0;
	update_state(game);
	if (state != game->spike_state)
	{
		while (game->spikes[i])
		{
			pos.x = game->spikes[i]->instances->x;
			pos.y = game->spikes[i]->instances->y;
			mlx_delete_image(game->mlx, game->spikes[i]);
			if (game->spike_state == SPIKE_UP)
				game->spikes[i] = put_image(game->mlx, game->assets->spikes[1],
						pos.x, pos.y);
			else
				game->spikes[i] = put_image(game->mlx, game->assets->spikes[0],
						pos.x, pos.y);
			i++;
		}
		state = game->spike_state;
	}
}
