#ifndef QUEEN_H
#define QUEEN_H

#include "board.h"
#include "piece.h"

class Queen : public Piece
{
public:
    Queen(Color c);
    bool isValidMove(const Board *board, const std::pair<int, int> &fromCoords, const std::pair<int, int> &toCoords) const override;
    ~Queen() override = default;
};

#endif
