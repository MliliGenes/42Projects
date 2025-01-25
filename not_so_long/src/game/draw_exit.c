/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 19:51:18 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/25 20:00:48 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

static void	where_is_the_exit(t_list *map, t_position *pos)
{
	int	i;
	int	found;

	found = 0;
	pos->y = 0;
	while (map)
	{
		pos->x = 0;
		i = 0;
		while (map->line[i])
		{
			if (map->line[i] == 'E')
				return ;
			pos->x += TILE_SIZE;
			i++;
		}
		pos->y += TILE_SIZE;
		map = map->next;
	}
}

void	draw_exit(t_game **game)
{
	t_position	pos;

	where_is_the_exit((*game)->map->grid, &pos);
	put_image((*game)->mlx, (*game)->assets->exit, pos.x, pos.y);
}
