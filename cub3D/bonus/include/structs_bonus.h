/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 16:23:40 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/07/08 17:53:04 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_BONUS_H
# define STRUCTS_BONUS_H

# include "dependencies_bonus.h"

# define GAME_TITLE "LAZARETTO"

# define FOV 70

# define SCREEN_WIDTH_DEFAULT 1920
# define SCREEN_HEIGHT_DEFAULT 1080

# define TILE_SIZE 640
# define TEXTURE_SIZE 64

# define MINIMAP_TILE_SIZE 32
# define PLAYER_SIZE 16

# define MINIMAP_WIDTH 230
# define MINIMAP_HEIGHT 230

# define SCALE 0.02
# define MINIMAP_PADDING 20

typedef struct s_vec2d
{
	double			x;
	double			y;
}					t_vec2d;

typedef struct s_waah
{
	int				row;
	int				len;
	char			*line;
	int				col;
	int				k;
}					t_waah;

typedef struct s_vec2i
{
	int				x;
	int				y;
}					t_vec2i;

typedef struct s_norm
{
	int				i;
	int				flag;
	int				j;
	int				k;
	int				size;
	int				flags[6];
}					t_norm;

typedef struct s_help
{
	int				save;
	int				len;
	int				gg;
	int				to_malc;
}					t_help;

typedef struct s_map
{
	char			**map;
	int				x_player;
	int				y_player;
	int				width;
	int				height;
	char			player_dir;
	char			*north_texture_path;
	char			*south_texture_path;
	char			*east_texture_path;
	char			*west_texture_path;
	uint32_t		floor_color[3];
	uint32_t		ceiling_color[3];
}					t_map;

typedef struct s_minimap
{
	t_vec2i			offset;
	t_vec2i			center;
	int				visible_range;
	int				show_rays;
}					t_minimap;

typedef struct s_utils
{
	char			**no;
	char			**so;
	char			**we;
	char			**ea;
	char			**f;
	char			**c;
}					t_utils;

typedef struct s_player
{
	t_vec2i			pos;
	int				forward_backward;
	int				left_right;
	t_vec2d			forward;
	t_vec2d			strafe;
	t_vec2d			reminder;
	double			angle;
	double			move_speed;
	double			rot_speed;
}					t_player;

typedef struct s_ray
{
	double			angle;
	t_vec2d			dir;
	t_vec2d			hit_point;
	double			distance;
	t_vec2d			map_pixel_pos;
	t_vec2i			map_grid_pos;
	t_vec2d			delta_dist;
	t_vec2d			side_dist;
	t_vec2i			steps;
	int				side_hit;
	char			collision_type;
	double			wall_x;
}					t_ray;

// N = 0; S = 1; W = 2; E = 3
typedef struct s_wall_hit
{
	double			distance;
	t_vec2d			hit_point;
	int				side;
	char			type;
	double			texture_x_coord;
	int				texture_id;
}					t_wall_hit;

typedef struct s_wall_render
{
	int				start_y;
	int				end_y;
	double			line_h;
	int				tex_x;
	double			step;
	double			tex_pos;
}					t_wall_render;

typedef struct s_pixel
{
	uint8_t			r;
	uint8_t			g;
	uint8_t			b;
	uint8_t			a;
}					t_pixel;

typedef struct s_texture
{
	size_t			width;
	size_t			height;
	uint32_t		**arr;
}					t_texture;

typedef struct s_init_textures
{
	mlx_texture_t	*north;
	mlx_texture_t	*south;
	mlx_texture_t	*west;
	mlx_texture_t	*east;
	mlx_texture_t	*door;
}					t_init_textures;

typedef struct s_main_menu
{
	mlx_texture_t	*frames[5];
	mlx_image_t		*img;
}					t_main_menu;

typedef struct s_game
{
	mlx_t			*mlx;
	mlx_image_t		*img_scene;
	mlx_image_t		*img_stats;
	mlx_image_t		*img_minimap;
	mlx_image_t		*img_borders;
	t_map			*map_data;
	t_minimap		*minimap_data;
	t_player		*player_data;
	t_ray			*rays;
	t_wall_hit		*walls;
	t_main_menu		*frames;
	int				screen_width;
	int				screen_height;
	double			fov_rad;
	t_texture		walls_textures[5];
	bool			e_key_was_up;
	bool			start_game;
}					t_game;

#endif