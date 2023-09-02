#include <iostream>
#include "bishop.h"

// Constructor
Bishop::Bishop(Color c) : Piece(BISHOP, c) {}

// Determine if this is a valid move based on the rules of the Bishop.
bool Bishop::isValidMove(const Board *board, const std::pair<int, int> &fromCoords, const std::pair<int, int> &toCoords) const
{

    // If we've gotten this far, not a valid move
    return false;

}

