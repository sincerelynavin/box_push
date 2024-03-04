# Box Pushing Game

This is a simple C game where the player navigates through a map to push a box onto a goal tile.

## Prerequisites

- You need to have a C compiler installed on your system to compile and run this game.

## Getting Started

1. **Clone the repository:**

   ```bash
   git clone https://github.com/your-username/box-pushing-game.git
   ```

2. **Navigate to the project directory:**

   ```bash
   cd box-pushing-game
   ```

3. **Compile the source code:**

   ```bash
   gcc -o game main.c base.c box.c controls.c tutorial.c maparray.c
   ```

4. **Run the game with appropriate command line arguments:**

   ```bash
   ./game [row] [col] [player_row] [player_col] [goal_row] [goal_col]
   ```

   Replace `[row]`, `[col]`, `[player_row]`, `[player_col]`, `[goal_row]`, and `[goal_col]` with integer values representing the dimensions of the map, initial player position, and goal position respectively.

## Usage

- Use the arrow keys to move the player character.
- Push the box onto the goal tile to win the game.

