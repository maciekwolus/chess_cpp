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
    char getColumnLetter(int x); // gives a letter of column
    int getRowNumber(int y); // gives a number of a row
    int getColumnPixel(char column); // gives a spot of column
    int getRowPixel(int row); // gives a spot of column
    int getPieceIndex(QList<pieceOnBoard *>& piecesOnBoardList, int x, int y); // gives piece index

private:
    Ui::GameWindow *ui; // something smart about frontend idk
    QGraphicsScene *Scene; // scene of board
    QList<pieceOnBoard *>  piecesOnBoardList; // list of pieces (frontend)
    bool mouse_btn_clicked = false; // to know whether the mouse button is clicked or no
    char startColumn, endColumn; // columns of the move
    int startRow, endRow; // row of the move
    int piecePosition, pieceToDeletePosition; // position of element in the pieces list
    bool isOnMove = false; // variable to check if element is moving
};

#endif // GAMEWINDOW_H
