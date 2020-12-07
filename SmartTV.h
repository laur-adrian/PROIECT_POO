#ifndef MAIN_CPP_SMARTTV_H
#define MAIN_CPP_SMARTTV_H

#include <iostream>
#include <cstring>
#include "Ecran.h"
#include "Gadget.h"
#include "rang.hpp"


class SmartTV : public Gadget{

private:
    char _nume[20];
    int *_nrPorturiHDMI;
    char TunerDigital[7];
    Ecran _e=Ecran(0,"", "");

public:
    SmartTV(const char versOs[15], const char conex[15], const char nume[20], int nrPorturiHdmi, const char tunerDigital[7], const Ecran &e);

    SmartTV(const SmartTV &ob);

    const char *getNume() const;

    void setNume(const char nume[20]);

    int *getNrPorturiHdmi() const;

    void setNrPorturiHdmi(int nrPorturiHdmi);

    const char *getTunerDigital() const;

    void setTunerDigital(const char tunerDigital[7]);

    const Ecran &getE() const;

    void setE(const Ecran &e);

    SmartTV &operator =(const SmartTV &ob);

    friend std::ostream &operator<<(std::ostream &os, const SmartTV &tv);

    void printCaracteristici() override;

    ~SmartTV();

};


#endif
