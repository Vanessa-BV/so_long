# Codam Rank 02

# So_Long

## Overview
So_Long is a 2D game written in C using the MiniLibX graphical library. The player's objective is to collect all collectibles on the map and then escape via the shortest possible route. This project aims to improve skills in window management, event handling, colors, textures, and basic algorithms.

### Features
- Player Movement: Controlled using the W, A, S, and D keys.
- Directional Movement: Move up, down, left, or right.
- Collision Detection: The player cannot move through walls.
- Move Counter: Displays the number of movements in the shell.
- 2D View: Top-down or profile view.
- Window Management: Smooth handling of window changes, minimization, etc.
- Exit Handling: Close the window and quit the program by pressing ESC or clicking the window frame cross.

### Map Configuration
The game map is constructed from three components: walls, collectibles, and free space. The map must adhere to the following rules:

### Characters:
- 0 for an empty space.
- 1 for a wall.
- C for a collectible.
- E for a map exit.
- P for the player's starting position.

### Structure:
- The map must be rectangular.
- The map must be surrounded by walls.
- The map must contain exactly one exit, at least one collectible, and one starting position.

### Error Handling
The program will return an error and exit cleanly if:
- The map is not surrounded by walls.
- There is no valid path in the map.
- The map does not meet the required character composition.
- The map file is misconfigured.
- Errors will be indicated by displaying Error\n followed by a specific error message.


## Usage
To compile and run the game:

`make`

Run the executable with a valid map file:

`./so_long maps/choose_map` 

Example:

`./so_long maps/map_1.ber`
