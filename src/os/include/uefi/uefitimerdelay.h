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



inline const char8* enumToString(UefiTimerDelay delay) // TEST: NO
{
    switch (delay)
    {
        case UefiTimerDelay::CANCEL:   return "CANCEL";
        case UefiTimerDelay::PERIODIC: return "PERIODIC";
        case UefiTimerDelay::RELATIVE: return "RELATIVE";
        case UefiTimerDelay::MAXIMUM:  return "MAXIMUM";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(UefiTimerDelay delay) // TEST: NO
{
    switch (delay)
    {
        case UefiTimerDelay::CANCEL:   return "CANCEL";
        case UefiTimerDelay::PERIODIC: return "PERIODIC";
        case UefiTimerDelay::RELATIVE: return "RELATIVE";
        case UefiTimerDelay::MAXIMUM:  return "MAXIMUM";

        default: return "UNKNOWN";
    }
}



#endif // UEFI_UEFITIMERDELAY_H
