#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include "board.h"
#include "piece.h"
#include "pawn.h"
#include "rook.h"
#include "bishop.h"
#include "knight.h"
#include "king.h"
#include "queen.h"
#include <QDebug>

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
    prepSquares();
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
        { createKings(); }
}

// Squares - stored in a map - pair to unique_ptr to Square object
// e.g. a8 is a std::pair<0,0>
void Board::prepSquares()
{
    for (int i = 0; i < 8; i++)
    {

        for (int j = 0; j < 8; j++)
        {
            squares.insert(std::pair <std::pair <int, int>, std::unique_ptr<Square>> (std::make_pair(i, j), std::make_unique<Square>()));
        }
    }
}

// Put piece to location in the map
std::unique_ptr<Piece> Board::setPiece(const std::pair<int, int> &coords, std::unique_ptr<Piece> piece)
{
    return squares[coords]->setPiece(std::move(piece));
}

// creates Pawns on places
void Board::createPawns()
{
    // White pawns
    setPiece(std::make_pair(6, 0), std::make_unique<Pawn>(WHITE));
    setPiece(std::make_pair(6, 1), std::make_unique<Pawn>(WHITE));
    setPiece(std::make_pair(6, 2), std::make_unique<Pawn>(WHITE));
    setPiece(std::make_pair(6, 3), std::make_unique<Pawn>(WHITE));
    setPiece(std::make_pair(6, 4), std::make_unique<Pawn>(WHITE));
    setPiece(std::make_pair(6, 5), std::make_unique<Pawn>(WHITE));
    setPiece(std::make_pair(6, 6), std::make_unique<Pawn>(WHITE));
    setPiece(std::make_pair(6, 7), std::make_unique<Pawn>(WHITE));

    // Black pawns
    setPiece(std::make_pair(1, 0), std::make_unique<Pawn>(BLACK));
    setPiece(std::make_pair(1, 1), std::make_unique<Pawn>(BLACK));
    setPiece(std::make_pair(1, 2), std::make_unique<Pawn>(BLACK));
    setPiece(std::make_pair(1, 3), std::make_unique<Pawn>(BLACK));
    setPiece(std::make_pair(1, 4), std::make_unique<Pawn>(BLACK));
    setPiece(std::make_pair(1, 5), std::make_unique<Pawn>(BLACK));
    setPiece(std::make_pair(1, 6), std::make_unique<Pawn>(BLACK));
    setPiece(std::make_pair(1, 7), std::make_unique<Pawn>(BLACK));
}

// creates Rooks on places
void Board::createRooks()
{
    // White Rooks
    setPiece(std::make_pair(7, 0), std::make_unique<Rook>(WHITE));
    setPiece(std::make_pair(7, 7), std::make_unique<Rook>(WHITE));

    // Black Rooks
    setPiece(std::make_pair(0, 0), std::make_unique<Rook>(BLACK));
    setPiece(std::make_pair(0, 7), std::make_unique<Rook>(BLACK));
}

// creates Knights on places
void Board::createKnights()
{
    // White Knights
    setPiece(std::make_pair(7, 1), std::make_unique<Knight>(WHITE));
    setPiece(std::make_pair(7, 6), std::make_unique<Knight>(WHITE));

    // Black Knights
    setPiece(std::make_pair(0, 1), std::make_unique<Knight>(BLACK));
    setPiece(std::make_pair(0, 6), std::make_unique<Knight>(BLACK));
}

// creates Bishops on places
void Board::createBishops()
{
    // White Bishops
    setPiece(std::make_pair(7, 2), std::make_unique<Bishop>(WHITE));
    setPiece(std::make_pair(7, 5), std::make_unique<Bishop>(WHITE));

    // Black Bishops
    setPiece(std::make_pair(0, 2), std::make_unique<Bishop>(BLACK));
    setPiece(std::make_pair(0, 5), std::make_unique<Bishop>(BLACK));
}

// creates Queens on places
void Board::createQueens()
{
    // White Queen
    setPiece(std::make_pair(7, 3), std::make_unique<Queen>(WHITE));

    // Black Queen
    setPiece(std::make_pair(0, 3), std::make_unique<Queen>(BLACK));
}

// creates Kings on places
void Board::createKings()
{
    // White King
    setPiece(std::make_pair(7, 4), std::make_unique<King>(WHITE));

    // Black King
    setPiece(std::make_pair(0, 4), std::make_unique<King>(BLACK));
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
        qDebug() << "WARNING - you can't move out of board";
        return false;
    }

     // Check if to location is occupied by piece of same color
    if (isOccupiedSameColor(fromCoords, toCoords))
    {
        qDebug() << "WARNING - you can't move here because it's occupied";
        return false;
    }

    // Check if there is a piece
    const Piece *piece = getPiece(fromCoords);
    if (piece == nullptr)
    {
        qDebug() << "WARNING - no piece here";
        return false;
    }

    // Check if this is a valid move for this piece
    if (!piece->isValidMove(this, fromCoords, toCoords))
    {
        qDebug() << "WARNING - not a valid move";
        return false;
    }

    return true;
}
