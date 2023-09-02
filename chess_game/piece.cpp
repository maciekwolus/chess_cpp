#include <iostream>
#include "piece.h"

/* Default constructor */
Piece::Piece(Type t, Color c)
{
    type = t;
    color = c;
    moves = 0;
}

Color Piece::getColor() const
{
    return color;
}
