/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 05:31:38 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/16 21:07:57 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

// // Initialize animations structure
// static t_animations *init_animations(void)
// {
//     t_animations *animations;
//     int i;

//     animations = malloc(sizeof(t_animations));
//     if (!animations)
//         return (NULL);

//     animations->idle = NULL;
//     for (i = 0; i < 4; i++)
//     {
//         animations->walk_right[i] = NULL;
//         animations->walk_left[i] = NULL;
//         animations->walk_up[i] = NULL;
//         animations->walk_down[i] = NULL;
//     }
//     animations->current_frame = 0;
//     animations->frame_duration = 8; // Adjust this value as needed

//     return (animations);
// }

// // Initialize player structure
// static t_player *init_player(void)
// {
//     t_player *player;

//     player = malloc(sizeof(t_player));
//     if (!player)
//         return (NULL);

//     player->state = IDLE;
//     player->grid_pos.x = 0;
//     player->grid_pos.y = 0;
//     player->pixel_pos.x = 0;
//     player->pixel_pos.y = 0;

//     return (player);
// }

// Main initialization function
t_game	*init_game_struct(void)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game->mlx = NULL;
	game->assets = init_assets();
	// game->animations = init_animations();
	game->player = init_player();
	game->map = init_map();
	game->moves = 0;
	game->coins = 0;
	game->title = GAME_NAME;
	if (!game->assets || !game->player || !game->map)
	{
		free(game);
		return (NULL);
	}
	return (game);
}
