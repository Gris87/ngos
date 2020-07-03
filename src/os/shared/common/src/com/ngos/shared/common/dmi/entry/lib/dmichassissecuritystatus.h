#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICHASSISSECURITYSTATUS_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICHASSISSECURITYSTATUS_H



#include <common/src/com/ngos/shared/common/log/assert.h>
#include <common/src/com/ngos/shared/common/log/log.h>
#include <common/src/com/ngos/shared/common/printf/printf.h>
#include <common/src/com/ngos/shared/common/ngos/types.h>



enum class DmiChassisSecurityStatus: u8
{
    NULL                              = 0,
    OTHER                             = 1,
    UNKNOWN                           = 2,
    NONE                              = 3,
    EXTERNAL_INTERFACE_LOCKED_OUT     = 4,
    EXTERNAL_INTERFACE_LOCKED_ENABLED = 5
};



inline const char8* enumToString(DmiChassisSecurityStatus status) // TEST: NO
{
    // COMMON_LT((" | status = %u", status)); // Commented to avoid bad looking logs



    switch (status)
    {
        case DmiChassisSecurityStatus::NULL:                              return "NULL";
        case DmiChassisSecurityStatus::OTHER:                             return "OTHER";
        case DmiChassisSecurityStatus::UNKNOWN:                           return "UNKNOWN";
        case DmiChassisSecurityStatus::NONE:                              return "NONE";
        case DmiChassisSecurityStatus::EXTERNAL_INTERFACE_LOCKED_OUT:     return "EXTERNAL_INTERFACE_LOCKED_OUT";
        case DmiChassisSecurityStatus::EXTERNAL_INTERFACE_LOCKED_ENABLED: return "EXTERNAL_INTERFACE_LOCKED_ENABLED";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(DmiChassisSecurityStatus status) // TEST: NO
{
    // COMMON_LT((" | status = %u", status)); // Commented to avoid bad looking logs



    static char8 res[41];

    sprintf(res, "0x%02X (%s)", status, enumToString(status));

    return res;
}



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICHASSISSECURITYSTATUS_H
