/*
Purpose:
Handles printing the game board and messages.
Displays which player’s turn it is.
Shows the final result (who wins or if it’s a draw).
*/

#include "display.h"

#include <stdio.h>

#include "data_structures.h"

/**
 * @brief Displays the game board layout with a larger evenly spaced grid
 * design.
 *
 * This function prints the game board to the console, showing the current state
 * of the game. It includes a header row with column numbers, and each cell is
 * represented by a symbol (X for Uno, O for Tres, or a space for an empty
 * cell).
 *
 * @param grid The game board, represented as a 2D array of integers.
 */
void
display_board(int grid[GRID_SIZE][GRID_SIZE])
{
    // Print a legend explaining the symbols used on the board
    printf("%10s%25s%10s\n", "", "Marks: X (Uno), O (Tres)", "");
    // Print the column header row with numbers 1-4
    printf("\n          1       2       3       4  \n");
    printf("      +-------+-------+-------+-------+\n");

    // Iterate over each row of the grid
    for (int row = 0; row < GRID_SIZE; row++)
    {
        // Print the row header with the row number
        for (int i = 0; i < 3; i++)
        {
            if (i == 1)
            {
                printf("    %d |", row + 1);
            }
            else
            {
                printf("      |");
            }

            // Iterate over each column of the grid
            for (int col = 0; col < GRID_SIZE; col++)
            {
                char symbol = ' ';  // Initialize the symbol to a space (for
                                    // empty cells)

                // Determine the symbol to use based on the cell's value
                if (grid[row][col] == 1)
                    symbol = 'X';  // X represents Uno
                else if (grid[row][col] == 2)
                    symbol = 'O';  // O represents Tres

                // Print the symbol for this cell
                if (i == 1)
                    printf("   %c   |", symbol);
                else
                    printf("       |");
            }
            printf("\n");
        }
        // Print the row footer with the grid lines
        printf("      +-------+-------+-------+-------+\n");
    }
    printf("\n");
}