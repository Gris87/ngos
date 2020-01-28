#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMICACHELOCATION_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMICACHELOCATION_H



#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>
#include <common/src/bits64/printf/printf.h>
#include <ngos/types.h>



enum class DmiCacheLocation: u8
{
    INTERNAL = 0,
    EXTERNAL = 1,
    UNKNOWN  = 3
};



inline const char8* enumToString(DmiCacheLocation location) // TEST: NO
{
    // COMMON_LT((" | location = %u", location)); // Commented to avoid bad looking logs



    switch (location)
    {
        case DmiCacheLocation::INTERNAL: return "INTERNAL";
        case DmiCacheLocation::EXTERNAL: return "EXTERNAL";
        case DmiCacheLocation::UNKNOWN:  return "UNKNOWN";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(DmiCacheLocation location) // TEST: NO
{
    // COMMON_LT((" | location = %u", location)); // Commented to avoid bad looking logs



    static char8 res[16];

    sprintf(res, "0x%02X (%s)", location, enumToString(location));

    return res;
}



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMICACHELOCATION_H
