#include <iostream>
#include "queen.h"

// Constructor
Queen::Queen(Color c) : Piece(QUEEN, c) {}

// She can move like she wants
bool Queen::isValidMove(const Board *board, const std::pair<int, int> &fromCoords, const std::pair<int, int> &toCoords) const
{
    if(board->isVerticalMove(fromCoords, toCoords) || board->isHorizontalMove(fromCoords, toCoords))
    {
        if (board->isPathClear(fromCoords, toCoords))
        {
            return true;
        }
    }
    else if (board->isDiagonalMove(fromCoords, toCoords))
    {
        if (board->isPathClear(fromCoords, toCoords))
        {
            return true;
        }
    }

    // Not a valid if the condition are not made
    return false;

}
