#ifndef UEFI_UEFISIMPLEPOINTERMODE_H
#define UEFI_UEFISIMPLEPOINTERMODE_H



#include <common/src/com/ngos/shared/common/ngos/types.h>



struct UefiSimplePointerMode
{
    u64  resolutionX;
    u64  resolutionY;
    u64  resolutionZ;
    bool leftButton;
    bool rightButton;
};



#endif // UEFI_UEFISIMPLEPOINTERMODE_H
