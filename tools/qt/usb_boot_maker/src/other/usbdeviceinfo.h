#ifndef USB_BOOT_MAKER_SRC_OTHER_USBDEVICEINFO_H
#define USB_BOOT_MAKER_SRC_OTHER_USBDEVICEINFO_H



#include <QString>



struct UsbDeviceInfo
{
    QString title;
    quint64 diskNumber;
    quint64 diskSize;
    QString letters;
    QString deviceName;
};

Q_DECLARE_METATYPE(UsbDeviceInfo *); // TEST: NO



#endif // USB_BOOT_MAKER_SRC_OTHER_USBDEVICEINFO_H
