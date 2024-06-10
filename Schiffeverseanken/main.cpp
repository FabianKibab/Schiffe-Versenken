#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget window;
    window.resize(1920, 1080);
    window.setWindowTitle("Hauptfenster");
    QVBoxLayout *windowlayout = new QVBoxLayout(&window);
    windowlayout->setAlignment(Qt::AlignTop); // Widgets am oberen Rand des Fensters ausrichten

    // Oberleiste
    QWidget *Oberleiste = new QWidget(&window);
    Oberleiste->setFixedHeight(40);
    Oberleiste->setStyleSheet("QWidget { border: 1px solid black; }"); // Rahmen um die Oberleiste zeichnen
    QHBoxLayout *Oberleistelayout = new QHBoxLayout(Oberleiste);
    Oberleistelayout->setAlignment(Qt::AlignLeft | Qt::AlignVCenter); // Label links ausrichten, zentrieren vertikal

    QLabel *label1 = new QLabel("Oberleiste", Oberleiste);
    label1->setFixedSize(100, 40); // Setzt die Größe des Labels auf 100x40 Pixel
    Oberleistelayout->addWidget(label1); // automatische Ausrichtung des Labels

    // Spielfeld
    QWidget *Spielfeld = new QWidget(&window);
    Spielfeld->setFixedHeight(500);
    std::cout<<Spielfeld->height()<<std::endl;
    Spielfeld->setStyleSheet("QWidget { border: 1px solid black; }"); // Rahmen um das Spielfeld zeichnen
    QGridLayout *Spielfeldlayout = new QGridLayout(Spielfeld);

    QLabel *label2 = new QLabel("Spieler", Spielfeld);
    QLabel *label3 = new QLabel("Gegner", Spielfeld);

    Spielfeldlayout->addWidget(label2, 0, 0); // (Zeile 0, Spalte 0)
    Spielfeldlayout->addWidget(label3, 0, 1); // (Zeile 0, Spalte 1)

    // Unterleiste
    QWidget *Unterleiste = new QWidget(&window);
    Unterleiste->setFixedHeight(200);
    Unterleiste->setStyleSheet("QWidget { border: 1px solid black; }"); // Rahmen um die Unterleiste zeichnen
    QHBoxLayout *Unterleistelayout = new QHBoxLayout(Unterleiste);
    Unterleistelayout->setAlignment(Qt::AlignLeft | Qt::AlignVCenter); // Label links ausrichten, zentrieren vertikal

    QLabel *label4 = new QLabel("Unterleiste", Unterleiste);
    label4->setFixedSize(100, 40); // Setzt die Größe des Labels auf 100x40 Pixel
    Unterleistelayout->addWidget(label4); // automatische Ausrichtung des Labels

    // Widgets zum Hauptlayout hinzufügen
    windowlayout->addWidget(Oberleiste);
    windowlayout->addWidget(Spielfeld);
    windowlayout->addWidget(Unterleiste);

    window.show();
    return a.exec();
}

