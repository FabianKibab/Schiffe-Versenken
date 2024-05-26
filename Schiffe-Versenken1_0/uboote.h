#ifndef UBOOTE_H
#define UBOOTE_H
#include "schiffe.h"

//Sind 2 Kaesten lang

class UBoote:public Schiffe{
public:
    void spitzeOben() override;
    void spitzeLinks() override;
    void geradeVertikal() override;
    void geradeHorrizontal() override;
};

#endif // UBOOTE_H
