#include "brett.h"
#include "menue.h"

Brett::Brett(QWidget *parent) : QWidget(parent)
{

    this->setFixedSize(440, 440);
    Raster = new QGridLayout(this);
    Raster->setSpacing(0);

    QStringList letters = {"0", "A", "B", "C", "D", "E", "F", "G", "H", "I", "J"};
    for (int i = 0; i < letters.size(); ++i) {
        letterButton = new QPushButton(letters[i]);
        letterButton->setFixedHeight(40);
        Raster->addWidget(letterButton, 0, i);
    }

    for (int i = 1; i <= 10; ++i) {
        numberButton = new QPushButton(QString::number(i));
        numberButton->setFixedHeight(40);
        Raster->addWidget(numberButton, i, 0);

        for (int j = 1; j <= 10; ++j) {
            emptyButton = new QPushButton(" ");
            emptyButton->setFixedHeight(40);
            emptyButton->setStyleSheet("background-color: lightblue;");
            Raster->addWidget(emptyButton, i, j);
            felderEins[i][j] = emptyButton;
            felderZwei[i][j] = emptyButton;
            felderDrei[i][j] = emptyButton;
            felderVier[i][j] = emptyButton;
            connect(emptyButton, &QPushButton::clicked, this, &Brett::plazierenEins);
            connect(emptyButton, &QPushButton::clicked, this, &Brett::plazierenZwei);
            connect(emptyButton, &QPushButton::clicked, this, &Brett::plazierenDrei);
            connect(emptyButton, &QPushButton::clicked, this, &Brett::plazierenVier);
        }
    }

    for (int j = 0; j < 11; ++j) {
        Raster->setColumnStretch(j, 1);
    }
    for (int i = 0; i <= 10; ++i) {
        Raster->setRowStretch(i, 1);
    }
}

void Brett::plazierenEins() {
    QPushButton *clickedButton = qobject_cast<QPushButton*>(sender());
    if (clickedButton) {

        // Suche den angeklickten Button im felder-Array
        int row = -1, col = -1;

        for (int i = 1; i <= 10; ++i) {
            for (int j = 1; j <= 10; ++j) {
                if (felderEins[i][j] == clickedButton) {
                    row = i;
                    col = j;
                    break;
                }
            }
            if (row != -1) break;
        }
        // Signal wird gesendet
        emit zelleGeklickt(clickedButton,row,col);
    }}

void Brett::plazierenZwei() {
    QPushButton *clickedButton = qobject_cast<QPushButton*>(sender());
    if (clickedButton) {

        // Suche den angeklickten Button im felder-Array
        int row = -1, col = -1;

        for (int i = 1; i <= 10; ++i) {
            for (int j = 1; j <= 10; ++j) {
                if (felderZwei[i][j] == clickedButton) {
                    row = i;
                    col = j;
                    break;
                }
            }
            if (row != -1) break;
        }

        // Signal wird gesendet
        emit zelleGeklicktZwei(clickedButton,row,col);
    }
}

void Brett::plazierenDrei() {
    QPushButton *clickedButton = qobject_cast<QPushButton*>(sender());
    if (clickedButton) {

        // Suche den angeklickten Button im felder-Array
        int row = -1, col = -1;

        for (int i = 1; i <= 10; ++i) {
            for (int j = 1; j <= 10; ++j) {
                if (felderDrei[i][j] == clickedButton) {
                    row = i;
                    col = j;
                    break;
                }
            }
            if (row != -1) break;
        }

        // Signal wird gesendet
        emit zelleGeklicktDrei(clickedButton,row,col);
    }}

void Brett::plazierenVier() {
    QPushButton *clickedButton = qobject_cast<QPushButton*>(sender());
    if (clickedButton) {

        // Suche den angeklickten Button im felder-Array
        int row = -1, col = -1;

        for (int i = 1; i <= 10; ++i) {
            for (int j = 1; j <= 10; ++j) {
                if (felderVier[i][j] == clickedButton) {
                    row = i;
                    col = j;
                    break;
                }
            }
            if (row != -1) break;
        }

        // Signal wird gesendet
        emit zelleGeklicktVier(clickedButton,row,col);
    }
}


QPushButton* Brett::getButtonEins(int row, int col) {
    if (row >= 1 && row <= 10 && col >= 1 && col <= 10) {
        return felderEins[row][col];
    }
    return nullptr;
}

QPushButton* Brett::getButtonZwei(int row, int col) {
    if (row >= 1 && row <= 10 && col >= 1 && col <= 10) {
        return felderZwei[row][col];
    }
    return nullptr;
}

QPushButton* Brett::getButtonDrei(int row, int col) {
    if (row >= 1 && row <= 10 && col >= 1 && col <= 10) {
        return felderDrei[row][col];
    }
    return nullptr;
}

QPushButton* Brett::getButtonVier(int row, int col) {
    if (row >= 1 && row <= 10 && col >= 1 && col <= 10) {
        return felderVier[row][col];
    }
    return nullptr;
}

bool Brett::getroffenEins(int row, int col,bool skip){
    if(felderEins[row][col]->styleSheet() == "background-color: black;")
    {
        if(skip == false){
            getroffeneFelderEins++;
        }
        std::cout<<"getroffenefelder1 ="<<getroffeneFelderEins<<std::endl;
        felderEins[row][col]->setStyleSheet("background-color: green;");
        return true;
    }
    else{
        return false;
    }
}

bool Brett::getroffenZwei(int row, int col,bool skip){
    if(felderZwei[row][col]->styleSheet() == "background-color: black;"){
        if(skip == false){
            getroffeneFelderZwei++;
        }
        std::cout<<"getroffenefelder2 ="<<getroffeneFelderZwei<<std::endl;
        felderEins[row][col]->setStyleSheet("background-color: green;");
        return true;
    }else{
        return false;
    }
}

bool Brett::doppelt(int row,int col){
    if(felderEins[row][col]->styleSheet() == "background-color: green;")
    {
        std::cout<<"Du hast bereits hier drauf geklickt"<<std::endl;
        return false;
    }
    return true;
}

bool Brett::gewonnen(){
    if(getroffeneFelderEins == 14){
        std::cout<<"Spieler 1 hat gewonnen"<<std::endl;
        getroffeneFelderEins = 0;
        getroffeneFelderZwei = 0;
        return true;
    }
    else if(getroffeneFelderZwei == 14){
        std::cout<<"Spieler 2 hat gewonnen"<<std::endl;
        getroffeneFelderEins = 0;
        getroffeneFelderZwei = 0;
        return true;
    }
    return false;
}
