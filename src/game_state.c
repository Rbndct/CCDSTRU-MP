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

/**
 * @brief Checks if a player has won the game.
 *
 * This function checks all possible winning conditions (rows, columns, and
 * diagonals) and returns the number of the winning player (1 for Uno, 3 for
 * Tres), or 2 if the board is full and no player has won.
 *
 * @param grid The game grid, represented as a 2D array of integers.
 * @return The number of the winning player, or 2 if the board is full.
 */
int
check_winner(int grid[GRID_SIZE][GRID_SIZE])
{
    int uno_wins = 0, tres_wins = 0;   // Initialize win flags
    int full   = is_board_full(grid);  // Check if the board is full
    int result = 0;                    // Initialize result variable

    // Define all possible winning conditions (rows, columns, and diagonals)
    int win_conditions[4][4][2] = {{{0, 0}, {0, 1}, {0, 2}, {0, 3}},
                                   {{0, 0}, {1, 1}, {2, 2}, {3, 3}},
                                   {{0, 3}, {1, 2}, {2, 1}, {3, 0}},
                                   {{3, 0}, {3, 1}, {3, 2}, {3, 3}}};

    // Iterate over all winning conditions
    for (int w = 0; w < 4; w++)
    {
        int uno_count = 0, tres_count = 0;  // Initialize count variables
        // Iterate over all positions in the current winning condition
        for (int i = 0; i < 4; i++)
        {
            int r = win_conditions[w][i][0];  // Get row index
            int c = win_conditions[w][i][1];  // Get column index
            // Check if the current position belongs to Uno or Tres
            if (grid[r][c] == 1) uno_count++;
            if (grid[r][c] == 2) tres_count++;
        }
        // Check if Uno or Tres has won
        if (uno_count == 4) uno_wins = 1;
        if (tres_count == 4) tres_wins = 1;
    }

    // Determine the result based on the win flags and board full flag
    if (uno_wins)
        result = 1;
    else if (tres_wins)
        result = 3;
    else if (full)
        result = 2;

    return result;
}

/**
 * @brief Runs the game loop.
 *
 * This function displays the initial board, then enters a loop where each
 * player makes a move, and the board is updated and displayed after each move.
 * The game continues until a player has won or the board is full.
 *
 * @param grid The game grid, represented as a 2D array of integers.
 * @param uno The Uno player's grid, represented as a 2D array of integers.
 * @param dos The Dos player's grid, represented as a 2D array of integers.
 * @param tres The Tres player's grid, represented as a 2D array of integers.
 * @param turn A pointer to the current turn flag.
 * @param go A pointer to the current go flag.
 * @param over A pointer to the game over flag.
 */
void
run_game(int grid[GRID_SIZE][GRID_SIZE], int uno[GRID_SIZE][GRID_SIZE],
         int dos[GRID_SIZE][GRID_SIZE], int tres[GRID_SIZE][GRID_SIZE],
         int *turn, int *go, int *over)
{
    // Display the initial board
    display_board(grid);

    // Game loop
    while (!*over)
    {
        int player_number;  // Initialize player number variable

        // Determine the current player based on the go and turn flags
        if (*go)
        {
            // If go is true, it's Uno's turn
            player_number = 1;
        }
        else
        {
            // If go is false, check the turn flag
            if (*turn)
            {
                // If turn is true, it's Tres's turn
                player_number = 3;
            }
            else
            {
                // If turn is false, it's Dos's turn
                player_number = 2;
            }
        }

        // Display the current player's turn message
        printf("Player %d's turn.\n", player_number);

        // Make a move
        if (make_move(grid, turn, go, uno, dos, tres))
        {
            // Refresh the board after a successful move
            display_board(grid);

            // Check if a player has won or the board is full
            int winner = check_winner(grid);
            if (winner > 0)
            {
                // Display the winner message
                if (winner == 1)
                {
                    printf("Player 1 (Uno) wins!\n");
                }
                else if (winner == 2)
                {
                    printf("Game Over! The board is full, (Dos) wins!.\n");
                }
                else if (winner == 3)  // Board Full
                {
                    printf("Player 3 (Tres) wins!\n");
                }
                // Set the game over flag
                *over = 1;
            }
        }
    }
}