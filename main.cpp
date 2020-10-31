#include <iostream>
#include <cstring>

#define RESET   "\033[0m"
#define BOLDRED     "\033[1m\033[31m"

using namespace std;

class Gadget{

private:
    char OS[15];
    char conexiune[20];

public:
    Gadget(const char vers_OS[15],const char conex[15]) {
        strcpy(OS, vers_OS);
        strcpy(conexiune, conex);
    }

    const char *getOs() const {
        return OS;
    }

    const char *getConexiune() const {
        return conexiune;
    }
    
    void setOs(const char *os){
        strcpy(OS,os);
    }

    void setConexiune(const char *conex){
        strcpy(conexiune,conex);
    }

    Gadget &operator=(const Gadget &ob){
        strcpy(OS,ob.OS);
        strcpy(conexiune,ob.conexiune);
    }

    friend ostream &operator<<(ostream &os, const Gadget &gadget) {
        os << "OS: " << gadget.OS << " conexiune: " << gadget.conexiune;
        return os;
    }

};

class Ecran{

private:
    int *_diag;
    char tehnologie_ecran[15];
    char rezolutie[10];

public:
    Ecran(int diag,const char tehn_ecr[15],const char rez[6]){
        _diag=new int(diag);
        strcpy(tehnologie_ecran,tehn_ecr);
        strcpy(rezolutie,rez);
    }

    Ecran (const Ecran & ob) {
        _diag=new int (*ob._diag);
        strcpy(this->tehnologie_ecran,ob.tehnologie_ecran);
        strcpy(this->rezolutie,ob.rezolutie);
    }

    int *getDiag() const {
        return _diag;
    }

    const char *getTehnologieEcran() const {
        return tehnologie_ecran;
    }

    const char *getRezolutie() const {
        return rezolutie;
    }

    void setDiag(int diag) {
        *_diag = diag;
    }

    void setTehnologieEcran(const char *tehnologieecran){
        strcpy(tehnologie_ecran, tehnologieecran);
    }

    void setRezolutie(const char *rez){
        strcpy(rezolutie,rez);
    }

    Ecran &operator=(const Ecran &ob){
        *_diag=*ob._diag;
        strcpy(tehnologie_ecran,ob.tehnologie_ecran);
        strcpy(rezolutie,ob.rezolutie);
    }

    friend ostream &operator<<(ostream &os, const Ecran &ecran) {
        os << "Diagonala: " << *ecran._diag << " Tehnologie Ecran: " << ecran.tehnologie_ecran << " Rezolutie Ecran: "
           << ecran.rezolutie;
        return os;
    }

    ~Ecran(){
        delete _diag;
    }

};

class SmartPhone : public Gadget{

private:
    char _nume[20];
    int *_spatiuStocare;
    int *_memorie;
    int *_capacitatebaterie;
    Ecran _e = Ecran(0, "", "");

public:
    SmartPhone(const char versOs[15], const char conex[15], const char nume[20], int spatiuStocare, int memorie, int capacitatebaterie, const Ecran &e)
            : Gadget(versOs, conex),_e(e) {
        strcpy(_nume,nume);
        _spatiuStocare=new int (spatiuStocare);
        _memorie=new int (memorie);
        _capacitatebaterie=new int (capacitatebaterie);
    }

    SmartPhone(const SmartPhone &ob) : Gadget(ob.getOs(), ob.getConexiune()) {
        strcpy(_nume,ob._nume);
        *_spatiuStocare=*ob._spatiuStocare;
        *_memorie=*ob._memorie;
        *_capacitatebaterie=*ob._capacitatebaterie;
        _e=ob._e;

    }

    const char *getNume() const{
        return _nume;
    }

    int *getSpatiuStocare() const {
        return _spatiuStocare;
    }

    int *getMemorie() const {
        return _memorie;
    }

    int *getCapacitatebaterie() const {
        return _capacitatebaterie;
    }

    const Ecran &getE() const {
        return _e;
    }

    void setNume(const char *nume){
        strcpy(_nume,nume);
    }

    void setSpatiuStocare(int spatiuStocare) {
        *_spatiuStocare = spatiuStocare;
    }

    void setMemorie(int memorie) {
        *_memorie = memorie;
    }

    void setCapacitatebaterie(int capacitatebaterie) {
        *_capacitatebaterie = capacitatebaterie;
    }

    void setE(const Ecran &e) {
        SmartPhone::_e = e;
    }

    SmartPhone &operator =(const SmartPhone &ob){
        this->setOs(ob.getOs());
        this->setConexiune(ob.getConexiune());
        strcpy(_nume,ob._nume);
        *_spatiuStocare=*ob._spatiuStocare;
        *_memorie=*ob._memorie;
        *_capacitatebaterie=*ob._capacitatebaterie;
        this->_e=ob._e;
    }

