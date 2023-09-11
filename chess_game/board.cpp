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
#include <fstream>
#include <stdexcept>
#include <ctime>
#include <sstream>

/**
 * @file
 * @brief Contains the implementation of the Board class.
 */

/**
 * @brief Constructs a new Board object and initializes the chessboard.
 */
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

/**
 * @brief Initializes the chessboard with empty squares.
 *
 * The chessboard is represented as a map of coordinates to Square objects.
 */
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

/**
 * @brief Places a piece on the chessboard at the specified coordinates.
 *
 * @param coords The coordinates where the piece should be placed.
 * @param piece The piece to place on the board.
 * @return A pointer to the placed piece.
 */
std::unique_ptr<Piece> Board::setPiece(const std::pair<int, int> &coords, std::unique_ptr<Piece> piece)
{
    return squares[coords]->setPiece(std::move(piece));
}

/**
 * @brief Creates and places pawn pieces on the chessboard.
 *
 * Pawns are placed on their initial starting positions for both white and black.
 */
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

/**
 * @brief Creates and places rook pieces on the chessboard.
 *
 * Rooks are placed on their initial starting positions for both white and black.
 */
void Board::createRooks()
{
    // White Rooks
    setPiece(std::make_pair(7, 0), std::make_unique<Rook>(WHITE));
    setPiece(std::make_pair(7, 7), std::make_unique<Rook>(WHITE));

    // Black Rooks
    setPiece(std::make_pair(0, 0), std::make_unique<Rook>(BLACK));
    setPiece(std::make_pair(0, 7), std::make_unique<Rook>(BLACK));
}

/**
 * @brief Creates and places knight pieces on the chessboard.
 *
 * Knights are placed on their initial starting positions for both white and black.
 */
void Board::createKnights()
{
    // White Knights
    setPiece(std::make_pair(7, 1), std::make_unique<Knight>(WHITE));
    setPiece(std::make_pair(7, 6), std::make_unique<Knight>(WHITE));

    // Black Knights
    setPiece(std::make_pair(0, 1), std::make_unique<Knight>(BLACK));
    setPiece(std::make_pair(0, 6), std::make_unique<Knight>(BLACK));
}

/**
 * @brief Creates and places bishop pieces on the chessboard.
 *
 * Bishops are placed on their initial starting positions for both white and black.
 */
void Board::createBishops()
{
    // White Bishops
    setPiece(std::make_pair(7, 2), std::make_unique<Bishop>(WHITE));
    setPiece(std::make_pair(7, 5), std::make_unique<Bishop>(WHITE));

    // Black Bishops
    setPiece(std::make_pair(0, 2), std::make_unique<Bishop>(BLACK));
    setPiece(std::make_pair(0, 5), std::make_unique<Bishop>(BLACK));
}

/**
 * @brief Creates and places queen pieces on the chessboard.
 *
 * Queens are placed on their initial starting positions for both white and black.
 */
void Board::createQueens()
{
    // White Queen
    setPiece(std::make_pair(7, 3), std::make_unique<Queen>(WHITE));

    // Black Queen
    setPiece(std::make_pair(0, 3), std::make_unique<Queen>(BLACK));
}

/**
 * @brief Creates and places king pieces on the chessboard.
 *
 * Kings are placed on their initial starting positions for both white and black.
 */
void Board::createKings()
{
    // White King
    setPiece(std::make_pair(7, 4), std::make_unique<King>(WHITE));

    // Black King
    setPiece(std::make_pair(0, 4), std::make_unique<King>(BLACK));
}

/**
 * @brief Converts algebraic coordinates to integer coordinates.
 *
 * @param algebraicCoords The algebraic coordinates to convert (e.g., "a8").
 * @return A pair of integers representing the converted coordinates (e.g., <0,0>).
 */
std::pair<int, int> Board::algebraicToInt(std::string algebraicCoords) const
{
    int col = algebraicCoords[0] - 'a'; // Convert letter to int
    int row = 8 - (algebraicCoords[1] - '0'); // Convert ASCII character to int and flip
    return std::make_pair(row, col);
}

