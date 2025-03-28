#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H
/*
Purpose:
Defines structs for Position and MoveSet.
Declares global variables for Uno, Dos, Tres, F, turn, go, over.
*/

#include <stdbool.h>

// Define grid size based on A = {x ∈ ℤ+ | x < 5} (i.e., 4x4)
#define GRID_SIZE 4
#define MAX_MOVES (GRID_SIZE * GRID_SIZE)

// Represents a position on the grid
typedef struct
{
    int x;  // Row index (1-based)
    int y;  // Column index (1-based)
} Position;

// Stores a set of moves (used for Uno, Dos, Tres, and F)
typedef struct
{
    Position moves[MAX_MOVES];  // Array of positions
    int      count;             // Number of elements in the set
} MoveSet;

// Predefined winning conditions (W)
typedef struct
{
    Position winMoves[GRID_SIZE];  // A winning set consists of GRID_SIZE moves
} WinningCondition;

#endif  // DATA_STRUCTURES_H
