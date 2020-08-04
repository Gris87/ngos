#ifndef COM_NGOS_SHARED_COMMON_UEFI_UEFIFILEPATH_H
#define COM_NGOS_SHARED_COMMON_UEFI_UEFIFILEPATH_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/uefi/types.h>
#include <com/ngos/shared/common/uefi/uefidevicepath.h>



struct UefiFilePath
{
    UefiDevicePath header;
    char16         pathName[0];
};



#endif // COM_NGOS_SHARED_COMMON_UEFI_UEFIFILEPATH_H
