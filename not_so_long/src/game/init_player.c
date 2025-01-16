/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 21:06:56 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/16 21:07:59 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

t_player	*init_player(void)
{
	t_player *player;

	player = malloc(sizeof(t_player));
	if (!player)
		return (NULL);

	player->state = IDLE;
	player->grid_pos.x = 0;
	player->grid_pos.y = 0;
	player->pixel_pos.x = 0;
	player->pixel_pos.y = 0;

	return (player);
}