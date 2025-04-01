/*
Purpose:
Implements the rules and mechanics of the game.
Enforces set operations (adding/removing positions from sets).
Ensures valid moves based on the system specifications.
*/
#include "game_logic.h"

#include <stdio.h>

#include "data_structures.h"

/**
 * @brief Checks if a grid position is empty.
 *
 * This function takes a grid and a row and column index as input, and returns
 * 1 if the position is empty (i.e., its value is 0), and 0 otherwise.
 *
 * @param grid The game grid, represented as a 2D array of integers.
 * @param row The row index of the position to check.
 * @param col The column index of the position to check.
 * @return 1 if the position is empty, 0 otherwise.
 */
int
is_empty(int grid[GRID_SIZE][GRID_SIZE], int row, int col)
{
    // Check if the position's value is 0 (i.e., it's empty)
    int isPositionEmpty = (grid[row][col] == 0);
    return isPositionEmpty;
}

/**
 * @brief Checks if the grid is full.
 *
 * This function iterates over all positions in the grid, and returns 1 if all
 * positions are non-empty (i.e., their values are non-zero), and 0 otherwise.
 *
 * @param grid The game grid, represented as a 2D array of integers.
 * @return 1 if the grid is full, 0 otherwise.
 */
int
is_board_full(int grid[GRID_SIZE][GRID_SIZE])
{
    int full = 1;  // Assume the grid is full initially
    // Iterate over all positions in the grid
    for (int i = 0; i < GRID_SIZE; i++)
    {
        for (int j = 0; j < GRID_SIZE; j++)
        {
            // If we find an empty position, the grid is not full
            if (grid[i][j] == 0)
            {
                full = 0;
            }
        }
    }
    return full;
}

/**
 * @brief Checks if a move is within the grid boundaries.
 *
 * This function takes a row and column index as input, and returns 1 if the
 * position is within the grid boundaries (i.e., its indices are non-negative
 * and less than GRID_SIZE), and 0 otherwise.
 *
 * @param row The row index of the position to check.
 * @param col The column index of the position to check.
 * @return 1 if the move is valid, 0 otherwise.
 */
int
is_valid_move(int row, int col)
{
    // Check if the row and column indices are within the grid boundaries
    int valid = (row >= 0 && row < GRID_SIZE && col >= 0 && col < GRID_SIZE);
    return valid;
}