#include <iostream>
#include "bishop.h"

/**
 * @brief Constructor for Bishop class.
 *
 * @param c The color of the Bishop (WHITE or BLACK).
 */
Bishop::Bishop(Color c) : Piece(BISHOP, c) {}

/**
 * @brief Check if the Bishop can make a valid move.
 *
 * @param board The chessboard on which the move is being checked.
 * @param fromCoords The coordinates of the current position of the Bishop.
 * @param toCoords The coordinates of the destination position.
 * @return true if the move is valid for a Bishop, false otherwise.
 */
bool Bishop::isValidMove(const Board *board, const std::pair<int, int> &fromCoords, const std::pair<int, int> &toCoords) const
{
    if (board->isDiagonalMove(fromCoords, toCoords))
    {
        if (board->isPathClear(fromCoords, toCoords))
        {
            return true;
        }
    }

    // Not valid if the conditions are not met
    return false;
}
