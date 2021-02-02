#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMISYSTEMWAKEUPTYPE_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMISYSTEMWAKEUPTYPE_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class DmiSystemWakeUpType: bad_uint8
{
    NONE              = 0,
    OTHER             = 1,
    UNKNOWN           = 2,
    APM_TIMER         = 3,
    MODEM_RING        = 4,
    LAN_REMOTE        = 5,
    POWER_SWITCH      = 6,
    PCI_PME           = 7,
    AC_POWER_RESTORED = 8
};



inline const char8* enumToString(DmiSystemWakeUpType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    switch (type)
    {
        case DmiSystemWakeUpType::NONE:              return "NONE";
        case DmiSystemWakeUpType::OTHER:             return "OTHER";
        case DmiSystemWakeUpType::UNKNOWN:           return "UNKNOWN";
        case DmiSystemWakeUpType::APM_TIMER:         return "APM_TIMER";
        case DmiSystemWakeUpType::MODEM_RING:        return "MODEM_RING";
        case DmiSystemWakeUpType::LAN_REMOTE:        return "LAN_REMOTE";
        case DmiSystemWakeUpType::POWER_SWITCH:      return "POWER_SWITCH";
        case DmiSystemWakeUpType::PCI_PME:           return "PCI_PME";
        case DmiSystemWakeUpType::AC_POWER_RESTORED: return "AC_POWER_RESTORED";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(DmiSystemWakeUpType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    static char8 res[25];

    sprintf(res, "0x%02X (%s)", (bad_uint8)type, enumToString(type));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMISYSTEMWAKEUPTYPE_H
