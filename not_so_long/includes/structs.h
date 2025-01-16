/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 06:06:57 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/16 10:06:37 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "mlx42.h"

typedef struct list_s
{
	char			*line;
	struct list_s	*next;
	struct list_s	*prev;
}					list_t;

typedef struct play_pos_s
{
	list_t			*line;
	int				x;
}					play_pos_t;

typedef struct validate_s
{
	int				line_len;
	int				collectibles_found;
	int				exits_found;
	int				players_found;
}					validate_t;

typedef struct assets_s
{
	mlx_texture_t	*wall;
	mlx_texture_t	*tile;
	mlx_texture_t	*collectible;
	mlx_texture_t	*exit;
	mlx_texture_t	*player;
}					assets_t;

typedef struct animations_s
{
	mlx_image_t		*idle;
	mlx_image_t		*walk_right[4];
	mlx_image_t		*walk_left[4];
	mlx_image_t		*walk_up[4];
	mlx_image_t		*walk_down[4];
	int				current_frame;
	int				frame_duration;
}					animations_t;

typedef struct position_s
{
	int				x;
	int				y;
}					position_t;

typedef enum state_s
{
	IDLE = 0,
	MOVING_RIGHT = 1,
	MOVING_LEFT = 2,
	MOVING_UP = 3,
	MOVING_DOWN = 4,
}					state_t;

typedef struct player_s
{
	state_t			state;
	position_t		grid_pos;
	position_t		pixel_pos;
}					player_t;

typedef struct map_s
{
	list_t			*grid;
	int				width;
	int				height;
}					map_t;

typedef struct game_s
{
	mlx_t			*mlx;
	assets_t		*assets;
	animations_t	*animations;
	player_t		*player;
	map_t			*map;
	int				moves;
	int				coins;
	const char		*title;
}					game_t;

#endif