#ifndef SO_LONG_H
# define SO_LONG_H

# include "./lib.h"
# include "./mlx42.h"

typedef struct assets_s
{
	mlx_texture_t	*top_wall;
	mlx_texture_t	*floor;
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
	mlx_t			*mlx;
	list_t			**grid;
	int				width;
	int				height;
	int				coins;
}					map_t;

typedef struct game_s
{
	assets_t		*assets;
	animations_t	*animations;
	player_t		*player;
	map_t			*map;
	int				score;
	int				moves;
	const char		*title;
}					game_t;

#endif