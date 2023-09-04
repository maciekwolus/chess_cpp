#include <iostream>
#include "bishop.h"

// Constructor
Bishop::Bishop(Color c) : Piece(BISHOP, c) {}

// It can goes like from corner to corner idk how to descibe that
bool Bishop::isValidMove(const Board *board, const std::pair<int, int> &fromCoords, const std::pair<int, int> &toCoords) const
{
    if (board->isDiagonalMove(fromCoords, toCoords))
        {
            if (board->isPathClear(fromCoords, toCoords))
            {
                return true;
            }
        }

    // Not a valid if the condition are not made
    return false;

}

