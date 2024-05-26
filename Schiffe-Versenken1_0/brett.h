#ifndef BRETT_H
#define BRETT_H

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QBrush>
#include <QPen>

class Brett {
private:
    QGraphicsScene* board;

public:
    Brett();
    QGraphicsScene* getScene();
};

#endif
