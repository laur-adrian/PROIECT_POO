#include "SmartTV.h"

using namespace std;

SmartTV::SmartTV(const char versOs[15], const char conex[15], const char nume[20], int nrPorturiHdmi, const char tunerDigital[7], const Ecran &e) : Gadget(versOs, conex), _nrPorturiHDMI(nrPorturiHdmi), _e(e){
    strcpy(_nume,nume);
    strcpy(TunerDigital,tunerDigital);
}

SmartTV::SmartTV(const SmartTV &ob) : Gadget(ob.getOs(), ob.getConexiune()),_nrPorturiHDMI(ob._nrPorturiHDMI) {

    strcpy(_nume,ob._nume);
    strcpy(TunerDigital,ob.TunerDigital);
    _e=ob._e;

}

const char* SmartTV::getNume() const {
    return _nume;
}

void SmartTV::setNume(const char nume[20]){
    strcpy(_nume,nume);
}

int SmartTV::getNrPorturiHdmi() const {
    return _nrPorturiHDMI;
}

void SmartTV::setNrPorturiHdmi(int nrPorturiHdmi) {
    _nrPorturiHDMI = nrPorturiHdmi;
}

const char* SmartTV::getTunerDigital() const {
    return TunerDigital;
}

void SmartTV::setTunerDigital(const char tunerDigital[7]){
    strcpy(TunerDigital,tunerDigital);
}

const Ecran& SmartTV::getE() const {
    return _e;
}

void SmartTV::setE(const Ecran &e) {
    SmartTV::_e = e;
}

SmartTV& SmartTV::operator =(const SmartTV &ob) {
    this->setOs(ob.getOs());
    this->setConexiune(ob.getConexiune());
    strcpy(this->_nume,ob._nume);
    this->_nrPorturiHDMI =ob._nrPorturiHDMI;
    strcpy(this->TunerDigital, ob.TunerDigital);
    this->_e = ob._e;
    return *this;
}

ostream &operator<<(ostream &os, const SmartTV &tv) {
    os << "Televizorul "<< tv._nume << " are specificatiile:\n" << "Sistem de Operare: "<< tv.getOs()<< ", Conexiune: "<< tv.getConexiune()
       << ", Numar de Porturi HDMI: " << tv._nrPorturiHDMI << ", Tuner Digital: "<< tv.TunerDigital << ", Ecran: " << tv._e << endl << endl;
    return os;
}

void SmartTV::printCaracteristici(){
    cout << rang::fg::blue << *this << rang::fg::reset;
}

SmartTV::~SmartTV() {
    cout << "S-a sters Obiectul " << _nume << endl << endl;
}
