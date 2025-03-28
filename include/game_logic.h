#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

#include "data_structures.h"

int
is_empty(int grid[GRID_SIZE][GRID_SIZE], int row, int col);

int
is_board_full(int grid[GRID_SIZE][GRID_SIZE]);

int
is_valid_move(int row, int col);

#endif  // GAME_LOGIC_H
