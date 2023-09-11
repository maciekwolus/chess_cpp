#include "gamewindow.h"
#include "ui_gamewindow.h"

#include <iostream>
#include <QPixmap>
#include <QImage>
#include <QGraphicsPixmapItem>
#include <QString>
#include <QMouseEvent>
#include <QLabel>

/**
 * @brief GameWindow constructor.
 *
 * Constructs a GameWindow instance.
 *
 * @param parent The parent widget.
 */
GameWindow::GameWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    qApp->installEventFilter(this);

    // Prepare game setup
    board_setup();
    pieces_setup();
}

// BUTTONS FUNCTIONS

/**
 * @brief Slot for handling the "Exit" button click event.
 *
 * This slot is triggered when the "Exit" button is clicked, allowing the user to exit the game.
 */
void GameWindow::on_pushButton_exit_clicked()
{
    hide();
    confirmation_window = new ConfirmationWindow(this, EXIT_GAME);
    confirmation_window->show();
}

/**
 * @brief Slot for handling the "Restart" button click event.
 *
 * This slot is triggered when the "Restart" button is clicked, allowing the user to restart the game.
 */
void GameWindow::on_pushButton_restart_clicked()
{
    hide();
    confirmation_window = new ConfirmationWindow(this, RESTART_GAME);
    confirmation_window->show();
}

// PREPARE GAME FUNCTIONS

/**
 * @brief Prepare the game board for display.
 *
 * This function sets up the game board for display, including initializing the chessboard scene and adding the chessboard image.
 */
void GameWindow::board_setup()
{
    // SHOW THE BOARD
    Scene = new QGraphicsScene(this);
    Scene->addPixmap(QPixmap(":/resources/img/board.png"));
    ui->graphicsView->setScene(Scene);
}

/**
 * @brief Prepare pictures of chess pieces on the board (frontend).
 *
 * This function initializes and sets up the graphical representations of chess pieces on the game board.
 * It creates instances of `pieceOnBoard` for each chess piece and places them on the board scene.
 */
void GameWindow::pieces_setup()
{
    // CREATING LIST OF PIECES PICTURES
    // Pawns
    piecesOnBoardList.append(new pieceOnBoard('a',2,WHITE,QString(":/resources/img/white_pawn.png"), Scene));
    piecesOnBoardList.append(new pieceOnBoard('b',2,WHITE,QString(":/resources/img/white_pawn.png"), Scene));
    piecesOnBoardList.append(new pieceOnBoard('c',2,WHITE,QString(":/resources/img/white_pawn.png"), Scene));
    piecesOnBoardList.append(new pieceOnBoard('d',2,WHITE,QString(":/resources/img/white_pawn.png"), Scene));
    piecesOnBoardList.append(new pieceOnBoard('e',2,WHITE,QString(":/resources/img/white_pawn.png"), Scene));
    piecesOnBoardList.append(new pieceOnBoard('f',2,WHITE,QString(":/resources/img/white_pawn.png"), Scene));
    piecesOnBoardList.append(new pieceOnBoard('g',2,WHITE,QString(":/resources/img/white_pawn.png"), Scene));
    piecesOnBoardList.append(new pieceOnBoard('h',2,WHITE,QString(":/resources/img/white_pawn.png"), Scene));
    piecesOnBoardList.append(new pieceOnBoard('a',7,BLACK,QString(":/resources/img/black_pawn.png"), Scene));
    piecesOnBoardList.append(new pieceOnBoard('b',7,BLACK,QString(":/resources/img/black_pawn.png"), Scene));
    piecesOnBoardList.append(new pieceOnBoard('c',7,BLACK,QString(":/resources/img/black_pawn.png"), Scene));
    piecesOnBoardList.append(new pieceOnBoard('d',7,BLACK,QString(":/resources/img/black_pawn.png"), Scene));
    piecesOnBoardList.append(new pieceOnBoard('e',7,BLACK,QString(":/resources/img/black_pawn.png"), Scene));
    piecesOnBoardList.append(new pieceOnBoard('f',7,BLACK,QString(":/resources/img/black_pawn.png"), Scene));
    piecesOnBoardList.append(new pieceOnBoard('g',7,BLACK,QString(":/resources/img/black_pawn.png"), Scene));
    piecesOnBoardList.append(new pieceOnBoard('h',7,BLACK,QString(":/resources/img/black_pawn.png"), Scene));

    // Knights
    piecesOnBoardList.append(new pieceOnBoard('b',1,WHITE,QString(":/resources/img/white_knight.png"), Scene));
    piecesOnBoardList.append(new pieceOnBoard('g',1,WHITE,QString(":/resources/img/white_knight.png"), Scene));
    piecesOnBoardList.append(new pieceOnBoard('b',8,BLACK,QString(":/resources/img/black_knight.png"), Scene));
    piecesOnBoardList.append(new pieceOnBoard('g',8,BLACK,QString(":/resources/img/black_knight.png"), Scene));

    // Rooks
    piecesOnBoardList.append(new pieceOnBoard('a',1,WHITE,QString(":/resources/img/white_rook.png"), Scene));
    piecesOnBoardList.append(new pieceOnBoard('h',1,WHITE,QString(":/resources/img/white_rook.png"), Scene));
    piecesOnBoardList.append(new pieceOnBoard('a',8,BLACK,QString(":/resources/img/black_rook.png"), Scene));
    piecesOnBoardList.append(new pieceOnBoard('h',8,BLACK,QString(":/resources/img/black_rook.png"), Scene));

    // Bishops
    piecesOnBoardList.append(new pieceOnBoard('c',1,WHITE,QString(":/resources/img/white_bishop.png"), Scene));
    piecesOnBoardList.append(new pieceOnBoard('f',1,WHITE,QString(":/resources/img/white_bishop.png"), Scene));
    piecesOnBoardList.append(new pieceOnBoard('c',8,BLACK,QString(":/resources/img/black_bishop.png"), Scene));
    piecesOnBoardList.append(new pieceOnBoard('f',8,BLACK,QString(":/resources/img/black_bishop.png"), Scene));

    // Queens
    piecesOnBoardList.append(new pieceOnBoard('d',1,WHITE,QString(":/resources/img/white_queen.png"), Scene));
    piecesOnBoardList.append(new pieceOnBoard('d',8,BLACK,QString(":/resources/img/black_queen.png"), Scene));

    // Kings
    piecesOnBoardList.append(new pieceOnBoard('e',1,WHITE,QString(":/resources/img/white_king.png"), Scene));
    piecesOnBoardList.append(new pieceOnBoard('e',8,BLACK,QString(":/resources/img/black_king.png"), Scene));
}

