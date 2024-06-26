#include "mainwindow.h"
#include "ui_mainwindow.h"

QString Erster;
QString Zweiter;

struct Player {
    QString name;
    QString password;
    int victories;

    bool operator<(const Player& other) const {
        return victories > other.victories; // Sortiere absteigend nach Anzahl der Siege
    }
};

Fenster::Fenster(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    haufigkeit(0)
{
    ui->setupUi(this);

    this->setWindowTitle("Menue");
    this->resize(1000,1000);
    menue = new Menue(this);
    zeigeMenue();
    // Verbindung des Menüs mit dem Hauptfenster
    connect(menue, &Menue::spielenClicked, this, &Fenster::zeigeHauptfenster);
    connect(menue, &Menue::spielerNamen, this,&Fenster::Namensaufloesung);

}

void Fenster::Namensaufloesung(const QString &nameEins,const QString &nameZwei){

    Eigenenamen = true;
    Erster = nameEins;
    Zweiter = nameZwei;
    std::cout<<"ich werde ausgefuehrt"<<std::endl;
    Reihenfolge->setText(nameEins + " am Zug");
}

Fenster::~Fenster()
{
    delete ui;
}

void Fenster::zeigeMenue()
{
    setCentralWidget(menue);
}

void Fenster::zeigeHauptfenster()
{
    setWindowTitle("Schiffeversenken");
    resize(1000, 1000);

    Richtung = true;
    Loeschen = true;
    Zahlverboten2 = false;
    Zahlverboten3 = false;
    Zahlverboten4 = false;
    Zahlverboten5 = false;
    SpielerEinsIstFertig = false;
    brett1spielIsCreated = false;
    brett2spielIsCreated = false;
    EinsOderzwei = 0;

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
    Spielfeldlayout->addWidget(brett2, 0, 2);

    //Richtungs Button
    button = new QPushButton("Richtung");
    button->setMinimumSize(100, 25);
    button->setMaximumSize(440, 25);
    button->setFixedHeight(100);
    Spielfeldlayout->addWidget(button, 2, 0);

    //Doppelpfeil Button
    Doppelpfeil = new QPushButton;
    Doppelpfeil->setFixedSize(50,50);
    Doppelpfeil->setIcon(QIcon("D:/2.Semester/FORTGESCHRITTENES C&CPP/Projete mit QT/Schiffeversenke Probe1/doppelpfeil.png"));
    Doppelpfeil->setIconSize(QSize(50,50));
    Spielfeldlayout->addWidget(Doppelpfeil,0,1);

    // Anzeige des QVBoxlayout
    qvboxwidget = new QWidget();
    qvboxwidget->setFixedSize(450,205);
    qvboxwidget->setStyleSheet("QWidget { border: 1px solid black; }");
    qvboxlayout = new QVBoxLayout(qvboxwidget);
    qvboxlayout->setAlignment(Qt::AlignCenter);
    Spielfeldlayout->addWidget(qvboxwidget,2,2,0,0);

    uboot = new UBoote();
    qvboxlayout->addWidget(uboot);
    qvboxlayout->setAlignment(Qt::AlignCenter);

    erweiterteslayoutEins = new QHBoxLayout();
    Spielfeldlayout->addLayout(erweiterteslayoutEins, 3, 0);

    if(Eigenenamen == false){
        SpielerEins = new QLabel("Spieler 1");
        SpielerEins->setMinimumSize(200, 25);
        SpielerEins->setMaximumSize(200, 25);
        Spielfeldlayout->addWidget(SpielerEins, 1, 0);
    }else{
        SpielerEins = new QLabel(Erster);
        SpielerEins->setMinimumSize(200, 25);
        SpielerEins->setMaximumSize(200, 25);
        Spielfeldlayout->addWidget(SpielerEins, 1, 0);
    }

    if(Eigenenamen == false){
        SpielerZwei = new QLabel("Spieler 2");
        SpielerZwei->setMinimumSize(200, 25);
        SpielerZwei->setMaximumSize(200, 25);
        Spielfeldlayout->addWidget(SpielerZwei, 1, 2);
    }else{
        SpielerZwei = new QLabel(Zweiter);
        SpielerZwei->setMinimumSize(200, 25);
        SpielerZwei->setMaximumSize(200, 25);
        Spielfeldlayout->addWidget(SpielerZwei, 1, 2);
    }

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
    connect(button, &QPushButton::clicked, this, &Fenster::VoHButton);
    connect(Doppelpfeil, &QPushButton::clicked, this ,&Fenster::onButtonClickedZwei);
    connect(spinboxbuttonhoch, &QPushButton::clicked, this, &Fenster::erhoehen);
    connect(spinboxbuttonrunter, &QPushButton::clicked, this, &Fenster::verringern);
    connect(brett1, &Brett::zelleGeklickt, this, &Fenster::zelleGeklicktSlotEins);

    // Widgets zum Hauptlayout hinzufügen
    windowlayout->addWidget(Oberleiste);
    windowlayout->addWidget(Spielfeld);

    QWidget *centralWidget = new QWidget();
    centralWidget->setLayout(windowlayout);
    setCentralWidget(centralWidget);
}

void Fenster::VoHButton()
{
    Richtung = !Richtung; // Richtung umschalten
    button->setText(Richtung ? "Horizontal" : "Vertikal");
    std::cout << "Richtung(change) = " << Richtung << std::endl;
    switchShip(Zahl,Richtung);
}

void Fenster::onButtonClickedZwei()
{

    try{
        int blackCount = 0;

        if(EinsOderzwei == 0){
            blackCount = 0;

            for (int i = 1; i <= 10; i++) {
                for (int j = 1; j <= 10; j++) {
                    QPushButton *button = brett1->getButtonEins(i, j);
                    if (button->styleSheet() == "background-color: black;") {
                        blackCount++;
                    }
                }
            }

            if(blackCount < 14){
                throw std::runtime_error("Es wurden noch nicht alle Schiffe plaziert!");
            }
            disconnect(brett1, &Brett::zelleGeklickt, this, &Fenster::zelleGeklicktSlotEins);
            connect(brett2, &Brett::zelleGeklicktZwei, this, &Fenster::zelleGeklicktSlotZwei);
            if (brett1spielIsCreated == false) {
                brett1spiel = new Brett();
                Spielfeldlayout->addWidget(brett1spiel, 0, 0);
                brett1spielIsCreated = true;
            }
            if(Eigenenamen == false){
                Reihenfolge->setText("Spieler 2 am Zug");
            }
            else{
                Reihenfolge->setText(Zweiter + " am Zug");
            }
            Zahlverboten2 = false;
            Zahlverboten3 = false;
            Zahlverboten4 = false;
            Zahlverboten5 = false;
            erhoehen();
            EinsOderzwei++;

        }else if(EinsOderzwei == 1){
            blackCount = 0;

            for (int i = 1; i <= 10; i++) {
                for (int j = 1; j <= 10; j++) {
                    QPushButton *button = brett2->getButtonZwei(i, j);
                    if (button->styleSheet() == "background-color: black;") {
                        blackCount++;
                    }
                }
            }

            if(blackCount < 14){
                throw std::runtime_error("Es wurden noch nicht alle Schiffe plaziert!");
            }
            disconnect(brett2, &Brett::zelleGeklickt, this, &Fenster::zelleGeklicktSlotZwei);
            if (brett2spielIsCreated == false) {
                brett2spiel = new Brett();
                Spielfeldlayout->addWidget(brett2spiel, 0, 2);
                brett2spielIsCreated = true;
            }
            if(Eigenenamen == false){
                Reihenfolge->setText("Spieler 1 am Zug");
            }else{
                Reihenfolge->setText(Erster + " am Zug");
            }
            Spielen();

        }



    }catch (std::exception &e) {
        std::cerr << "Fehler: " << e.what() << std::endl;
    }
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
    else if (Zahl == 2) {
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

void Fenster::zelleGeklicktSlotEins(QPushButton *clickedButton, int row, int col) {
    try {
        if (Richtung) { // horizontal
            if (col + Zahl <= 11 && sindZellenFreiEins(row, col, Zahl, true)) {
                for (int i = 0; i < Zahl; ++i) {
                    QPushButton *NachbarH = brett1->getButtonEins(row, col + i);
                    if (NachbarH) {
                        NachbarH->setStyleSheet("background-color: black;");
                    }
                }
            } else {
                throw std::out_of_range("Horizontal passt das Schiff nicht rein oder die Zellen sind besetzt!");
            }
        } else { // vertikal
            if (row + Zahl <= 11 && sindZellenFreiEins(row, col, Zahl, false))
            {

                for (int i = 0; i < Zahl; ++i) {
                    QPushButton *NachbarV = brett1->getButtonEins(row + i, col);
                    if (NachbarV) {
                        NachbarV->setStyleSheet("background-color: black;");
                    }
                }
            }
            else {
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

bool Fenster::sindZellenFreiEins(int row, int col, int laenge, bool horizontal) {
    QString Wasser = "background-color: lightblue;";

    if (horizontal) {
        for (int i = 0; i < laenge; ++i) {
            QPushButton *button = brett1->getButtonEins(row, col + i);
            if (!button || button->styleSheet() != Wasser) {
                return false;
            }
        }
    } else {
        for (int i = 0; i < laenge; ++i) {
            QPushButton *button = brett1->getButtonEins(row + i, col);
            if (!button || button->styleSheet() != Wasser) {
                return false;
            }
        }
    }
    return true;
}

void Fenster::zelleGeklicktSlotZwei(QPushButton *clickedButton, int row, int col) {
    try {
        if (Richtung) { // horizontal
            if (col + Zahl <= 11 && sindZellenFreiZwei(row, col, Zahl, true)) {
                for (int i = 0; i < Zahl; ++i) {
                    QPushButton *NachbarH = brett2->getButtonZwei(row, col + i);
                    if (NachbarH) {
                        NachbarH->setStyleSheet("background-color: black;");
                    }
                }
            } else {
                throw std::out_of_range("Horizontal passt das Schiff nicht rein oder die Zellen sind besetzt!");
            }
        } else { // vertikal
            if (row + Zahl <= 11 && sindZellenFreiZwei(row, col, Zahl, false)) {
                for (int i = 0; i < Zahl; ++i) {
                    QPushButton *NachbarV = brett2->getButtonZwei(row + i, col);
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

bool Fenster::sindZellenFreiZwei(int row, int col, int laenge, bool horizontal) {
    QString Wasser = "background-color: lightblue;";

    if (horizontal) {
        for (int i = 0; i < laenge; ++i) {
            QPushButton *button = brett2->getButtonZwei(row, col + i);
            if (!button || button->styleSheet() != Wasser) {
                return false;
            }
        }
    } else {
        for (int i = 0; i < laenge; ++i) {
            QPushButton *button = brett2->getButtonZwei(row + i, col);
            if (!button || button->styleSheet() != Wasser) {
                return false;
            }
        }
    }
    return true;
}

void Fenster::zelleGeklicktSlotDrei(QPushButton *clickedButton, int row, int col) {
    bool dukannstnochmal = false;

    if (brett1->getroffenEins(row, col, false)) {
        if (brett1->gewonnen()) {
            // Jetzt muss das in die txt Datei geschrieben werden
            QFile file("D://GitHub//Repository//Schiffe-Versenken//Schiffeverseanken//loginDatei.txt");
            if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
                qDebug() << "Fehler beim Öffnen der Datei:" << file.errorString();
                return;
            }

            QTextStream stream(&file);
            QVector<Player> players;
            QString name, password;
            int victories;

            // Read existing players
            while (!stream.atEnd()) {
                Player player;
                player.name = stream.readLine();
                if (stream.atEnd()) break;  // Handle incomplete entries
                player.password = stream.readLine();
                if (stream.atEnd()) break;  // Handle incomplete entries
                player.victories = stream.readLine().toInt();
                players.append(player);
            }

            // Update player data
            for (Player &player : players) {
                if (player.name == Zweiter) { // Assuming Erster is defined elsewhere
                    player.victories += 1;
                    break;
                }
            }

            // Write back updated data
            file.resize(0); // Clear the file before writing
            for (const Player &player : players) {
                stream << player.name << "\n" << player.password << "\n" << player.victories << "\n";
            }

            file.close();

            // Lösche die Widgets aus dem Layout, falls sie existieren
            if (brett1spiel) {
                Spielfeldlayout->removeWidget(brett1spiel);
                delete brett1spiel;
                brett1spiel = nullptr; // Setze den Zeiger auf nullptr, um undefiniertes Verhalten zu vermeiden
            }
            if (brett2spiel) {
                Spielfeldlayout->removeWidget(brett2spiel);
                delete brett2spiel;
                brett2spiel = nullptr; // Setze den Zeiger auf nullptr, um undefiniertes Verhalten zu vermeiden
            }

            Eigenenamen = false;
            // Erstelle ein neues Menü und verbinde die Signale
            createAndSetNewMenue();
        }

        if (!brett1->gewonnen()) {
            // Überprüfe, ob brett1spiel gültig ist, bevor du darauf zugreifst
            if (brett1spiel) {
                brett1spiel->getButtonEins(row, col)->setStyleSheet("background-color: rgb(255, 0, 0)");
                brett1spiel->getButtonEins(row, col)->setText("X");
                dukannstnochmal = true;
            }
        }
    } else if (!brett1->getroffenEins(row, col, true)) {
        if (brett1->doppelt(row, col)) {
            // Überprüfe, ob brett1spiel gültig ist, bevor du darauf zugreifst
            if (brett1spiel) {
                brett1spiel->getButtonEins(row, col)->setText("O");
            }
            dukannstnochmal = false;
        } else {
            std::cout << "Du kannst nochmal" << std::endl;
            dukannstnochmal = true;
        }
    }

    if (!dukannstnochmal) {
        if (!Eigenenamen) {
            Reihenfolge->setText("Spieler 1 am Zug");
        } else {
            Reihenfolge->setText(Erster + " am Zug");
        }
        disconnect(brett1spiel, &Brett::zelleGeklicktDrei, this, &Fenster::zelleGeklicktSlotDrei);
        connect(brett2spiel, &Brett::zelleGeklicktVier, this, &Fenster::zelleGeklicktSlotVier);
    }
}


bool Fenster::sindZellenFreiDrei(int row, int col, int laenge, bool horizontal) {
    QString Wasser = "background-color: lightblue;";

    QPushButton *button = brett1spiel->getButtonEins(row, col);
    if (!button || button->styleSheet() != Wasser) {
        return false;
    }
    return true;
}

bool Fenster::sindZellenFreiVier(int row, int col, int laenge, bool horizontal) {
    QString Wasser = "background-color: lightblue;";


    QPushButton *button = brett2spiel->getButtonEins(row, col);
    if (!button || button->styleSheet() != Wasser) {
        return false;
    }
    return true;

}

void Fenster::zelleGeklicktSlotVier(QPushButton *clickedButton, int row, int col) {
    bool dukannstnochmal = false;

    if (brett2->getroffenZwei(row, col, false)) {
        if (brett2->gewonnen()) {
            // Datei öffnen und Daten aktualisieren
            QFile file("D://GitHub//Repository//Schiffe-Versenken//Schiffeverseanken//loginDatei.txt");
            if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
                qDebug() << "Fehler beim Öffnen der Datei:" << file.errorString();
                return;
            }

            QTextStream stream(&file);
            QVector<Player> players;

            // Bestehende Spielerdaten einlesen
            while (!stream.atEnd()) {
                Player player;
                player.name = stream.readLine();
                if (stream.atEnd()) break;
                player.password = stream.readLine();
                if (stream.atEnd()) break;
                player.victories = stream.readLine().toInt();
                players.append(player);
            }

            // Spielerdaten aktualisieren
            for (Player &player : players) {
                if (player.name == Erster) {
                    player.victories += 1;
                    break;
                }
            }

            // Aktualisierte Daten in die Datei schreiben
            file.resize(0); // Dateiinhalt löschen
            for (const Player &player : players) {
                stream << player.name << "\n" << player.password << "\n" << player.victories << "\n";
            }

            file.close();

            // Widgets aus dem Layout entfernen und löschen
            if (brett2spiel) {
                Spielfeldlayout->removeWidget(brett2spiel);
                delete brett2spiel;
                brett2spiel = nullptr;
            }
            if (brett1spiel) {
                Spielfeldlayout->removeWidget(brett1spiel);
                delete brett1spiel;
                brett1spiel = nullptr;
            }


            Eigenenamen = false;
            // Neues Menü erstellen und anzeigen
            createAndSetNewMenue();
        }

        // Wenn das Spiel nicht gewonnen wurde
        if (!brett2->gewonnen()) {
            // Überprüfen, ob brett2spiel gültig ist
            if (brett2spiel) {
                QPushButton *button = brett2spiel->getButtonZwei(row, col);
                if (button) {
                    button->setStyleSheet("background-color: rgb(255, 0, 0)");
                    button->setText("X");
                    dukannstnochmal = true;
                }
            }
        }
    } else if (!brett2->getroffenEins(row, col, true)) {
        if (brett2->doppelt(row, col)) {
            // Überprüfen, ob brett2spiel gültig ist
            if (brett2spiel) {
                QPushButton *button = brett2spiel->getButtonZwei(row, col);
                if (button) {
                    button->setText("O");
                }
            }
            dukannstnochmal = false;
        } else {
            std::cout << "Du kannst nochmal" << std::endl;
            dukannstnochmal = true;
        }
    }

    // Text je nach Spielername aktualisieren
    if (!dukannstnochmal) {
        if (!Eigenenamen) {
            Reihenfolge->setText("Spieler 2 am Zug");
        } else {
            Reihenfolge->setText(Zweiter + " am Zug");
        }
        disconnect(brett2spiel, &Brett::zelleGeklicktVier, this, &Fenster::zelleGeklicktSlotVier);
        connect(brett1spiel, &Brett::zelleGeklicktDrei, this, &Fenster::zelleGeklicktSlotDrei);
    }
}

void Fenster::Spielen() {
    // Verbindungen aktualisieren
    disconnect(brett2, &Brett::zelleGeklicktZwei, this, &Fenster::zelleGeklicktSlotZwei);
    connect(brett2spiel, &Brett::zelleGeklicktVier, this, &Fenster::zelleGeklicktSlotVier);
}

void Fenster::createAndSetNewMenue() {
    // Neues Menü erstellen
    Menue *newMenue = new Menue(this);

    // Signale des neuen Menüs verbinden
    connect(newMenue, &Menue::spielenClicked, this, &Fenster::zeigeHauptfenster);
    connect(newMenue, &Menue::spielerNamen, this,&Fenster::Namensaufloesung);

    // Neues Menü als zentrales Widget setzen
    setCentralWidget(newMenue);

    // Aktuelles Menü aktualisieren
    currentMenue = newMenue;
}
