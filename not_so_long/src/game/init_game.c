/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 05:31:38 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/16 10:03:24 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

game_t	*init_game_struct(void)
{
	game_t	*game;

	game = ft_calloc(1, sizeof(game_t));
	return (game);
}
