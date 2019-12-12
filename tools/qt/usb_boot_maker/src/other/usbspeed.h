#ifndef USB_BOOT_MAKER_SRC_OTHER_USBSPEED_H
#define USB_BOOT_MAKER_SRC_OTHER_USBSPEED_H



#include <Qt>



enum class UsbSpeed: quint8
{
    NONE           = 0,
    LOW            = 1,
    FULL           = 2,
    HIGH           = 3,
    SUPER_OR_LATER = 4
};



inline const char* enumToString(UsbSpeed speed) // TEST: NO
{
    switch (speed)
    {
        case UsbSpeed::NONE:           return "NONE";
        case UsbSpeed::LOW:            return "LOW";
        case UsbSpeed::FULL:           return "FULL";
        case UsbSpeed::HIGH:           return "HIGH";
        case UsbSpeed::SUPER_OR_LATER: return "SUPER_OR_LATER";

        default: return "UNKNOWN";
    }
}



inline const char* enumToFullString(UsbSpeed speed) // TEST: NO
{
    switch (speed)
    {
        case UsbSpeed::NONE:           return "NONE";
        case UsbSpeed::LOW:            return "LOW";
        case UsbSpeed::FULL:           return "FULL";
        case UsbSpeed::HIGH:           return "HIGH";
        case UsbSpeed::SUPER_OR_LATER: return "SUPER_OR_LATER";

        default: return "UNKNOWN";
    }
}



inline const char* enumToHumanString(UsbSpeed speed) // TEST: NO
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
