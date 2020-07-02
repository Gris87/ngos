#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMITEMPERATUREPROBESTATUS_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMITEMPERATUREPROBESTATUS_H



#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>
#include <common/src/bits64/printf/printf.h>
#include <ngos/types.h>



enum class DmiTemperatureProbeStatus: u8
{
    NONE            = 0,
    OTHER           = 1,
    UNKNOWN         = 2,
    OK              = 3,
    NON_CRITICAL    = 4,
    CRITICAL        = 5,
    NON_RECOVERABLE = 6
};



inline const char8* enumToString(DmiTemperatureProbeStatus status) // TEST: NO
{
    // COMMON_LT((" | status = %u", status)); // Commented to avoid bad looking logs



    switch (status)
    {
        case DmiTemperatureProbeStatus::NONE:            return "NONE";
        case DmiTemperatureProbeStatus::OTHER:           return "OTHER";
        case DmiTemperatureProbeStatus::UNKNOWN:         return "UNKNOWN";
        case DmiTemperatureProbeStatus::OK:              return "OK";
        case DmiTemperatureProbeStatus::NON_CRITICAL:    return "NON_CRITICAL";
        case DmiTemperatureProbeStatus::CRITICAL:        return "CRITICAL";
        case DmiTemperatureProbeStatus::NON_RECOVERABLE: return "NON_RECOVERABLE";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(DmiTemperatureProbeStatus status) // TEST: NO
{
    // COMMON_LT((" | status = %u", status)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%02X (%s)", status, enumToString(status));

    return res;
}



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMITEMPERATUREPROBESTATUS_H
