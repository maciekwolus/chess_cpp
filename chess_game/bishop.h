#ifndef BISHOP_H
#define BISHOP_H

#include "board.h"
#include "piece.h"

/**
 * @brief Class representing a Bishop chess piece.
 */
class Bishop : public Piece
{
public:
    /**
     * @brief Constructor for Bishop class.
     *
     * @param c The color of the Bishop (WHITE or BLACK).
     */
    Bishop(Color c);

    /**
     * @brief Check if the Bishop can make a valid move.
     *
     * This function checks if the Bishop can move from the 'fromCoords' to the 'toCoords'
     * on the given 'board' following the rules for Bishop movement.
     *
     * @param board The chessboard on which the move is being checked.
     * @param fromCoords The coordinates of the current position of the Bishop.
     * @param toCoords The coordinates of the destination position.
     * @return true if the move is valid for a Bishop, false otherwise.
     */
    bool isValidMove(const Board *board, const std::pair<int, int> &fromCoords, const std::pair<int, int> &toCoords) const override;

    /// Destructor for Bishop class
    ~Bishop() override = default;
};

#endif
