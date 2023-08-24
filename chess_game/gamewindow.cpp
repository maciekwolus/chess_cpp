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
    qDebug() << "konsola dziala";

    // move of first piece
    //piecesOnBoardList.first()->movePiecePicture('c', 4);

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
        if (event->type() == QEvent::MouseButtonPress) //mouse button is clicked
        {
            QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event); // Cast the event to QMouseEvent
            mouse_btn_clicked = true;
            for (const auto& piece : piecesOnBoardList) {
                if (piece->giveXCoord() == (mouseEvent->pos().x()-100)/100*100 // X position on the screen
                        && piece->giveYCoord() == (mouseEvent->pos().y()-100)/100*100) // Y position on the screen
                {
                    qDebug() << "cos tu jest";
                    // Do something with the object that matches the criteria
                }
            }
        }
        else if (event->type() == QEvent::MouseButtonRelease) //mouse button unclicked
        {
            QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event); // Cast the event to QMouseEvent
            mouse_btn_clicked = false;
        }
        else if (event->type() == QEvent::MouseMove && mouse_btn_clicked == true) //mouse button moving
        {
            //QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
            //qDebug() << obj->metaObject()->className();
            //qDebug() << "(x,y): " << mouseEvent->pos();
            //qDebug() << "x: " << mouseEvent->pos().x(); // Print the message on the console
            //qDebug() << "y: " << mouseEvent->pos().y();

        }
    }

    return QObject::eventFilter(obj, event);
}


GameWindow::~GameWindow()
{
    delete ui;
}
