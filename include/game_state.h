#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "data_structures.h"

int
check_winner(int grid[GRID_SIZE][GRID_SIZE]);

void
run_game(int grid[GRID_SIZE][GRID_SIZE], int uno[GRID_SIZE][GRID_SIZE],
         int dos[GRID_SIZE][GRID_SIZE], int tres[GRID_SIZE][GRID_SIZE],
         int *turn, int *go, int *over);

#endif  // GAME_STATE_H
