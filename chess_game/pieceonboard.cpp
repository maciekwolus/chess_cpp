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
    image->setFlags(QGraphicsItem::ItemIsMovable);
    image->setPos(xCoord, yCoord);

    // Add image to scene
    s->addItem(image);
}

void pieceOnBoard::movePiecePicture(int x, int y)
{
    // Set new coordinates
    //xCoord = x;
    //yCoord = y;

    // Move image to new position
    if (image != nullptr) {
        image->setPos(x, y);
    } else {
        qDebug() << "Error: image is null";
    }
}
