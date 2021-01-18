#ifndef MAIN_CPP_SMARTPHONE_H
#define MAIN_CPP_SMARTPHONE_H

#include <iostream>
#include <cstring>
#include "Ecran.h"
#include "Gadget.h"
#include "rang.hpp"


class SmartPhone : public Gadget {

private:
    char _nume[20];
    int _spatiuStocare;
    int _memorie;
    int _capacitatebaterie;
    Ecran _e = Ecran(0, "", "");

public:
    SmartPhone(const char versOs[15], const char conex[15], const char nume[20], int spatiuStocare, int memorie,
               int capacitatebaterie, const Ecran &e);

    SmartPhone(const SmartPhone &ob);

    const char *getNume() const;

    int getSpatiuStocare() const;

    int getMemorie() const;

    int getCapacitatebaterie() const;

    const Ecran &getE() const;

    void setNume(const char *nume);

    void setSpatiuStocare(int spatiuStocare);

    void setMemorie(int memorie);

    void setCapacitatebaterie(int capacitatebaterie);

    void setE(const Ecran &e);

    SmartPhone &operator=(const SmartPhone &ob);

    friend std::ostream &operator<<(std::ostream &os, const SmartPhone &phone);

    void SeViruseaza();

    void printCaracteristici() override;

    ~SmartPhone();

};


#endif