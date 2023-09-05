#ifndef PIECE_H
#define PIECE_H

#include <utility>

// Forward declaration to avoid circular dependency
class Board;

enum Type
{
    PAWN,
    KNIGHT,
    BISHOP,
    ROOK,
    QUEEN,
    KING
};

enum Color
{
    WHITE,
    BLACK
};

class Piece
{
public:
    // Constructor
    Piece(Type, Color);

    Color getColor() const; // get color of piece
    bool getMoved() const; // check if piece has moved
    Type getType() const; // gives type
    void incrementMoves(); // increase number of moves made by a piece
    void decrementMoves(); // decrease number of moves made by a piece

    virtual bool isValidMove(const Board *board, const std::pair<int, int> &fromCoords, const std::pair<int, int> &toCoords) const = 0; // void to check if piece can move like that

    // Destructor
    virtual ~Piece() = default;
protected:
    Color color;
    Type type;
    int moves;

};

#endif
