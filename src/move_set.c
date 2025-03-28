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

int
make_move(int grid[GRID_SIZE][GRID_SIZE], int *turn, int *go,
          int uno[GRID_SIZE][GRID_SIZE], int dos[GRID_SIZE][GRID_SIZE],
          int tres[GRID_SIZE][GRID_SIZE])
{
    int row, col;
    int validMove = 0;

    while (!validMove)
    {
        printf("\nPlayer %d, enter row and column (1-4) separated by space: ",
               (*turn == 0) ? 2 : ((*go) ? 1 : 3));
        if (scanf("%d %d", &row, &col) != 2)
        {
            printf("Invalid input! Please enter two numbers.");
            while (getchar() != '\n');
            continue;
        }
        row--;
        col--;

        if (!is_valid_move(row, col))
        {
            printf("Invalid move! Position is out of bounds. Try again.\n");
        }
        else if (*turn == 0)
        {
            if (uno[row][col] == 1 || tres[row][col] == 1)
            {
                uno[row][col]  = 0;
                tres[row][col] = 0;
                grid[row][col] = 0;
                *turn          = !(*turn);
                validMove      = 1;
            }
            else
            {
                printf(
                    "Invalid move! Position is not marked by Uno or Tres. Try "
                    "again.\n");
            }
        }
        else
        {
            if (!is_empty(grid, row, col))
            {
                printf("Invalid move! Position already occupied. Try again.\n");
            }
            else
            {
                if (*go)
                {
                    uno[row][col]  = 1;
                    grid[row][col] = 1;
                    *turn          = !(*turn);
                    *go            = !(*go);
                }
                else
                {
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
