#include "mainwindow.h"
#include "ui_mainwindow.h"


Fenster::Fenster(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    haufigkeit(0)
{
    //Hauptfenster Einstellungen
    ui->setupUi(this);
    setWindowTitle("Schiffeversenken");
    resize(1000, 1000);

    // Hauptlayout für das Fenster erstellen
    windowlayout = new QVBoxLayout();
    windowlayout->setAlignment(Qt::AlignTop); // Widgets am oberen Rand des Fensters ausrichten

    // Oberleiste erstellen
    Oberleiste = new QWidget();
    Oberleiste->setFixedHeight(40);
    Oberleiste->setMinimumWidth(1100);
    Oberleiste->setStyleSheet("QWidget { border: 1px solid black; }"); // Rahmen um die Oberleiste zeichnen
    Oberleistelayout = new QHBoxLayout(Oberleiste);
    Oberleistelayout->setAlignment(Qt::AlignLeft | Qt::AlignVCenter); // Label links ausrichten, zentrieren vertikal
    Reihenfolge = new QLabel("Spieler 1 am Zug", Oberleiste);
    Reihenfolge->setFixedSize(100, 40);
    Oberleistelayout->addWidget(Reihenfolge);

    // Spielfeld erstellen
    Spielfeld = new QWidget();
    Spielfeldlayout = new QGridLayout(Spielfeld);
    Spielfeld->setFixedHeight(710);
    Spielfeld->setMinimumWidth(1000);
    Spielfeld->setStyleSheet("QWidget { border: 1px solid black; }");

    // Anzeige des Bretts
    brett1 = new Brett();
    brett2 = new Brett();
    Spielfeldlayout->addWidget(brett1, 0, 0);
    Spielfeldlayout->addWidget(brett2, 0, 1);

    button = new QPushButton("Richtung");
    button->setMinimumSize(100, 25);
    button->setMaximumSize(440, 25);
    button->setFixedHeight(100);
    Spielfeldlayout->addWidget(button, 2, 0);

    // Anzeige des QVBoxlayout
    qvboxwidget = new QWidget();
    qvboxwidget->setFixedSize(450,205);
    qvboxwidget->setStyleSheet("QWidget { border: 1px solid black; }");
    qvboxlayout = new QVBoxLayout(qvboxwidget);
    qvboxlayout->setAlignment(Qt::AlignCenter);
    Spielfeldlayout->addWidget(qvboxwidget,2,1,0,0);

    //hier muss ich eine connect methode machen
    uboot = new UBoote();
    qvboxlayout->addWidget(uboot);
    qvboxlayout->setAlignment(Qt::AlignCenter);

    erweiterteslayoutEins = new QHBoxLayout();
    Spielfeldlayout->addLayout(erweiterteslayoutEins, 3, 0);

    SpielerEins = new QLabel("Spieler 1");
    SpielerEins->setMinimumSize(200, 25);
    SpielerEins->setMaximumSize(200, 25);
    Spielfeldlayout->addWidget(SpielerEins, 1, 0);

    SpielerZwei = new QLabel("Spieler 2");
    SpielerZwei->setMinimumSize(200, 25);
    SpielerZwei->setMaximumSize(200, 25);
    Spielfeldlayout->addWidget(SpielerZwei, 1, 1);

    spinboxtext = new QLabel();
    spinboxtext->setAlignment(Qt::AlignCenter);
    spinboxtext->setNum(2);
    spinboxtext->setMinimumSize(200, 25);
    spinboxtext->setMaximumSize(200, 25);
    spinboxtext->setFixedHeight(100);
    erweiterteslayoutEins->addWidget(spinboxtext);
    spinboxbuttonhoch = new QPushButton("Hoch");
    spinboxbuttonhoch->setMinimumSize(115, 25);
    spinboxbuttonhoch->setMaximumSize(115, 25);
    spinboxbuttonhoch->setFixedHeight(100);
    spinboxbuttonhoch->setStyleSheet("background-color: lightgreen; border: 2px solid darkgreen;");
    erweiterteslayoutEins->addWidget(spinboxbuttonhoch);
    spinboxbuttonrunter = new QPushButton("Runter");
    spinboxbuttonrunter->setMinimumSize(115, 25);
    spinboxbuttonrunter->setMaximumSize(115, 25);
    spinboxbuttonrunter->setFixedHeight(100);
    spinboxbuttonrunter->setStyleSheet("background-color: red; border: 2px solid darkred;");
    erweiterteslayoutEins->addWidget(spinboxbuttonrunter);

    // Alle connections
    connect(button, &QPushButton::clicked, this, &Fenster::onButtonClicked);
    connect(spinboxbuttonhoch, &QPushButton::clicked, this, &Fenster::erhoehen);
    connect(spinboxbuttonrunter, &QPushButton::clicked, this, &Fenster::verringern);

    if(SpielerEinsIstFertig == false){
        connect(brett1, &Brett::zelleGeklickt, this, &Fenster::zelleGeklicktSlot);
    }

    //connect(brett2, &Brett::zelleGeklickt, this, &Fenster::zelleGeklicktSlot);

    // Widgets zum Hauptlayout hinzufügen
    windowlayout->addWidget(Oberleiste);
    windowlayout->addWidget(Spielfeld);

    QWidget *centralWidget = new QWidget();
    centralWidget->setLayout(windowlayout);
    setCentralWidget(centralWidget);
}

Fenster::~Fenster()
{
    delete ui;
}


void Fenster::onButtonClicked()
{
    Richtung = !Richtung; // Richtung umschalten
    button->setText(Richtung ? "Horizontal" : "Vertikal");
    std::cout << "Richtung(change) = " << Richtung << std::endl;
    switchShip(Zahl,Richtung);
}

void Fenster::erhoehen()
{
    if(Zahl == 0){
        Zahl++;
        Zahl++;
        if(Zahlverboten2){
            Zahl++;
            if(Zahlverboten3){
                Zahl++;
                if(Zahlverboten4){
                    Zahl++;
                    if(Zahlverboten5){
                        Zahl = 0;
                    }
                }
            }
        }
    }
    if (Zahl == 2) {
        Zahl++;
        if(Zahlverboten3){
            Zahl++;
            if(Zahlverboten4){
                Zahl++;
                if(Zahlverboten5){
                    verringern();
                }
            }
        }
    } else if (Zahl == 3) {
        Zahl++;
        if(Zahlverboten4){
            Zahl++;
            if(Zahlverboten5){
                verringern();
            }
        }
    } else if (Zahl == 4) {
        Zahl++;
        if (Zahlverboten5) {
            verringern();
        }
    } else if (Zahl == 5) {
        if(Zahlverboten5 == true){
            verringern();
        }
    }

    spinboxtext->setNum(Zahl);
    switchShip(Zahl, Richtung);

}
void Fenster::verringern()
{
    if(Zahl > 2){
        Zahl--;
        if(Zahl == 4){
            if(Zahlverboten4){
                Zahl--;
                if(Zahlverboten3){
                    Zahl--;
                    if(Zahlverboten2){
                        std::cout<<"Es wurden alle Schiffe plaziert"<<std::endl;
                    }
                }
            }
        }
        if(Zahl == 3){
            if(Zahlverboten3){
                Zahl--;
                if(Zahlverboten2){
                    std::cout<<"Es wurden alle Schiffe plaziert"<<std::endl;
                }
            }
        }
        if(Zahl == 2){
            if(Zahlverboten2){
                if(Zahlverboten3&&Zahlverboten4&&Zahlverboten5){
                    std::cout<<"Es wurden alle Schiffe plaziert"<<std::endl;
                    Zahl--;
                    Zahl--;
                }
                else{
                    erhoehen();
                }
            }
        }

    }
    spinboxtext->setNum(Zahl);
    switchShip(Zahl,Richtung);
}

void Fenster::switchShip(int Zahl, bool Richtung)
{
    if (uboot) {
        qvboxlayout->removeWidget(uboot);
        delete uboot;
        uboot = nullptr;
    }
    if (zerstoerer) {
        qvboxlayout->removeWidget(zerstoerer);
        delete zerstoerer;
        zerstoerer = nullptr;
    }
    if (kreuzer) {
        qvboxlayout->removeWidget(kreuzer);
        delete kreuzer;
        kreuzer = nullptr;
    }
    if (schlachtschiff) {
        qvboxlayout->removeWidget(schlachtschiff);
        delete schlachtschiff;
        schlachtschiff = nullptr;
    }
    if (ubootV) {
        qvboxlayout->removeWidget(ubootV);
        delete ubootV;
        ubootV = nullptr;
    }
    if (zerstoererV) {
        qvboxlayout->removeWidget(zerstoererV);
        delete zerstoererV;
        zerstoererV = nullptr;
    }
    if (kreuzerV) {
        qvboxlayout->removeWidget(kreuzerV);
        delete kreuzerV;
        kreuzerV = nullptr;
    }
    if (schlachtschiffV) {
        qvboxlayout->removeWidget(schlachtschiffV);
        delete schlachtschiffV;
        schlachtschiffV = nullptr;
    }

    std::cout<<"Die Richtung hier ist:"<<Richtung<<std::endl;

    if (Richtung) {
        switch (Zahl) {
        case 2:
            uboot = new UBoote();
            uboot->setDirection(true);
            qvboxlayout->addWidget(uboot);
            break;
        case 3:
            zerstoerer = new Zerstoerer();
            zerstoerer->setDirection(true);
            qvboxlayout->addWidget(zerstoerer);
            break;
        case 4:
            kreuzer = new Kreuzer();
            kreuzer->setDirection(true);
            qvboxlayout->addWidget(kreuzer);
            break;
        case 5:
            schlachtschiff = new Schlachtschiff();
            schlachtschiff->setDirection(true);
            qvboxlayout->addWidget(schlachtschiff);
            break;
        default:
            break;
        }
    } else{
        switch (Zahl) {
        case 2:
            ubootV = new UBoote();
            ubootV->setDirection(false);
            qvboxlayout->addWidget(ubootV);
            break;
        case 3:
            zerstoererV = new Zerstoerer();
            zerstoererV->setDirection(false);
            qvboxlayout->addWidget(zerstoererV);
            break;
        case 4:
            kreuzerV = new Kreuzer();
            kreuzerV->setDirection(false);
            qvboxlayout->addWidget(kreuzerV);
            break;
        case 5:
            schlachtschiffV = new Schlachtschiff();
            schlachtschiffV->setDirection(false);
            qvboxlayout->addWidget(schlachtschiffV);
            break;
        default:
            break;
        }
    }
    qvboxlayout->setAlignment(Qt::AlignCenter);
}


void Fenster::zelleGeklicktSlot(QPushButton *clickedButton, int row, int col) {
    try {
        if (Richtung) { // horizontal
            if (col + Zahl <= 11 && sindZellenFrei(row, col, Zahl, true)) {
                for (int i = 0; i < Zahl; ++i) {
                    QPushButton *NachbarH = brett1->getButton(row, col + i);
                    if (NachbarH) {
                        NachbarH->setStyleSheet("background-color: black;");
                    }
                }
            } else {
                throw std::out_of_range("Horizontal passt das Schiff nicht rein oder die Zellen sind besetzt!");
            }
        } else { // vertikal
            if (row + Zahl <= 11 && sindZellenFrei(row, col, Zahl, false)) {
                for (int i = 0; i < Zahl; ++i) {
                    QPushButton *NachbarV = brett1->getButton(row + i, col);
                    if (NachbarV) {
                        NachbarV->setStyleSheet("background-color: black;");
                    }
                }
            } else {
                throw std::out_of_range("Vertikal passt das Schiff nicht rein oder die Zellen sind besetzt!");
            }
        }

        // Aktualisieren Sie die `Zahlverboten`-Flags
        switch (Zahl) {
        case 5:
            Zahlverboten5 = true;
            break;
        case 4:
            Zahlverboten4 = true;
            break;
        case 3:
            Zahlverboten3 = true;
            break;
        case 2:
            Zahlverboten2 = true;
            break;
        default:
            break;
        }

        erhoehen();
    } catch (std::out_of_range &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

bool Fenster::sindZellenFrei(int row, int col, int laenge, bool horizontal) {
    if (horizontal) {
        for (int i = 0; i < laenge; ++i) {
            if (!brett1->getButton(row, col + i)->styleSheet().isEmpty()) {
                return false;
            }
        }
    } else {
        for (int i = 0; i < laenge; ++i) {
            if (!brett1->getButton(row + i, col)->styleSheet().isEmpty()) {
                return false;
            }
        }
    }
    return true;
}
