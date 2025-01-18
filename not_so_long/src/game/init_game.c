/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 05:31:38 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/18 22:37:24 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

static t_animations	*init_animations(void)
{
	t_animations	*animations;

	animations = malloc(sizeof(t_animations));
	if (!animations)
		return (NULL);
	animations->current_frame = 0;
	animations->frame_duration = 0;
	return (animations);
}

t_game	*init_game_struct(void)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game->mlx = NULL;
	game->assets = init_assets();
	if (!init_assets_animations_up(&(game->assets))
		|| !init_assets_animations_down(&(game->assets))
		|| !init_assets_animations_left(&(game->assets))
		|| !init_assets_animations_right(&(game->assets)))
		return (free_assets(game->assets), NULL);
	game->animations = init_animations();
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
