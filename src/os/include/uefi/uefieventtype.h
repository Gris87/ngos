#ifndef UEFI_UEFIEVENTTYPE_H
#define UEFI_UEFIEVENTTYPE_H



#include <ngos/types.h>



enum class UefiEventType: u32
{
    TIMER = 0x80000000
};



#endif // UEFI_UEFIEVENTTYPE_H
