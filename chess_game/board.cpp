#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include "board.h"


Board::Board()
{
    prepSquares();
    createPawns();
    createRooks();
    createKnights();
    createBishops();
    createQueens();
    createKings();
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

// Returns the piece at a given square
Piece* Board::getPiece(const std::pair<int, int> &coords) const
{
    return squares.find(coords)->second->getPiece();
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

// Checks if a particular square is occupied. Returns true if so, false otherwise.
bool Board::isOccupied(const std::pair<int, int> &coords) const
{
    return getPiece(coords) != nullptr;
}

// Returns true if the destination is occupied by a piece of same color as the origin, false otherwise.
bool Board::isOccupiedSameColor(const std::pair<int, int> &fromCoords, const std::pair<int, int> &toCoords) const
{
    const Piece *fromPiece = getPiece(fromCoords);
    Color fromColor;
    if (fromPiece != nullptr)
    {
        fromColor = fromPiece->getColor();
    }
    else
    {
        return false;
    }

    const Piece *toPiece = getPiece(toCoords);
    Color toColor;
    if (toPiece != nullptr)
    {
        toColor = toPiece->getColor();
    }
    else
    {
        return false;
    }

    return fromColor == toColor;
}

// Check if move is valid
bool Board::isValidMove(const std::pair<int, int> &fromCoords, const std::pair<int, int> &toCoords) const
{
    // Check if from and to locations are on the board
    if (!isOnBoard(fromCoords) || !isOnBoard(toCoords))
    {
        std::cout << "WARNING - you can't move out of board";
        return false;
    }


     // Check if to location is occupied by piece of same color
    if (isOccupiedSameColor(fromCoords, toCoords))
    {
        std::cout << "WARNING - you can't move here because it's occupied";
        return false;
    }
/*
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
