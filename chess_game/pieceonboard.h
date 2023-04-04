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
    pieceOnBoard(int x, int y, int c, QString d, QGraphicsScene *s); // constructor
    void movePiecePicture(int x, int y); // function to move the graphic of piece

private:
    int xCoord, yCoord, color; // obvious variables
    QGraphicsPixmapItem *image; // visual representation of piece

signals:

};

#endif // BOARDPLACE_H
