#ifndef UEFI_UEFIABSOLUTEPOINTERSTATE_H
#define UEFI_UEFIABSOLUTEPOINTERSTATE_H



#include <common/src/com/ngos/shared/common/ngos/types.h>
#include <common/src/com/ngos/shared/common/uefi/uefiabsolutepointerstateactivebuttonflags.h>



struct UefiAbsolutePointerState
{
    u64                                       currentX;
    u64                                       currentY;
    u64                                       currentZ;
    UefiAbsolutePointerStateActiveButtonFlags activeButtons;
};



#endif // UEFI_UEFIABSOLUTEPOINTERSTATE_H
