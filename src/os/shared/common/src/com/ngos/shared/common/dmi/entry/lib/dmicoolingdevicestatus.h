#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMICOOLINGDEVICESTATUS_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMICOOLINGDEVICESTATUS_H



#include <common/src/com/ngos/shared/common/log/assert.h>
#include <common/src/com/ngos/shared/common/log/log.h>
#include <common/src/com/ngos/shared/common/printf/printf.h>
#include <common/src/com/ngos/shared/common/ngos/types.h>



enum class DmiCoolingDeviceStatus: u8
{
    NONE            = 0,
    OTHER           = 1,
    UNKNOWN         = 2,
    OK              = 3,
    NON_CRITICAL    = 4,
    CRITICAL        = 5,
    NON_RECOVERABLE = 6
};



inline const char8* enumToString(DmiCoolingDeviceStatus status) // TEST: NO
{
    // COMMON_LT((" | status = %u", status)); // Commented to avoid bad looking logs



    switch (status)
    {
        case DmiCoolingDeviceStatus::NONE:            return "NONE";
        case DmiCoolingDeviceStatus::OTHER:           return "OTHER";
        case DmiCoolingDeviceStatus::UNKNOWN:         return "UNKNOWN";
        case DmiCoolingDeviceStatus::OK:              return "OK";
        case DmiCoolingDeviceStatus::NON_CRITICAL:    return "NON_CRITICAL";
        case DmiCoolingDeviceStatus::CRITICAL:        return "CRITICAL";
        case DmiCoolingDeviceStatus::NON_RECOVERABLE: return "NON_RECOVERABLE";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(DmiCoolingDeviceStatus status) // TEST: NO
{
    // COMMON_LT((" | status = %u", status)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%02X (%s)", status, enumToString(status));

    return res;
}



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMICOOLINGDEVICESTATUS_H
