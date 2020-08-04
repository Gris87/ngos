#ifndef COM_NGOS_DEVTOOLS_USB_BOOT_MAKER_OTHER_USBPROPERTIES_H
#define COM_NGOS_DEVTOOLS_USB_BOOT_MAKER_OTHER_USBPROPERTIES_H



#include <Qt>

#include <com/ngos/devtools/usb_boot_maker/other/usbspeed.h>



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



#endif // COM_NGOS_DEVTOOLS_USB_BOOT_MAKER_OTHER_USBPROPERTIES_H
