#include "Gadget.h"

using namespace std;

Gadget::Gadget(const char vers_OS[15],const char conex[15]) {
    strcpy(OS, vers_OS);
    strcpy(conexiune, conex);
}

const char* Gadget::getOs() const {
    return OS;
}

const char* Gadget::getConexiune() const {
    return conexiune;
}

void Gadget::setOs(const char *os){
    strcpy(OS,os);
}

void Gadget::setConexiune(const char *conex){
    strcpy(conexiune,conex);
}

Gadget& Gadget::operator=(const Gadget &ob){
    strcpy(OS,ob.OS);
    strcpy(conexiune,ob.conexiune);
    return *this;
}

ostream &operator<<(ostream &os, const Gadget &gadget) {
    os << "OS: " << gadget.OS << " conexiune: " << gadget.conexiune;
    return os;
}

void Gadget::printCaracteristici (){
    cout<< "Sistem de Operare: " << getOs() << endl << "Conexiune: " << getConexiune() << endl << endl;
}

Gadget::~Gadget() = default;
