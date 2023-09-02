#include <iostream>
#include "king.h"

// Constructor
King::King(Color c) : Piece(KING, c) {}

/* Determine if this is a valid move based on the rules of the King.
 * There are two possibile movement types for the King
 * First, the King can move one square in any direction
 * Second, the King may castle if permitted (https://en.wikipedia.org/wiki/Castling)
 * Players may not make a move that places their own King in Check */
bool King::isValidMove(const Board *board, const std::pair<int, int> &fromCoords, const std::pair<int, int> &toCoords) const
{
    return false;
}
