/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_spikes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 20:46:01 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/30 21:16:05 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_coins.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:30:14 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/25 23:50:15 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

static void	set_spike(t_game **game, mlx_image_t **spike, t_position pos)
{
	(*spike) = put_image((*game)->mlx, (*game)->assets->spikes[0], pos.x,
			pos.y);
}

void	draw_spikes(t_game **game)
{
	t_position	pos;
	t_position	i_j;
	int			i;
	char		**grid;

	pos.y = 0;
	i_j.y = 0;
	grid = (*game)->map->pixels;
	i = 0;
	while (grid[i_j.y])
	{
		pos.x = 0;
		i_j.x = 0;
		while (grid[i_j.y][i_j.x])
		{
			if (grid[i_j.y][i_j.x] == 'S')
				set_spike(game, &((*game)->spikes[i++]), pos);
			pos.x += TILE_SIZE;
			i_j.x++;
		}
		pos.y += TILE_SIZE;
		i_j.y++;
	}
}
