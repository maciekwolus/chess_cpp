#include <iostream>
#include "king.h"

// Constructor
King::King(Color c) : Piece(KING, c) {}

// He can go one way every way of he can castle
bool King::isValidMove(const Board *board, const std::pair<int, int> &fromCoords, const std::pair<int, int> &toCoords) const
{
// TODO - add casling
    if (board->getMoveLength(fromCoords, toCoords) == 1)
    {
        return true;
    }
    else
    {
        return false;
    }

}
