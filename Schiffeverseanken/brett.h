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
    QPushButton* getButtonEins(int row, int col);
    QPushButton* getButtonZwei(int row, int col);
    QPushButton* getButtonDrei(int row, int col);
    QPushButton* getButtonVier(int row, int col);
    bool getroffenEins(int row, int col);
    bool getroffenZwei(int row, int col);

private slots:
    void plazierenEins();
    void plazierenZwei();
    void plazierenDrei();
    void plazierenVier();
signals:
    void zelleGeklickt(QPushButton *clickedButton,int col, int row);
    void zelleGeklicktZwei(QPushButton *clickedButton,int col, int row);
    void zelleGeklicktDrei(QPushButton *clickedButton, int col, int row);
    void zelleGeklicktVier(QPushButton *clickedButton, int col, int row);
private:
    QGridLayout *Raster;
    QPushButton *letterButton;
    QPushButton *numberButton;
    QPushButton *emptyButton;
    QPushButton *felderEins[11][11];
    QPushButton *felderZwei[11][11];
    QPushButton *felderDrei[11][11];
    QPushButton *felderVier[11][11];

};

#endif
