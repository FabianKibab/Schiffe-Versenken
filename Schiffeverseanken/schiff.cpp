#include "schiff.h"

Schiff::Schiff(QWidget *parent) : QWidget(parent), drawHorrizontal(true) {
    setFixedSize(400, 400);
}

void Schiff::setDirection(bool horizontal) {
    drawHorrizontal = horizontal;
    update();
}

void Schiff::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    if(drawHorrizontal){
        zeichneH(painter);
    } else {
        zeichneV(painter);
    }
}

Schiff::~Schiff() {}

