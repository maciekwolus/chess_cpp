#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QDialog>
#include <QGraphicsScene>
#include <QString>
#include <QDebug>
#include "pieceonboard.h"

namespace Ui {
class GameWindow;
}

enum Color
{
    WHITE,
    BLACK
};

class GameWindow : public QDialog
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = nullptr);
    ~GameWindow();

    void board_setup(); //showing the board
    void pieces_setup(); //showing the pieces at the begining
    void grabPiece(QMouseEvent *event);

private:
    Ui::GameWindow *ui;
    QGraphicsScene *Scene;
    QList<pieceOnBoard *>  piecesOnBoardList;
};

#endif // GAMEWINDOW_H
