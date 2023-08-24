#ifndef BOARDPLACE_H
#define BOARDPLACE_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QString>
#include <QPixmap>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QPointF>

class pieceOnBoard : public QObject
{
    Q_OBJECT
public:
    pieceOnBoard(char x, int y, int c, QString d, QGraphicsScene *s); // constructor
    void movePiecePicture(char x, int y); // function to move the graphic of piece
    int giveXCoord(); // return x coordinate
    int giveYCoord(); // return y coordinate

private:
    int xCoord, yCoord, color; // obvious variables
    QGraphicsPixmapItem *image; // visual representation of piece

signals:

};

#endif // BOARDPLACE_H
