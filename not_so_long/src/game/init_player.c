/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 21:06:56 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/18 11:24:19 by sel-mlil         ###   ########.fr       */
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
	player->player = NULL;

	return (player);
}