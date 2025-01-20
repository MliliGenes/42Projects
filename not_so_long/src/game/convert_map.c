/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 12:14:10 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/19 00:10:28 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

void	convert_map(t_game **game)
{
	(*game)->map->pixels = expand_map_by_scale((*game)->map->grid,
			(*game)->map->width / 64, (*game)->map->height / 64, 1);
}
