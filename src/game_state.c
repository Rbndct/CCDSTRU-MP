/*
Purpose:
Manages game initialization and state tracking.
Stores the current game state (sets and boolean flags).
Determines if the game has ended.
*/

#include "game_state.h"

#include <stdio.h>

#include "data_structures.h"
#include "display.c"
#include "move_set.c"
int
check_winner(int grid[GRID_SIZE][GRID_SIZE])
{
    int uno_wins = 0, tres_wins = 0;
    int full   = is_board_full(grid);
    int result = 0;

    int win_conditions[4][4][2] = {{{0, 0}, {0, 1}, {0, 2}, {0, 3}},
                                   {{0, 0}, {1, 1}, {2, 2}, {3, 3}},
                                   {{0, 3}, {1, 2}, {2, 1}, {3, 0}},
                                   {{3, 0}, {3, 1}, {3, 2}, {3, 3}}};

    for (int w = 0; w < 4; w++)
    {
        int uno_count = 0, tres_count = 0;
        for (int i = 0; i < 4; i++)
        {
            int r = win_conditions[w][i][0];
            int c = win_conditions[w][i][1];
            if (grid[r][c] == 1) uno_count++;
            if (grid[r][c] == 2) tres_count++;
        }
        if (uno_count == 4) uno_wins = 1;
        if (tres_count == 4) tres_wins = 1;
    }

    if (uno_wins)
        result = 1;
    else if (tres_wins)
        result = 3;
    else if (full)
        result = 2;

    return result;
}

void
run_game(int grid[GRID_SIZE][GRID_SIZE], int uno[GRID_SIZE][GRID_SIZE],
         int dos[GRID_SIZE][GRID_SIZE], int tres[GRID_SIZE][GRID_SIZE],
         int *turn, int *go, int *over)
{
    display_board(grid);  // Display initial board

    while (!*over)
    {
        int player_number;

        if (*go)
        {
            player_number = 1;
        }
        else
        {
            if (*turn)
            {
                player_number = 3;
            }
            else
            {
                player_number = 2;
            }
        }

        printf("Player %d's turn.\n", player_number);

        if (make_move(grid, turn, go, uno, dos, tres))
        {
            display_board(grid);  // Refresh board after a successful move

            // **Check if a player has won or board is full**
            int winner = check_winner(grid);
            if (winner > 0)
            {
                if (winner == 1)
                {
                    printf("Player 1 (Uno) wins!\n");
                }
                else if (winner == 2)
                {
                    printf("Player 2 (Tres) wins!\n");
                }
                else if (winner == 3)  // Board Full
                {
                    printf("Game Over! The board is full, no winner.\n");
                }
                else if (winner == 4)  // Dos Wins
                {
                    printf("Player 3 (Dos) wins!\n");
                }
                *over = 1;  // Set game over flag
            }
        }
    }
}
