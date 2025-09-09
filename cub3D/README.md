# Cub3D

Cub3D is a 3D game engine that uses raycasting to create a realistic 3D environment. The project is inspired by the classic game Wolfenstein 3D and is built using the C programming language and the MiniLibX graphics library.

## Features

- **Raycasting Engine:** The core of the project is a raycasting engine that renders a 2D map into a 3D perspective.
- **Map Parsing:** The game can parse `.cub` files that describe the map layout, textures, and colors.
- **Player Movement:** The player can move around the map and rotate their view.
- **Collision Detection:** The engine handles collisions with walls.
- **Textures:** The walls are textured to create a more immersive environment.
- **Minimap:** A minimap is displayed on the screen to help the player navigate the map.
- **Bonus Features:** The project includes bonus features such as a skybox, floor and ceiling textures, and animated sprites.

## How to Play

1. **Compile the project:** Run `make` to compile the project.
2. **Run the game:** Execute the `cub3D` binary with a map file as an argument (e.g., `./cub3D maps/map.cub`).
3. **Controls:**
   - **W, A, S, D:** Move the player forward, left, backward, and right.
   - **Arrow Keys:** Rotate the player's view.
   - **ESC:** Exit the game.

## Project Structure

The project is divided into two main parts:

- **`mandatory`:** This part contains the core functionality of the game engine.
- **`bonus`:** This part includes additional features that are not required for the main project.

The code is organized into several modules, including:

- **`parsing`:** Handles the parsing of the `.cub` map files.
- **`raycaster`:** Implements the raycasting algorithm.
- **`player`:** Manages the player's movement and state.
- **`game`:** Contains the main game loop and event handling.
- **`init`:** Initializes the game state and graphics.
- **`lib`:** Includes utility functions.
- **`include`:** Contains the header files for the project.
