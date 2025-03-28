/*
Purpose:
Implements the rules and mechanics of the game.
Enforces set operations (adding/removing positions from sets).
Ensures valid moves based on the system specifications.
*/
#include "game_logic.h"

#include <stdio.h>

#include "data_structures.h"

// Function to check if the grid position is empty
int
is_empty(int grid[GRID_SIZE][GRID_SIZE], int row, int col)
{
    int isPositionEmpty = (grid[row][col] == 0);
    return isPositionEmpty;
}

// Function to check if the grid position is full
int
is_board_full(int grid[GRID_SIZE][GRID_SIZE])
{
    int full = 1;
    for (int i = 0; i < GRID_SIZE; i++)
    {
        for (int j = 0; j < GRID_SIZE; j++)
        {
            if (grid[i][j] == 0)
            {
                full = 0;
            }
        }
    }
    return full;
}

// Function to validate if a move is within the grid boundaries
int
is_valid_move(int row, int col)
{
    int valid = (row >= 0 && row < GRID_SIZE && col >= 0 && col < GRID_SIZE);
    return valid;
}
