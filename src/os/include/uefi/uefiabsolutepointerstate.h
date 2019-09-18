#ifndef UEFI_UEFIABSOLUTEPOINTERSTATE_H
#define UEFI_UEFIABSOLUTEPOINTERSTATE_H



#include <ngos/types.h>
#include <uefi/uefiabsolutepointerstateactivebuttonflags.h>



struct UefiAbsolutePointerState
{
    u64                                             currentX;
    u64                                             currentY;
    u64                                             currentZ;
    uefi_absolute_pointer_state_active_button_flags activeButtons;
};



#endif // UEFI_UEFIABSOLUTEPOINTERSTATE_H
