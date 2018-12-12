#ifndef CONFIGURE_SRC_BITS64_A_UEFI_UEFI_LIB_EFIPIXELBITMASK_H
#define CONFIGURE_SRC_BITS64_A_UEFI_UEFI_LIB_EFIPIXELBITMASK_H



#include <ngos/types.h>



struct EfiPixelBitmask
{
    u32 redMask;
    u32 greenMask;
    u32 blueMask;
    u32 reservedMask;
};



#endif // CONFIGURE_SRC_BITS64_A_UEFI_UEFI_LIB_EFIPIXELBITMASK_H
