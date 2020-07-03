#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFISIMPLEPOINTERMODE_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFISIMPLEPOINTERMODE_H



#include <com/ngos/shared/common/ngos/types.h>



struct UefiSimplePointerMode
{
    u64  resolutionX;
    u64  resolutionY;
    u64  resolutionZ;
    bool leftButton;
    bool rightButton;
};



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFISIMPLEPOINTERMODE_H
