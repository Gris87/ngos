#ifndef UEFI_UEFITIMERDELAY_H
#define UEFI_UEFITIMERDELAY_H



#include <ngos/types.h>



enum class UefiTimerDelay: u32
{
    CANCEL,
    PERIODIC,
    RELATIVE,
    MAXIMUM
};



#endif // UEFI_UEFITIMERDELAY_H
