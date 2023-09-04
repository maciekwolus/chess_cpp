#include <iostream>
#include "piece.h"

// Default constructor
Piece::Piece(Type t, Color c)
{
    type = t;
    color = c;
    moves = 0;
}


// Gives a color of piece
Color Piece::getColor() const
{
    return color;
}

// Says if piece has moved
bool Piece::getMoved() const
{
    return moves > 0; // true if more than 0
}

// Increases number of moves
void Piece::incrementMoves()
{
    moves++;
}
