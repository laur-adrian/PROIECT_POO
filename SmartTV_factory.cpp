#include "SmartTV_factory.h"
#include "Ecran.h"

SmartTV SmartTV_factory::HisenseTv() {
    Ecran ecran = Ecran(32, "LED", "FullHD");
    return SmartTV("WebOs", "Cablu", "HisenseSmartTv", 2, "DVB-C", ecran);
}

SmartTV SmartTV_factory::PhilipsTv() {
    Ecran ecran = Ecran(52, "OLED", "4K");
    return SmartTV("Android 9", "Cablu+WIFI", "PhilipsSmartTv", 4, "DVB-C/T/S", ecran);
}