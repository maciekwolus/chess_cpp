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
    // construcotr
    pieceOnBoard(char x, int y, int c, QString d, QGraphicsScene *s);

    void movePiecePicture(char x, int y); // function to move the graphic of piece
    void piecePictureIsMoving(int x, int y); // function to move the graphic of piece while the mouse is moving
    int giveXCoord(); // return x coordinate
    int giveYCoord(); // return y coordinate
    void deleteImage(); // deleting image

private:
    int xCoord, yCoord, color; // obvious variables
    QGraphicsPixmapItem *image; // visual representation of piece

signals:

};

#endif // BOARDPLACE_H
