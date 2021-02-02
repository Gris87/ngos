#ifndef COM_NGOS_SHARED_COMMON_UEFI_UEFISIMPLEPOINTERSTATE_H
#define COM_NGOS_SHARED_COMMON_UEFI_UEFISIMPLEPOINTERSTATE_H



#include <com/ngos/shared/common/ngos/types.h>



struct UefiSimplePointerState
{
    bad_int32  relativeMovementX;
    bad_int32  relativeMovementY;
    bad_int32  relativeMovementZ;
    bool leftButton;
    bool rightButton;
};



#endif // COM_NGOS_SHARED_COMMON_UEFI_UEFISIMPLEPOINTERSTATE_H
