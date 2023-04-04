#include "pieceOnBoard.h"

pieceOnBoard::pieceOnBoard(int x, int y, int c, QString d, QGraphicsScene *s)
{
    // Set member variables
    xCoord = x;
    yCoord = y;
    color = c;

    // Create QGraphicsPixmapItem for image
    image = new QGraphicsPixmapItem(QPixmap(QString(d)));

    // Set flags and position for image
    image->setFlags(QGraphicsItem::ItemIsMovable); // allow to move pieces
    image->setPos(xCoord, yCoord);

    // Add image to scene
    s->addItem(image);
}

void pieceOnBoard::movePiecePicture(int x, int y)
{
    // Move image to new position
    if (image != nullptr) {
        image->setPos(x, y);
    } else {
        qDebug() << "Error: image is null";
    }
}
