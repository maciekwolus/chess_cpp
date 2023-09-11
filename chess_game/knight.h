#ifndef KNIGHT_H
#define KNIGHT_H

#include "board.h"
#include "piece.h"

/**
 * @brief Class representing a Knight chess piece.
 */
class Knight : public Piece
{
public:
    /**
     * @brief Constructor for Knight class.
     *
     * @param c The color of the Knight (WHITE or BLACK).
     */
    Knight(Color c);

    /**
     * @brief Check if the Knight can make a valid move.
     *
     * This function checks if the Knight can move from the 'fromCoords' to the 'toCoords'
     * on the given 'board' following the rules for Knight movement.
     *
     * @param board The chessboard on which the move is being checked.
     * @param fromCoords The coordinates of the current position of the Knight.
     * @param toCoords The coordinates of the destination position.
     * @return true if the move is valid for a Knight, false otherwise.
     */
    bool isValidMove(const Board *board, const std::pair<int, int> &fromCoords, const std::pair<int, int> &toCoords) const override;

    /// Destructor for Knight class
    ~Knight() override = default;
};

#endif
