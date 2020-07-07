#ifndef USB_BOOT_MAKER_SRC_COM_NGOS_DEVTOOLS_USB_BOOT_MAKER_OTHER_USBSPEED_H
#define USB_BOOT_MAKER_SRC_COM_NGOS_DEVTOOLS_USB_BOOT_MAKER_OTHER_USBSPEED_H



#include <Qt>
#include <stdio.h>

#include <com/ngos/shared/common/ngos/types.h>



enum class UsbSpeed: quint8 // Ignore CppEnumVerifier
{
    NONE           = 0,
    LOW            = 1,
    FULL           = 2,
    HIGH           = 3,
    SUPER_OR_LATER = 4
};



inline const char8* enumToString(UsbSpeed speed) // TEST: NO
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



inline const char8* enumToFullString(UsbSpeed speed) // TEST: NO
{
    static char8 res[22];

    sprintf(res, "0x%02X (%s)", (quint8)speed, enumToString(speed));

    return res;
}



inline const char8* enumToHumanString(UsbSpeed speed) // TEST: NO
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



#endif // USB_BOOT_MAKER_SRC_COM_NGOS_DEVTOOLS_USB_BOOT_MAKER_OTHER_USBSPEED_H
