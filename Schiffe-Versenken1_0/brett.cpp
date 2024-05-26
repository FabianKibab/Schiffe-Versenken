#include "brett.h"


Brett::Brett() {

    board = new QGraphicsScene();
    QPen mypen(Qt::blue);
    board ->addRect(0,0,300,300,QPen(),QBrush(Qt::cyan));

}

QGraphicsScene* Brett::getScene() {
    return board;
}
