#ifndef UEFI_UEFIFILEPATH_H
#define UEFI_UEFIFILEPATH_H



#include <common/src/com/ngos/shared/common/ngos/types.h>
#include <common/src/com/ngos/shared/common/uefi/types.h>
#include <common/src/com/ngos/shared/common/uefi/uefidevicepath.h>



struct UefiFilePath
{
    UefiDevicePath header;
    char16         pathName[0];
};



#endif // UEFI_UEFIFILEPATH_H
