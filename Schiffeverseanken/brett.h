// brett.h
#ifndef BRETT_H
#define BRETT_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QPainter>
#include <iostream>
#include <QString>

class Brett : public QWidget {
    Q_OBJECT
public:
    Brett(QWidget *parent = nullptr);
    QPushButton* getButton(int row, int col);
private slots:
    void plazieren();
signals:
    void zelleGeklickt(QPushButton *clickedButton,int col, int row);
private:
    QGridLayout *Raster;
    QPushButton *letterButton;
    QPushButton *numberButton;
    QPushButton *emptyButton;
    QPushButton *felder[11][11];

};

#endif
