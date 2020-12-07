#include "Ecran.h"

using namespace std;

Ecran::Ecran(int diag,const char tehn_ecr[15],const char rez[6]): _diag(std::unique_ptr<int>(new int(diag))){
    strcpy(tehnologie_ecran,tehn_ecr);
    strcpy(rezolutie,rez);
}

Ecran::Ecran (const Ecran & ob): _diag(std::unique_ptr<int>(new int (*ob._diag))){
    strcpy(this->tehnologie_ecran,ob.tehnologie_ecran);
    strcpy(this->rezolutie,ob.rezolutie);
}

int Ecran::getDiag() const {
    return *_diag;
}

const char* Ecran::getTehnologieEcran() const {
    return tehnologie_ecran;
}

const char* Ecran::getRezolutie() const {
    return rezolutie;
}

void Ecran::setDiag(int diag) {
    *_diag = diag;
}

void Ecran::setTehnologieEcran(const char *tehnologieecran){
    strcpy(tehnologie_ecran, tehnologieecran);
}

void Ecran::setRezolutie(const char *rez){
    strcpy(rezolutie,rez);
}

Ecran& Ecran::operator=(const Ecran &ob){
    *_diag=*ob._diag;
    strcpy(tehnologie_ecran,ob.tehnologie_ecran);
    strcpy(rezolutie,ob.rezolutie);
    return *this;
}

ostream&operator<<(ostream &os, const Ecran &ecran) {
    os << "Diagonala: " << *ecran._diag << " Tehnologie Ecran: " << ecran.tehnologie_ecran << " Rezolutie Ecran: "
       << ecran.rezolutie;
    return os;
}


Ecran::~Ecran(){
    cout << "S-a sters Ecranul " << tehnologie_ecran << " cu diagonala " << *_diag << " si rezolutia " << rezolutie << endl << endl ;
}