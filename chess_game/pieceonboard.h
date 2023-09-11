#ifndef BOARDPLACE_H
#define BOARDPLACE_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QString>
#include <QPixmap>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QPointF>

/**
 * @brief Class representing a piece on a chessboard.
 */
class pieceOnBoard : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief Constructor for pieceOnBoard class.
     *
     * @param x The character representing the column (a-h) where the piece is located.
     * @param y The integer representing the row (1-8) where the piece is located.
     * @param c The color of the piece.
     * @param d The filename of the image representing the piece.
     * @param s The QGraphicsScene where the piece will be displayed.
     */
    pieceOnBoard(char x, int y, int c, QString d, QGraphicsScene *s);

    /**
     * @brief Move the graphical representation of the piece to a new position on the chessboard.
     *
     * @param x The character representing the column (a-h) where the piece should be moved.
     * @param y The integer representing the row (1-8) where the piece should be moved.
     */
    void movePiecePicture(char x, int y);

    /**
     * @brief Move the graphical representation of the piece while the mouse is moving.
     *
     * @param x The x-coordinate of the new position (e.g. mouse coordinate).
     * @param y The y-coordinate of the new position (e.g. mouse coordinate).
     */
    void piecePictureIsMoving(int x, int y);

    /**
     * @brief Get the x-coordinate of the piece on the chessboard.
     *
     * @return The x-coordinate.
     */
    int giveXCoord();

    /**
     * @brief Get the y-coordinate of the piece on the chessboard.
     *
     * @return The y-coordinate.
     */
    int giveYCoord();

    /**
     * @brief Delete the image of the piece from the QGraphicsScene.
     */
    void deleteImage();

private:
    int xCoord; ///< The x coordinates of picture
    int yCoord; ///< The y coordinates of picture
    int color; ///< The image of picture
    QGraphicsPixmapItem *image; ///< Visual representation of piece

signals:

};

#endif // BOARDPLACE_H
