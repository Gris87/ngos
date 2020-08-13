#ifndef COM_NGOS_SHARED_COMMON_UEFI_UEFITIMERDELAY_H
#define COM_NGOS_SHARED_COMMON_UEFI_UEFITIMERDELAY_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class UefiTimerDelay: u32
{
    CANCEL,
    PERIODIC,
    RELATIVE,
    MAXIMUM
};



inline const char8* enumToString(UefiTimerDelay delay) // TEST: NO
{
    // COMMON_LT((" | delay = %u", delay)); // Commented to avoid bad looking logs



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
    // COMMON_LT((" | delay = %u", delay)); // Commented to avoid bad looking logs



    static char8 res[22];

    sprintf(res, "0x%08X (%s)", (u32)delay, enumToString(delay));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_UEFI_UEFITIMERDELAY_H
