#ifndef BOARD_H
#define BOARD_H

#include <map>
#include <memory>
#include <vector>
#include "square.h"

/**
 * @brief The Board class represents the backend logic of a chessboard.
 */
class Board {
public:
    /**
     * @brief Constructs a new Board object.
     */
    Board();

    /**
     * @brief Converts algebraic coordinates to integer coordinates.
     *
     * @param algebraicCoords The algebraic coordinates to convert (e.g., "a8").
     * @return A pair of integers representing the converted coordinates (e.g., <0,0>).
     */
    std::pair<int, int> algebraicToInt(std::string algebraicCoords) const;

    /**
     * @brief Switches the current player's turn (color).
     */
    void switchColor();

    /**
     * @brief Retrieves the piece at the given coordinates.
     *
     * @param coords The coordinates of the square.
     * @return A pointer to the piece at the specified coordinates, or nullptr if no piece is present.
     */
    Piece* getPiece(const std::pair<int, int> coords) const;

    /**
     * @brief Calculates the length of a move from one set of coordinates to another.
     *
     * @param fromCoords The starting coordinates.
     * @param toCoords The destination coordinates.
     * @return The length of the move.
     */
    int getMoveLength(const std::pair<int, int> fromCoords, const std::pair<int, int> toCoords) const;

    /**
     * @brief Checks if the specified coordinates are within the bounds of the chessboard.
     *
     * @param coords The coordinates to check.
     * @return true if the coordinates are on the board; false otherwise.
     */
    bool isOnBoard(const std::pair<int, int> coords) const;

    /**
     * @brief Checks if the specified coordinates are occupied by a piece.
     *
     * @param coords The coordinates to check.
     * @return true if the coordinates are occupied; false otherwise.
     */
    bool isOccupied(const std::pair<int, int> coords) const;

    /**
     * @brief Checks if the specified coordinates are occupied by a piece of the same color.
     *
     * @param fromCoords The starting coordinates.
     * @param toCoords The destination coordinates.
     * @return true if the coordinates are occupied by a piece of the same color; false otherwise.
     */
    bool isOccupiedSameColor(const std::pair<int, int> fromCoords, const std::pair<int, int> toCoords) const;

    /**
     * @brief Checks if the specified coordinates are occupied by a piece of a different color.
     *
     * @param fromCoords The starting coordinates.
     * @param toCoords The destination coordinates.
     * @return true if the coordinates are occupied by a piece of a different color; false otherwise.
     */
    bool isOccupiedDifferentColor(const std::pair<int, int> fromCoords, const std::pair<int, int> toCoords) const;

    /**
     * @brief Checks if a move is vertical (top to bottom or reverse).
     *
     * @param fromCoords The starting coordinates.
     * @param toCoords The destination coordinates.
     * @return true if the move is vertical; false otherwise.
     */
    bool isVerticalMove(const std::pair<int, int> fromCoords, const std::pair<int, int> toCoords) const;

    /**
     * @brief Checks if a move is horizontal (left to right or reverse).
     *
     * @param fromCoords The starting coordinates.
     * @param toCoords The destination coordinates.
     * @return true if the move is horizontal; false otherwise.
     */
    bool isHorizontalMove(const std::pair<int, int> fromCoords, const std::pair<int, int> toCoords) const;

    /**
     * @brief Checks if a move is diagonal (like that of a bishop).
     *
     * @param fromCoords The starting coordinates.
     * @param toCoords The destination coordinates.
     * @return true if the move is diagonal; false otherwise.
     */
    bool isDiagonalMove(const std::pair<int, int> fromCoords, const std::pair<int, int> toCoords) const;

    /**
     * @brief Checks if a move is forward for a pawn (black or white).
     *
     * @param fromCoords The starting coordinates.
     * @param toCoords The destination coordinates.
     * @param piece The piece making the move.
     * @return true if the move is forward; false otherwise.
     */
    bool isForwardMove(const std::pair<int, int> fromCoords, const std::pair<int, int> toCoords, const Piece* piece) const;

    /**
     * @brief Checks if the path between two coordinates is clear of pieces.
     *
     * @param fromCoords The starting coordinates.
     * @param toCoords The destination coordinates.
     * @return true if the path is clear; false otherwise.
     */
    bool isPathClear(const std::pair<int, int> fromCoords, const std::pair<int, int> toCoords) const;

    /**
     * @brief Checks if a move from one set of coordinates to another is a valid move.
     *
     * @param fromCoords The starting coordinates.
     * @param toCoords The destination coordinates.
     * @return true if the move is possible; false otherwise.
     */
    bool isValidMove(const std::pair<int, int> &fromCoords, const std::pair<int, int> &toCoords) const;

    /**
     * @brief Forces a piece to move from one set of coordinates to another without checking for validity.
     *
     * @param fromCoords The starting coordinates.
     * @param toCoords The destination coordinates.
     */
    void forceMovePiece(const std::pair<int, int> fromCoords, const std::pair<int, int> toCoords);

