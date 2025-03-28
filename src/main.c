// Author: Raphael Maagma
// Date: '24
#include <stdio.h>

#include "data_structures.h"
#include "game_state.c"

int
main()
{
    int turn = 1;  // Player 1 starts (1 = Uno, 0 = Tres)
    int go   = 0;  // Controls player action rules
    int over = 0;  // Flag to keep the game running

    int grid[GRID_SIZE][GRID_SIZE] = {0};  // Game board
    int uno[GRID_SIZE][GRID_SIZE]  = {0};  // Player 1's marked positions
    int dos[GRID_SIZE][GRID_SIZE]  = {0};  // Player 2's marked positions
    int tres[GRID_SIZE][GRID_SIZE] = {0};  // Player 3's marked positions

    run_game(grid, uno, dos, tres, &turn, &go, &over);  // Start the game

    return 0;
}