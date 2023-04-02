#include "pieceOnBoard.h"

pieceOnBoard::pieceOnBoard(int x, int y, bool w, QString d, QGraphicsScene *s)
{
    xCoord = x;
    yCoord = y;
    white = w;
    QString dir = d;
    QGraphicsPixmapItem *image = new QGraphicsPixmapItem(QPixmap(dir));
    image->setPos(xCoord, yCoord);
    s->addItem(image);
}
