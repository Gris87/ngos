#ifndef BOOTLOADER_SRC_BITS64_OTHER_OSINFO_H
#define BOOTLOADER_SRC_BITS64_OTHER_OSINFO_H



#include "src/bits64/other/ostype.h"
#include "src/bits64/other/volumeinfo.h"



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



#endif // BOOTLOADER_SRC_BITS64_OTHER_OSINFO_H
