#include "uboote.h"
#include <QPainter>

UBoote::UBoote(QWidget *parent) : Schiff(parent) {
}

void UBoote::zeichneH(QPainter &painter) {
    setFixedSize(62,42);
    QPolygonF polygon;
    polygon <<
        QPointF(0, 20) <<
        QPointF(20, 0) <<
        QPointF(60, 0) <<
        QPointF(60, 40) <<
        QPointF(20, 40);


    QBrush brush(Qt::lightGray);
    painter.setBrush(brush);

    painter.drawPolygon(polygon);

}

void UBoote::zeichneV(QPainter &painter) {
    setFixedSize(42,62);
    QPolygonF polygon;
    polygon <<
        QPointF(1, 20) <<
        QPointF(20, 0) <<
        QPointF(40, 20) <<
        QPointF(40, 60) <<
        QPointF(1, 60);


    QBrush brush(Qt::lightGray);
    painter.setBrush(brush);

    painter.drawPolygon(polygon);

}
