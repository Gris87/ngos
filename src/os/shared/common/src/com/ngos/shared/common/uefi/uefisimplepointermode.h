#ifndef COM_NGOS_SHARED_COMMON_UEFI_UEFISIMPLEPOINTERMODE_H
#define COM_NGOS_SHARED_COMMON_UEFI_UEFISIMPLEPOINTERMODE_H



#include <com/ngos/shared/common/ngos/types.h>



struct UefiSimplePointerMode
{
    u64  resolutionX;
    u64  resolutionY;
    u64  resolutionZ;
    bool leftButton;
    bool rightButton;
};



#endif // COM_NGOS_SHARED_COMMON_UEFI_UEFISIMPLEPOINTERMODE_H
