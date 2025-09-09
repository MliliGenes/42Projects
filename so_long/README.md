# so_long

`so_long` is a 2D game project from 42 school. The goal is to create a simple game where the player has to collect all collectibles on the map and then reach the exit. The project is built using the C programming language and the MiniLibX graphics library.

## Game Elements

The game consists of the following elements:

- **Player:** The character controlled by the user.
- **Walls:** Impassable obstacles.
- **Collectibles:** Items that the player must collect.
- **Exit:** The goal that can only be reached after collecting all collectibles.
- **Enemies:** (Bonus) Obstacles that can kill the player.

## Map Files

The game reads the map layout from a file with the `.ber` extension. The map must be rectangular and enclosed by walls. It must also contain at least one player, one exit, and one collectible.

### Example Map

```
11111111
1P0C0E01
10010001
11111111
```

- `1`: Wall
- `0`: Empty space
- `P`: Player
- `C`: Collectible
- `E`: Exit

## How to Play

1. **Compile the project:** Run `make` to compile the project.
2. **Run the game:** Execute the `so_long` binary with a map file as an argument (e.g., `./so_long maps/map.ber`).
3. **Controls:**
   - **W, A, S, D:** Move the player up, left, down, and right.
   - **ESC:** Exit the game.

## Bonus Features

The bonus part of this project includes:

- **Animated Sprites:** The player and collectibles are animated.
- **Enemies:** The map can contain enemies that will kill the player on contact.
- **Move Counter:** The number of moves is displayed on the screen.
