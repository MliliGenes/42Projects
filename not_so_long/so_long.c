/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:21:00 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/16 20:40:22 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/game.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		return (EXIT_FAILURE);
	game = NULL;
	game = init_game_struct();
	if (!parser(argv[1], &(game->map)))
		return (error("Bad Trip"), free(game), EXIT_FAILURE);
	// if (!init_textures(&(game->assets)))
	// 	return (error(message), free(game), EXIT_FAILURE);
	start_game(game);
	return (EXIT_FAILURE);
}
