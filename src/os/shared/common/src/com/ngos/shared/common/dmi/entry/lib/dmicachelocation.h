#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICACHELOCATION_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICACHELOCATION_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



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



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICACHELOCATION_H
