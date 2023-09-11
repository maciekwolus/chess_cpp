#ifndef KING_H
#define KING_H

#include "board.h"
#include "piece.h"

/**
 * @brief Class representing a King chess piece.
 */
class King : public Piece
{
public:
    /**
     * @brief Constructor for King class.
     *
     * @param c The color of the King (WHITE or BLACK).
     */
    King(Color c);

    /**
     * @brief Check if the King can make a valid move.
     *
     * This function checks if the King can move from the 'fromCoords' to the 'toCoords'
     * on the given 'board' following the rules for King movement.
     *
     * @param board The chessboard on which the move is being checked.
     * @param fromCoords The coordinates of the current position of the King.
     * @param toCoords The coordinates of the destination position.
     * @return true if the move is valid for a King, false otherwise.
     */
    bool isValidMove(const Board *board, const std::pair<int, int> &fromCoords, const std::pair<int, int> &toCoords) const override;

    /// Destructor for King class
    ~King() override = default;
};

#endif
