#ifndef SQUARE_H
#define SQUARE_H

#include <memory>
#include "piece.h"

// container for a Piece

class Square
{
public:
    Piece* getPiece() const; // gives a piece ona a square
    std::unique_ptr<Piece> setPiece(std::unique_ptr<Piece> piece); // put a piece on square
protected:
    std::unique_ptr<Piece> piece;
};

#endif
