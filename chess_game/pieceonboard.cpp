#include "pieceOnBoard.h"

pieceOnBoard::pieceOnBoard(char x, int y, int c, QString d, QGraphicsScene *s)
{
    color = c; // color set
    // Set member variables (conversion to pixels)
    if (x < 'a' || x > 'h' || y < 1 || y > 8)
    {
        throw std::out_of_range("Error: x_int or y_int is out of range.");
    }
    else {
    xCoord = (static_cast<int>(x) - 97)*100;
    yCoord = (8 - y)*100;
    }

    // Create QGraphicsPixmapItem for image
    image = new QGraphicsPixmapItem(QPixmap(QString(d)));

    // Set flags and position for image
    //image->setFlags(QGraphicsItem::ItemIsMovable); // allow to move pieces
    image->setPos(xCoord, yCoord);

    // Add image to scene
    s->addItem(image);
}

void pieceOnBoard::movePiecePicture(char x, int y)
{
    // Error while not on board
    if (x < 'a' || x > 'h' || y < 1 || y > 8)
    {
        throw std::out_of_range("Error: x_int or y_int is out of range.");
    }

    // Convert chessboard coordinates to pixels
    // X: a - 97, h - 104
    // Y: 1 - 700, 8 - 000
    int x_int = (static_cast<int>(x) - 97)*100;
    int y_int = (8 - y)*100;

    // Move image to new position
    if (image != nullptr) {
        image->setPos(x_int, y_int);
        // Move piece coordinates
        xCoord = (static_cast<int>(x) - 97)*100;
        yCoord = (8 - y)*100;
    } else {
        qDebug() << "Error: image is null";
    }
}

void pieceOnBoard::piecePictureIsMoving(int x, int y)
{
    // Move image to new position
    if (image != nullptr) {
        image->setPos(x - 150, y - 150);
    } else {
        qDebug() << "Error: image is null";
    }
}

int pieceOnBoard::giveXCoord()
{
    return xCoord;
};

int pieceOnBoard::giveYCoord()
{
    return yCoord;
};

void pieceOnBoard::deleteImage()
{
    if (image)
    {
        delete image; // Delete the QGraphicsPixmapItem object
        image = nullptr; // Set the pointer to nullptr to avoid any potential access after deletion
    }
}
