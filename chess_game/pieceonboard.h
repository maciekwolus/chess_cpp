#ifndef BOARDPLACE_H
#define BOARDPLACE_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QString>
#include <QPixmap>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

class pieceOnBoard : public QObject
{
    Q_OBJECT
public:
    //CONSTRUCTOR
    pieceOnBoard(int x, int y, int c, QString d, QGraphicsScene *s);
    void updatePieceCoordinates(int xCoord, int yCoord);

private:
    int xCoord, yCoord, color;
    QGraphicsPixmapItem *image;

signals:

};

#endif // BOARDPLACE_H