/**
 * @brief Switches the color whose turn it is to play.
 */
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

/**
 * @brief Retrieves the piece at a given square.
 *
 * @param coords The coordinates of the square to check.
 * @return A pointer to the piece at the specified coordinates, or nullptr if no piece is present.
 */
Piece* Board::getPiece(const std::pair<int, int> coords) const
{
    return squares.find(coords)->second->getPiece();
}

/**
 * @brief Calculates the number of board pixels between two locations.
 *
 * @param fromCoords The starting coordinates.
 * @param toCoords The destination coordinates.
 * @return The length of the move in terms of board pixels.
 */
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
        return abs(toCoords.first - fromCoords.first); // If it goes one right and one up, consider it as one pixel.
    }
    else
    {
        // Return -1 if none of the conditions are met (invalid move).
        return -1;
    }
}

/**
 * @brief Checks if a given location is on the chessboard.
 *
 * @param coords The coordinates to check.
 * @return true if the coordinates are on the board; false otherwise.
 */
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

/**
 * @brief Checks if a particular square on the chessboard is occupied by a piece.
 *
 * @param coords The coordinates of the square to check.
 * @return true if the square is occupied; false otherwise.
 */
bool Board::isOccupied(const std::pair<int, int> coords) const
{
    return getPiece(coords) != nullptr;
}

/**
 * @brief Checks if a particular square is occupied by a piece of the same color.
 *
 * @param fromCoords The coordinates of the source square.
 * @param toCoords The coordinates of the destination square.
 * @return true if the destination square is occupied by a piece of the same color as the source square; false otherwise.
 */
bool Board::isOccupiedSameColor(const std::pair<int, int> fromCoords, const std::pair<int, int> toCoords) const
{
    const Piece* fromPiece = getPiece(fromCoords);
    Color fromColor;

    if (fromPiece != nullptr)
    {
        fromColor = fromPiece->getColor();
    }
    else
    {
        return false;
    }

    const Piece* toPiece = getPiece(toCoords);
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

/**
 * @brief Checks if a particular square is occupied by a piece of a different color.
 *
 * @param fromCoords The coordinates of the source square.
 * @param toCoords The coordinates of the destination square.
 * @return true if the destination square is occupied by a piece of a different color than the source square; false otherwise.
 */
bool Board::isOccupiedDifferentColor(const std::pair<int, int> fromCoords, const std::pair<int, int> toCoords) const
{
    const Piece* fromPiece = getPiece(fromCoords);
    Color fromColor;

    if (fromPiece != nullptr)
    {
        fromColor = fromPiece->getColor();
    }
    else
    {
        return false;
    }

    const Piece* toPiece = getPiece(toCoords);
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

/**
 * @brief Checks if a move is vertical.
 *
 * @param fromCoords The coordinates of the source square.
 * @param toCoords The coordinates of the destination square.
 * @return true if the move is vertical (up or down); false otherwise.
 */
bool Board::isVerticalMove(const std::pair<int, int> fromCoords, const std::pair<int, int> toCoords) const
{
    return fromCoords.second == toCoords.second;
}

/**
 * @brief Checks if a move is horizontal.
 *
 * @param fromCoords The coordinates of the source square.
 * @param toCoords The coordinates of the destination square.
 * @return true if the move is horizontal (left or right); false otherwise.
 */
bool Board::isHorizontalMove(const std::pair<int, int> fromCoords, const std::pair<int, int> toCoords) const
{
    return fromCoords.first == toCoords.first;
}

/**
 * @brief Checks if a move is diagonal.
 *
 * @param fromCoords The coordinates of the source square.
 * @param toCoords The coordinates of the destination square.
 * @return true if the move is diagonal (like that of a bishop); false otherwise.
 */
bool Board::isDiagonalMove(const std::pair<int, int> fromCoords, const std::pair<int, int> toCoords) const
{
    return abs(toCoords.first - fromCoords.first) == abs(toCoords.second - fromCoords.second);
}

/**
 * @brief Checks if a pawn move is forward based on its color.
 *
 * @param fromCoords The coordinates of the source square.
 * @param toCoords The coordinates of the destination square.
 * @param piece A pointer to the pawn piece.
 * @return true if the pawn move is in the forward direction based on its color; false otherwise.
 */
bool Board::isForwardMove(const std::pair<int, int> fromCoords, const std::pair<int, int> toCoords, const Piece* piece) const
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

/**
 * @brief Checks if there is a clear path between the start and end coordinates for a piece.
 *
 * This function checks if there are no pieces in the path between the specified start and end coordinates.
 * It takes into account the direction of movement (vertical, horizontal, or diagonal).
 *
 * @param fromCoords The coordinates of the source square.
 * @param toCoords The coordinates of the destination square.
 * @return true if the path between the start and end coordinates is clear; false if there is any obstruction.
 */
bool Board::isPathClear(const std::pair<int, int> fromCoords, const std::pair<int, int> toCoords) const
{
    // Start parameters
    int moveLength = getMoveLength(fromCoords, toCoords); // Length of move
    bool movingDown = fromCoords.first < toCoords.first;   // Moving from black side to white side (top to bottom)
    bool movingRight = fromCoords.second < toCoords.second; // Moving from left to right

    // If the move length is 0 or 1, there are no intermediate squares to check.
    if (moveLength == 0 || moveLength == 1)
    {
        return true;
    }

    // Temporarily swap coordinates if moving in the opposite direction to simplify checking
    std::pair<int, int> fromTemp = fromCoords;
    std::pair<int, int> toTemp = toCoords;

    // Check for VERTICAL move - from top to bottom or reverse
    if (isVerticalMove(fromCoords, toCoords))
    {
        // If moving up, swap coordinates to check as if moving down (0 is at the top and 7 at the bottom).
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

        // Checked all squares in between - the path is clear.
        return true;
    }

    // Check for HORIZONTAL move - from left to right or reverse
    else if (isHorizontalMove(fromCoords, toCoords))
    {
        // If moving from right to left, swap coordinates to check as if moving from left to right (0 is at the left and 7 at the right).
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

        // Checked all squares in between - the path is clear.
        return true;
    }

    // Check for DIAGONAL move
    else if (isDiagonalMove(fromCoords, toCoords))
    {
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

            // Checked all squares in between - the path is clear.
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

            // Checked all squares in between - the path is clear.
            return true;
        }
    }

    // Path is not vertical, horizontal, or diagonal - the move is invalid.
    return false;
}

/**
 * @brief Checks if a move from the source square to the destination square is valid.
 *
 * This function performs several checks to determine if a move is valid:
 * 1. Checks if the source and destination squares are on the board.
 * 2. Checks if the destination square is occupied by a piece of the same color as the source square.
 * 3. Checks if there is a piece at the source square.
 * 4. Calls the `isValidMove` function of the piece to check if it's a valid move for that piece.
 *
 * @param fromCoords The coordinates of the source square.
 * @param toCoords The coordinates of the destination square.
 * @return true if the move is valid; false otherwise.
 */
bool Board::isValidMove(const std::pair<int, int>& fromCoords, const std::pair<int, int>& toCoords) const
{
    // Check if from and to locations are on the board
    if (!isOnBoard(fromCoords) || !isOnBoard(toCoords))
    {
        // qDebug() << "WARNING - you can't move out of the board";
        return false;
    }

    // Check if the destination location is occupied by a piece of the same color
    if (isOccupiedSameColor(fromCoords, toCoords))
    {
        // qDebug() << "WARNING - you can't move here because it's occupied by a piece of the same color";
        return false;
    }

    // Check if there is a piece at the source location
    const Piece* piece = getPiece(fromCoords);
    if (piece == nullptr)
    {
        // qDebug() << "WARNING - no piece at the source location";
        return false;
    }

    // Check if this is a valid move for the piece
    if (!piece->isValidMove(this, fromCoords, toCoords))
    {
        // qDebug() << "WARNING - not a valid move for this piece";
        return false;
    }

    // If all checks pass, the move is valid
    return true;
}

/**
 * @brief Moves a piece from one square to another without any checking.
 *
 * This function is used to move a piece from the source square to the destination square without performing any validity checks.
 *
 * @param fromCoords The coordinates of the source square.
 * @param toCoords The coordinates of the destination square.
 */
void Board::forceMovePiece(const std::pair<int, int> fromCoords, const std::pair<int, int> toCoords)
{
    setPiece(toCoords, setPiece(fromCoords, nullptr));
}

/**
 * @brief Reverts the last move made on the board.
 *
 * This function undoes the last move made on the board. It moves the piece back to its original position and, if the last move
 * resulted in a capture, it restores the captured piece to the board.
 */
void Board::revertLastMove()
{
    // Get the last move from the moves vector
    std::pair<std::pair<int, int>, std::pair<int, int>> lastMove = moves.back();

    // Undo the last move
    forceMovePiece(lastMove.second, lastMove.first);

    // If the last move was a capture, then replace the captured piece
    int previousMove = moves.size() - 1;
    if (capturedPieces.find(previousMove) != capturedPieces.end())
    {
        // Move the piece from capturedPieces map to the board
        setPiece(lastMove.second, std::move(capturedPieces[previousMove]));

        // Erase the entry from capturedPieces map
        capturedPieces.erase(previousMove);
    }

    // Remove the last move from the moves vector
    moves.pop_back();

    // Decrement the move counter in the piece
    getPiece(lastMove.first)->decrementMoves();
}

/**
 * @brief Checks if a piece at the given coordinates has the same color as the current turn color.
 *
 * This function checks if the piece at the specified coordinates has the same color as the current turn color.
 *
 * @param fromCoords The coordinates of the square containing the piece to be checked.
 * @return true if the piece has the same color as the current turn color; false otherwise.
 */
bool Board::checkPieceColor(const std::pair<int, int> fromCoords) const
{
    // Iterate through all squares with pointers to pieces
    for (auto const& square : squares)
    {
        Piece* piece = square.second->getPiece();

        // If the piece on the given coordinates has the same color as the current turn color, return true
        if (square.first == fromCoords && piece->getColor() == colorTurn)
        {
            return true;
        }
    }

    // If no piece on those coordinates matches the color of the current turn, return false
    return false;
}

/**
 * @brief Returns the current color whose turn it is to move.
 *
 * This function returns the color (either WHITE or BLACK) indicating whose turn it is to make a move.
 *
 * @return The color representing the current turn.
 */
Color Board::getColor()
{
    return colorTurn;
}

/**
 * @brief Moves a piece from one square to another.
 *
 * This function attempts to move a piece from the source square to the destination square. It performs several checks to ensure
 * the move is valid, including checking for path obstruction and capturing. If the move is valid, it updates the board and stores
 * the move in the moves vector.
 *
 * @param fromCoords The coordinates of the source square.
 * @param toCoords The coordinates of the destination square.
 * @return true if the move is successful; false if the move is invalid.
 */
bool Board::movePiece(const std::pair<int, int>& fromCoords, const std::pair<int, int>& toCoords)
{
    if (isValidMove(fromCoords, toCoords))
    {
        // If the destination square is occupied, save the captured piece
        if (squares[toCoords]->getPiece() != nullptr)
        {
            int index = moves.size();
            capturedPieces.insert(std::pair<int, std::unique_ptr<Piece>>(index, setPiece(toCoords, nullptr)));
        }

        // Move the piece from the source square to the destination square
        setPiece(toCoords, setPiece(fromCoords, nullptr));

        // Increment the move counter for the moved piece
        getPiece(toCoords)->incrementMoves();

        // Store the move in the moves vector
        moves.emplace_back(fromCoords, toCoords);

        return true;
    }

    return false;
}

/**
 * @brief Checks if a move represents castling and performs castling if valid.
 *
 * This function checks if the given move represents a castling move and, if so, performs castling if the move is valid.
 * Castling is a special chess move involving the king and a rook.
 *
 * @param toMove The color whose turn it is to move.
 * @param from The starting coordinates for the move.
 * @param to The destination coordinates for the move.
 * @return true if the castling move is valid and executed; false otherwise.
 */
bool Board::castle(const Color toMove, const std::pair<int, int> from, const std::pair<int, int> to)
{
    // Check if it's the king at the starting coordinates
    if (getKingLocation(toMove) != from)
    {
        return false;
    }

    // Determine the rook location and the intermediate location between the king and rook
    Piece* rook;
    std::pair<int, int> intermediateLocation; // Position between rook and king
    std::pair<int, int> rookLocation;
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

    // Check if there is a clear path between the king and rook, and that it's a horizontal move
    if (!isPathClear(from, rookLocation) || !isHorizontalMove(from, to))
    {
        return false;
    }

    // Check if the king is not in check
    if (isInCheck(toMove))
    {
        return false;
    }

    // Check if the rook and king haven't moved
    if (getPiece(from)->getMoved() || rook->getMoved())
    {
        return false;
    }

    // Make the first step for the king (moving to the intermediate location)
    if (movePiece(from, intermediateLocation))
    {
        // Verify that the move doesn't put the player in check
        if (isInCheck(toMove))
        {
            // If the move puts the player in check, revert the move and let the player enter a different move
            revertLastMove();
            return false;
        }
    }

    // Make the second step for the king (moving to the final destination)
    if (movePiece(intermediateLocation, to))
    {
        // Verify that the move doesn't put the player in check
        if (isInCheck(toMove))
        {
            // If the move puts the player in check, revert the last two moves and let the player enter a different move
            revertLastMove();
            revertLastMove();
            return false;
        }
    }

    // The king has moved legally, now move the rook
    forceMovePiece(rookLocation, intermediateLocation);

    return true;
}

/**
 * @brief Checks if the king of the given color is in check.
 *
 * This function determines if the king of the specified color is currently in check. It checks if any opposing pieces can attack
 * the king's position.
 *
 * @param defendingColor The color of the king to check for being in check.
 * @return true if the king is in check; false otherwise.
 */
bool Board::isInCheck(Color defendingColor) const
{
    // Get the opposite side (attacking color)
    Color attackingColor = (defendingColor == WHITE) ? BLACK : WHITE;

    // Get the locations of the defending king and attacking pieces
    std::pair<int, int> kingLocation = getKingLocation(defendingColor);
    std::vector<std::pair<int, int>> pieceLocations = getPieceLocations(attackingColor);

    // Check if any attacking piece can move to the king's location
    for (const auto& attackingPiece : pieceLocations)
    {
        if (isValidMove(attackingPiece, kingLocation))
        {
            return true;
        }
    }

    // If the king is not in check, return false
    return false;
}

/**
 * @brief Returns the location of the king of a given color.
 *
 * This function finds and returns the location of the king of the specified color on the chessboard.
 *
 * @param color The color of the king to locate (either WHITE or BLACK).
 * @return The coordinates (row, column) of the king.
 */
std::pair<int, int> Board::getKingLocation(Color color) const
{
    for (const auto& square : squares)
    {
        Piece* piece = square.second->getPiece();
        if (piece != nullptr && piece->getColor() == color && piece->getType() == KING)
        {
            return square.first;
        }
    }

    // This code should never execute if the king is present on the board
    return std::make_pair(-1, -1);
}

/**
 * @brief Returns the locations of all pieces of a given color.
 *
 * This function finds and returns the locations of all pieces of the specified color currently on the chessboard.
 *
 * @param color The color of the pieces to locate (either WHITE or BLACK).
 * @return A vector of coordinates (row, column) representing the locations of the pieces.
 */
std::vector<std::pair<int, int>> Board::getPieceLocations(Color color) const
{
    std::vector<std::pair<int, int>> pieceLocations;
    pieceLocations.reserve(squares.size());

    for (const auto& square : squares)
    {
        Piece* piece = square.second->getPiece();
        if (piece != nullptr && piece->getColor() == color)
        {
            pieceLocations.push_back(square.first);
        }
    }

    return pieceLocations;
}

/**
 * @brief Returns the locations of all squares on the chessboard.
 *
 * This function returns the coordinates (row, column) of all squares on the chessboard.
 *
 * @return A vector of coordinates representing all squares on the chessboard.
 */
std::vector<std::pair<int, int>> Board::getLocations() const
{
    std::vector<std::pair<int, int>> squareLocations;
    squareLocations.reserve(squares.size());

    for (const auto& square : squares)
    {
        squareLocations.push_back(square.first);
    }

    return squareLocations;
}

/**
 * @brief Checks if the current player is in checkmate.
 *
 * This function determines whether the current player, with the specified defending color, is in checkmate.
 * It first checks if the player is in check. If the player is in check, it iterates through all their pieces
 * and potential move destinations to see if any move can remove the king from check. If such a move is found,
 * the function returns false (not in checkmate). Otherwise, if no move can remove the king from check, it returns true (checkmate).
 *
 * @param defendingColor The color of the player to check for checkmate.
 * @return true if the player is in checkmate; false otherwise.
 */
bool Board::isInCheckMate(Color defendingColor)
{
    if (isInCheck(defendingColor))
    {
        std::vector<std::pair<int, int>> pieceLocations = getPieceLocations(defendingColor);
        std::vector<std::pair<int, int>> locations = getLocations();

        for (const auto &pieceLocation : pieceLocations)
        {
            for (const auto &location : locations)
            {
                // Try to move the piece
                if (movePiece(pieceLocation, location))
                {
                    // If the player is not in check after the move, then they have a valid move to escape check.
                    if (!isInCheck(defendingColor))
                    {
                        // Revert the last move and return false (not in checkmate)
                        revertLastMove();
                        return false; // Not in checkmate
                    }

                    // Revert the last move if the player was still in check and continue looping (or end the game).
                    revertLastMove();
                }
            }
        }
    }
    else
    {
        return false;
    }

    // Return true when in checkmate
    return true;
}

/**
 * @brief Checks if the current player is in stalemate.
 *
 * This function determines whether the current player, with the specified defending color, is in stalemate.
 * It first checks if the player is in check. If the player is not in check, it iterates through all their pieces
 * and potential move destinations to see if any move can be made. If such a move is found, the function returns false (not in stalemate).
 * Otherwise, if no move can be made, it returns true (stalemate).
 *
 * @param defendingColor The color of the player to check for stalemate.
 * @return true if the player is in stalemate; false otherwise.
 */
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

        for (const auto &pieceLocation : pieceLocations)
        {
            for (const auto &location : locations)
            {
                // Try to move the piece
                if (movePiece(pieceLocation, location))
                {
                    // If the player is not in check after the move, then they have a valid move to make.
                    if (!isInCheck(defendingColor))
                    {
                        // Revert the last move and return false (not in stalemate)
                        revertLastMove();
                        return false; // Not in stalemate
                    }

                    // Revert the last move if the player was still in check and continue looping (or end the game).
                    revertLastMove();
                }
            }
        }
    }

    // Return true when in stalemate
    return true;
}

/**
 * @brief Promote pawn to a queen if it goes to the end of board.
 *
 * Functions check if the color of piece is good and the piece which
 * is moving is a pawn. Secondly, according to the color, it check if
 * pawn is at the end. If it is - it changes into queen and returns true
 * to the frontend.
 *
 * @param toMove The color of the player to move.
 * @param coordinates The coordinates of the piece.
 * @return true if it is the pawn to promote; false otherwise.
 */
bool Board::promotePawn(Color toMove, std::pair<int, int> coordinates)
{
    Piece *pieceToPromote = getPiece(coordinates); // Get index to piece

    // Check if color is ok
    if (toMove != colorTurn)
    {
        return false;
    }

    // Check if thats pawn
    if(pieceToPromote->getType() != PAWN)
    {
        return false;
    }

    // Check if proper color at the end
    if (toMove == BLACK && coordinates.first == 0)
    {
        // Promote white piece
        setPiece(coordinates, std::make_unique<Queen>(WHITE));
        return true;
    }
    else if (toMove == WHITE && coordinates.first == 7)
    {
        // Promote black piece
        setPiece(coordinates, std::make_unique<Queen>(BLACK));
        return true;
    }

    // Definitely nothing good happened if you are this far
    return false;
}

/**
 * @brief Ends the chess game if it's in checkmate or stalemate.
 *
 * This function checks if the game has ended due to either checkmate or stalemate for the specified player.
 * If the player is in checkmate, the game is considered ended, and the function returns true with a message indicating
 * which color has won. If the player is in stalemate, the game is also considered ended, and the function returns true
 * with a message indicating that it's a draw. If neither of these conditions is met, the function returns false, indicating
 * that the game continues.
 *
 * @param toMove The color of the player who is currently making a move.
 * @return true if the game has ended; false if the game continues.
 */
