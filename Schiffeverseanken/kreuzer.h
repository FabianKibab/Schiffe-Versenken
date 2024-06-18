#ifndef Kreuzer_H
#define Kreuzer_H

#include "schiff.h"

class Kreuzer : public Schiff
{
public:
    explicit Kreuzer(QWidget *parent = nullptr);
    void zeichneH(QPainter &painter) override;
    void zeichneV(QPainter &painter) override;
};

#endif
