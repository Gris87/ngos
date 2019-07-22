#ifndef USB_BOOT_MAKER_SRC_OTHER_USBSPEED_H
#define USB_BOOT_MAKER_SRC_OTHER_USBSPEED_H



#include <Qt>



enum class UsbSpeed: quint8 // Ignore CppEnumVerifier
{
    NONE           = 0,
    LOW            = 1,
    FULL           = 2,
    HIGH           = 3,
    SUPER_OR_LATER = 4
};



inline const char* usbSpeedToString(UsbSpeed speed) // TEST: NO
{
    switch (speed)
    {
        case UsbSpeed::NONE:           return "NONE";
        case UsbSpeed::LOW:            return "USB 1.0";
        case UsbSpeed::FULL:           return "USB 1.1";
        case UsbSpeed::HIGH:           return "USB 2.0";
        case UsbSpeed::SUPER_OR_LATER: return "USB 3.0";

        default: return "UNKNOWN";
    }
}



#endif // USB_BOOT_MAKER_SRC_OTHER_USBSPEED_H
