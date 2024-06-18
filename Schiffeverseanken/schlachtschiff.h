#ifndef Schlachtschiff_H
#define Schlachtschiff_H
#include "schiff.h"

class Schlachtschiff : public Schiff
{
public:
    explicit Schlachtschiff(QWidget *parent = nullptr);
    void zeichneH(QPainter &painter) override;
    void zeichneV(QPainter &painter) override;
};

#endif
