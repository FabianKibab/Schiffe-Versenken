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
#include "menue.h"

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

    void zeigeMenue();
    void zeigeHauptfenster();
    void VoHButton();
    void onButtonClickedZwei();
    void erhoehen();
    void verringern();
    void switchShip(int Zahl, bool Richtung);
    void zelleGeklicktSlotEins(QPushButton *clickedButton,int row, int col);
    void zelleGeklicktSlotZwei(QPushButton *clickedButton,int row, int col);
    void zelleGeklicktSlotDrei(QPushButton *clickedButton,int row, int col);
    void zelleGeklicktSlotVier(QPushButton *clickedButton,int row, int col);
    bool sindZellenFreiEins(int row, int col, int laenge, bool horizontal);
    bool sindZellenFreiZwei(int row, int col, int laenge, bool horizontal);
    bool sindZellenFreiDrei(int row, int col, int laenge, bool horizontal);
    bool sindZellenFreiVier(int row, int col, int laenge, bool horizontal);
    void Spielen();

private:
    Ui::MainWindow *ui;
    Menue *menue;
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
    QPushButton *Doppelpfeil;
    QPushButton *spinboxbuttonhoch;
    QPushButton *spinboxbuttonrunter;
    QLabel *spinboxtext;
    QHBoxLayout *erweiterteslayoutEins;
    int Zahl = 2;
    //Spielbrett zum erstellen
    Brett *brett1;
    Brett *brett2;
    //Spielbrett zum spielen
    Brett *brett1spiel;
    Brett *brett2spiel;

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
    bool brett1spielIsCreated = false;
    bool brett2spielIsCreated = false;
    int EinsOderzwei = 0;
    bool Siegergefunden = false;
};

#endif // MAINWINDOW_H
