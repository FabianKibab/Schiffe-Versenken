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
#include <QFile>
#include <QTextStream>
#include <vector>
#include <algorithm>
#include <iostream>

class Menue : public QWidget {
    Q_OBJECT

public:
    explicit Menue(QWidget *parent = nullptr);
    QString playerNameOne;
    QString playerPasswordOne;
    QString playerNameTwo;
    QString playerPasswordTwo;

signals:
    void spielenClicked();
    void spielerNamen(const QString &nameEins,const QString &nameZwei);

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
    void ResetLabels();
    void Kontrolle();

private:
    QGridLayout *layout;

    QLabel *Gewinner;
    QPushButton *Spielen, *Verlassen, *Rangliste;

    QPushButton *Anmelden, *Regestrieren, *Gastbenutzer;
    QLineEdit *SpielernameEins, *passwortEins, *SpielernameZwei, *passwortZwei;
    QPushButton *BestaetigenEins, *BestaetigenZwei, *Bestaetigen, *Zurueck;
    QLineEdit *Spielername, *passwort;

    QList<QLabel*> rankingLabels;

};

#endif // MENUE_H
