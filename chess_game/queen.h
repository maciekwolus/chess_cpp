#ifndef QUEEN_H
#define QUEEN_H

#include "board.h"
#include "piece.h"

/**
 * @brief Class representing a Queen chess piece.
 */
class Queen : public Piece
{
public:
    /**
     * @brief Constructor for Queen class.
     *
     * @param c The color of the Queen (WHITE or BLACK).
     */
    Queen(Color c);

    /**
     * @brief Check if the Queen can make a valid move.
     *
     * This function checks if the Queen can move from the 'fromCoords' to the 'toCoords'
     * on the given 'board' following the rules for Queen movement.
     *
     * @param board The chessboard on which the move is being checked.
     * @param fromCoords The coordinates of the current position of the Queen.
     * @param toCoords The coordinates of the destination position.
     * @return true if the move is valid for a Queen, false otherwise.
     */
    bool isValidMove(const Board *board, const std::pair<int, int> &fromCoords, const std::pair<int, int> &toCoords) const override;

    /// Destructor for Queen class
    ~Queen() override = default;
};

#endif
