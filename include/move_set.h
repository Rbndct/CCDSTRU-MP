#ifndef MOVE_SET_H
#define MOVE_SET_H

#include "data_structures.h"

int
make_move(int grid[GRID_SIZE][GRID_SIZE], int *turn, int *go,
          int uno[GRID_SIZE][GRID_SIZE], int dos[GRID_SIZE][GRID_SIZE],
          int tres[GRID_SIZE][GRID_SIZE]);

#endif  // MOVE_SET_H
