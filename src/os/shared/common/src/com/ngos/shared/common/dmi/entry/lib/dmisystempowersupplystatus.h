#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMISYSTEMPOWERSUPPLYSTATUS_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMISYSTEMPOWERSUPPLYSTATUS_H



#include <common/src/com/ngos/shared/common/log/assert.h>
#include <common/src/com/ngos/shared/common/log/log.h>
#include <common/src/com/ngos/shared/common/printf/printf.h>
#include <common/src/com/ngos/shared/common/ngos/types.h>



enum class DmiSystemPowerSupplyStatus: u8
{
    NONE         = 0,
    OTHER        = 1,
    UNKNOWN      = 2,
    OK           = 3,
    NON_CRITICAL = 4,
    CRITICAL     = 5
};



inline const char8* enumToString(DmiSystemPowerSupplyStatus status) // TEST: NO
{
    // COMMON_LT((" | status = %u", status)); // Commented to avoid bad looking logs



    switch (status)
    {
        case DmiSystemPowerSupplyStatus::NONE:         return "NONE";
        case DmiSystemPowerSupplyStatus::OTHER:        return "OTHER";
        case DmiSystemPowerSupplyStatus::UNKNOWN:      return "UNKNOWN";
        case DmiSystemPowerSupplyStatus::OK:           return "OK";
        case DmiSystemPowerSupplyStatus::NON_CRITICAL: return "NON_CRITICAL";
        case DmiSystemPowerSupplyStatus::CRITICAL:     return "CRITICAL";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(DmiSystemPowerSupplyStatus status) // TEST: NO
{
    // COMMON_LT((" | status = %u", status)); // Commented to avoid bad looking logs



    static char8 res[20];

    sprintf(res, "0x%02X (%s)", status, enumToString(status));

    return res;
}



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMISYSTEMPOWERSUPPLYSTATUS_H
