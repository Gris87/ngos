#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFISIMPLEPOINTERSTATE_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFISIMPLEPOINTERSTATE_H



#include <common/src/com/ngos/shared/common/ngos/types.h>



struct UefiSimplePointerState
{
    i32  relativeMovementX;
    i32  relativeMovementY;
    i32  relativeMovementZ;
    bool leftButton;
    bool rightButton;
};



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFISIMPLEPOINTERSTATE_H
