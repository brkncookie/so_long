# so_long

The so_long project introduces learners to the minilibx library provided by the 42 Network. The goal is to develop a basic 2D game where the player's objective is to collect every collectible present on the map and then escape by choosing the shortest possible route.

## Description

### Game Features:
- The player's goal is to collect every collectible present on the map and then escape by choosing the shortest possible route.
- The W, A, S, and D keys are used to move the main character.
- The player can move in four directions: up, down, left, and right.
- The player cannot move into walls.
- The current number of movements is displayed in the shell after every move.
- The game uses a 2D view (top-down or profile).
- The game does not have to be real-time.
- The theme of the game can be customized (e.g., dolphin theme or any other theme).

### Map Components:
- The map is constructed with three components: walls, collectibles, and free space.
- The map consists of five characters:
  - '0' for an empty space
  - '1' for a wall
  - 'C' for a collectible
  - 'E' for a map exit
  - 'P' for the player's starting position
