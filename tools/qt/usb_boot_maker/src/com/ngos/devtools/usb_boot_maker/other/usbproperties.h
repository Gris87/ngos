#ifndef USB_BOOT_MAKER_SRC_OTHER_USBPROPERTIES_H
#define USB_BOOT_MAKER_SRC_OTHER_USBPROPERTIES_H



#include <Qt>

#include "src/other/usbspeed.h"



struct UsbProperties
{
    quint32  vid;
    quint32  pid;
    quint32  port;
    UsbSpeed speed;
    bool     isUSB;
    bool     isSCSI;
    bool     isCARD;
    bool     isUASP;
    bool     isVHD;
    bool     isRemovable;
    bool     isLowerSpeed;
};



#endif // USB_BOOT_MAKER_SRC_OTHER_USBPROPERTIES_H
