#ifndef COM_NGOS_SHARED_COMMON_UEFI_UEFIABSOLUTEPOINTERSTATE_H
#define COM_NGOS_SHARED_COMMON_UEFI_UEFIABSOLUTEPOINTERSTATE_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/uefi/uefiabsolutepointerstateactivebuttonflags.h>



struct UefiAbsolutePointerState
{
    bad_uint64                                       currentX;
    bad_uint64                                       currentY;
    bad_uint64                                       currentZ;
    UefiAbsolutePointerStateActiveButtonFlags activeButtons;
};



#endif // COM_NGOS_SHARED_COMMON_UEFI_UEFIABSOLUTEPOINTERSTATE_H
