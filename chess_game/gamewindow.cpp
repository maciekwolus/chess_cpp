#include "gamewindow.h"
#include "ui_gamewindow.h"
#include <QPixmap>

GameWindow::GameWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);

    //LOAD THE PICTURE OF BOARD
    QPixmap board_pix(":/resources/img/board.png");
    int w = ui->board_pic->width();
    int h = ui->board_pic->height();
    ui->board_pic->setPixmap(board_pix.scaled(w,h,Qt::KeepAspectRatio));
}

GameWindow::~GameWindow()
{
    delete ui;
}
