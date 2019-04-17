#ifndef USB_BOOT_MAKER_SRC_OTHER_FILEINFO_H
#define USB_BOOT_MAKER_SRC_OTHER_FILEINFO_H



#include <QString>



struct FileInfo
{
    QString downloadName;
    QString filename;
    QString hash;
};

Q_DECLARE_METATYPE(FileInfo *); // TEST: NO



#endif // USB_BOOT_MAKER_SRC_OTHER_FILEINFO_H
