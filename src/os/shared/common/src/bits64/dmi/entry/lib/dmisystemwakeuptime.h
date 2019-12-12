#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMISYSTEMWAKEUPTIME_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMISYSTEMWAKEUPTIME_H



#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>
#include <common/src/bits64/printf/printf.h>
#include <ngos/types.h>



enum class DmiSystemWakeUpTime: u8
{
    NONE              = 0,
    OTHER             = 1,
    UNKNOWN           = 2,
    APM_TIMER         = 3,
    MODEOM_RING       = 4,
    LAN_REMOTE        = 5,
    POWER_SWITCH      = 6,
    PCI_PME           = 7,
    AC_POWER_RESTORED = 8
};



inline const char8* enumToString(DmiSystemWakeUpTime time) // TEST: NO
{
    // COMMON_LT((" | time = %u", time)); // Commented to avoid bad looking logs



    switch (time)
    {
        case DmiSystemWakeUpTime::NONE:              return "NONE";
        case DmiSystemWakeUpTime::OTHER:             return "OTHER";
        case DmiSystemWakeUpTime::UNKNOWN:           return "UNKNOWN";
        case DmiSystemWakeUpTime::APM_TIMER:         return "APM_TIMER";
        case DmiSystemWakeUpTime::MODEOM_RING:       return "MODEOM_RING";
        case DmiSystemWakeUpTime::LAN_REMOTE:        return "LAN_REMOTE";
        case DmiSystemWakeUpTime::POWER_SWITCH:      return "POWER_SWITCH";
        case DmiSystemWakeUpTime::PCI_PME:           return "PCI_PME";
        case DmiSystemWakeUpTime::AC_POWER_RESTORED: return "AC_POWER_RESTORED";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(DmiSystemWakeUpTime time) // TEST: NO
{
    // COMMON_LT((" | time = %u", time)); // Commented to avoid bad looking logs



    static char8 res[25];

    sprintf(res, "0x%02X (%s)", time, enumToString(time));

    return res;
}



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMISYSTEMWAKEUPTIME_H
