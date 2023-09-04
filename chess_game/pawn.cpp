#include <iostream>
#include "pawn.h"

// Constructor
Pawn::Pawn(Color c) : Piece(PAWN, c) {}

// It push by 1, but first move he can 2. It beats up vertical. Weird guy
bool Pawn::isValidMove(const Board *board, const std::pair<int, int> &fromCoords, const std::pair<int, int> &toCoords) const
{
    // Move lenght might
    int moveLength = board->getMoveLength(fromCoords, toCoords);

    // It has to move forward (white go from bottom to top, black from top to bottom)
    if (!board->isForwardMove(fromCoords, toCoords, this))
    {
        return false;
    }

    // It can't go horizontal (from left to right or reverse)
    if (board->isHorizontalMove(fromCoords, toCoords))
    {
        return false;
    }

    // If it hits - length = 1 and diagonal
    if (board->isDiagonalMove(fromCoords, toCoords))
    {
        // Is 1 step?
        if (moveLength == 1 && board->isOccupiedDifferentColor(fromCoords, toCoords))
        {
            return true;
        }
        else
        {
            // Only moveLength of 1 is allowed on diagonals
            return false;
        }
    }

    // If it moves - length 1 or 2, clear path, nothing between, 2 can be when first move
    if (board->isVerticalMove(fromCoords, toCoords))
    {
        // Occupied by same color?
        if (board->isOccupied(toCoords))
        {
            return false;
        }

        // Length == 2?
        if (moveLength == 2)
        {
            if (!getMoved() && board->isPathClear(fromCoords, toCoords))
            {
                return true;
            }
        }
        // Not occupied so it can go
        else if (moveLength == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }


    // Not a valid if the condition are not made
    return false;

}
