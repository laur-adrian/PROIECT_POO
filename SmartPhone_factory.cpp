#include "SmartPhone_factory.h"
#include "SmartPhone.h"
#include "Ecran.h"

using namespace std;

SmartPhone SmartPhone_factory::HuaweiP20Lite() {
    Ecran ecran = Ecran(5, "IPS", "FullHD");
    return SmartPhone("Android 8", "WIFI", "HuaweiP20Lite", 128, 4, 4250, ecran);
}

SmartPhone SmartPhone_factory::XiaomiRedmi9() {
    Ecran ecran = Ecran(7, "LED", "FullHD");
    return SmartPhone("Android 10", "WIFI", "XiaomiRedmi9", 64, 4, 5050, ecran);
}