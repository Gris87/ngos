#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFIPIXELBITMASK_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFIPIXELBITMASK_H



#include <common/src/com/ngos/shared/common/ngos/types.h>



struct UefiPixelBitmask
{
    u32 redMask;
    u32 greenMask;
    u32 blueMask;
    u32 reservedMask;
};



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFIPIXELBITMASK_H
