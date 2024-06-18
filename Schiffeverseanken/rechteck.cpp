#include "rechteck.h"
#include <QPainter>

Rechteck::Rechteck(QWidget *parent) : Schiff(parent) {
    setFixedSize(400, 400);
}

void Rechteck::zeichne(QPainter &painter) {
    QPolygonF polygon;
    polygon <<
        QPointF(1, 0) <<
        QPointF(1, 200) <<
        QPointF(400, 200) <<
        QPointF(400, 1);
    painter.drawPolygon(polygon);

}

