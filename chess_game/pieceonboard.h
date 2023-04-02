#ifndef BOARDPLACE_H
#define BOARDPLACE_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QString>
#include <QPixmap>
#include <QGraphicsScene>

class pieceOnBoard : public QObject
{
    Q_OBJECT
public:
    pieceOnBoard(int x, int y, QString d, QGraphicsScene *s);
private:
    int xCoord, yCoord;
    QString dir;
    QGraphicsPixmapItem *image;


signals:

};

#endif // BOARDPLACE_H
