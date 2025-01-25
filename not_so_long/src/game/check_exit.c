/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 19:58:42 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/25 20:17:39 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

void	check_exit(t_game *game, int x, int y)
{
	t_position	positions[4];
	int			i;

	check_player_positions(positions, x, y);
	i = 0;
	while (i < 4)
	{
		if (game->map->pixels[positions[i].y][positions[i].x] == 'E')
            clean_exit(&game);
		i++;
	}
}
