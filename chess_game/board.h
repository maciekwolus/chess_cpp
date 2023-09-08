#ifndef BOARD_H
#define BOARD_H

#include <map>
#include <memory>
#include <vector>
#include "square.h"

// Forward declaration to avoid circular dependency
class Piece;

// Board is a class to have a backend logic

class Board {
public:
    // Constructors
    Board();
    Board(bool Pawns, bool Knights, bool Rooks, bool Bishops, bool Queens, bool Kings);

    // Making code shorter
    std::pair<int, int> algebraicToInt(std::string algebraicCoords) const; // change letters to number, e.g. a8 to <0,0>
    void switchColor();

    // Function to make the logic more clear
    Piece* getPiece(const std::pair<int, int> coords) const; // get piece from given coordinates
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
    bool isValidMove(const std::pair<int, int> &fromCoords, const std::pair<int, int> &toCoords) const; // check if the move is possible
    void forceMovePiece(const std::pair<int, int> fromCoords, const std::pair<int, int> toCoords); // move piece without any checking (used to move rook in castle for example)
    void revertLastMove(); // undo last move (used to check if there is a check >.<)
    bool checkPieceColor(const std::pair<int, int> fromCoords) const; // check if piece has the same color as given

    // Function to save moves
    std::string getCurrentTimestamp(); // take timestamp to create and save to file
    void saveMoves(); // saves moves which was made

    // Function to check if move is good - it's a connector to frontend
    Color getColor();
    bool movePiece(const std::pair<int, int> &fromCoords, const std::pair<int, int> &toCoords); // change coordinates of the piece
    bool castle(Color toMove, std::pair<int, int> from, std::pair<int, int> to);
    bool endGame(Color toMove); // ends game when it checkmate or stealmate

    // Locations - might be useful for check, checkmate
    std::vector<std::pair<int,int>> getPieceLocations(Color color) const;
    std::pair<int,int> getKingLocation(Color color) const;
    std::vector<std::pair<int,int>> getLocations() const; // returns location of all pieces in vector

    // End game
    bool isInCheck(Color defendingColor) const; // check if check
    bool isInCheckMate(Color defendingColor); // check if checkmate
    bool isInStalemate(Color defendingColor); // check if stalemate

    // Destructor
    //~Board();

private:
    std::map<std::pair<int, int>, std::unique_ptr<Square>> squares; // coordinates of single place on board
    std::vector<std::pair<std::pair<int, int>,std::pair<int, int>>> moves; // list of moves made
    std::map<int, std::unique_ptr<Piece>> capturedPieces; // list of captured pieces
    std::unique_ptr<Piece> setPiece(const std::pair<int, int> &coords, std::unique_ptr<Piece> piece); // put a piece on a square, part of preparation which is below
    Color colorTurn = WHITE; // starting color

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
