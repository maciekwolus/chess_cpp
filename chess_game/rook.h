#ifndef ROOK_H
#define ROOK_H

#include "board.h"
#include "piece.h"

/**
 * @brief Class representing a Rook chess piece.
 */
class Rook : public Piece
{
public:
    /**
     * @brief Constructor for Rook class.
     *
     * @param c The color of the Rook (WHITE or BLACK).
     */
    Rook(Color c);

    /**
     * @brief Check if the Rook can make a valid move.
     *
     * This function checks if the Rook can move from the 'fromCoords' to the 'toCoords'
     * on the given 'board' following the rules for Rook movement.
     *
     * @param board The chessboard on which the move is being checked.
     * @param fromCoords The coordinates of the current position of the Rook.
     * @param toCoords The coordinates of the destination position.
     * @return true if the move is valid for a Rook, false otherwise.
     */
    bool isValidMove(const Board *board, const std::pair<int, int> &fromCoords, const std::pair<int, int> &toCoords) const override;

    /// Destructor for Rook class
    ~Rook() override = default;
};

#endif
