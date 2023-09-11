#ifndef PAWN_H
#define PAWN_H

#include "board.h"
#include "piece.h"

/**
 * @brief Class representing a Pawn chess piece.
 */
class Pawn : public Piece
{
public:
    /**
     * @brief Constructor for Pawn class.
     *
     * @param c The color of the Pawn (WHITE or BLACK).
     */
    Pawn(Color c);

    /**
     * @brief Check if the Pawn can make a valid move.
     *
     * This function checks if the Pawn can move from the 'fromCoords' to the 'toCoords'
     * on the given 'board' following the rules for Pawn movement.
     *
     * @param board The chessboard on which the move is being checked.
     * @param fromCoords The coordinates of the current position of the Pawn.
     * @param toCoords The coordinates of the destination position.
     * @return true if the move is valid for a Pawn, false otherwise.
     */
    bool isValidMove(const Board *board, const std::pair<int, int> &fromCoords, const std::pair<int, int> &toCoords) const override;

    /// Destructor for Pawn class
    ~Pawn() override = default;
};

#endif
