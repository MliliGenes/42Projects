/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 05:31:38 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/30 21:36:05 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

static t_animations	*init_animations(void)
{
	t_animations	*animations;

	animations = ft_calloc(1, sizeof(t_animations));
	if (!animations)
		return (NULL);
	animations->current_frame = 0;
	animations->frame_duration = 0;
	return (animations);
}

t_game	*init_game_struct(void)
{
	t_game	*game;

	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		return (NULL);
	game->assets = init_assets();
	if (!init_exit_spikes(&(game->assets))
		|| !init_assets_animations_up(&(game->assets))
		|| !init_assets_animations_down(&(game->assets))
		|| !init_assets_animations_left(&(game->assets))
		|| !init_assets_animations_right(&(game->assets)))
		return (free_assets(game->assets), NULL);
	game->animations = init_animations();
	game->player = init_player();
	game->map = init_map();
	game->title = GAME_NAME;
	game->moves = 0;
	game->spike_state = SPIKE_DOWN;
	game->can_exit = false;
	if (!game->assets || !game->player || !game->map)
		return (NULL);
	return (game);
}
