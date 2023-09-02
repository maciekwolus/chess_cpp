#ifndef BOARD_H
#define BOARD_H

#include <map>
#include <memory>
#include <vector>
#include "square.h"

// Forward declaration to avoid circular dependency
class Piece;

/* The Board is the intermediary through which pieces are accessed and manipulated. It's primary data source is an
 map which maps algebraic chess locations (as strings) to Squares. Each Square has the capability of holding a
 single Piece. */

class Board {
public:
    // Constructors
    Board();
    Board(bool Pawns, bool Knights, bool Rooks, bool Bishops, bool Queens, bool Kings);

    bool isOnBoard(const std::pair<int, int> &coords) const;
    bool isValidMove(const std::pair<int, int> &fromCoords, const std::pair<int, int> &toCoords) const; // check if the move is possible

    // Destructor
    ~Board();

private:
};

#endif
