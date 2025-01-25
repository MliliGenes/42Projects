/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:21:00 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/25 18:55:54 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/game.h"
#include <stdlib.h>

void	ll(void)
{
	system("leaks so_long");
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		return (EXIT_FAILURE);
	game = init_game_struct();
	if (!game)
		return (clean_exit(&game), EXIT_FAILURE);
	if (!parser(argv[1], &(game->map)))
		return (error("BAD MAP!!!"), free(game), EXIT_FAILURE);
	if (!convert_map(&game))
		return (EXIT_FAILURE);
	start_game(&game);
	return (EXIT_SUCCESS);
}
