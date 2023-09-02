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

    virtual bool isValidMove(const Board *board, const std::pair<int, int> &fromCoords, const std::pair<int, int> &toCoords) const = 0;

    // Destructor
    virtual ~Piece() = default;
protected:
    Color color;
    Type type;
    int moves;

};

#endif
