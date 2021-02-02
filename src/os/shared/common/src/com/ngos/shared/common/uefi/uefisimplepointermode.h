#ifndef COM_NGOS_SHARED_COMMON_UEFI_UEFISIMPLEPOINTERMODE_H
#define COM_NGOS_SHARED_COMMON_UEFI_UEFISIMPLEPOINTERMODE_H



#include <com/ngos/shared/common/ngos/types.h>



struct UefiSimplePointerMode
{
    bad_uint64  resolutionX;
    bad_uint64  resolutionY;
    bad_uint64  resolutionZ;
    bool leftButton;
    bool rightButton;
};



#endif // COM_NGOS_SHARED_COMMON_UEFI_UEFISIMPLEPOINTERMODE_H
