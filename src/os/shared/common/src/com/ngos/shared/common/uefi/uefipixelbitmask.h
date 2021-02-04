#ifndef COM_NGOS_SHARED_COMMON_UEFI_UEFIPIXELBITMASK_H
#define COM_NGOS_SHARED_COMMON_UEFI_UEFIPIXELBITMASK_H



#include <com/ngos/shared/common/ngos/types.h>



struct UefiPixelBitmask
{
    u32 redMask;
    u32 greenMask;
    u32 blueMask;
    u32 reservedMask;
};



#endif // COM_NGOS_SHARED_COMMON_UEFI_UEFIPIXELBITMASK_H
