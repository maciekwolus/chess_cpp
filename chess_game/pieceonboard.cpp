#include "pieceOnBoard.h"

pieceOnBoard::pieceOnBoard(int x, int y, int c, QString d, QGraphicsScene *s)
{
    xCoord = x;
    yCoord = y;
    color = c;
    QGraphicsPixmapItem *image = new QGraphicsPixmapItem(QPixmap(QString(d)));
    image->setPos(xCoord, yCoord);
    s->addItem(image);
}

void pieceOnBoard::updatePieceCoordinates(int xCoord, int yCoord)
{
    qDebug() << "wchodzi do updatePieceCoordinates";

    image->setPos(xCoord, yCoord); //TU SIE WYWALA

    qDebug() << "konczy updatePieceCoordinates";
}
