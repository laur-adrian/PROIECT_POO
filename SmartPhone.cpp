#include "SmartPhone.h"

using namespace std;


SmartPhone::SmartPhone(const char versOs[15], const char conex[15], const char nume[20], int spatiuStocare, int memorie, int capacitatebaterie, const Ecran &e)
        : Gadget(versOs, conex), _spatiuStocare(new int (spatiuStocare)), _memorie(new int (memorie)), _capacitatebaterie(new int (capacitatebaterie)), _e(e) {
    strcpy(_nume,nume);
}

SmartPhone::SmartPhone(const SmartPhone &ob) : Gadget(ob.getOs(), ob.getConexiune()),
                                               _spatiuStocare(new int (*ob.getSpatiuStocare())), _memorie(new int (*ob.getMemorie())),
                                               _capacitatebaterie(new int (*ob.getCapacitatebaterie())){
    strcpy(_nume,ob._nume);
    *_spatiuStocare=*ob.getSpatiuStocare();
    *_memorie=*ob._memorie;
    *_capacitatebaterie=*ob._capacitatebaterie;
    _e=ob._e;

}

const char* SmartPhone::getNume() const{
    return _nume;
}

int* SmartPhone::getSpatiuStocare() const {
    return _spatiuStocare;
}

int* SmartPhone::getMemorie() const {
    return _memorie;
}

int* SmartPhone::getCapacitatebaterie() const {
    return _capacitatebaterie;
}

const Ecran& SmartPhone::getE() const {
    return _e;
}

void SmartPhone::setNume(const char *nume){
    strcpy(_nume,nume);
}

void SmartPhone::setSpatiuStocare(int spatiuStocare) {
    *_spatiuStocare = spatiuStocare;
}

void SmartPhone::setMemorie(int memorie) {
    *_memorie = memorie;
}

void SmartPhone::setCapacitatebaterie(int capacitatebaterie) {
    *_capacitatebaterie = capacitatebaterie;
}

void SmartPhone::setE(const Ecran &e) {
    SmartPhone::_e = e;
}

SmartPhone& SmartPhone::operator =(const SmartPhone &ob){
    this->setOs(ob.getOs());
    this->setConexiune(ob.getConexiune());
    strcpy(_nume,ob._nume);
    *_spatiuStocare=*ob._spatiuStocare;
    *_memorie=*ob._memorie;
    *_capacitatebaterie=*ob._capacitatebaterie;
    this->_e=ob._e;
    return *this;
}

ostream &operator<<(ostream &os, const SmartPhone &phone) {
    os << "Telefonul " << phone._nume << " are specificatiile:"<< endl << "Sistem de Operare: "<< phone.getOs()<< ", Conexiune: "<< phone.getConexiune()
       << ", Spatiu de Stocare: "<< *phone._spatiuStocare << " GB, Memorie RAM: "<< *phone._memorie << " GB RAM, Capacitate Baterie: " << *phone._capacitatebaterie
       << " mAh, Ecran: "<< phone._e <<endl << endl;
    return os;
}

void SmartPhone::SeViruseaza(){
    *this->_spatiuStocare-=2;
    *this->_memorie-=4;
    *this->_capacitatebaterie-=1000;
    cout<< rang::style::bold << rang::fg::red <<"PACAT!! Telefonul tau "<< this->_nume <<" a fost virusat!!Acum mai ai doar "<<*this->_spatiuStocare<<" GB, "
        <<*this->_memorie<<" GB RAM, "<<*this->_capacitatebaterie<<" mAh baterie!" << rang::fg::reset << rang::style::reset << endl << endl;
    throw std::runtime_error("S-a virusat telefonul!!");
}

void SmartPhone::printCaracteristici(){
    cout << rang::fg::blue << *this << rang::fg::reset;
}

SmartPhone::~SmartPhone() {
    delete _spatiuStocare;
    delete _memorie;
    delete _capacitatebaterie;
    cout << "S-a sters Obiectul " << _nume << endl << endl;
}
