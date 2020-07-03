#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFIFILEPATH_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFIFILEPATH_H



#include <common/src/com/ngos/shared/common/ngos/types.h>
#include <common/src/com/ngos/shared/common/uefi/types.h>
#include <common/src/com/ngos/shared/common/uefi/uefidevicepath.h>



struct UefiFilePath
{
    UefiDevicePath header;
    char16         pathName[0];
};



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFIFILEPATH_H
