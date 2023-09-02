#include <iostream>
#include "queen.h"

// Constructor
Queen::Queen(Color c) : Piece(QUEEN, c) {}

// Determine if this is a valid move based on the rules of the Queen.
bool Queen::isValidMove(const Board *board, const std::pair<int, int> &fromCoords, const std::pair<int, int> &toCoords) const
{


    // If we've gotten this far, not a valid move
    return false;

}
