#ifndef MENUE_H
#define MENUE_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QGridLayout>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <stdexcept>
#include <QObject>


class Menue : public QWidget {
    Q_OBJECT

public:
    explicit Menue(QWidget *parent = nullptr);


signals:
    void spielenClicked();

public slots:
    void Start();

private slots:
    void ranking();
    void spielenButtonClicked();
    void anmeldeButtonClicked();
    void regestrierenButtonClicked();
    void gastbenutzerButtonClicked();
    void bestaetigen();
    void PruefenEins();
    void PruefenZwei();
    void Exit();
    void Reset();
    void ResetZwei();
    void Kontrolle();

private:
    QGridLayout *layout;

    // Menue
    QLabel *Gewinner;
    QPushButton *Spielen, *Verlassen, *Rangliste;

    // Spielen
    QPushButton *Anmelden, *Regestrieren, *Gastbenutzer;
    // Anmelden
    QLineEdit *SpielernameEins, *passwortEins, *SpielernameZwei, *passwortZwei;
    QPushButton *BestaetigenEins, *BestaetigenZwei, *Bestaetigen, *Zurueck;
    // Regestrieren
    QLineEdit *Spielername, *passwort;
};

#endif // MENUE_H
