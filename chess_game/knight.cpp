#include <iostream>
#include "knight.h"

/**
 * @brief Constructor for Knight class.
 *
 * @param c The color of the Knight (WHITE or BLACK).
 */
Knight::Knight(Color c) : Piece(KNIGHT, c) {}

/**
 * @brief Check if the Knight can make a valid move.
 *
 * @param board The chessboard on which the move is being checked.
 * @param fromCoords The coordinates of the current position of the Knight.
 * @param toCoords The coordinates of the destination position.
 * @return true if the move is valid for a Knight, false otherwise.
 */
bool Knight::isValidMove(const Board *board, const std::pair<int, int> &fromCoords, const std::pair<int, int> &toCoords) const
{
    // Calculate vertical and horizontal differences
    int verticalDifference = abs(toCoords.first - fromCoords.first);
    int horizontalDifference = abs(toCoords.second - fromCoords.second);

    // Check if it's a valid Knight move (L-shape)
    if ((verticalDifference == 2 && horizontalDifference == 1) || (verticalDifference == 1 && horizontalDifference == 2))
    {
        return true;
    }
    else
    {
        // Not valid if the conditions are not met
        return false;
    }
}
