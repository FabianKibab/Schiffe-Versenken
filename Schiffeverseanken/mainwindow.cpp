#include "mainwindow.h"

Fenster::Fenster(QWidget *parent)
    : QWidget(parent)
{
    // Hauptlayout für das Fenster erstellen
    windowlayout = new QVBoxLayout(this);
    windowlayout->setAlignment(Qt::AlignTop); // Widgets am oberen Rand des Fensters ausrichten

    // Oberleiste erstellen
    Oberleiste = new QWidget(this);
    Oberleiste->setFixedHeight(40);
    Oberleiste->setStyleSheet("QWidget { border: 1px solid black; }"); // Rahmen um die Oberleiste zeichnen
    Oberleistelayout = new QHBoxLayout(Oberleiste);
    Oberleistelayout->setAlignment(Qt::AlignLeft | Qt::AlignVCenter); // Label links ausrichten, zentrieren vertikal
    label1 = new QLabel("Oberleiste", Oberleiste);
    label1->setFixedSize(100, 40); // Setzt die Größe des Labels auf 100x40 Pixel
    Oberleistelayout->addWidget(label1); // automatische Ausrichtung des Labels

    // Spielfeld erstellen
    Spielfeld = new QWidget(this);
    Spielfeld->setFixedHeight(500);
    Spielfeld->setStyleSheet("QWidget { border: 1px solid black; }"); // Rahmen um das Spielfeld zeichnen
    Spielfeldlayout = new QGridLayout(Spielfeld);
    label2 = new QLabel("Spieler", Spielfeld);
    label3 = new QLabel("Gegner", Spielfeld);
    Spielfeldlayout->addWidget(label2, 0, 0); // (Zeile 0, Spalte 0)
    Spielfeldlayout->addWidget(label3, 0, 1); // (Zeile 0, Spalte 1)

    // Unterleiste erstellen
    Unterleiste = new QWidget(this);
    Unterleiste->setFixedHeight(200);
    Unterleiste->setStyleSheet("QWidget { border: 1px solid black; }"); // Rahmen um die Unterleiste zeichnen
    Unterleistelayout = new QHBoxLayout(Unterleiste);
    Unterleistelayout->setAlignment(Qt::AlignLeft | Qt::AlignVCenter); // Label links ausrichten, zentrieren vertikal

    button = new QPushButton("Richtung");
    button->setMinimumSize(100,25);
    Unterleistelayout->addWidget(button);
    connect(button,&QPushButton::clicked, this ,&Fenster::onButtonClicked);

    // Widgets zum Hauptlayout hinzufügen
    windowlayout->addWidget(Oberleiste);
    windowlayout->addWidget(Spielfeld);
    windowlayout->addWidget(Unterleiste);
}

Fenster::~Fenster()
{
    delete Oberleiste;
    delete Spielfeld;
    delete Unterleiste;
}

void Fenster::onButtonClicked()
{
    haufigkeit++;
    if (haufigkeit % 2 == 0) {
        button->setText("Vertikal");
    } else {
        button->setText("Horizontal");
    }
    if (haufigkeit == 1000) {
        haufigkeit = 1;
    }
}
