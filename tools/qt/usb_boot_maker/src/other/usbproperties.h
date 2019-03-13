#ifndef USBPROPERTIES_H
#define USBPROPERTIES_H



#include <Qt>



struct UsbProperties
{
    quint32  vid;
    quint32  pid;
    quint32  speed;
    quint32  port;
    bool     isUSB;
    bool     isSCSI;
    bool     isCARD;
    bool     isUASP;
    bool     isVHD;
    bool     isRemovable;
    bool     isLowerSpeed;
};



#endif // USBPROPERTIES_H
