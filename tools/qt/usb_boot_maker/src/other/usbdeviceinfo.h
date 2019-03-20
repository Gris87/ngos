#ifndef USBDEVICEINFO_H
#define USBDEVICEINFO_H



#include <QString>



struct UsbDeviceInfo
{
    QString title;
};

Q_DECLARE_METATYPE(UsbDeviceInfo *);



#endif // USBDEVICEINFO_H
