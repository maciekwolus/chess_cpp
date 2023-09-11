#ifndef PIECE_H
#define PIECE_H

#include <utility>

/// Forward declaration to avoid circular dependency
class Board;

/// Enumeration for different types of chess pieces
enum Type
{
    PAWN,   ///< Pawn piece
    KNIGHT, ///< Knight piece
    BISHOP, ///< Bishop piece
    ROOK,   ///< Rook piece
    QUEEN,  ///< Queen piece
    KING    ///< King piece
};

/// Enumeration for piece colors
enum Color
{
    WHITE, ///< White color
    BLACK  ///< Black color
};

/// Class representing a chess piece
class Piece
{
public:
    /// Constructor for Piece class
    Piece(Type, Color);

    /// Get the color of the piece
    Color getColor() const;

    /// Check if the piece has moved
    bool getMoved() const;

    /// Get the type of the piece
    Type getType() const;

    /// Increment the number of moves made by a piece
    void incrementMoves();

    /// Decrement the number of moves made by a piece
    void decrementMoves();

    /**
     * @brief Check if the piece can make a valid move.
     *
     * This pure virtual function should be implemented by derived classes.
     * It checks if a piece can move from the 'fromCoords' to the 'toCoords' on the given 'board'.
     *
     * @param board The chessboard on which the move is being checked.
     * @param fromCoords The coordinates of the current position of the piece.
     * @param toCoords The coordinates of the destination position.
     * @return true if the move is valid, false otherwise.
     */
    virtual bool isValidMove(const Board *board, const std::pair<int, int> &fromCoords, const std::pair<int, int> &toCoords) const = 0;

    /// Destructor for Piece class
    virtual ~Piece() = default;

protected:
    Color color; ///< The color of the piece (either WHITE or BLACK)
    Type type;   ///< The type of the piece (e.g., PAWN, KNIGHT, etc.)
    int moves;   ///< The number of moves made by the piece
};

#endif
