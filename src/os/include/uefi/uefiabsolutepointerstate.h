#ifndef UEFI_UEFIABSOLUTEPOINTERSTATE_H
#define UEFI_UEFIABSOLUTEPOINTERSTATE_H



#include <ngos/types.h>
#include <uefi/uefiabsolutepointerstateactivebuttonflags.h>



struct UefiAbsolutePointerState
{
    u64                                       currentX;
    u64                                       currentY;
    u64                                       currentZ;
    UefiAbsolutePointerStateActiveButtonFlags activeButtons;
};



#endif // UEFI_UEFIABSOLUTEPOINTERSTATE_H
