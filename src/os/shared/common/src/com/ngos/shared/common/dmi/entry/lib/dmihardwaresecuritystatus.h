#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIHARDWARESECURITYSTATUS_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIHARDWARESECURITYSTATUS_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



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



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIHARDWARESECURITYSTATUS_H
