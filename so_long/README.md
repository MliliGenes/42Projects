# So_long Game Pseudocode Reference

## 1. Main Controller Function
```c
function init_game_controller(game_t *game, const char *map_path):
    1. Memory Allocation & Basic Init
        - Allocate all main structures (game components)
        - Check for allocation failures
        - Initialize basic variables (score = 0, moves = 0, etc.)

    2. MLX Initialization
        - Initialize MLX window
        - Set up window properties
        - Check for MLX init failure

    3. Map Loading & Validation
        - Call init_map(game->map, map_path)
        - Validate map structure
        - Find player starting position
        - Count collectibles
        - If any step fails, cleanup and return false

    4. Asset Loading
        - Call load_assets(game->assets)
        - If failed, cleanup and return false

    5. Animation Setup
        - Call init_animations(game->animations, game->assets->player_sprite_sheet)
        - Set initial animation states
        - If failed, cleanup and return false

    6. Player Setup
        - Initialize player position from map
        - Set initial state to IDLE
        - Set up pixel position based on grid position

    7. Game Hooks Setup
        - Set up key hook for player input
        - Set up loop hook for animation updates
        - Set up close window hook

    8. Error Handling
        - If any step fails:
            - Call cleanup functions
            - Return false
        - If all successful, return true
```

## 2. Asset Management
```c
function load_assets(assets_t *assets):
    1. Load wall texture using mlx_load_png("path/to/wall.png")
    2. Load floor texture
    3. Load collectible texture
    4. Load exit texture
    5. Load player sprite sheet
    6. Check if any load failed
    7. Return success/failure

function init_animations(animations_t *anim, mlx_texture_t *sprite_sheet):
    1. Calculate frame dimensions from sprite sheet
    2. For each animation type (idle, walk_right, etc.):
        - Extract 4 frames from sprite sheet
        - Convert to mlx_image using mlx_texture_to_image
    3. Set initial frame_duration and current_frame
    4. Return success/failure
```

## 3. Player Management
```c
function update_player_state(play_t *player, map_t *map, int key):
    1. Check if movement key pressed
    2. Calculate new grid position based on direction
    3. Verify movement is valid (check map boundaries and walls)
    4. Update player state (MOVING_RIGHT, IDLE, etc.)
    5. Update grid_pos if movement valid
    6. Calculate new pixel_pos based on grid_pos

function update_animation(animations_t *anim, play_t *player):
    1. Based on player state, select correct animation array
    2. Update current_frame counter
    3. If frame_duration reached:
        - Move to next frame
        - Reset duration counter
    4. Hide all animation frames except current
```

## 4. Map Management
```c
function init_map(map_t *map, const char *file_path):
    1. Open and read .ber file
    2. Allocate grid based on file dimensions
    3. Parse file into grid structure
    4. Count coins
    5. Validate map (walls, player, exit, etc.)
    6. Return success/failure

function check_movement(map_t *map, position_t new_pos, game_t *game):
    1. Check if position is within bounds
    2. Check if position is a wall
    3. If collectible:
        - Increment score
        - Decrease coins count
    4. If exit and all coins collected:
        - Trigger win condition
    5. Return if movement is valid
```

## 5. Game State Management
```c
function init_game(game_t *game, const char *map_path):
    1. Allocate all struct components
    2. Initialize MLX
    3. Load assets
    4. Initialize animations
    5. Load map
    6. Set initial player position and state
    7. Initialize score and moves
    8. Return success/failure

function game_update(void *param):
    1. Cast param to game_t*
    2. Update player animations
    3. Handle any continuous movement
    4. Update UI elements (score, moves)
    5. Check win/lose conditions

function cleanup_game(game_t *game):
    1. Free all textures in assets
    2. Free all images in animations
    3. Free map grid
    4. Free all struct components
    5. Terminate MLX
```

## 6. UI and Rendering
```c
function render_ui(game_t *game):
    1. Create score text
    2. Create moves text
    3. Convert to images
    4. Position on screen

function update_title(game_t *game):
    1. Format title string with moves count
    2. Update window title using mlx_set_window_title
```

## 7. Input Handling
```c
function handle_input(mlx_key_data_t keydata, void* param):
    1. Cast param to game_t*
    2. If key is pressed:
        - Check which movement key (W,A,S,D)
        - Calculate new position based on direction
        - Validate movement
        - Update player state and position if valid
        - Increment move counter
    3. If ESC pressed:
        - Trigger game cleanup and exit
```

## 8. Error Handling
```c
function handle_error(const char *message):
    1. Print error message
    2. Clean up any allocated resources
    3. Exit with appropriate error code

function cleanup_and_return(game_t *game, bool return_value):
    1. Check which components were initialized
    2. Clean up in reverse order of initialization
    3. Free all allocated memory
    4. Return the provided return_value
```

## 9. Main Function
```c
function main(int argc, char **argv):
    1. Validate input arguments (must be 2)
    2. Allocate and initialize game structure
    3. Call init_game_controller
    4. If initialization successful:
        - Start game loop
    5. Clean up resources
    6. Return success/failure status
