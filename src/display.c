/*
Purpose:
Handles printing the game board and messages.
Displays which player’s turn it is.
Shows the final result (who wins or if it’s a draw).
*/

#include "display.h"

#include <stdio.h>

#include "data_structures.h"

// Function to display the board layout with a larger evenly spaced grid design
void
display_board(int grid[GRID_SIZE][GRID_SIZE])
{
    printf("\n          1       2       3       4  \n");
    printf("      +-------+-------+-------+-------+\n");

    for (int row = 0; row < GRID_SIZE; row++)
    {
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

            for (int col = 0; col < GRID_SIZE; col++)
            {
                char symbol = ' ';

                if (grid[row][col] == 1)
                    symbol = 'X';
                else if (grid[row][col] == 2)
                    symbol = 'O';

                if (i == 1)
                    printf("   %c   |", symbol);
                else
                    printf("       |");
            }
            printf("\n");
        }
        printf("      +-------+-------+-------+-------+\n");
    }
    printf("\n");
}