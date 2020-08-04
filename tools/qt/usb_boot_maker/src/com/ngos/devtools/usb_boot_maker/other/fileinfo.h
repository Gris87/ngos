#ifndef COM_NGOS_DEVTOOLS_USB_BOOT_MAKER_OTHER_FILEINFO_H
#define COM_NGOS_DEVTOOLS_USB_BOOT_MAKER_OTHER_FILEINFO_H



#include <QString>



struct FileInfo
{
    QString downloadName;
    QString fileName;
    QString hash;
};

Q_DECLARE_METATYPE(FileInfo *); // TEST: NO



#endif // COM_NGOS_DEVTOOLS_USB_BOOT_MAKER_OTHER_FILEINFO_H
