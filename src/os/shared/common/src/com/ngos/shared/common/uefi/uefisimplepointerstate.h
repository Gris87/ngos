#ifndef UEFI_UEFISIMPLEPOINTERSTATE_H
#define UEFI_UEFISIMPLEPOINTERSTATE_H



#include <common/src/com/ngos/shared/common/ngos/types.h>



struct UefiSimplePointerState
{
    i32  relativeMovementX;
    i32  relativeMovementY;
    i32  relativeMovementZ;
    bool leftButton;
    bool rightButton;
};



#endif // UEFI_UEFISIMPLEPOINTERSTATE_H
