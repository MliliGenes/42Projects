/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_moves_in_win.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 23:12:14 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/30 23:46:06 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

void	print_moves_in_win(t_game *game)
{
	char		*moves_str;
	static int	old_move;

	if (game->moves != old_move)
	{
		moves_str = ft_itoa(game->moves - 1);
		if (!moves_str)
			return ;
		moves_str = ft_strjoin(moves_str, " moves");
		mlx_delete_image(game->mlx, game->move);
		game->move = mlx_put_string(game->mlx, moves_str, 30, game->map->height
				- 45);
		free(moves_str);
		old_move = game->moves;
	}
}
