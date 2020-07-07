#ifndef BOOTLOADER_SRC_COM_NGOS_BOOTLOADER_OTHER_OSINFO_H
#define BOOTLOADER_SRC_COM_NGOS_BOOTLOADER_OTHER_OSINFO_H



#include <com/ngos/bootloader/other/ostype.h>
#include <com/ngos/bootloader/other/volumeinfo.h>



struct OsInfo
{
    OsType        type;
    VolumeInfo   *volume;
    const char16 *path;



    bool operator<(const OsInfo &another) const // TEST: NO
    {
        if (volume->type < another.volume->type)
        {
            return true;
        }

        if (volume->type > another.volume->type)
        {
            return false;
        }

        if (type < another.type)
        {
            return true;
        }

        if (type > another.type)
        {
            return false;
        }

        return strcmpi(path, another.path) < 0;
    }
};



#endif // BOOTLOADER_SRC_COM_NGOS_BOOTLOADER_OTHER_OSINFO_H
