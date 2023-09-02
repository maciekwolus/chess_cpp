#ifndef SQUARE_H
#define SQUARE_H

#include <memory>
#include "piece.h"

// container for a Piece

class Square
{
public:
    Piece* getPiece() const;
    std::unique_ptr<Piece> setPiece(std::unique_ptr<Piece> piece);
protected:
    std::unique_ptr<Piece> piece;
};

#endif
