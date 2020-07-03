#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFIABSOLUTEPOINTERSTATE_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFIABSOLUTEPOINTERSTATE_H



#include <common/src/com/ngos/shared/common/ngos/types.h>
#include <common/src/com/ngos/shared/common/uefi/uefiabsolutepointerstateactivebuttonflags.h>



struct UefiAbsolutePointerState
{
    u64                                       currentX;
    u64                                       currentY;
    u64                                       currentZ;
    UefiAbsolutePointerStateActiveButtonFlags activeButtons;
};



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFIABSOLUTEPOINTERSTATE_H
