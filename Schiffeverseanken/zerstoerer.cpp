#include "zerstoerer.h"
#include <QPainter>

Zerstoerer::Zerstoerer(QWidget *parent) : Schiff(parent) {

}

void Zerstoerer::zeichneH(QPainter &painter) {
    setFixedSize(82, 42);
    QPolygonF polygon;
    polygon <<
        QPointF(0, 20) <<
        QPointF(20, 0) <<
        QPointF(80, 0) <<
        QPointF(80, 40) <<
        QPointF(20, 40);


    QBrush brush(Qt::lightGray);
    painter.setBrush(brush);

    painter.drawPolygon(polygon);

}

void Zerstoerer::zeichneV(QPainter &painter) {
    setFixedSize(42, 82);
    QPolygonF polygon;
    polygon <<
        QPointF(1, 20) <<
        QPointF(20, 0) <<
        QPointF(40, 20) <<
        QPointF(40, 80) <<
        QPointF(1, 80);


    QBrush brush(Qt::lightGray);
    painter.setBrush(brush);

    painter.drawPolygon(polygon);

}
