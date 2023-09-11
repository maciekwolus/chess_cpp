#include <iostream>
#include "piece.h"

// Default constructor for Piece class
Piece::Piece(Type t, Color c)
{
    type = t;
    color = c;
    moves = 0;
}

/**
 * @brief Get the color of the piece.
 *
 * @return The color of the piece (WHITE or BLACK).
 */
Color Piece::getColor() const
{
    return color;
}

/**
 * @brief Check if the piece has moved.
 *
 * @return true if the piece has moved (moves > 0), false otherwise.
 */
bool Piece::getMoved() const
{
    return moves > 0;
}

/**
 * @brief Get the type of the piece.
 *
 * @return The type of the piece (e.g., PAWN, KNIGHT, etc.).
 */
Type Piece::getType() const
{
    return type;
}

/**
 * @brief Increment the number of moves made by the piece.
 */
void Piece::incrementMoves()
{
    moves++;
}

/**
 * @brief Decrement the number of moves made by the piece.
 */
void Piece::decrementMoves()
{
    moves--;
}
