#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QDialog>
#include <QGraphicsScene>
#include <QString>
#include <QDebug>
#include <QMainWindow>
#include "pieceonboard.h"
#include "board.h"
#include "confirmationwindow.h"

namespace Ui {
class GameWindow;
}

/**
 * @brief Represents the main game window for a chess game.
 *
 * This class is responsible for displaying the chessboard, handling user input, and controlling the game logic.
 * It also provides functions for setting up the initial game state, managing pieces, and ending the game.
 */
class GameWindow : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Constructs a GameWindow object.
     *
     * @param parent The parent widget (if any).
     */
    explicit GameWindow(QWidget *parent = nullptr);

    /**
     * @brief Destroys the GameWindow object.
     */
    ~GameWindow();

    /**
     * @brief Sets up the chessboard for display.
     *
     * This function initializes and displays the chessboard on the user interface.
     */
    void board_setup();

    /**
     * @brief Sets up the initial positions of chess pieces on the board.
     *
     * This function displays the chess pieces on the board at the beginning of the game.
     */
    void pieces_setup();

    /**
     * @brief Event filter to catch all events on the board.
     *
     * This function filters and handles events on the chessboard, allowing the game to respond to user input.
     *
     * @param obj The object that sent the event.
     * @param event The event being processed.
     * @return true if the event is handled; otherwise, false.
     */
    bool eventFilter(QObject *obj, QEvent *event);

    /**
     * @brief Template function to convert an integer column index to a letter representation.
     *
     * Given an integer column index, this function returns the corresponding letter representation (e.g., 0 -> 'A').
     *
     * @tparam T The type of the return value (e.g., char or QString).
     * @param x The column index.
     * @return The letter representation of the column.
     */
    template<typename T> T getColumnLetter(int x);

    /**
     * @brief Template function to convert an integer row index to a number representation.
     *
     * Given an integer row index, this function returns the corresponding number representation (e.g., 0 -> '1').
     *
     * @tparam T The type of the return value (e.g., char or QString).
     * @param y The row index.
     * @return The number representation of the row.
     */
    template<typename T> T getRowNumber(int y);

    /**
     * @brief Template function to convert a column character to a pixel position.
     *
     * Given a column character (e.g., 'A'), this function returns the corresponding pixel position on the board.
     *
     * @tparam T The type of the return value (e.g., int or qreal).
     * @param column The column character.
     * @return The pixel position of the column.
     */
    template<typename T> T getColumnPixel(char column);

    /**
     * @brief Template function to convert a row index to a pixel position.
     *
     * Given a row index (e.g., 0), this function returns the corresponding pixel position on the board.
     *
     * @tparam T The type of the return value (e.g., int or qreal).
     * @param row The row index.
     * @return The pixel position of the row.
     */
    template<typename T> T getRowPixel(int row);

    /**
     * @brief Get the index of a piece in the piecesOnBoardList.
     *
     * Given the x and y coordinates of a piece, this function returns the index of the piece
     * in the `piecesOnBoardList`.
     *
     * @param piecesOnBoardList The list of pieces on the board.
     * @param x The x-coordinate of the piece.
     * @param y The y-coordinate of the piece.
     * @return The index of the piece in the list, or -1 if not found.
     */
    int getPieceIndex(QList<pieceOnBoard *> piecesOnBoardList, int x, int y);

    /**
     * @brief Convert column and row characters to a pair of coordinates.
     *
     * Given a column character (e.g., 'A') and a row number (e.g., 1), this function
     * returns the corresponding pair of coordinates (x, y).
     *
     * @param x The column character.
     * @param y The row number.
     * @return A pair of coordinates (x, y).
     */
    std::pair<int, int> giveCoordinates(char x, int y);

    /**
     * @brief Perform castling at the frontend.
     *
     * This function visually performs castling on the chessboard, moving the king and rook accordingly.
     *
     * @param piecesOnBoardList The list of pieces on the board.
     * @param startCoordinates The starting coordinates of the move.
     * @param endCoordinates The ending coordinates of the move.
     */
    void castleFrontent(QList<pieceOnBoard *> piecesOnBoardList, std::pair<int, int> startCoordinates, std::pair<int, int> endCoordinates);

    /**
     * @brief End the game based on specific conditions.
     *
     * This function checks if the game should end based on certain conditions, such as checkmate or stalemate.
     * If the game ends, it may display a message to the user.
     */
    void endGame();

    /**
     * @brief Restart the chessboard and game settings.
     *
     * This function resets the chessboard and game settings to their initial state, allowing the players to start a new game.
     */
    void boardRestart();

    /**
     * @brief Connecting frontend to backend.
     *
     * This variable represents backend board and connect that to the frontend logic
     */
    Board board = Board();

private slots:
    /**
     * @brief Handler for the "Exit" button click event.
     *
     * This slot is triggered when the "Exit" button is clicked, allowing the user to exit the game.
     */
    void on_pushButton_exit_clicked();

    /**
     * @brief Handler for the "Restart" button click event.
     *
     * This slot is triggered when the "Restart" button is clicked, allowing the user to restart the game.
     */
    void on_pushButton_restart_clicked();

private:
    Ui::GameWindow *ui; ///< User interface elements
    ConfirmationWindow *confirmation_window; ///< Pointer to a confirmation window (for yes and no options)

    QGraphicsScene *Scene; ///< The scene for displaying the chessboard
    QList<pieceOnBoard *>  piecesOnBoardList; ///< List of chess pieces (frontend)
    bool mouse_btn_clicked = false; ///< Indicates whether the mouse button is clicked
    char startColumn, endColumn; ///< Columns of the move
    int startRow, endRow; ///< Rows of the move
    int piecePosition, pieceToDeletePosition; ///< Positions of elements in the pieces list
    bool isOnMove = false; ///< Indicates if a piece is currently being moved
};


#endif // GAMEWINDOW_H
