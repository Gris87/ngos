#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMISYSTEMSLOTSUSAGE_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMISYSTEMSLOTSUSAGE_H



#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>
#include <common/src/bits64/printf/printf.h>
#include <ngos/types.h>



enum class DmiSystemSlotsUsage: u8
{
    NONE        = 0,
    OTHER       = 1,
    UNKNOWN     = 2,
    AVAILABLE   = 3,
    IN_USE      = 4,
    UNAVAILABLE = 5
};



inline const char8* enumToString(DmiSystemSlotsUsage usage) // TEST: NO
{
    // COMMON_LT((" | usage = %u", usage)); // Commented to avoid bad looking logs



    switch (usage)
    {
        case DmiSystemSlotsUsage::NONE:              return "NONE";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(DmiSystemSlotsUsage usage) // TEST: NO
{
    // COMMON_LT((" | usage = %u", usage)); // Commented to avoid bad looking logs



    static char8 res[25];

    sprintf(res, "0x%02X (%s)", usage, enumToString(usage));

    return res;
}



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMISYSTEMSLOTSUSAGE_H
