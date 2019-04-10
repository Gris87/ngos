#ifndef USBSPEED_H
#define USBSPEED_H



#include <Qt>



enum class UsbSpeed: quint8
{
    NONE,
    LOW,
    FULL,
    HIGH,
    SUPER_OR_LATER
};



const char* usbSpeedToString(UsbSpeed speed); // TEST: NO



#endif // USBSPEED_H
