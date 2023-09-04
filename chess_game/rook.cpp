#include <iostream>
#include "rook.h"

// Constructor
Rook::Rook(Color c) : Piece(ROOK, c) {}

// It can move from left to right and reverse or from up to down or reverse when there is nothing between
bool Rook::isValidMove(const Board *board, const std::pair<int, int> &fromCoords, const std::pair<int, int> &toCoords) const
{
   if(board->isVerticalMove(fromCoords, toCoords) || board->isHorizontalMove(fromCoords, toCoords))
        {
            if (board->isPathClear(fromCoords, toCoords))
            {
                return true;
            }
        }

    // Not a valid if the condition are not made
    return false;

}
