#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include "board.h"


Board::Board()
{
}

// This creates a board with the pieces specified by argument parameters
Board::Board(bool Pawns, bool Knights, bool Rooks, bool Bishops, bool Queens, bool Kings)
{
    /*prepSquares();
    if (Pawns)
        { createPawns(); }
    if (Rooks)
        { createRooks(); }
    if (Knights)
        { createKnights(); }
    if (Bishops)
        { createBishops(); }
    if (Queens)
        { createQueens(); }
    if (Kings)
        { createKings(); }*/
}

// Checks if a given location is on the board
bool Board::isOnBoard(const std::pair<int, int> &coords) const
{
    if (coords.first < 0 || coords.first > 7)
    {
        return false;
    }
    else if (coords.second < 0 || coords.second > 7)
    {
        return false;
    }
    else
    {
        return true;
    }
}

// Check if move is valid
bool Board::isValidMove(const std::pair<int, int> &fromCoords, const std::pair<int, int> &toCoords) const
{
    // Check if from and to locations are on the board
    if (!isOnBoard(fromCoords) || !isOnBoard(toCoords))
    {
        // std::cout << "Error: Coords are out of bounds" << '\n';
        return false;
    }

    /*
     * // Check if to location is occupied by piece of same color
    if (isOccupiedSameColor(fromCoords, toCoords))
    {
        // std::cout << "Error: Cannot move from " << intToAlgebraic(fromCoords) << " to " << intToAlgebraic(toCoords)
        // 		  << " because there's a friendly piece at " << intToAlgebraic(toCoords) << '\n';
        return false;
    }

    // Check if this is a valid move for this piece
    const Piece *piece = getPiece(fromCoords);
    if (piece == nullptr)
    {
        // std::cout << "Error: No piece at this starting square" << '\n';
        return false;
    }
    if (!piece->isValidMove(this, fromCoords, toCoords))
    {
        // std::cout << "Error: This is an invalid move for this piece" << '\n';
        return false;
    }*/

    return true;
}
