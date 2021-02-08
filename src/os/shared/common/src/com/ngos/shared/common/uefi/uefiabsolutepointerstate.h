#ifndef COM_NGOS_SHARED_COMMON_UEFI_UEFIABSOLUTEPOINTERSTATE_H
#define COM_NGOS_SHARED_COMMON_UEFI_UEFIABSOLUTEPOINTERSTATE_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/uefi/uefiabsolutepointerstateactivebuttonflags.h>



struct UefiAbsolutePointerState
{
    u64                                       currentX;
    u64                                       currentY;
    u64                                       currentZ;
    UefiAbsolutePointerStateActiveButtonFlags activeButtons;
};



#endif // COM_NGOS_SHARED_COMMON_UEFI_UEFIABSOLUTEPOINTERSTATE_H
