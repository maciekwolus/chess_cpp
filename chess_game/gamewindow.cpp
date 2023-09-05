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

    // debug test
    //qDebug() << "konsola dziala";

}

void GameWindow::board_setup()
{
    // SHOW THE BOARD
    Scene = new QGraphicsScene(this);
    Scene->addPixmap(QPixmap(":/resources/img/board.png"));
    ui->graphicsView->setScene(Scene);
}

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

bool GameWindow::eventFilter(QObject *obj, QEvent *event)
{
    if (QString(obj->metaObject()->className()) == "QWidgetWindow") // getting mouse move only from board
    {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);

        // Mouse button CLICK
        if (event->type() == QEvent::MouseButtonPress)
        {
            mouse_btn_clicked = true; // mouse is clicked
            startColumn = getColumnLetter(mouseEvent->pos().x()); // get column converted into letter
            startRow = getRowNumber(mouseEvent->pos().y()); // get row

            // Get the index of the piece at the specified coordinates
            piecePosition = getPieceIndex(piecesOnBoardList, getColumnPixel(startColumn), getRowPixel(startRow));

            if (piecePosition != -1)
            {
                isOnMove = true; // make visible that piece is moving
            }
        }

        // Mouse button UNCLICK
        else if (event->type() == QEvent::MouseButtonRelease)
        {
            mouse_btn_clicked = false; // mouse not clicked anymore
            endColumn = getColumnLetter(mouseEvent->pos().x());; // get column converted into letter
            endRow = getRowNumber(mouseEvent->pos().y()); // get row
            qDebug() << "endColumn" << endColumn;
            qDebug() << "endRow" << endRow;
            if (isOnMove == true)
            {
                pieceToDeletePosition = getPieceIndex(piecesOnBoardList, getColumnPixel(endColumn), getRowPixel(endRow));

                pieceOnBoard *pieceToMove = piecesOnBoardList[piecePosition]; // pointer to a piece to move
                pieceOnBoard *pieceToDelete; // pointer to a piece to delete (no value now as it might be empty)



                // Move piece into square when it's valid and move back when it's not
                if (board.castle(board.getColor(), giveCoordinates(startColumn, startRow), giveCoordinates(endColumn, endRow)) == true)
                {
                    pieceToMove->movePiecePicture(endColumn, endRow);
                    castleFrontent(piecesOnBoardList, giveCoordinates(startColumn, startRow), giveCoordinates(endColumn, endRow));
                }
                else if (board.movePiece(giveCoordinates(startColumn, startRow), giveCoordinates(endColumn, endRow)) == true)
                {
                    pieceToMove->movePiecePicture(endColumn, endRow);

// TODO Add function for below
                    // delete piece when it's captured
                    if (pieceToDeletePosition != -1 && (startColumn != endColumn || startRow != endRow))
                    {
                        pieceToDelete = piecesOnBoardList[pieceToDeletePosition]; // Not empty so there is a value
                        pieceToDelete->deleteImage(); // Delete image of piece
                        delete pieceToDelete; // Delete the object
                        piecesOnBoardList.erase(piecesOnBoardList.begin() + pieceToDeletePosition); // Remove it from the list
                    }
                }
                else
                {
                    pieceToMove->movePiecePicture(startColumn, startRow);
                }
                isOnMove = false; // piece is not moving
            }
        }

        // Mouse button MOVING CLICKED
        else if (event->type() == QEvent::MouseMove && mouse_btn_clicked == true && isOnMove == true) //clicked mouse button moving
        {
            piecesOnBoardList.at(piecePosition)->piecePictureIsMoving(mouseEvent->pos().x(), mouseEvent->pos().y());
        }
    }

    return QObject::eventFilter(obj, event);
}

char GameWindow::getColumnLetter(int x)
{
    return static_cast<char>((x - 100) / 100 + 'a');
}

int GameWindow::getRowNumber(int y)
{
    return 8 - (y - 100) / 100;
}

int GameWindow::getColumnPixel(char column)
{
    return (column - 'a') * 100;
}

int GameWindow::getRowPixel(int row)
{
    return (8 - row) * 100;
}

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
        pieceOnBoard *rookToMove = piecesOnBoardList[getPieceIndex(piecesOnBoardList, getColumnPixel('h'), getRowPixel(1))];
        rookToMove->movePiecePicture('f', 1);
    }
    // WHITE LONG
    else if (endCoordinates.first == 7 && endCoordinates.second == 2)
    {
        pieceOnBoard *rookToMove = piecesOnBoardList[getPieceIndex(piecesOnBoardList, getColumnPixel('a'), getRowPixel(1))];
        rookToMove->movePiecePicture('d', 1);
    }
    // BLACK SHORT
    else if (endCoordinates.first == 0 && endCoordinates.second == 6)
    {
        pieceOnBoard *rookToMove = piecesOnBoardList[getPieceIndex(piecesOnBoardList, getColumnPixel('h'), getRowPixel(8))];
        rookToMove->movePiecePicture('f', 8);
    }
    // BLACK LONG
    else if (endCoordinates.first == 0 && endCoordinates.second == 2)
    {
        pieceOnBoard *rookToMove = piecesOnBoardList[getPieceIndex(piecesOnBoardList, getColumnPixel('a'), getRowPixel(8))];
        rookToMove->movePiecePicture('d', 8);
    }
}

GameWindow::~GameWindow()
{
    delete ui;
}
