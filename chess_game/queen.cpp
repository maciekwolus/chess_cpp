#include <iostream>
#include "queen.h"

/**
 * @brief Constructor for Queen class.
 *
 * @param c The color of the Queen (WHITE or BLACK).
 */
Queen::Queen(Color c) : Piece(QUEEN, c) {}

/**
 * @brief Check if the Queen can make a valid move.
 *
 * @param board The chessboard on which the move is being checked.
 * @param fromCoords The coordinates of the current position of the Queen.
 * @param toCoords The coordinates of the destination position.
 * @return true if the move is valid for a Queen, false otherwise.
 */
bool Queen::isValidMove(const Board *board, const std::pair<int, int> &fromCoords, const std::pair<int, int> &toCoords) const
{
    if (board->isVerticalMove(fromCoords, toCoords) || board->isHorizontalMove(fromCoords, toCoords))
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

    // Not valid if the conditions are not met
    return false;
}
