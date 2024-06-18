#include "schlachtschiff.h"
#include <QPainter>

Schlachtschiff::Schlachtschiff(QWidget *parent) : Schiff(parent) {
}

void Schlachtschiff::zeichneH(QPainter &painter) {
    setFixedSize(122, 42);
    QPolygonF polygon;
    polygon <<
        QPointF(0, 20) <<
        QPointF(20, 0) <<
        QPointF(120, 0) <<
        QPointF(120, 40) <<
        QPointF(20, 40);


    QBrush brush(Qt::lightGray);
    painter.setBrush(brush);

    painter.drawPolygon(polygon);

}

void Schlachtschiff::zeichneV(QPainter &painter) {
    setFixedSize(42, 122);
    QPolygonF polygon;
    polygon <<
        QPointF(1, 20) <<
        QPointF(20, 0) <<
        QPointF(40, 20) <<
        QPointF(40, 120) <<
        QPointF(1, 120);


    QBrush brush(Qt::lightGray);
    painter.setBrush(brush);

    painter.drawPolygon(polygon);

}
