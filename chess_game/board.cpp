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

// change letters to number, e.g. a8 to <0,0>
std::pair<int, int> Board::algebraicToInt(std::string algebraicCoords) const
{
    int col = algebraicCoords[0] - 'a'; 			// letter to int
    int row = 8 - (algebraicCoords[1] - '0');		// ascii letter to int and flip
    return std::make_pair(row,col);
}

// Switch color turn
void Board::switchColor()
{
    if (colorTurn == WHITE)
    {
        colorTurn = BLACK;
    }
    else
    {
        colorTurn = WHITE;
    }

}

// Returns the piece at a given square
Piece* Board::getPiece(const std::pair<int, int> coords) const
{
    return squares.find(coords)->second->getPiece();
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
bool Board::isValidMove(const std::pair<int, int> &fromCoords, const std::pair<int, int> &toCoords) const
{
    // Check if from and to locations are on the board
    if (!isOnBoard(fromCoords) || !isOnBoard(toCoords))
    {
        // qDebug() << "WARNING - you can't move out of board";
        return false;
    }

     // Check if to location is occupied by piece of same color
    if (isOccupiedSameColor(fromCoords, toCoords))
    {
        // qDebug() << "WARNING - you can't move here because it's occupied (same color piece stays here)";
        return false;
    }

    // Check if there is a piece
    const Piece *piece = getPiece(fromCoords);
    if (piece == nullptr)
    {
        // qDebug() << "WARNING - no piece here";
        return false;
    }

    // Check if this is a valid move for this piece
    if (!piece->isValidMove(this, fromCoords, toCoords))
    {
        // qDebug() << "WARNING - not a valid move";
        return false;
    }

    // If you are here then it is ture
    return true;
}

// Move piece without any checking (used to move rook in castle for example)
void Board::forceMovePiece(const std::pair<int, int> fromCoords, const std::pair<int, int> toCoords)
{
    setPiece(toCoords, setPiece(fromCoords, nullptr));
}

// Undo last move
void Board::revertLastMove()
{
    // Get last move from moves vector
    std::pair<std::pair<int, int>, std::pair<int, int>> lastMove = moves.back();

    // Undo last move
    forceMovePiece(lastMove.second, lastMove.first);

    // If last move was a capture, then replace captured piece
    int previousMove = moves.size() - 1;
    if (capturedPieces.find(previousMove) != capturedPieces.end())
    {
        // Move the piece from capturedPieces map to the board
        setPiece(lastMove.second, std::move(capturedPieces[previousMove]));

        // Erase the entry from capturedPieces map
        capturedPieces.erase(previousMove);
    }

    // Remove it from move vector
    moves.pop_back();

    // Decrement move counter in piece
    getPiece(lastMove.first)->decrementMoves();
}

// Check if piece color is same as turn color
bool Board::checkPieceColor(const std::pair<int, int> fromCoords) const
{
    // iterate through all squares with pointers to pieces
    for (auto const& square : squares)
    {
        Piece* piece = square.second->getPiece();

        // if piece on given coordinates has same color, then true
        if (square.first == fromCoords && piece->getColor() == colorTurn)
        {
            return true;
        }
    }

    // if no piece on that coordinates with matching color then false
    return false;
}

// Gives a color of move
Color Board::getColor()
{
    return colorTurn;
}

// Move piece - change the coordinates of the piece
bool Board::movePiece(const std::pair<int, int> &fromCoords, const std::pair<int, int> &toCoords)
{
    if (isValidMove(fromCoords, toCoords))
    {
        // If the piece represents a capture (i.e., destination is occupied), then save captured piece
        if (squares[toCoords]->getPiece() != nullptr)
        {
            int index = moves.size();
            capturedPieces.insert(std::pair<int, std::unique_ptr<Piece>>(index, setPiece(toCoords, nullptr)));
        }

        // setPiece inside check if something is already at this loaction. If there is, it puts a null here and return the old coordinates
        // So it's remove if something is here and do nothing when there's nothing
        setPiece(toCoords, setPiece(fromCoords, nullptr));

        // Change the value of piece moves (useful for pawn move for example)
        getPiece(toCoords)->incrementMoves();
        moves.emplace_back(fromCoords, toCoords);

        return true;
    }

    return false;
}

// Check if the move is castling
bool Board::castle(const Color toMove, const std::pair<int, int> from, const std::pair<int, int> to)
{
    // Get the rook we're going to castle with and intermediate location
    Piece* rook;
    std::pair<int,int> intermediateLocation; // position between rook and king
    std::pair<int,int> rookLocation;
    if (to == algebraicToInt("g8"))
    {
        rookLocation = algebraicToInt("h8");
        intermediateLocation = algebraicToInt("f8");
    }
    else if (to == algebraicToInt("c8"))
    {
        rookLocation = algebraicToInt("a8");
        intermediateLocation = algebraicToInt("d8");
    }
    else if (to == algebraicToInt("g1"))
    {
        rookLocation = algebraicToInt("h1");
        intermediateLocation = algebraicToInt("f1");
    }
    else if (to == algebraicToInt("c1"))
    {
        rookLocation = algebraicToInt("a1");
        intermediateLocation = algebraicToInt("d1");
    }
    else
    {
        return false;
    }

    // Get a pointer to the rook
    rook = getPiece(rookLocation);

    // Check if there is a clear path between them and that it's a horizontal move
    if (!isPathClear(from, rookLocation) || !isHorizontalMove(from, to))
    {
        return false;
    }

    // Check if king is not in check
    if (isInCheck(toMove))
    {
        return false;
    }

    // Check if rook and king haven't moved
    if (getPiece(from)->getMoved() || rook->getMoved())
    {
        return false;
    }

    // King can not be in check after the move
    // First step for king
    if (movePiece(from, intermediateLocation))
    {
        // Verify that move doesn't put player in check
        if (isInCheck(toMove))
        {
            // If move puts player in check, revert move, and let player enter different move
            revertLastMove();
            return false;
        }

    }
    // Second step for king
    if (movePiece(intermediateLocation, to))
    {
        // Verify that move doesn't put player in check
        if (isInCheck(toMove))
        {
            // If move puts player in check, revert last two moves, and let player enter different move
            revertLastMove();
            revertLastMove();
            return false;
        }
    }

    // Ling has moved legally. Rook can move
    forceMovePiece(rookLocation, intermediateLocation);

    return true;
}

// Check if someone is in check
bool Board::isInCheck(Color defendingColor) const
{
    // Gettin opposite sites
    Color attackingColor;
    if (defendingColor == WHITE)
    {
        attackingColor = BLACK;
    }
    else
    {
        attackingColor = WHITE;
    }

    // Get locations of defending king and attacking pieces
    std::pair<int, int> kingLocation = getKingLocation(defendingColor);
    std::vector<std::pair<int, int>> pieceLocations = getPieceLocations(attackingColor);

    for (auto attackingPiece : pieceLocations)
    {
        if (isValidMove(attackingPiece, kingLocation))
        {
            return true;
        }
    }

    // Not chech if u r here
    return false;
}

// Gives a king location of a given color
std::pair<int, int> Board::getKingLocation(Color color) const
{
    for (auto const& square : squares) {
        Piece* piece = square.second->getPiece();
        if (piece != nullptr && piece->getColor() == color && piece->getType() == KING)
        {
            return square.first;
        }
    }

    // King is never removed from the board = never execute
    return std::make_pair(-1,-1);
}

// Gives all locations of pieces of a given color.
std::vector<std::pair<int, int>> Board::getPieceLocations(Color color) const
{
    std::vector<std::pair<int, int>> pieceLocations;
    pieceLocations.reserve(squares.size());

    for (auto const& square : squares)
    {
        Piece* piece = square.second->getPiece();
        if (piece != nullptr && piece->getColor() == color)
        {
            pieceLocations.push_back(square.first);
        }
    }

    return pieceLocations;
}

// Returns Location of all pieces in vector
std::vector<std::pair<int, int>> Board::getLocations() const
{
    std::vector<std::pair<int, int>> pieceLocations;
    pieceLocations.reserve(squares.size());

    for (auto const& square : squares)
    {
        pieceLocations.push_back(square.first);
    }

    return pieceLocations;
}

// Check if checkmate - in check and has no moves
bool Board::isInCheckMate(Color defendingColor)
{
    if (isInCheck(defendingColor))
    {
        std::vector<std::pair<int, int>> pieceLocations = getPieceLocations(defendingColor);
        std::vector<std::pair<int, int>> locations = getLocations();

        for (auto const &pieceLocation : pieceLocations)
        {
            for (auto const &location : locations)
            {
                // try to move piece
                if (movePiece(pieceLocation, location))
                {
                    // if player is no in check, then he has moves - undo move and return false
                    if (!isInCheck(defendingColor))
                    {
                        revertLastMove();
                        return false; // not in check
                    }

                    // revert the last move if the player was still in check and continue looping (or end game)
                    revertLastMove();
                }
            }
        }
    }
    else
    {
        return false;
    }

    // return true when checkmate
    return true;
}

// Check if stalemate - NOT in check and has no moves
bool Board::isInStalemate(Color defendingColor)
{
    if (isInCheck(defendingColor))
    {
        return false;
    }
    else
    {
        std::vector<std::pair<int, int>> pieceLocations = getPieceLocations(defendingColor);
        std::vector<std::pair<int, int>> locations = getLocations();

        for (auto const &pieceLocation : pieceLocations)
        {
            for (auto const &location : locations)
            {
                // try to move piece
                if (movePiece(pieceLocation, location))
                {
                    // if player is no in check, then he has moves - undo move and return false
                    if (!isInCheck(defendingColor))
                    {
                        revertLastMove();
                        return false; // not in stalemate
                    }

                    // revert the last move if the player was still in check and continue looping (or end game)
                    revertLastMove();
                }
            }
        }
    }

    // return true when checkmate stalemate
    return true;
}

// Ends game when it checkmate or stealmate
bool Board::endGame(Color toMove)
{
    Color defendingColor = WHITE;
    if (toMove == WHITE)
    {
        defendingColor = BLACK;
    }

    if (isInCheckMate(defendingColor))
    {
        qDebug() << "GAME IS ENDED! " << toMove << " color has won!";
        return true;
    }

    if (isInStalemate(defendingColor))
    {
        qDebug() << "GAME IS ENDED! It is a DRAW!";
        return true;
    }

    return false;
}
