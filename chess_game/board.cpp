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
Piece* Board::getPiece(const std::pair<int, int> coords) const
{
    return squares.find(coords)->second->getPiece();
}

// Change the coordinates of the piece
void Board::movePiece(const std::pair<int, int> &fromCoords, const std::pair<int, int> &toCoords)
{
// TODO check this
    // If the piece represents a capture (i.e., destination is occupied), then save captured piece
    //if (squares[toCoords]->getPiece() != nullptr)
    //{
    //    size_t index = moves.size();
    //    capturedPieces.insert(std::pair<int, std::unique_ptr<Piece>>(index, setPiece(toCoords, nullptr)));
    //}

    // setPiece inside check if something is already at this loaction. If there is, it puts a null here and return the old coordinates
    // So it's remove if something is here and do nothing when there's nothing
    setPiece(toCoords, setPiece(fromCoords, nullptr));

    // Change the value of piece moves (useful for pawn move for example)
    getPiece(toCoords)->incrementMoves();

// TODO check this - probably list of moves (not neeeded until save or smth)
    //moves.emplace_back(fromCoords, toCoords);
}

// Number of board pixels between locations
int Board::getMoveLength(const std::pair<int, int> fromCoords, const std::pair<int, int> toCoords) const
{
    if (isVerticalMove(fromCoords, toCoords))
    {
        return abs(toCoords.first - fromCoords.first);
    }
    else if (isHorizontalMove(fromCoords, toCoords))
    {
        return abs(toCoords.second - fromCoords.second);
    }
    else if (isDiagonalMove(fromCoords, toCoords))
    {
        return abs(toCoords.first - fromCoords.first); // if it goes one right and one up, let's say it's one and not sqrt from 2
    }
    else
    {
        // -1 if all false
        return -1;
    }
}

// Checks if a given location is on the board
bool Board::isOnBoard(const std::pair<int, int> coords) const
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
bool Board::isOccupied(const std::pair<int, int> coords) const
{
    return getPiece(coords) != nullptr;
}

// True when there is something in the same color
bool Board::isOccupiedSameColor(const std::pair<int, int> fromCoords, const std::pair<int, int> toCoords) const
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

// True when there is something in a different same color
bool Board::isOccupiedDifferentColor(const std::pair<int, int> fromCoords, const std::pair<int, int> toCoords) const
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

    return fromColor != toColor;
}

// Same column - move is vertical
bool Board::isVerticalMove(const std::pair<int, int> fromCoords, const std::pair<int, int> toCoords) const
{
    return fromCoords.second == toCoords.second;
}

// Same row - move is horizontal
bool Board::isHorizontalMove(const std::pair<int, int> fromCoords, const std::pair<int, int> toCoords) const
{
    return fromCoords.first == toCoords.first;
}

// Difference between vertical and horizontal are the same - move is diagonal
bool Board::isDiagonalMove(const std::pair<int, int> fromCoords, const std::pair<int, int> toCoords) const
{
    return abs(toCoords.first - fromCoords.first) == abs(toCoords.second - fromCoords.second);
}

// Check if white go from bottom to top and black from top to bottom
bool Board::isForwardMove(const std::pair<int, int> fromCoords, const std::pair<int, int> toCoords, const Piece *piece) const
{
    Color pieceColor = piece->getColor();
    if (pieceColor == BLACK && fromCoords.first < toCoords.first)
    {
        return true;
    }
    else if (pieceColor == WHITE && fromCoords.first > toCoords.first)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Check if there is a piece between the start and end coordinates (except pawn - he is dumb and different)
bool Board::isPathClear(const std::pair<int, int> fromCoords, const std::pair<int, int> toCoords) const
{
    // Start parameters
    int moveLength = getMoveLength(fromCoords, toCoords);       // Lenght of move
    bool movingDown = fromCoords.first < toCoords.first; 		// From black side to white side (up to bottom)
    bool movingRight = fromCoords.second < toCoords.second;		// From left to right

    // Same or 1 - if it's not occupied then definitely true
    if (moveLength == 0 || moveLength == 1)
    {
        return true;
    }

    // Temp needed to prevent coords change
    std::pair<int,int> fromTemp = fromCoords;
    std::pair<int,int> toTemp = toCoords;

    // Check for VERTICAL move - from top to bottom or reverse
    if (isVerticalMove(fromCoords, toCoords) == true)
    {
        // Function is checking for moving down so if it's going up we change it to still check like it was move down (0 is at top and 7 and the bottom so i want it to increase)
        if (!movingDown)
        {
            std::swap(fromTemp, toTemp);
        }

        for (int i = fromTemp.first + 1; i < toTemp.first; i++)
        {
            if (isOccupied(std::make_pair(i, fromTemp.second)))
            {
                return false;
            }
        }

        // Checked all between - all clear
        return true;
    }

    // Check for HORIZONTAL move - from left to right or reverse
    else if (isHorizontalMove(fromCoords, toCoords) == true)
    {
        // Function is checking for moving from left to right so if it's going up we change it to still check like it was like that (0 is at left and 7 and the right so i want it to increase)
        if (!movingRight)
        {
            std::swap(fromTemp, toTemp);
        }

        for (int i = fromTemp.second + 1; i < toTemp.second; i++)
        {
            if (isOccupied(std::make_pair(fromTemp.first, i)))
            {
                return false;
            }
        }

        // Checked all between - all clear
        return true;
    }

    // Check for DIAGONAL move
    else if (isDiagonalMove(fromCoords, toCoords) == true)
    {
        // Not gonna lie - do not really know how it all works in diagonal, but lot of debugging (and a little gpt help) make it work >.<
        if (movingDown == movingRight)
        {
            if (!movingDown && !movingRight)
            {
                std::swap(fromTemp, toTemp);
            }

            int col = fromTemp.second + 1;
            for (int row = fromTemp.first + 1; row < toTemp.first; row++)
            {
                if (isOccupied(std::make_pair(row, col)))
                {
                    return false;
                }
                col++;
            }

            // Checked all between - all clear
            return true;

        }
        else if (movingDown != movingRight)
        {
            if (movingDown && !movingRight)
            {
                std::swap(fromTemp, toTemp);
            }

            int col = fromTemp.second + 1;
            for (int row = fromTemp.first - 1; row > toTemp.first; row--)
            {
                if (isOccupied(std::make_pair(row, col)))
                {
                    return false;
                }
                col++;
            }

            // Checked all between - all clear
            return true;
        }
    }

    // Path NOT IN (vertical, horizontal, diagonal) - do not have to change that then as the move is definitely wrong
    return false;
}

// Check if move is valid
bool Board::isValidMove(const std::pair<int, int> &fromCoords, const std::pair<int, int> &toCoords)
{

// TODO - Check checkmate, check etc

    // Check if from and to locations are on the board
    if (!isOnBoard(fromCoords) || !isOnBoard(toCoords))
    {
        qDebug() << "WARNING - you can't move out of board";
        return false;
    }

     // Check if to location is occupied by piece of same color
    if (isOccupiedSameColor(fromCoords, toCoords))
    {
        qDebug() << "WARNING - you can't move here because it's occupied (same color piece stays here)";
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

    // If you are here then it is ture
    movePiece(fromCoords, toCoords);
    return true;
}
