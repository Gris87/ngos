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



#endif // USBSPEED_H
