// Author: Raphael Maagma
// Date: '24
#include <stdio.h>

#include "data_structures.h"
#include "game_state.c"

int
main()
{
    // Initialize game state variables
    int turn = 1;  // Player 1 starts (1 = Uno, 0 = Tres)
    int go   = 0;  // Controls player action rules
    int over = 0;  // Flag to keep the game running

    // Initialize game boards
    int grid[GRID_SIZE][GRID_SIZE] = {0};  // Game board
    int uno[GRID_SIZE][GRID_SIZE]  = {0};  // Player 1's marked positions
    int dos[GRID_SIZE][GRID_SIZE]  = {0};  // Player 2's marked positions
    int tres[GRID_SIZE][GRID_SIZE] = {0};  // Player 3's marked positions

    // Start the game loop
    run_game(grid, uno, dos, tres, &turn, &go, &over);

    return 0;
}