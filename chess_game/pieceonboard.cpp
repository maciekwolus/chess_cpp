#include "pieceOnBoard.h"

pieceOnBoard::pieceOnBoard(int x, int y, int c, QString d, QGraphicsScene *s)
{
    // Set member variables
    xCoord = x;
    yCoord = y;
    color = c;

    // Create QGraphicsPixmapItem for image
    QGraphicsPixmapItem *image = new QGraphicsPixmapItem(QPixmap(QString(d)));

    // Set flags and position for image
    image->setFlags(QGraphicsItem::ItemIsMovable);
    image->setPos(xCoord, yCoord);

    // Add image to scene
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
