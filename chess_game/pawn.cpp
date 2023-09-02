#include <iostream>
#include "pawn.h"

// Constructor
Pawn::Pawn(Color c) : Piece(PAWN, c) {}

// Determine if this is a valid move based on the rules of the pawn
bool Pawn::isValidMove(const Board *board, const std::pair<int, int> &fromCoords, const std::pair<int, int> &toCoords) const
{
    // TO DO

    // If we've gotten this far, definitely not a valid move
    return false;

}
