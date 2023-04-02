#include "gamewindow.h"
#include "ui_gamewindow.h"
#include <QPixmap>
#include <QImage>
#include <QGraphicsPixmapItem>
#include <QString>

GameWindow::GameWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    board_setup();
    pieces_setup();
}

void GameWindow::board_setup()
{
    //SHOW THE BOARD
    Scene = new QGraphicsScene(this);
    Scene->addPixmap(QPixmap(":/resources/img/board.png"));
    ui->graphicsView->setScene(Scene);
}

void GameWindow::pieces_setup()
{
    pieceOnBoard whiteRook(0,700,QString(":/resources/img/white_rook.png"), Scene);
    pieceOnBoard blackPawn(400,100,QString(":/resources/img/black_pawn.png"), Scene);
}

GameWindow::~GameWindow()
{
    delete ui;
}
