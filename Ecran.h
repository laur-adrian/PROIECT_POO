#ifndef MAIN_CPP_ECRAN_H
#define MAIN_CPP_ECRAN_H

#include <iostream>
#include <cstring>
#include <memory>


class Ecran{

private:
    std::unique_ptr<int> _diag;
    char tehnologie_ecran[15];
    char rezolutie[10];

public:
    Ecran(int diag,const char tehn_ecr[15],const char rez[6]);

    Ecran (const Ecran & ob);

    int getDiag() const;

    const char *getTehnologieEcran() const;

    const char *getRezolutie() const;

    void setDiag(int diag);

    void setTehnologieEcran(const char *tehnologieecran);

    void setRezolutie(const char *rez);

    Ecran &operator=(const Ecran &ob);

    friend std::ostream &operator<<(std::ostream &os, const Ecran &ecran) ;

    ~Ecran();

};


#endif
