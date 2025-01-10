#include "includes/mlx42.h"
#include <stdlib.h>

typedef struct assets_s {
   mlx_texture_t *wall;
   mlx_texture_t *floor;
   mlx_texture_t *collectible;
   mlx_texture_t *exit;
   mlx_texture_t *player_sprite_sheet;
} assets_t;

typedef struct animations_s {
   mlx_image_t *idle[4];
   mlx_image_t *walk_right[4]; 
   mlx_image_t *walk_left[4];
   mlx_image_t *walk_up[4];
   mlx_image_t *walk_down[4];
   mlx_image_t *death[4];
   int current_frame;
   int frame_duration;
} animations_t;

typedef struct position_s
{
    int x;
    int y;
} position_t;

typedef enum state_s
{
    IDLE = 0,
    MOVING_RIGHT = 1,
    MOVING_LEFT = 2,
    MOVING_UP = 3,
    MOVING_DOWN = 4,
    DEAD = 5,
} state_t;

typedef struct play_s 
{
    state_t state;
    position_t grid_pos;  // Grid position
    position_t pixel_pos; // Actual render position
} play_t;

typedef struct map_s {
    mlx_t *mlx;
    char **grid;
    int width;
    int height;
    mlx_image_t *wall_texture;
    mlx_image_t *floor_texture;
    mlx_image_t *collectible_texture;
} map_t;

typedef struct game_s {
    assets_t *assets;           
    animations_t *animations;  
    play_t *player;             
    map_t *map;                 
    int score;                 
    int lives;                
    int moves;                
    const char *title;         
} game_t;


int main()
{

}