/**
 * @brief Event filter to handle mouse events on the game board.
 *
 * This function filters and handles mouse events on the game board. It is responsible for managing
 * the piece movement, capturing, and checking for game-ending conditions.
 *
 * @param obj The QObject triggering the event.
 * @param event The QEvent representing the mouse event.
 * @return True if the event was handled, otherwise false.
 */
bool GameWindow::eventFilter(QObject *obj, QEvent *event)
{
    if (QString(obj->metaObject()->className()) == "QWidgetWindow") // Getting mouse move only from the board
    {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);

        // Mouse button CLICK
        if (event->type() == QEvent::MouseButtonPress)
        {
            mouse_btn_clicked = true; // Mouse is clicked
            startColumn = getColumnLetter<int>(mouseEvent->pos().x()); // Get column converted into a letter
            startRow = getRowNumber<int>(mouseEvent->pos().y()); // Get row

            // Get the index of the piece at the specified coordinates
            piecePosition = getPieceIndex(piecesOnBoardList, getColumnPixel<int>(startColumn), getRowPixel<int>(startRow));

            if (piecePosition != -1)
            {
                isOnMove = true; // Make it visible that a piece is moving
            }
        }

        // Mouse button UNCLICK
        else if (event->type() == QEvent::MouseButtonRelease)
        {
            mouse_btn_clicked = false; // Mouse is not clicked anymore
            endColumn = getColumnLetter<int>(mouseEvent->pos().x()); // Get column converted into a letter
            endRow = getRowNumber<int>(mouseEvent->pos().y()); // Get row

            if (isOnMove == true)
            {
                pieceToDeletePosition = getPieceIndex(piecesOnBoardList, getColumnPixel<int>(endColumn), getRowPixel<int>(endRow)); // Index of piece to delete when captured

                pieceOnBoard *pieceToMove = piecesOnBoardList[piecePosition]; // Pointer to a piece to move
                pieceOnBoard *pieceToDelete; // Pointer to a piece to delete (no value now as it might be empty)

                // Coordinates to give to the backend
                std::pair<int, int> startCoordinates = giveCoordinates(startColumn, startRow);
                std::pair<int, int> endCoordinates = giveCoordinates(endColumn, endRow);

                // Check if the piece has the correct color
                if (board.checkPieceColor(startCoordinates))
                {
                    // Move the piece into a square when it's valid and move back when it's not
                    if (board.castle(board.getColor(), startCoordinates, endCoordinates))
                    {
                        pieceToMove->movePiecePicture(endColumn, endRow);
                        board.switchColor(); // Switching the color which will move next
                        castleFrontent(piecesOnBoardList, startCoordinates, endCoordinates);
                    }
                    else if (board.movePiece(startCoordinates, endCoordinates))
                    {
                        pieceToMove->movePiecePicture(endColumn, endRow);
                        board.switchColor(); // Switching the color which will move next

                        // Delete the piece when it's captured
                        if (pieceToDeletePosition != -1 && (startColumn != endColumn || startRow != endRow))
                        {
                            pieceToDelete = piecesOnBoardList[pieceToDeletePosition]; // Not empty, so there is a value
                            pieceToDelete->deleteImage(); // Delete the image of the piece
                            delete pieceToDelete; // Delete the object
                            piecesOnBoardList.erase(piecesOnBoardList.begin() + pieceToDeletePosition); // Remove it from the list
                        }

                        if (board.promotePawn(board.getColor(), endCoordinates))
                        {
                            qDebug() << "PROMOCJA FRONT";
                        }
                    }
                    // No valid move
                    else
                    {
                        pieceToMove->movePiecePicture(startColumn, startRow);
                    }
                }
                // Wrong color
                else
                {
                    pieceToMove->movePiecePicture(startColumn, startRow);
                }
                isOnMove = false; // Piece is not moving
            }
            // Check for game ending
            endGame();
        }

        // Mouse button MOVING CLICKED
        else if (event->type() == QEvent::MouseMove && mouse_btn_clicked == true && isOnMove == true) // Clicked mouse button moving
        {
            piecesOnBoardList.at(piecePosition)->piecePictureIsMoving(mouseEvent->pos().x(), mouseEvent->pos().y());
        }
    }

    return QObject::eventFilter(obj, event);
}

/**
 * @brief Convert an integer to a column letter.
 *
 * This template function converts an integer value representing a column on the chessboard
 * to the corresponding column letter.
 *
 * @tparam T The return type (e.g., char for column letter).
 * @param x The integer value representing the column.
 * @return The column letter corresponding to the integer value.
 */
template<typename T>
T GameWindow::getColumnLetter(int x)
{
    return static_cast<T>((x - 100) / 100 + 'a');
}

/**
 * @brief Convert a Y-coordinate to a row number.
 *
 * This template function converts a Y-coordinate value on the chessboard
 * to the corresponding row number.
 *
 * @tparam T The return type (e.g., int for row number).
 * @param y The Y-coordinate value.
 * @return The row number corresponding to the Y-coordinate.
 */
template<typename T>
T GameWindow::getRowNumber(int y)
{
    return static_cast<T>(8 - (y - 100) / 100);
}

/**
 * @brief Convert a column letter to an integer coordinate.
 *
 * This template function converts a column letter to the corresponding integer
 * coordinate on the chessboard.
 *
 * @tparam T The return type (e.g., int for integer coordinate).
 * @param column The column letter (e.g., 'a', 'b', ...).
 * @return The integer coordinate corresponding to the column letter.
 */
template<typename T>
T GameWindow::getColumnPixel(char column)
{
    return static_cast<T>((column - 'a') * 100);
}

/**
 * @brief Convert a row number to a Y-coordinate.
 *
 * This template function converts a row number to the corresponding Y-coordinate
 * on the chessboard.
 *
 * @tparam T The return type (e.g., int for Y-coordinate).
 * @param row The row number.
 * @return The Y-coordinate corresponding to the row number.
 */
template<typename T>
T GameWindow::getRowPixel(int row)
{
    return static_cast<T>((8 - row) * 100);
}

/**
 * @brief Get the index of a piece from a list based on its coordinates.
 *
 * This function searches for a piece in the provided list of pieces based on its X and Y coordinates.
 * If found, it returns the index of the piece; otherwise, it returns -1.
 *
 * @param piecesOnBoardList The list of pieces to search in.
 * @param x The X-coordinate of the piece.
 * @param y The Y-coordinate of the piece.
 * @return The index of the found piece or -1 if not found.
 */
int GameWindow::getPieceIndex(QList<pieceOnBoard *> piecesOnBoardList, int x, int y)
{
    for (int i = 0; i < piecesOnBoardList.size(); ++i)
    {
        pieceOnBoard* piece = piecesOnBoardList.at(i);
        if (piece->giveXCoord() == x && piece->giveYCoord() == y)
        {
            return i; // Return the index of the found piece
        }
    }
    return -1; // Return -1 if no piece was found
}

/**
 * @brief Convert integer coordinates to a pair for backend use.
 *
 * This function converts integer coordinates (column and row) into a std::pair
 * suitable for passing to the backend logic.
 *
 * @param x The X-coordinate (column).
 * @param y The Y-coordinate (row).
 * @return A std::pair representing the coordinates.
 */
std::pair<int, int> GameWindow::giveCoordinates(char x, int y)
{
    return std::make_pair(8 - y, x - 97);
}

/**
 * @brief Update the frontend representation of castling.
 *
 * This function updates the frontend representation of castling when it occurs in the game.
 * It adjusts the position of the rook picture accordingly based on the start and end coordinates.
 *
 * @param piecesOnBoardList The list of pieces on the board (frontend).
 * @param startCoordinates The starting coordinates of the castling move.
 * @param endCoordinates The ending coordinates of the castling move.
 */
void GameWindow::castleFrontent(QList<pieceOnBoard *> piecesOnBoardList, std::pair<int, int> startCoordinates, std::pair<int, int> endCoordinates)
{
    // WHITE SHORT
    if (endCoordinates.first == 7 && endCoordinates.second == 6)
    {
        pieceOnBoard *rookToMove = piecesOnBoardList[getPieceIndex(piecesOnBoardList, getColumnPixel<int>('h'), getRowPixel<int>(1))];
        rookToMove->movePiecePicture('f', 1);
    }
    // WHITE LONG
    else if (endCoordinates.first == 7 && endCoordinates.second == 2)
    {
        pieceOnBoard *rookToMove = piecesOnBoardList[getPieceIndex(piecesOnBoardList, getColumnPixel<int>('a'), getRowPixel<int>(1))];
        rookToMove->movePiecePicture('d', 1);
    }
    // BLACK SHORT
    else if (endCoordinates.first == 0 && endCoordinates.second == 6)
    {
        pieceOnBoard *rookToMove = piecesOnBoardList[getPieceIndex(piecesOnBoardList, getColumnPixel<int>('h'), getRowPixel<int>(8))];
        rookToMove->movePiecePicture('f', 8);
    }
    // BLACK LONG
    else if (endCoordinates.first == 0 && endCoordinates.second == 2)
    {
        pieceOnBoard *rookToMove = piecesOnBoardList[getPieceIndex(piecesOnBoardList, getColumnPixel<int>('a'), getRowPixel<int>(8))];
        rookToMove->movePiecePicture('d', 8);
    }
}

/**
 * @brief Handle the end of the game.
 *
 * This function checks if the game has ended (either in checkmate or stalemate) and takes appropriate actions.
 * It saves the game moves to a file, asks if the player wants to play again, and resets the board for the next game.
 */
void GameWindow::endGame()
{
    if (board.endGame(board.getColor()))
    {
        // Save moves
        board.saveMoves();

        // Ask if the player still wants to play
        hide(); // Hide the board
        if (board.isInCheckMate(board.getColor())) // Communicate to set the message on the next window
        {
            if (board.getColor() == WHITE)
            {
                confirmation_window = new ConfirmationWindow(this, BLACK_WON);
            }
            else if (board.getColor() == BLACK)
            {
                confirmation_window = new ConfirmationWindow(this, WHITE_WON);
            }
        }

        if (board.isInStalemate(board.getColor()))
        {
            confirmation_window = new ConfirmationWindow(this, STALEMATE);
        }
        boardRestart(); // Reset the board for the next game
        confirmation_window->show(); // Show the next window
    }
}

/**
 * @brief Reset board settings for the next game.
 *
 * This function resets the board settings for the next game by creating a new instance of the Board class.
 */
void GameWindow::boardRestart()
{
    board = Board();
}

/**
 * @brief Destructor for the GameWindow class.
 *
 * This function is the destructor for the GameWindow class and is responsible for cleaning up resources.
 */
GameWindow::~GameWindow()
{
    delete ui;
}

