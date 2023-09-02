#ifndef ROOK_H
#define ROOK_H

#include "board.h"
#include "piece.h"

class Rook : public Piece
{
public:
    Rook(Color c);
    bool isValidMove(const Board *board, const std::pair<int, int> &fromCoords, const std::pair<int, int> &toCoords) const override;
    ~Rook() override = default;
};

#endif
