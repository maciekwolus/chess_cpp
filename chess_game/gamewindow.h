#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QDialog>
#include <QGraphicsScene>
#include <QString>
#include <QDebug>
#include <QMainWindow>
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

    void board_setup(); // showing the board
    void pieces_setup(); // showing the pieces at the begining
    bool eventFilter(QObject *obj, QEvent *event); // catching all events on board
    //void grabPiece(QMouseEvent *event); // #TODO doing it now. its supposed to move the image of piece

private:
    Ui::GameWindow *ui; // something smart about frontend idk
    QGraphicsScene *Scene; // scene of board
    QList<pieceOnBoard *>  piecesOnBoardList; // list of pieces (frontend)
    bool mouse_btn_clicked = false; // to know whether the mouse button is clicked or no
};

#endif // GAMEWINDOW_H
