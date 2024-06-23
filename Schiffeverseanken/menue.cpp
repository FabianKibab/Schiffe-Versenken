#include "menue.h"

struct Player {
    QString name;
    QString password;
    int victories;

    bool operator<(const Player& other) const {
       return victories > other.victories; // Sortiere absteigend nach Anzahl der Siege
    }
};

Menue::Menue(QWidget *parent) : QWidget(parent), layout(nullptr) {

    Start();
}

void Menue::Start() {

    Gewinner = new QLabel("Schiffeversenken", this);
    Gewinner->setFixedHeight(200);
    Gewinner->setAlignment(Qt::AlignCenter);

    Spielen = new QPushButton("Spielen", this);
    Spielen->setFixedHeight(200);
    Verlassen = new QPushButton("Verlassen", this);
    Verlassen->setFixedHeight(200);
    Rangliste = new QPushButton("Rangliste", this);
    Rangliste->setFixedHeight(200);

    if (!layout) {
        layout = new QGridLayout(this);
    }
    layout->addWidget(Gewinner, 0, 0, 1, 1);
    layout->addWidget(Spielen, 1, 0, 1, 1);
    layout->addWidget(Rangliste, 2, 0, 1, 1);
    layout->addWidget(Verlassen, 3, 0, 1, 1);

    connect(Spielen, &QPushButton::clicked, this, &Menue::spielenButtonClicked);
    connect(Verlassen, &QPushButton::clicked, this, &Menue::Exit);
    connect(Rangliste, &QPushButton::clicked, this, &Menue::ranking);

}

void Menue::ranking() {
    // Vorherige Widgets entfernen (ausser Ranking-Labels)
    if (Gewinner) {
        layout->removeWidget(Gewinner);
        delete Gewinner;
        Gewinner = nullptr;
    }
    if (Spielen) {
        layout->removeWidget(Spielen);
        delete Spielen;
        Spielen = nullptr;
    }
    if (Rangliste) {
        layout->removeWidget(Rangliste);
        delete Rangliste;
        Rangliste = nullptr;
    }
    if (Verlassen) {
        layout->removeWidget(Verlassen);
        delete Verlassen;
        Verlassen = nullptr;
    }

    // Benutzerdaten einlesen
    std::vector<Player> players;
    QFile file("D://GitHub//Repository//Schiffe-Versenken//Schiffeverseanken//loginDatei.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Fehler beim Öffnen der Datei:" << file.errorString();
        return;
    }

    QTextStream stream(&file);
    while (!stream.atEnd()) {
        Player player;
        player.name = stream.readLine();
        player.password = stream.readLine();
        player.victories = stream.readLine().toInt();
        players.push_back(player);
    }
    file.close();

    // Benutzerdaten sortieren
    std::sort(players.begin(), players.end());

    // Alte Ranking-Labels löschen
    qDeleteAll(rankingLabels);
    rankingLabels.clear();

    // Dynamisch Widgets für Rangliste hinzufügen
    for (size_t i = 0; i < players.size(); ++i) {
        QLabel* label = new QLabel(QString("%1. %2 - Siege: %3")
                                       .arg(i + 1)
                                       .arg(players[i].name)
                                       .arg(players[i].victories), this);
        label->setAlignment(Qt::AlignCenter);
        label->setFixedHeight(50);
        layout->addWidget(label, static_cast<int>(i), 0, 1, 1);
        rankingLabels.append(label);  // Speichern des Widgets
    }

    // Zurück-Button hinzufügen
    Zurueck = new QPushButton("Zurück", this);
    Zurueck->setFixedHeight(200);
    layout->addWidget(Zurueck, static_cast<int>(players.size()), 0, 1, 1);
    connect(Zurueck, &QPushButton::clicked, this, &Menue::ResetLabels);
}

void Menue::Exit() {
    exit(0);
}

void Menue::spielenButtonClicked() {
    // Widgets entfernen und löschen
    layout->removeWidget(Gewinner);
    delete Gewinner;
    Gewinner = nullptr;
    layout->removeWidget(Spielen);
    delete Spielen;
    Spielen = nullptr;
    layout->removeWidget(Rangliste);
    delete Rangliste;
    Rangliste = nullptr;
    layout->removeWidget(Verlassen);
    delete Verlassen;
    Verlassen = nullptr;

    // Neue Buttons hinzufügen
    Anmelden = new QPushButton("Anmelden", this);
    Anmelden->setFixedHeight(200);
    layout->addWidget(Anmelden, 0, 0, 1, 1);

    Regestrieren = new QPushButton("Registrieren", this);
    Regestrieren->setFixedHeight(200);
    layout->addWidget(Regestrieren, 1, 0, 1, 1);

    Gastbenutzer = new QPushButton("Gastbenutzer", this);
    Gastbenutzer->setFixedHeight(200);
    layout->addWidget(Gastbenutzer, 2, 0, 1, 1);

    connect(Anmelden, &QPushButton::clicked, this, &Menue::anmeldeButtonClicked);
    connect(Regestrieren, &QPushButton::clicked, this, &Menue::regestrierenButtonClicked);
    connect(Gastbenutzer, &QPushButton::clicked, this, &Menue::gastbenutzerButtonClicked);

}

