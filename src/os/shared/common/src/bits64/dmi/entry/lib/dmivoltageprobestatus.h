#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIVOLTAGEPROBESTATUS_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIVOLTAGEPROBESTATUS_H



#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>
#include <common/src/bits64/printf/printf.h>
#include <ngos/types.h>



enum class DmiVoltageProbeStatus: u8
{
    NONE            = 0,
    OTHER           = 1,
    UNKNOWN         = 2,
    OK              = 3,
    NON_CRITICAL    = 4,
    CRITICAL        = 5,
    NON_RECOVERABLE = 6
};



inline const char8* enumToString(DmiVoltageProbeStatus status) // TEST: NO
{
    // COMMON_LT((" | status = %u", status)); // Commented to avoid bad looking logs



    switch (status)
    {
        case DmiVoltageProbeStatus::NONE:            return "NONE";
        case DmiVoltageProbeStatus::OTHER:           return "OTHER";
        case DmiVoltageProbeStatus::UNKNOWN:         return "UNKNOWN";
        case DmiVoltageProbeStatus::OK:              return "OK";
        case DmiVoltageProbeStatus::NON_CRITICAL:    return "NON_CRITICAL";
        case DmiVoltageProbeStatus::CRITICAL:        return "CRITICAL";
        case DmiVoltageProbeStatus::NON_RECOVERABLE: return "NON_RECOVERABLE";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(DmiVoltageProbeStatus status) // TEST: NO
{
    // COMMON_LT((" | status = %u", status)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%02X (%s)", status, enumToString(status));

    return res;
}



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIVOLTAGEPROBESTATUS_H
