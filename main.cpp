#include <iostream>
#include "Gadget.h"
#include "Ecran.h"
#include "SmartPhone.h"
#include "SmartTV.h"

using namespace std;

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
    try{
        p1.SeViruseaza();
    }
    catch (std::runtime_error& e) {
        cout<< rang::style::bold << rang::fg::red << e.what() << rang::fg::reset << rang::style::reset << endl << endl;
    }
    p1.printCaracteristici();

    SmartTV tv1=SmartTV("Android9","cablu","Samsung SmartTV",2,"DVB-C",e2);
    cout<<tv1;
    tv1.setConexiune("Cablu si Wifi");
    cout<< tv1;
    SmartTV tv2(tv1);
    tv2.setNume("LG");
    tv2.setNrPorturiHdmi(3);
    tv2.setConexiune("WiFi");
    tv2.printCaracteristici();

    return 0;
}