void Menue::anmeldeButtonClicked() {
    // Widgets entfernen und löschen
    layout->removeWidget(Anmelden);
    delete Anmelden;
    Anmelden = nullptr;
    layout->removeWidget(Regestrieren);
    delete Regestrieren;
    Regestrieren = nullptr;
    layout->removeWidget(Gastbenutzer);
    delete Gastbenutzer;
    Gastbenutzer = nullptr;

    // Neue Widgets hinzufügen
    SpielernameEins = new QLineEdit("Hier Name von Spieler 1 angeben!", this);
    layout->addWidget(SpielernameEins, 0, 0, 1, 1);
    SpielernameEins->setAlignment(Qt::AlignCenter);

    passwortEins = new QLineEdit(this);
    passwortEins->setPlaceholderText("Hier Passwort von Spieler 1 angeben!");
    passwortEins->setEchoMode(QLineEdit::Password);
    layout->addWidget(passwortEins, 0, 1, 1, 1);
    passwortEins->setAlignment(Qt::AlignCenter);

    BestaetigenEins = new QPushButton("Überprüfen", this);
    BestaetigenEins->setFixedHeight(200);
    BestaetigenEins->setFixedWidth(200);
    layout->addWidget(BestaetigenEins, 0, 2, 1, 1);

    SpielernameZwei = new QLineEdit("Hier Name von Spieler 2 angeben!", this);
    layout->addWidget(SpielernameZwei, 1, 0, 1, 1);
    SpielernameZwei->setAlignment(Qt::AlignCenter);

    passwortZwei = new QLineEdit(this);
    passwortZwei->setPlaceholderText("Hier Passwort von Spieler 2 angeben!");
    passwortZwei->setEchoMode(QLineEdit::Password);
    layout->addWidget(passwortZwei, 1, 1, 1, 1);
    passwortZwei->setAlignment(Qt::AlignCenter);

    BestaetigenZwei = new QPushButton("Überprüfen", this);
    BestaetigenZwei->setFixedHeight(200);
    BestaetigenZwei->setFixedWidth(200);
    layout->addWidget(BestaetigenZwei, 1, 2, 1, 1);

    Zurueck = new QPushButton("Zurück", this);
    Zurueck->setFixedHeight(200);
    layout->addWidget(Zurueck, 2, 0, 1, 3);

    connect(Zurueck, &QPushButton::clicked, this, &Menue::Reset);
    connect(BestaetigenEins, &QPushButton::clicked, this, &Menue::PruefenEins);
    connect(BestaetigenZwei, &QPushButton::clicked, this, &Menue::PruefenZwei);
}

void Menue::regestrierenButtonClicked() {
    // Widgets entfernen und löschen
    layout->removeWidget(Anmelden);
    delete Anmelden;
    Anmelden = nullptr;
    layout->removeWidget(Regestrieren);
    delete Regestrieren;
    Regestrieren = nullptr;
    layout->removeWidget(Gastbenutzer);
    delete Gastbenutzer;
    Gastbenutzer = nullptr;

    // Neue Widgets hinzufügen
    Spielername = new QLineEdit("Neuer Benutzername", this);
    layout->addWidget(Spielername, 0, 0, 1, 1);
    Spielername->setAlignment(Qt::AlignCenter);

    passwort = new QLineEdit(this);
    passwort->setPlaceholderText("Neues Passwort");
    passwort->setEchoMode(QLineEdit::Password);
    layout->addWidget(passwort, 0, 1, 1, 1);
    passwort->setAlignment(Qt::AlignCenter);

    Bestaetigen = new QPushButton("Speichern", this);
    Bestaetigen->setFixedHeight(200);
    layout->addWidget(Bestaetigen, 1, 0, 1, 2);

    Zurueck = new QPushButton("Zurück", this);
    Zurueck->setFixedHeight(200);
    layout->addWidget(Zurueck, 2, 0, 1, 2);

    connect(Bestaetigen, &QPushButton::clicked, this, &Menue::bestaetigen);
    connect(Zurueck, &QPushButton::clicked, this, &Menue::ResetZwei);
}

void Menue::gastbenutzerButtonClicked() {
    emit spielenClicked();
}

void Menue::bestaetigen() {
    QString playerName = Spielername->text();
    QString playerPassword = passwort->text();

    QFile file("D://GitHub//Repository//Schiffe-Versenken//Schiffeverseanken//loginDatei.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append)) {
        qDebug() << "Fehler beim Öffnen der Datei:" << file.errorString();
        return;
    }

    QTextStream stream(&file);
    stream << playerName << "\n" << playerPassword << "\n" << "0\n";  // Anzahl der Siege initialisieren
    file.close();

    qDebug() << "Daten erfolgreich gespeichert:" << playerName << playerPassword;
}

void Menue::Reset() {

    if(SpielernameEins){
        layout->removeWidget(SpielernameEins);
        delete SpielernameEins;
        SpielernameEins = nullptr;
    }
    if(passwortEins){
        layout->removeWidget(passwortEins);
        delete passwortEins;
        passwortEins = nullptr;
    }
    if(BestaetigenEins){
        layout->removeWidget(BestaetigenEins);
        delete BestaetigenEins;
        BestaetigenEins = nullptr;
    }
    if(SpielernameZwei){
        layout->removeWidget(SpielernameZwei);
        delete SpielernameZwei;
        SpielernameZwei = nullptr;
    }
    if(passwortZwei){
        layout->removeWidget(passwortZwei);
        delete passwortZwei;
        passwortZwei = nullptr;
    }
    if(BestaetigenZwei){
        layout->removeWidget(BestaetigenZwei);
        delete BestaetigenZwei;
        BestaetigenZwei = nullptr;
    }
    if(Zurueck){
        layout->removeWidget(Zurueck);
        delete Zurueck;
        Zurueck = nullptr;

    }
    Start();
}

void Menue::ResetZwei() {
    layout->removeWidget(Spielername);
    delete Spielername;
    Spielername = nullptr;
    layout->removeWidget(passwort);
    delete passwort;
    passwort = nullptr;
    layout->removeWidget(Bestaetigen);
    delete Bestaetigen;
    Bestaetigen = nullptr;
    layout->removeWidget(Zurueck);
    delete Zurueck;
    Zurueck = nullptr;

    Start();
}

void Menue::ResetLabels(){
    // Dynamische Ranking-Labels löschen
    qDeleteAll(rankingLabels);
    rankingLabels.clear();
    layout->removeWidget(Zurueck);
    delete Zurueck;
    Zurueck = nullptr;
    Start();

}
void Menue::PruefenEins() {
    try {
        if (SpielernameEins->text() == SpielernameZwei->text()) {
            throw std::runtime_error("Man kann nicht gegen sich selbst spielen!");
        }
        QString playerNameOne = SpielernameEins->text();
        QString playerPasswordOne = passwortEins->text();

        QFile file("D://GitHub//Repository//Schiffe-Versenken//Schiffeverseanken//loginDatei.txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            qDebug() << "Fehler beim Öffnen der Datei:" << file.errorString();
            return;
        }

        QTextStream stream(&file);
        bool found = false;
        while (!stream.atEnd()) {
            QString storedUserName = stream.readLine();
            QString storedPassword = stream.readLine();
            QString storedSiege = stream.readLine(); // Anzahl der Siege lesen

            if (playerNameOne == storedUserName && playerPasswordOne == storedPassword) {
                found = true;
                break;
            }
        }
        file.close();

        if (found) {
            qDebug() << "Benutzername und Passwort stimmen überein.";
            BestaetigenEins->setStyleSheet("background-color: green;");
            SpielernameEins->setReadOnly(true);
            passwortEins->setReadOnly(true);
        } else {
            qDebug() << "Benutzername oder Passwort sind falsch.";
            BestaetigenEins->setStyleSheet("background-color: rgb(255,0,0);");
        }
        Kontrolle();
    } catch (std::runtime_error &e) {
        SpielernameEins->setText("Fehler: Man kann nicht gegen sich selbst spielen!");
    }
}

void Menue::PruefenZwei() {
    try {
        if (SpielernameZwei->text() == SpielernameEins->text()) {
            throw std::runtime_error("Man kann nicht gegen sich selbst spielen!");
        }

        QString playerNameTwo = SpielernameZwei->text();
        QString playerPasswordTwo = passwortZwei->text();

        QFile file("D://GitHub//Repository//Schiffe-Versenken//Schiffeverseanken//loginDatei.txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            qDebug() << "Fehler beim Öffnen der Datei:" << file.errorString();
            return;
        }

        QTextStream stream(&file);
        bool found = false;
        while (!stream.atEnd()) {
            QString storedUserName = stream.readLine();
            QString storedPassword = stream.readLine();
            QString storedSiege = stream.readLine(); // Anzahl der Siege lesen

            if (playerNameTwo == storedUserName && playerPasswordTwo == storedPassword) {
                found = true;
                break;
            }
        }
        file.close();

        if (found) {
            qDebug() << "Benutzername und Passwort stimmen überein.";
            BestaetigenZwei->setStyleSheet("background-color: green;");
            SpielernameZwei->setReadOnly(true);
            passwortZwei->setReadOnly(true);
        } else {
            qDebug() << "Benutzername oder Passwort sind falsch.";
            BestaetigenZwei->setStyleSheet("background-color: rgb(255,0,0);");
        }
        Kontrolle();
    } catch (std::runtime_error &e) {
        SpielernameZwei->setText("Fehler: Man kann nicht gegen sich selbst spielen!");
    }
}

void Menue::Kontrolle() {
    if (BestaetigenEins->styleSheet() == "background-color: green;" && BestaetigenZwei->styleSheet() == "background-color: green;") {
        QString playerNameOne = SpielernameEins->text();
        QString playerNameTwo = SpielernameZwei->text();
        emit spielenClicked();
        emit spielerNamen(playerNameOne,playerNameTwo);
    }
}

