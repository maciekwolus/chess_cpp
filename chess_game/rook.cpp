#include <iostream>
#include "rook.h"

/**
 * @brief Constructor for Rook class.
 *
 * @param c The color of the Rook (WHITE or BLACK).
 */
Rook::Rook(Color c) : Piece(ROOK, c) {}

/**
 * @brief Check if the Rook can make a valid move.
 *
 * @param board The chessboard on which the move is being checked.
 * @param fromCoords The coordinates of the current position of the Rook.
 * @param toCoords The coordinates of the destination position.
 * @return true if the move is valid for a Rook, false otherwise.
 */
bool Rook::isValidMove(const Board *board, const std::pair<int, int> &fromCoords, const std::pair<int, int> &toCoords) const
{
    if (board->isVerticalMove(fromCoords, toCoords) || board->isHorizontalMove(fromCoords, toCoords))
    {
        if (board->isPathClear(fromCoords, toCoords))
        {
            return true;
        }
    }

    // Not valid if the conditions are not met
    return false;
}
