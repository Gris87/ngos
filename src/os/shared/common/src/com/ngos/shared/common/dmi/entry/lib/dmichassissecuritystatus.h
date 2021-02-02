#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICHASSISSECURITYSTATUS_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICHASSISSECURITYSTATUS_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class DmiChassisSecurityStatus: bad_uint8
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

    sprintf(res, "0x%02X (%s)", (bad_uint8)status, enumToString(status));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICHASSISSECURITYSTATUS_H
