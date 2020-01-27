#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMISYSTEMSLOTSLENGTH_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMISYSTEMSLOTSLENGTH_H



#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>
#include <common/src/bits64/printf/printf.h>
#include <ngos/types.h>



enum class DmiSystemSlotsLength: u8
{
    NONE    = 0,
    OTHER   = 1,
    UNKNOWN = 2,
    SHORT   = 3,
    LONG    = 4
};



inline const char8* enumToString(DmiSystemSlotsLength length) // TEST: NO
{
    // COMMON_LT((" | length = %u", length)); // Commented to avoid bad looking logs



    switch (length)
    {
        case DmiSystemSlotsLength::NONE:    return "NONE";
        case DmiSystemSlotsLength::OTHER:   return "OTHER";
        case DmiSystemSlotsLength::UNKNOWN: return "UNKNOWN";
        case DmiSystemSlotsLength::SHORT:   return "SHORT";
        case DmiSystemSlotsLength::LONG:    return "LONG";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(DmiSystemSlotsLength length) // TEST: NO
{
    // COMMON_LT((" | length = %u", length)); // Commented to avoid bad looking logs



    static char8 res[15];

    sprintf(res, "0x%02X (%s)", length, enumToString(length));

    return res;
}



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMISYSTEMSLOTSLENGTH_H
