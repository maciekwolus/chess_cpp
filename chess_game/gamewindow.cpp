#include "gamewindow.h"
#include "ui_gamewindow.h"

#include <iostream>
#include <QPixmap>
#include <QImage>
#include <QGraphicsPixmapItem>
#include <QString>
#include <QMouseEvent>
#include <QLabel>

GameWindow::GameWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    qApp->installEventFilter(this);

    // prepare game setup
    board_setup();
    pieces_setup();
}

// BUTTONS FUNCIOTNS
// Button to exit the game (before making sure button)
void GameWindow::on_pushButton_exit_clicked()
{
    hide();
    confirmation_window = new ConfirmationWindow(this, EXIT_GAME);
    confirmation_window->show();
}

// Button to restart the game (before making sure button)
void GameWindow::on_pushButton_restart_clicked()
{
    hide();
    confirmation_window = new ConfirmationWindow(this, RESTART_GAME);
    confirmation_window->show();
}


// PREPARE GAME FUNCTIONS
// Prepare board
void GameWindow::board_setup()
{
    // SHOW THE BOARD
    Scene = new QGraphicsScene(this);
    Scene->addPixmap(QPixmap(":/resources/img/board.png"));
    ui->graphicsView->setScene(Scene);
}

// Prepare picutres of pieces on board (frontend)
void GameWindow::pieces_setup()
{
    // CREATING LIST OF PIECES PICTURES
    // pawns
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
    // knights
    piecesOnBoardList.append(new pieceOnBoard('b',1,WHITE,QString(":/resources/img/white_knight.png"), Scene));
    piecesOnBoardList.append(new pieceOnBoard('g',1,WHITE,QString(":/resources/img/white_knight.png"), Scene));
    piecesOnBoardList.append(new pieceOnBoard('b',8,BLACK,QString(":/resources/img/black_knight.png"), Scene));
    piecesOnBoardList.append(new pieceOnBoard('g',8,BLACK,QString(":/resources/img/black_knight.png"), Scene));
    // rooks
    piecesOnBoardList.append(new pieceOnBoard('a',1,WHITE,QString(":/resources/img/white_rook.png"), Scene));
    piecesOnBoardList.append(new pieceOnBoard('h',1,WHITE,QString(":/resources/img/white_rook.png"), Scene));
    piecesOnBoardList.append(new pieceOnBoard('a',8,BLACK,QString(":/resources/img/black_rook.png"), Scene));
    piecesOnBoardList.append(new pieceOnBoard('h',8,BLACK,QString(":/resources/img/black_rook.png"), Scene));
    // bishops
    piecesOnBoardList.append(new pieceOnBoard('c',1,WHITE,QString(":/resources/img/white_bishop.png"), Scene));
    piecesOnBoardList.append(new pieceOnBoard('f',1,WHITE,QString(":/resources/img/white_bishop.png"), Scene));
    piecesOnBoardList.append(new pieceOnBoard('c',8,BLACK,QString(":/resources/img/black_bishop.png"), Scene));
    piecesOnBoardList.append(new pieceOnBoard('f',8,BLACK,QString(":/resources/img/black_bishop.png"), Scene));
    // queens
    piecesOnBoardList.append(new pieceOnBoard('d',1,WHITE,QString(":/resources/img/white_queen.png"), Scene));
    piecesOnBoardList.append(new pieceOnBoard('d',8,BLACK,QString(":/resources/img/black_queen.png"), Scene));
    // kings
    piecesOnBoardList.append(new pieceOnBoard('e',1,WHITE, QString(":/resources/img/white_king.png"), Scene));
    piecesOnBoardList.append(new pieceOnBoard('e',8,BLACK,QString(":/resources/img/black_king.png"), Scene));
}

// WORKING GAME FUNCTIONS
// Event filter to catch what mouse do on screen
bool GameWindow::eventFilter(QObject *obj, QEvent *event)
{
    if (QString(obj->metaObject()->className()) == "QWidgetWindow") // getting mouse move only from board
    {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);

        // Mouse button CLICK
        if (event->type() == QEvent::MouseButtonPress)
        {
            mouse_btn_clicked = true; // mouse is clicked
            startColumn = getColumnLetter<int>(mouseEvent->pos().x()); // get column converted into letter
            startRow = getRowNumber<int>(mouseEvent->pos().y()); // get row

            // Get the index of the piece at the specified coordinates
            piecePosition = getPieceIndex(piecesOnBoardList, getColumnPixel<int>(startColumn), getRowPixel<int>(startRow));

            if (piecePosition != -1)
            {
                isOnMove = true; // make visible that piece is moving
            }
        }

        // Mouse button UNCLICK
        else if (event->type() == QEvent::MouseButtonRelease)
        {
            mouse_btn_clicked = false; // mouse not clicked anymore
            endColumn = getColumnLetter<int>(mouseEvent->pos().x());; // get column converted into letter
            endRow = getRowNumber<int>(mouseEvent->pos().y()); // get row

            if (isOnMove == true)
            {
                pieceToDeletePosition = getPieceIndex(piecesOnBoardList, getColumnPixel<int>(endColumn), getRowPixel<int>(endRow)); //index of piece to delete when captured

                pieceOnBoard *pieceToMove = piecesOnBoardList[piecePosition]; // pointer to a piece to move
                pieceOnBoard *pieceToDelete; // pointer to a piece to delete (no value now as it might be empty)

                // Coordinates to give to backend
                std::pair<int, int> startCoordinates = giveCoordinates(startColumn, startRow);
                std::pair<int, int> endCoordinates = giveCoordinates(endColumn, endRow);

                //Check if piece has good color
                if (board.checkPieceColor(startCoordinates))
                {
                    // Move piece into square when it's valid and move back when it's not
                    if (board.castle(board.getColor(), startCoordinates, endCoordinates))
                    {
                        pieceToMove->movePiecePicture(endColumn, endRow);
                        board.switchColor(); // switching color which will move next
                        castleFrontent(piecesOnBoardList, startCoordinates, endCoordinates);
                    }
                    else if (board.movePiece(startCoordinates, endCoordinates))
                    {
                        pieceToMove->movePiecePicture(endColumn, endRow);
                        board.switchColor(); // switching color which will move next

                        // delete piece when it's captured
                        if (pieceToDeletePosition != -1 && (startColumn != endColumn || startRow != endRow))
                        {
                            pieceToDelete = piecesOnBoardList[pieceToDeletePosition]; // Not empty so there is a value
                            pieceToDelete->deleteImage(); // Delete image of piece
                            delete pieceToDelete; // Delete the object
                            piecesOnBoardList.erase(piecesOnBoardList.begin() + pieceToDeletePosition); // Remove it from the list
                        }
                    }
                    // no valid move
                    else
                    {
                        pieceToMove->movePiecePicture(startColumn, startRow);
                    }
                }
                // Color is wrong
                else
                {
                    pieceToMove->movePiecePicture(startColumn, startRow);
                }
                isOnMove = false; // piece is not moving
            }
            // Game ending
            endGame();
        }

        // Mouse button MOVING CLICKED
        else if (event->type() == QEvent::MouseMove && mouse_btn_clicked == true && isOnMove == true) //clicked mouse button moving
        {
            piecesOnBoardList.at(piecePosition)->piecePictureIsMoving(mouseEvent->pos().x(), mouseEvent->pos().y());
        }
    }

    return QObject::eventFilter(obj, event);
}

// Return letter after giving an int (e.g.. when 0 then a)
template<typename T>
T GameWindow::getColumnLetter(int x)
{
    return static_cast<T>((x - 100) / 100 + 'a');
}

// Return the given row number of board
template<typename T>
T GameWindow::getRowNumber(int y)
{
    return static_cast<T>(8 - (y - 100) / 100);
}

// Return column number of that small square on board
template<typename T>
T GameWindow::getColumnPixel(char column)
{
    return static_cast<T>((column - 'a') * 100);
}


// Return row number of that small square on board
template<typename T>
T GameWindow::getRowPixel(int row)
{
    return static_cast<T>((8 - row) * 100);
}


// Return image piece index from list
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

// Convert int coordinates into a pair to give it into backend
std::pair<int, int> GameWindow::giveCoordinates(char x, int y)
{
    return std::make_pair(8 - y, x - 97);
}

// Make castling on frontend
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

// Function to end game
void GameWindow::endGame()
{
    if (board.endGame(board.getColor()))
    {
        // Save moves
        board.saveMoves();

        // Ask if player still want to play
        hide(); // hide board
        if (board.isInCheckMate(board.getColor())) // comunicates to set the massege on the next window
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
        boardRestart(); // reset board in case of next game
        confirmation_window->show(); // show the next window
    }
}

// Function to restart board settings
void GameWindow::boardRestart()
{
    board = Board();
}

// Destructor
GameWindow::~GameWindow()
{
    delete ui;
}
