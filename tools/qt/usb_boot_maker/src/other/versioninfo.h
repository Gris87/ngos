#ifndef USB_BOOT_MAKER_SRC_OTHER_VERSIONINFO_H
#define USB_BOOT_MAKER_SRC_OTHER_VERSIONINFO_H



#include <QString>



struct VersionInfo
{
    quint64 id;
    quint64 version;
    QString hash;
    QString server;
    qint64  delay;
};



#endif // USB_BOOT_MAKER_SRC_OTHER_VERSIONINFO_H
