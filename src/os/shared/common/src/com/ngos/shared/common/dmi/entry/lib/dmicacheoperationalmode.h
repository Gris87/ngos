#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICACHEOPERATIONALMODE_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICACHEOPERATIONALMODE_H



#include <common/src/com/ngos/shared/common/log/assert.h>
#include <common/src/com/ngos/shared/common/log/log.h>
#include <common/src/com/ngos/shared/common/printf/printf.h>
#include <common/src/com/ngos/shared/common/ngos/types.h>



enum class DmiCacheOperationalMode: u8
{
    WRITE_THROUGH              = 0,
    WRITE_BACK                 = 1,
    VARIES_WITH_MEMORY_ADDRESS = 2,
    UNKNOWN                    = 3
};



inline const char8* enumToString(DmiCacheOperationalMode mode) // TEST: NO
{
    // COMMON_LT((" | mode = %u", mode)); // Commented to avoid bad looking logs



    switch (mode)
    {
        case DmiCacheOperationalMode::WRITE_THROUGH:              return "WRITE_THROUGH";
        case DmiCacheOperationalMode::WRITE_BACK:                 return "WRITE_BACK";
        case DmiCacheOperationalMode::VARIES_WITH_MEMORY_ADDRESS: return "VARIES_WITH_MEMORY_ADDRESS";
        case DmiCacheOperationalMode::UNKNOWN:                    return "UNKNOWN";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(DmiCacheOperationalMode mode) // TEST: NO
{
    // COMMON_LT((" | mode = %u", mode)); // Commented to avoid bad looking logs



    static char8 res[34];

    sprintf(res, "0x%02X (%s)", mode, enumToString(mode));

    return res;
}



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICACHEOPERATIONALMODE_H
