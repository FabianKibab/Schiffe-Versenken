#ifndef UBOOTE_H
#define UBOOTE_H

#include "schiff.h"

class UBoote : public Schiff
{
public:
    explicit UBoote(QWidget *parent = nullptr);
    void zeichneH(QPainter &painter) override;
    void zeichneV(QPainter &painter) override;
};

#endif
