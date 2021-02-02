#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMITEMPERATUREPROBESTATUS_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMITEMPERATUREPROBESTATUS_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class DmiTemperatureProbeStatus: bad_uint8
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

    sprintf(res, "0x%02X (%s)", (bad_uint8)status, enumToString(status));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMITEMPERATUREPROBESTATUS_H
