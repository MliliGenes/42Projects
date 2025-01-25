/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 06:06:57 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/01/25 20:43:34 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "mlx42.h"

# ifndef TILE_SIZE
#  define TILE_SIZE 64
# endif

# ifndef SPEED
#  define SPEED 4
# endif

# ifndef ANIMATE
#  define ANIMATE false
# endif

# ifndef GAME_NAME
#  define GAME_NAME "so_long"
# endif

typedef struct s_list
{
	char			*line;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

typedef struct s_play_pos
{
	t_list			*line;
	int				x;
}					t_play_pos;

typedef struct s_validate
{
	int				line_len;
	int				collectibles_found;
	int				exits_found;
	int				players_found;
}					t_validate;

typedef struct s_assets
{
	mlx_texture_t	*wall;
	mlx_texture_t	*tile;
	mlx_texture_t	*rock;
	mlx_texture_t	*collectible;
	mlx_texture_t	*exit;
	mlx_texture_t	*player;
	mlx_texture_t	*walk_right[4];
	mlx_texture_t	*walk_left[4];
	mlx_texture_t	*walk_up[4];
	mlx_texture_t	*walk_down[4];
}					t_assets;

typedef struct s_animations
{
	int				current_frame;
	int				frame_duration;
}					t_animations;

typedef struct s_position
{
	int				x;
	int				y;
}					t_position;

typedef enum s_state
{
	IDLE,
	MOVING_RIGHT,
	MOVING_LEFT,
	MOVING_UP,
	MOVING_DOWN,
}					t_state;

typedef struct s_player
{
	mlx_image_t		*player;
	t_state			state;
}					t_player;

typedef struct s_map
{
	t_list			*grid;
	char			**pixels;
	int				width;
	int				height;
}					t_map;

typedef struct s_game
{
	mlx_t			*mlx;
	t_assets		*assets;
	t_animations	*animations;
	t_player		*player;
	mlx_image_t		**coins;
	t_map			*map;
	float			moves;
	int				coins_count;
	bool			can_exit;
	const char		*title;
}					t_game;

#endif