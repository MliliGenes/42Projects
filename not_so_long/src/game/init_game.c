/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 05:31:38 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/16 13:39:53 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

t_game	*init_game_struct(void)
{
	t_game	*game;

	game = ft_calloc(1, sizeof(t_game));
    game->title = GAME_NAME;
    game->moves = 0;
    game->coins = 0;
	return (game);
}
