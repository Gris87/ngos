#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMICHASSISSECURITYSTATUS_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMICHASSISSECURITYSTATUS_H



#include <ngos/types.h>



enum class DmiChassisSecurityStatus: u8
{
    NULL                              = 0,
    OTHER                             = 1,
    UNKNOWN                           = 2,
    NONE                              = 3,
    EXTERNAL_INTERFACE_LOCKED_OUT     = 4,
    EXTERNAL_INTERFACE_LOCKED_ENABLED = 5
};



inline const char8* dmiChassisSecurityStatusToString(DmiChassisSecurityStatus status) // TEST: NO
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



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMICHASSISSECURITYSTATUS_H
