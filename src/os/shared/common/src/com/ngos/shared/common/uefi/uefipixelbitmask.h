#ifndef UEFI_UEFIPIXELBITMASK_H
#define UEFI_UEFIPIXELBITMASK_H



#include <ngos/types.h>



struct UefiPixelBitmask
{
    u32 redMask;
    u32 greenMask;
    u32 blueMask;
    u32 reservedMask;
};



#endif // UEFI_UEFIPIXELBITMASK_H
