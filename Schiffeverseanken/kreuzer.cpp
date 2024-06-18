#include "kreuzer.h"
#include <QPainter>

Kreuzer::Kreuzer(QWidget *parent) : Schiff(parent) {
}

void Kreuzer::zeichneH(QPainter &painter) {
    setFixedSize(102, 42);
    QPolygonF polygon;
    polygon <<
        QPointF(0, 20) <<
        QPointF(20, 0) <<
        QPointF(100, 0) <<
        QPointF(100, 40) <<
        QPointF(20, 40);


    QBrush brush(Qt::lightGray);
    painter.setBrush(brush);

    painter.drawPolygon(polygon);

}

void Kreuzer::zeichneV(QPainter &painter) {
    setFixedSize(42, 102);
    QPolygonF polygon;
    polygon <<
        QPointF(1, 20) <<
        QPointF(20, 0) <<
        QPointF(40, 20) <<
        QPointF(40, 100) <<
        QPointF(1, 100);


    QBrush brush(Qt::lightGray);
    painter.setBrush(brush);

    painter.drawPolygon(polygon);

}
