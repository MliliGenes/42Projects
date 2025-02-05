/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 18:32:49 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/25 23:45:12 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

void	exit_game(t_game **game)
{
	if (mlx_is_key_down((*game)->mlx, MLX_KEY_ESCAPE))
	{
		write(1, "LOSER <3", 8);
		clean_exit(game);
	}
}
