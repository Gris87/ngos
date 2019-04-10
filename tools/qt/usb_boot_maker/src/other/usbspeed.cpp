#include "usbspeed.h"



const char* usbSpeedToString(UsbSpeed speed)
{
    switch (speed)
    {
        case UsbSpeed::NONE:           return "";
        case UsbSpeed::LOW:            return "USB 1.0";
        case UsbSpeed::FULL:           return "USB 1.1";
        case UsbSpeed::HIGH:           return "USB 2.0";
        case UsbSpeed::SUPER_OR_LATER: return "USB 3.0";

        default: return "UNKNOWN";
    }
}
