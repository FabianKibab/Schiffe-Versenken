#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>

class Fenster : public QWidget
{
    Q_OBJECT

public:
    Fenster(QWidget *parent = nullptr);
    ~Fenster();

private slots:
    void onButtonClicked();

private:
    QVBoxLayout *windowlayout;
    QWidget *Oberleiste;
    QWidget *Spielfeld;
    QWidget *Unterleiste;
    QHBoxLayout *Oberleistelayout;
    QGridLayout *Spielfeldlayout;
    QHBoxLayout *Unterleistelayout;
    QLabel *label1;
    QLabel *label2;
    QLabel *label3;
    int haufigkeit = 1;
    QPushButton *button;
};

#endif // MAINWINDOW_H
