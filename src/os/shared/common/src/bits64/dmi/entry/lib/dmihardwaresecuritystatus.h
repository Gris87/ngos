#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIHARDWARESECURITYSTATUS_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIHARDWARESECURITYSTATUS_H



#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>
#include <common/src/bits64/printf/printf.h>
#include <ngos/types.h>



enum class DmiHardwareSecurityStatus: u8
{
    DISABLED        = 0,
    ENABLED         = 1,
    NOT_IMPLEMENTED = 2,
    UNKNOWN         = 3
};



inline const char8* enumToString(DmiHardwareSecurityStatus status) // TEST: NO
{
    // COMMON_LT((" | status = %u", status)); // Commented to avoid bad looking logs



    switch (status)
    {
        case DmiHardwareSecurityStatus::DISABLED:        return "DISABLED";
        case DmiHardwareSecurityStatus::ENABLED:         return "ENABLED";
        case DmiHardwareSecurityStatus::NOT_IMPLEMENTED: return "NOT_IMPLEMENTED";
        case DmiHardwareSecurityStatus::UNKNOWN:         return "UNKNOWN";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(DmiHardwareSecurityStatus status) // TEST: NO
{
    // COMMON_LT((" | status = %u", status)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%02X (%s)", status, enumToString(status));

    return res;
}



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIHARDWARESECURITYSTATUS_H