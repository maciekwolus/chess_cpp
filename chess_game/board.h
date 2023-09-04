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




    // Functions to play
    Piece* getPiece(const std::pair<int, int> coords) const; // get piece from given coordinates
    void movePiece(const std::pair<int, int> &fromCoords, const std::pair<int, int> &toCoords); // change coordinates of the piece

    // Function to make the logic more clear
    int getMoveLength(const std::pair<int, int> fromCoords, const std::pair<int, int> toCoords) const; // get lenght of move
    bool isOnBoard(const std::pair<int, int> coords) const; // check if move is inside the board
    bool isOccupied(const std::pair<int, int> coords) const; // check if smth is on the coordinates
    bool isOccupiedSameColor(const std::pair<int, int> fromCoords, const std::pair<int, int> toCoords) const; // check if place is occupied by the same color
    bool isOccupiedDifferentColor(const std::pair<int, int> fromCoords, const std::pair<int, int> toCoords) const; // check if place is occupied by the different color
    bool isVerticalMove(const std::pair<int, int> fromCoords, const std::pair<int, int> toCoords) const; // check if move is vertical (top to bottom or reverse)
    bool isHorizontalMove(const std::pair<int, int> fromCoords, const std::pair<int, int> toCoords) const; // check if move is horizontal (left to right or reverse)
    bool isDiagonalMove(const std::pair<int, int> fromCoords, const std::pair<int, int> toCoords) const; // check if move is diagonal (like bishop)
    bool isForwardMove(const std::pair<int, int> fromCoords, const std::pair<int, int> toCoords, const Piece* piece) const; // check if pawns (black or white) goes in a good way
    bool isPathClear(const std::pair<int, int> fromCoords, const std::pair<int, int> toCoords) const; // check if there is a piece between coordinates

    // Function to check if move is good - it's a connector to frontend
    bool isValidMove(const std::pair<int, int> &fromCoords, const std::pair<int, int> &toCoords); // check if the move is possible

    // Destructor
    //~Board();

private:
    std::map<std::pair<int, int>, std::unique_ptr<Square>> squares; // coordinates of single place on board
    std::unique_ptr<Piece> setPiece(const std::pair<int, int> &coords, std::unique_ptr<Piece> piece); // put a piece on a square, part of preparation which is below

    // Prepare game
    void prepSquares();
    void createPawns();
    void createRooks();
    void createKnights();
    void createBishops();
    void createQueens();
    void createKings();

};

#endif
