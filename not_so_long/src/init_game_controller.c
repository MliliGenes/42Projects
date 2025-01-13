/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_controller.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:15:14 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/13 15:16:27 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void init_game_controller()
{
    // 1. Memory Allocation & Basic Init
    // - Allocate all main structures (game components)
    // - Check for allocation failures
    // - Initialize basic variables (score = 0, moves = 0, etc.)

    // 2. MLX Initialization
    //     - Initialize MLX window
    //     - Set up window properties
    //     - Check for MLX init failure

    // 3. Map Loading & Validation
    //     - Call init_map(game->map, map_path)
    //     - Validate map structure
    //     - Find player starting position
    //     - Count collectibles
    //     - If any step fails, cleanup and return false

    // 4. Asset Loading
    //     - Call load_assets(game->assets)
    //     - If failed, cleanup and return false

    // 5. Animation Setup
    //     - Call init_animations(game->animations, game->assets->player_sprite_sheet)
    //     - Set initial animation states
    //     - If failed, cleanup and return false

    // 6. Player Setup
    //     - Initialize player position from map
    //     - Set initial state to IDLE
    //     - Set up pixel position based on grid position

    // 7. Game Hooks Setup
    //     - Set up key hook for player input
    //     - Set up loop hook for animation updates
    //     - Set up close window hook

    // 8. Error Handling
    //     - If any step fails:
    //         - Call cleanup functions
    //         - Return false
    //     - If all successful, return true
}
