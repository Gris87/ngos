#ifndef USB_BOOT_MAKER_SRC_OTHER_USBSPEED_H
#define USB_BOOT_MAKER_SRC_OTHER_USBSPEED_H



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



#endif // USB_BOOT_MAKER_SRC_OTHER_USBSPEED_H
