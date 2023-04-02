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
    pieceOnBoard(int x, int y, bool w, QString d, QGraphicsScene *s);
private:
    int xCoord, yCoord;
    bool white;
    QString dir;
    QGraphicsPixmapItem *image;


signals:

};

#endif // BOARDPLACE_H
