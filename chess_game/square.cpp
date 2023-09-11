#include <iostream>
#include <memory>
#include "square.h"

/**
 * @brief Get the chess Piece on the square.
 *
 * @return A pointer to the Piece on the square or nullptr if the square is empty.
 */
Piece* Square::getPiece() const
{
    return piece.get();
}

/**
 * @brief Set a chess Piece on the square.
 *
 * @param piece A unique pointer to the Piece to be placed on the square.
 * @return A unique pointer to the previously placed Piece on the square (if any).
 */
std::unique_ptr<Piece> Square::setPiece(std::unique_ptr<Piece> piece)
{
    std::unique_ptr<Piece> old = std::move(this->piece);
    this->piece = std::move(piece);
    return old;
}
