#ifndef SCHIFFE_H
#define SCHIFFE_H
#include <QGraphicsScene>
#include <QGraphicsLineItem>
#include <QGraphicsView>
#include <QApplication>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QKeySequence>
#include <QPen>
#include <iostream>



class Schiffe{
private:
    int groesse;
    std::string ausrichtung;
    QGraphicsScene* scene;
public:
    Schiffe(int _groesse, std::string _ausrichtung);
    virtual ~Schiffe();
    QGraphicsScene* getScene();
    virtual void spitzeOben();
    virtual void spitzeLinks();
    virtual void geradeVertikal();
    virtual void geradeHorrizontal();
};

#endif // SCHIFFE_H
