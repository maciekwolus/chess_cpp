#ifndef BISHOP_H
#define BISHOP_H

#include "board.h"
#include "piece.h"

class Bishop : public Piece
{
public:
    Bishop(Color c);
    bool isValidMove(const Board *board, const std::pair<int, int> &fromCoords, const std::pair<int, int> &toCoords) const override;
    ~Bishop() override = default;
};

#endif
