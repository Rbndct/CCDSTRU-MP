/*
Purpose:
Handles set operations for Uno, Dos, Tres, F.
Checks if a position exists in a set.
Adds or removes positions from sets efficiently.
*/

#include "move_set.h"

#include <stdio.h>

#include "data_structures.h"
#include "game_logic.c"

/**
 * @brief Makes a move on the game board.
 *
 * This function handles player input, checks for valid moves, and updates the
 * game state accordingly.
 *
 * @param grid The game board, represented as a 2D array of integers.
 * @param turn A pointer to the current turn flag.
 * @param go A pointer to the current go flag.
 * @param uno The Uno player's marked positions, represented as a 2D array of
 * integers.
 * @param dos The Dos player's marked positions, represented as a 2D array of
 * integers.
 * @param tres The Tres player's marked positions, represented as a 2D array of
 * integers.
 * @return 1 if the move is valid, 0 otherwise.
 */
int
make_move(int grid[GRID_SIZE][GRID_SIZE], int *turn, int *go,
          int uno[GRID_SIZE][GRID_SIZE], int dos[GRID_SIZE][GRID_SIZE],
          int tres[GRID_SIZE][GRID_SIZE])
{
    int row, col;       // Initialize row and column variables
    int validMove = 0;  // Initialize valid move flag

    // Loop until a valid move is made
    while (!validMove)
    {
        // Prompt the player for input
        printf("\nPlayer %d, enter row and column (1-4) separated by space: ",
               (*turn == 0) ? 2 : ((*go) ? 1 : 3));

        // Read player input
        if (scanf("%d %d", &row, &col) != 2)
        {
            // Handle invalid input
            printf("Invalid input! Please enter two numbers.");
            while (getchar() != '\n');
            continue;
        }

        // Adjust row and column indices for 0-based indexing
        row--;
        col--;

        // Check if the move is valid
        if (!is_valid_move(row, col))
        {
            // Handle out-of-bounds move
            printf("Invalid move! Position is out of bounds. Try again.\n");
        }
        else if (*turn == 0)
        {
            // Handle Dos's turn
            if (uno[row][col] == 1 || tres[row][col] == 1)
            {
                // Remove mark from Uno or Tres
                uno[row][col]  = 0;
                tres[row][col] = 0;
                grid[row][col] = 0;
                *turn          = !(*turn);
                validMove      = 1;
            }
            else
            {
                // Handle invalid move
                printf(
                    "Invalid move! Position is not marked by Uno or Tres. Try "
                    "again.\n");
            }
        }
        else
        {
            // Handle Uno or Tres's turn
            if (!is_empty(grid, row, col))
            {
                // Handle occupied position
                printf("Invalid move! Position already occupied. Try again.\n");
            }
            else
            {
                // Make the move
                if (*go)
                {
                    // Uno's turn
                    uno[row][col]  = 1;
                    grid[row][col] = 1;
                    *turn          = !(*turn);
                    *go            = !(*go);
                }
                else
                {
                    // Tres's turn
                    tres[row][col] = 1;
                    grid[row][col] = 2;
                    *go            = !(*go);
                }
                validMove = 1;
            }
        }
    }
    return validMove;
}