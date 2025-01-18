/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 23:04:05 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/18 23:41:36 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

void update_player(t_game *game, bool animate)
{
    t_state state;
    t_position pos;

    // Increment frame duration to control speed of animation
    if (game->animations->frame_duration >= 6)
    {
        // Switch to the next frame and loop back to 0 if necessary
        if (game->animations->current_frame == 3)  // we have 4 frames (0, 1, 2, 3)
        {
            game->animations->current_frame = 0;
        }
        else
        {
            game->animations->current_frame++;
        }

        // Reset frame duration
        game->animations->frame_duration = 0;
    }
    else
    {
        game->animations->frame_duration++;
    }

    pos.x = game->player->player->instances->x;
    pos.y = game->player->player->instances->y;
    state = game->player->state;

    (void)animate;

    // Delete the previous image before placing the new one
    mlx_delete_image(game->mlx, game->player->player);
    game->player->player = NULL;

    // Select the correct frame based on the player's state
    if (state == IDLE)
    {
        game->player->player = put_image(game->mlx, game->assets->player, pos.x, pos.y);
    }
    else if (state == MOVING_UP)
    {
        game->player->player = put_image(game->mlx, game->assets->walk_up[game->animations->current_frame], pos.x, pos.y);
    }
    else if (state == MOVING_RIGHT)
    {
        game->player->player = put_image(game->mlx, game->assets->walk_right[game->animations->current_frame], pos.x, pos.y);
    }
    else if (state == MOVING_DOWN)
    {
        game->player->player = put_image(game->mlx, game->assets->walk_down[game->animations->current_frame], pos.x, pos.y);
    }
    else if (state == MOVING_LEFT)
    {
        game->player->player = put_image(game->mlx, game->assets->walk_left[game->animations->current_frame], pos.x, pos.y);
    }
}

