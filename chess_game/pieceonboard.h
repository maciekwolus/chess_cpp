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
    //CONSTRUCTOR
    pieceOnBoard(int x, int y, int c, QString d, QGraphicsScene *s);
    void updatePieceCoordinates(qreal xCoord,qreal yCoord);
    QGraphicsPixmapItem* getImage();

    //TODO change below to private after the error is handled
    int xCoord, yCoord, color;
    QGraphicsPixmapItem *image;

private:


signals:

};

#endif // BOARDPLACE_H
