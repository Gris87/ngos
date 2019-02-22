#ifndef UEFI_UEFIEVENT_H
#define UEFI_UEFIEVENT_H



#include <ngos/types.h>



enum class UefiEventType: u32
{
    TIMER = 0x80000000
};



#endif // UEFI_UEFIEVENT_H
