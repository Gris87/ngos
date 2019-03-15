#ifndef USBPROPERTIES_H
#define USBPROPERTIES_H



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



#endif // USBPROPERTIES_H
