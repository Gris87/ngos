#ifndef UEFI_UEFITIMERDELAY_H
#define UEFI_UEFITIMERDELAY_H



#include <common/src/com/ngos/shared/common/ngos/types.h>

#if defined(UEFI_APPLICATION) || defined(BUILD_TARGET_KERNEL) // Defined in Makefile
#include <common/src/com/ngos/shared/common/printf/printf.h>
#endif



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



#if defined(UEFI_APPLICATION) || defined(BUILD_TARGET_KERNEL) // Defined in Makefile



inline const char8* enumToFullString(UefiTimerDelay delay) // TEST: NO
{
    static char8 res[22];

    sprintf(res, "0x%08X (%s)", delay, enumToString(delay));

    return res;
}



#endif



#endif // UEFI_UEFITIMERDELAY_H
