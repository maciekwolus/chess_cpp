#ifndef KNIGHT_H
#define KNIGHT_H

#include "board.h"
#include "piece.h"

class Knight : public Piece
{
public:
    Knight(Color c);
    bool isValidMove(const Board *board, const std::pair<int, int> &fromCoords, const std::pair<int, int> &toCoords) const override;
    ~Knight() override = default;
};

#endif