    /**
     * @brief Reverts the last move, undoing it.
     */
    void revertLastMove();

    /**
     * @brief Checks if the piece at the specified coordinates has the same color as given.
     *
     * @param fromCoords The coordinates of the piece to check.
     * @return true if the piece has the same color as given; false otherwise.
     */
    bool checkPieceColor(const std::pair<int, int> fromCoords) const;

    /**
     * @brief Retrieves the current timestamp as a string.
     *
     * @return The current timestamp as a string.
     */
    std::string getCurrentTimestamp();

    /**
     * @brief Saves the moves made in the game.
     */
    void saveMoves();

    /**
     * @brief Retrieves the current player's color.
     *
     * @return The color of the current player.
     */
    Color getColor();

    /**
     * @brief Moves a piece from one set of coordinates to another, checking for validity.
     *
     * @param fromCoords The starting coordinates.
     * @param toCoords The destination coordinates.
     * @return true if the move is successful; false otherwise.
     */
    bool movePiece(const std::pair<int, int> &fromCoords, const std::pair<int, int> &toCoords);

    /**
     * @brief Castles the king under certain conditions.
     *
     * @param toMove The color of the player to move.
     * @param from The starting coordinates of the move.
     * @param to The destination coordinates of the move.
     * @return true if the castling is successful; false otherwise.
     */
    bool castle(Color toMove, std::pair<int, int> from, std::pair<int, int> to);

    /**
     * @brief Promote pawn to a queen if it goes to the end of board.
     *
     * @param toMove The color of the player to move.
     * @param coordinates The coordinates of the piece.
     * @return true if it is the pawn to promote; false otherwise.
     */
    bool promotePawn(Color toMove, std::pair<int, int> coordinates);

    /**
     * @brief Ends the game when it's checkmate or stalemate.
     *
     * @param toMove The color of the player to move.
     * @return true if the game has ended; false otherwise.
     */
    bool endGame(Color toMove);

    /**
     * @brief Retrieves the locations of pieces of the specified color.
     *
     * @param color The color of the pieces to retrieve.
     * @return A vector of pairs representing the locations of pieces of the specified color.
     */
    std::vector<std::pair<int,int>> getPieceLocations(Color color) const;

    /**
     * @brief Retrieves the location of the king of the specified color.
     *
     * @param color The color of the king to retrieve.
     * @return The coordinates of the king.
     */
    std::pair<int,int> getKingLocation(Color color) const;

    /**
     * @brief Retrieves the locations of all pieces on the board.
     *
     * @return A vector of pairs representing the locations of all pieces on the board.
     */
    std::vector<std::pair<int,int>> getLocations() const;

    /**
     * @brief Checks if the defending color is in check.
     *
     * @param defendingColor The color to check for check.
     * @return true if the defending color is in check; false otherwise.
     */
    bool isInCheck(Color defendingColor) const;

    /**
     * @brief Checks if the defending color is in checkmate.
     *
     * @param defendingColor The color to check for checkmate.
     * @return true if the defending color is in checkmate; false otherwise.
     */
    bool isInCheckMate(Color defendingColor);

    /**
     * @brief Checks if the defending color is in stalemate.
     *
     * @param defendingColor The color to check for stalemate.
     * @return true if the defending color is in stalemate; false otherwise.
     */
    bool isInStalemate(Color defendingColor);

    // Destructor
    //~Board();

private:
    /**
      * @brief Coordinates of single squares on the board.
      */
     std::map<std::pair<int, int>, std::unique_ptr<Square>> squares;

     /**
      * @brief List of moves made.
      */
     std::vector<std::pair<std::pair<int, int>,std::pair<int, int>>> moves;

     /**
      * @brief List of captured pieces.
      */
     std::map<int, std::unique_ptr<Piece>> capturedPieces;

     /**
      * @brief Puts a piece on a square (part of the board setup).
      *
      * @param coords The coordinates to place the piece.
      * @param piece The piece to place.
      * @return A pointer to the placed piece.
      */
     std::unique_ptr<Piece> setPiece(const std::pair<int, int> &coords, std::unique_ptr<Piece> piece);

     /**
      * @brief Starting color.
      */
     Color colorTurn = WHITE;

     // Prepare the game
     /**
      * @brief Initializes the squares on the board.
      */
     void prepSquares();

     /**
      * @brief Creates pawn pieces on the board.
      */
     void createPawns();

     /**
      * @brief Creates rook pieces on the board.
      */
     void createRooks();

     /**
      * @brief Creates knight pieces on the board.
      */
     void createKnights();

     /**
      * @brief Creates bishop pieces on the board.
      */
     void createBishops();

     /**
      * @brief Creates queen pieces on the board.
      */
     void createQueens();

     /**
      * @brief Creates king pieces on the board.
      */
     void createKings();
};

#endif
