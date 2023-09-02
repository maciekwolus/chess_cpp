#ifndef KING_H
#define KING_H

#include "board.h"
#include "piece.h"

class King : public Piece
{
public:
    King(Color c);
    bool isValidMove(const Board *board, const std::pair<int, int> &fromCoords, const std::pair<int, int> &toCoords) const override;
    ~King() override = default;
};

#endif
