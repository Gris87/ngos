#ifndef USB_BOOT_MAKER_SRC_OTHER_USBDEVICEINFO_H
#define USB_BOOT_MAKER_SRC_OTHER_USBDEVICEINFO_H



#include <QString>



struct UsbDeviceInfo
{
    QString title;
};

Q_DECLARE_METATYPE(UsbDeviceInfo *); // TEST: NO



#endif // USB_BOOT_MAKER_SRC_OTHER_USBDEVICEINFO_H