bool Board::endGame(Color toMove)
{
    Color defendingColor = toMove;
    if (isInCheckMate(defendingColor))
    {
        // qDebug() << "GAME IS ENDED! " << toMove << " color has won!";
        return true;
    }

    if (isInStalemate(defendingColor))
    {
        // qDebug() << "GAME IS ENDED! It is a DRAW!";
        return true;
    }

    return false;
}

/**
 * @brief Generates a timestamp for use in a filename.
 *
 * This function generates a timestamp in the format "YYYYMMDDHHMMSS" and returns it as a string.
 * The timestamp is typically used to create unique filenames for saving game data.
 *
 * @return A string containing the timestamp.
 */
std::string Board::getCurrentTimestamp()
{
    std::time_t now = std::time(nullptr);
    char buffer[80];
    std::strftime(buffer, sizeof(buffer), "%Y%m%d%H%M%S", std::localtime(&now));
    return buffer;
}

/**
 * @brief Saves the moves of the chess game to a CSV file.
 *
 * This function saves the moves of the chess game to a CSV (Comma-Separated Values) file with a filename
 * that includes a timestamp to make it unique. The moves are written in the format:
 * "from_row,from_column,to_row,to_column" for each move.
 *
 * @note The file is saved in a specified directory, and the filename includes a timestamp to ensure uniqueness.
 * @throws std::runtime_error if there is an error opening the file for writing.
 */
void Board::saveMoves()
{
    std::string directory = "C:/Users/User/Desktop/priv/magazynierka/1P - C++ (projekt to do)/PROJECT_REPO/chess_cpp/games/"; // Name of the directory
    std::string filename = directory + "ChessGame_" + getCurrentTimestamp() + ".csv"; // Filename with timestamp
    std::ofstream outputFile(filename); // File with that name

    // Showing moves (optional)
    /*for (const auto& move : moves)
    {
        qDebug() << "Move from (" << move.first.first << ", " << move.first.second
                     << ") to (" << move.second.first << ", " << move.second.second << ")";
    }*/

    // Check if the file is open
    if (!outputFile.is_open())
    {
        throw std::runtime_error("Error opening file: " + filename);
    }

    // Add moves to the file
    for (const auto& move : moves)
    {
        outputFile << move.first.first << "," << move.first.second << ","
                   << move.second.first << "," << move.second.second << "\n";
    }

    // Close the file
    outputFile.close();
    qDebug() << "Moves saved to " << filename;
}



