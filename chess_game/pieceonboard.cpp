#include "pieceOnBoard.h"

pieceOnBoard::pieceOnBoard(int x, int y, int c, QString d, QGraphicsScene *s)
{
    xCoord = x;
    yCoord = y;
    color = c;
    QGraphicsPixmapItem *image = new QGraphicsPixmapItem(QPixmap(QString(d)));
    image->setFlags(QGraphicsItem::ItemIsMovable);
    image->setPos(xCoord, yCoord);
    s->addItem(image);
}

void pieceOnBoard::updatePieceCoordinates(qreal xCoord,qreal yCoord)
{
    qDebug() << "wchodzi do updatePieceCoordinates";

    image->setPos(xCoord,yCoord); //TU SIE WYWALA

    qDebug() << "konczy updatePieceCoordinates";
}

QGraphicsPixmapItem* pieceOnBoard::getImage()
{
    return image;
}
