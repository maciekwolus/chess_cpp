#include <iostream>
#include "knight.h"

// Constructor
Knight::Knight(Color c) : Piece(KNIGHT, c) {}

// It can move like an 'L' - 2 up/down and 1 left/right or 2 left/right and 1 up/down
bool Knight::isValidMove(const Board *board, const std::pair<int, int> &fromCoords, const std::pair<int, int> &toCoords) const
{
    // Those two variables make the code cleaner - looks good with that ngl
    int verticalDifference = abs(toCoords.first - fromCoords.first);
    int horizontalDifference = abs(toCoords.second - fromCoords.second);

    if ((verticalDifference == 2 && horizontalDifference == 1) || (verticalDifference == 1 && horizontalDifference == 2))
    {
        return true;
    }
    else
    {
        // Not a valid if the condition are not made
        return false;
    }
}
