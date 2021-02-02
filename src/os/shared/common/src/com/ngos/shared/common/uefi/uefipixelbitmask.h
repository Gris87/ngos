#ifndef COM_NGOS_SHARED_COMMON_UEFI_UEFIPIXELBITMASK_H
#define COM_NGOS_SHARED_COMMON_UEFI_UEFIPIXELBITMASK_H



#include <com/ngos/shared/common/ngos/types.h>



struct UefiPixelBitmask
{
    bad_uint32 redMask;
    bad_uint32 greenMask;
    bad_uint32 blueMask;
    bad_uint32 reservedMask;
};



#endif // COM_NGOS_SHARED_COMMON_UEFI_UEFIPIXELBITMASK_H
