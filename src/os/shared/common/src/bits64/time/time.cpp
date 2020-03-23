#include "time.h"

#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>

#if defined(UEFI_APPLICATION)                       // Defined in Makefile
#include <uefibase/src/bits64/uefi/uefi.h>
#endif



u64 Time::currentTimestampInMilliseconds()
{
    COMMON_LT((""));



#if defined(UEFI_APPLICATION) // Defined in Makefile
    UefiTime             time;
    UefiTimeCapabilities capabilities;

    if (UEFI::getTime(&time, &capabilities) != UefiStatus::SUCCESS)
    {
        COMMON_LF(("Failed to get current time"));

        return 0;
    }

    // TODO: Need to count with day, month, year
    u64 res;

    res =  time.hour * 60;
    res =  (res + time.minute) * 60;
    res =  (res + time.second) * 1000;
    res += time.nanosecond / 1000000;

    return res;
#else
    // TODO: Should be updated when implemented

    return 0;
#endif
}
