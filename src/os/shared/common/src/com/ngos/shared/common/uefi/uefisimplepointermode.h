#ifndef UEFI_UEFISIMPLEPOINTERMODE_H
#define UEFI_UEFISIMPLEPOINTERMODE_H



#include <ngos/types.h>



struct UefiSimplePointerMode
{
    u64  resolutionX;
    u64  resolutionY;
    u64  resolutionZ;
    bool leftButton;
    bool rightButton;
};



#endif // UEFI_UEFISIMPLEPOINTERMODE_H
