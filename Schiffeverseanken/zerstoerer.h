#ifndef Zerstoerer_H
#define Zerstoerer_H

#include "schiff.h"

class Zerstoerer : public Schiff
{
public:
    explicit Zerstoerer(QWidget *parent = nullptr);
    void zeichneH(QPainter &painter) override;
    void zeichneV(QPainter &painter) override;
};

#endif
