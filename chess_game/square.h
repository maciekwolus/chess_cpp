#ifndef SQUARE_H
#define SQUARE_H

#include <memory>
#include "piece.h"

/**
 * @brief A container for a chess Piece.
 */
class Square
{
public:
    /**
     * @brief Get the piece on the square.
     *
     * @return A pointer to the Piece on the square or nullptr if the square is empty.
     */
    Piece* getPiece() const;

    /**
     * @brief Set a chess Piece on the square.
     *
     * @param piece A unique pointer to the Piece to be placed on the square.
     * @return A unique pointer to the previously placed Piece on the square (if any).
     */
    std::unique_ptr<Piece> setPiece(std::unique_ptr<Piece> piece);

protected:
    std::unique_ptr<Piece> piece; ///< The chess Piece on the square (nullptr if empty).
};

#endif
