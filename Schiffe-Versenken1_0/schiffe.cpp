#include "schiffe.h"

Schiffe::Schiffe(int _groesse, std::string _ausrichtung) : groesse(_groesse), ausrichtung(_ausrichtung) {
    scene = new QGraphicsScene();
}

Schiffe::~Schiffe() {
    delete scene; // Clean up QGraphicsScene
}

QGraphicsScene* Schiffe::getScene() {
    return scene;
}

void Schiffe::spitzeOben() {}
void Schiffe::spitzeLinks(){}
void Schiffe::geradeVertikal(){}
void Schiffe::geradeHorrizontal(){}
