#include "brett.h"

// Brett class definition
Brett::Brett(QWidget *parent) : QWidget(parent) {
    this->setFixedSize(440, 440);
    Raster = new QGridLayout(this);
    Raster->setSpacing(0);

    QStringList letters = {"0", "A", "B", "C", "D", "E", "F", "G", "H", "I", "J"};
    for (int i = 0; i < letters.size(); ++i) {
        QPushButton *letterButton = new QPushButton(letters[i]);
        letterButton->setFixedHeight(40);
        Raster->addWidget(letterButton, 0, i);
    }

    for (int i = 1; i <= 10; ++i) {
        QPushButton *numberButton = new QPushButton(QString::number(i));
        numberButton->setFixedHeight(40);
        Raster->addWidget(numberButton, i, 0);

        for (int j = 1; j <= 10; ++j) {
            QPushButton *emptyButton = new QPushButton(" ");
            emptyButton->setFixedHeight(40);
            Raster->addWidget(emptyButton, i, j);
            felder[i][j] = emptyButton;
            connect(emptyButton, &QPushButton::clicked, this, &Brett::plazieren);
        }
    }

    for (int j = 0; j < 11; ++j) {
        Raster->setColumnStretch(j, 1);
    }
    for (int i = 0; i <= 10; ++i) {
        Raster->setRowStretch(i, 1);
    }
}


void Brett::plazieren() {
    QPushButton *clickedButton = qobject_cast<QPushButton*>(sender());
    if (clickedButton) {

        // Suche den angeklickten Button im felder-Array
        int row = -1, col = -1;

        for (int i = 1; i <= 10; ++i) {
            for (int j = 1; j <= 10; ++j) {
                if (felder[i][j] == clickedButton) {
                    row = i;
                    col = j;
                    break;
                }
            }
            if (row != -1) break;
        }

        if (row != -1 && col != -1) {
            std::cout << "Die Array-Position des angeklickten Buttons: (" << row << ", " << col << ")" << std::endl;
        } else {
            std::cerr << "Fehler: Angeklickter Button nicht im felder-Array gefunden!" << std::endl;
        }

        // Signal wird gesendet
        emit zelleGeklickt(clickedButton,row,col);
    }
}


QPushButton* Brett::getButton(int row, int col) {
    if (row >= 1 && row <= 10 && col >= 1 && col <= 10) {
        return felder[row][col];
    }
    return nullptr;
}


