/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 23:17:39 by le-saad           #+#    #+#             */
/*   Updated: 2025/07/08 17:48:34 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game_bonus.h"

void	render_minimap(t_game *game)
{
	reset_minimap(game);
	render_world_on_minimap(game);
	draw_player(game->img_minimap);
	draw_dir(game->img_minimap, game->player_data, (t_vec2i){MINIMAP_WIDTH / 2,
		MINIMAP_HEIGHT / 2});
}
