#include <iostream>
#include "king.h"

/**
 * @brief Constructor for King class.
 *
 * @param c The color of the King (WHITE or BLACK).
 */
King::King(Color c) : Piece(KING, c) {}

/**
 * @brief Check if the King can make a valid move.
 *
 * @param board The chessboard on which the move is being checked.
 * @param fromCoords The coordinates of the current position of the King.
 * @param toCoords The coordinates of the destination position.
 * @return true if the move is valid for a King, false otherwise.
 */
bool King::isValidMove(const Board *board, const std::pair<int, int> &fromCoords, const std::pair<int, int> &toCoords) const
{
    // Check if the move length is 1 (King can move one square in any direction)
    if (board->getMoveLength(fromCoords, toCoords) == 1)
    {
        return true;
    }
    else
    {
        // Not valid if the conditions are not met
        return false;
    }
}