    friend ostream &operator<<(ostream &os, const SmartPhone &phone) {
        os << "Telefonul " << phone._nume << " are specificatiile:"<< endl << "Sistem de Operare: "<< phone.getOs()<< ", Conexiune: "<< phone.getConexiune()
            << ", Spatiu de Stocare: "<< *phone._spatiuStocare << " GB, Memorie RAM: "<< *phone._memorie << " GB RAM, Capacitate Baterie: " << *phone._capacitatebaterie
            << " mAh, Ecran: "<< phone._e <<endl << endl;
        return os;
    }

    void SeViruseaza(){
        *this->_spatiuStocare-=2;
        *this->_memorie-=4;
        *this->_capacitatebaterie-=1000;
        cout<< BOLDRED <<"PACAT!! Telefonul tau "<< this->_nume <<" a fost virusat!!Acum mai ai doar "<<*this->_spatiuStocare<<" GB, "<<*this->_memorie<<" GB RAM, "
            <<*this->_capacitatebaterie<<" mAh baterie!\n" << RESET << endl;
    }

    ~SmartPhone() {
        delete _spatiuStocare;
        delete _memorie;
        delete _capacitatebaterie;
        cout << "S-a sters Obiectul " << _nume << endl << endl ;    }
};

class SmartTV : public Gadget{

private:
    char _nume[20];
    int *_nrPorturiHDMI;
    char TunerDigital[7];
    Ecran _e=Ecran(0,"", "");

public:
    SmartTV(const char versOs[15], const char conex[15], const char nume[20], int nrPorturiHdmi, const char tunerDigital[7], const Ecran &e) : Gadget(versOs, conex),_e(e) {
        strcpy(_nume,nume);
        _nrPorturiHDMI = new int (nrPorturiHdmi);
        strcpy(TunerDigital,tunerDigital);
    }

    SmartTV(const SmartTV &ob) : Gadget(ob.getOs(), ob.getConexiune()) {

        strcpy(_nume,ob._nume);
        _nrPorturiHDMI=new int (*ob._nrPorturiHDMI);
        strcpy(TunerDigital,ob.TunerDigital);
        _e=ob._e;

    }

    const char *getNume() const {
        return _nume;
    }

    void setNume(const char nume[20]){
        strcpy(_nume,nume);
    }

    int *getNrPorturiHdmi() const {
        return _nrPorturiHDMI;
    }

    void setNrPorturiHdmi(int nrPorturiHdmi) {
        *_nrPorturiHDMI = nrPorturiHdmi;
    }

    const char *getTunerDigital() const {
        return TunerDigital;
    }

    void setTunerDigital(const char tunerDigital[7]){
        strcpy(TunerDigital,tunerDigital);
    }

    const Ecran &getE() const {
        return _e;
    }

    void setE(const Ecran &e) {
        SmartTV::_e = e;
    }

    SmartTV &operator =(const SmartTV &ob) {
        this->setOs(ob.getOs());
        this->setConexiune(ob.getConexiune());
        strcpy(this->_nume,ob._nume);
        *this->_nrPorturiHDMI =*ob._nrPorturiHDMI;
        strcpy(this->TunerDigital, ob.TunerDigital);
        this->_e = ob._e;
    }

    friend ostream &operator<<(ostream &os, const SmartTV &tv) {
        os << "Televizorul "<< tv._nume << " are specificatiile:\n" << "Sistem de Operare: "<< tv.getOs()<< ", Conexiune: "<< tv.getConexiune()
            << ", Numar de Porturi HDMI: " << *tv._nrPorturiHDMI << ", Tuner Digital: "<< tv.TunerDigital << ", Ecran: " << tv._e << endl << endl;
        return os;
    }

    ~SmartTV() {
        delete _nrPorturiHDMI;
        cout << "S-a sters Obiectul " << _nume << endl << endl ;
    }

};

int main() {

    Ecran e=Ecran(6,"IPS","FullHD");
    Ecran e2=Ecran(e);
    e2.setDiag(32);
    e2.setTehnologieEcran("LED");

    SmartPhone p1=SmartPhone("Android10","WiFi 802.11 b/g/n","Huawei P20",64,4,2500,e);
    SmartPhone p2=SmartPhone("","","",0,0,0,e);
    cout<<p1;
    p1.setMemorie(6);
    p2=p1;
    p2.setNume("Samsung S20");
    cout<<p2;
    p1.SeViruseaza();
    cout<<p1;

    SmartTV tv1=SmartTV("Android9","cablu","Samsung SmartTV",2,"DVB-C",e2);
    cout<<tv1;
    tv1.setConexiune("Cablu si Wifi");
    cout<< tv1;
    SmartTV tv2(tv1);
    tv2.setNume("LG");
    tv2.setNrPorturiHdmi(3);
    tv2.setConexiune("WiFi");
    cout<<tv2;

    return 0;
}
