#ifndef SCHIFF_H
#define SCHIFF_H

#include <QWidget>
#include <QPainter>

class Schiff : public QWidget
{
    Q_OBJECT
public:
    explicit Schiff(QWidget *parent = nullptr);
    void setDirection(bool horizontal);
    ~Schiff();

protected:
    void paintEvent(QPaintEvent *event) override;
    virtual void zeichneH(QPainter &painter) = 0;
    virtual void zeichneV(QPainter &painter) = 0;

private:
    bool drawHorrizontal; // Variable zur Speicherung der Richtung
};

#endif
