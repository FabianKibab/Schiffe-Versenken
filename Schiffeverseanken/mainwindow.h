#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>

#include "brett.h"
#include "schiff.h"
#include "uboote.h"
#include "zerstoerer.h"
#include "kreuzer.h"
#include "schlachtschiff.h"
#include "rechteck.h"

namespace Ui {
class MainWindow;
}

class Fenster : public QMainWindow
{
    Q_OBJECT

public:
    explicit Fenster(QWidget *parent = nullptr);
    ~Fenster();

private slots:

    void onButtonClicked();
    void erhoehen();
    void verringern();
    void switchShip(int Zahl, bool Richtung);
    void zelleGeklicktSlot(QPushButton *clickedButton,int row, int col);
    bool sindZellenFrei(int row, int col, int laenge, bool horizontal);

private:
    Ui::MainWindow *ui;
    QVBoxLayout *windowlayout;
    QWidget *Oberleiste;
    QWidget *Spielfeld;
    QHBoxLayout *Oberleistelayout;
    QGridLayout *Spielfeldlayout;
    QLabel *SpielerEins;
    QLabel *SpielerZwei;
    QLabel *Reihenfolge;
    int haufigkeit = 1;
    QPushButton *button;
    QPushButton *spinboxbuttonhoch;
    QPushButton *spinboxbuttonrunter;
    QLabel *spinboxtext;
    QHBoxLayout *erweiterteslayoutEins;
    int Zahl = 2;
    Brett *brett1;
    Brett *brett2;
    QVBoxLayout *qvboxlayout;
    QWidget *qvboxwidget;

    //Horrizontale Schiffe
    UBoote *uboot = nullptr;
    Zerstoerer *zerstoerer = nullptr;
    Kreuzer *kreuzer = nullptr;
    Schlachtschiff *schlachtschiff = nullptr;
    //vertikale Schiffe
    UBoote *ubootV = nullptr;
    Zerstoerer *zerstoererV = nullptr;
    Kreuzer *kreuzerV = nullptr;
    Schlachtschiff *schlachtschiffV = nullptr;

    bool Richtung = true;
    bool Loeschen = true;
    bool Zahlverboten2 = false;
    bool Zahlverboten3 = false;
    bool Zahlverboten4 = false;
    bool Zahlverboten5 = false;
    bool SpielerEinsIstFertig = false;

};

#endif // MAINWINDOW_H
