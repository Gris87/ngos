#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICHASSISSTATE_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICHASSISSTATE_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class DmiChassisState: u8
{
    NONE            = 0,
    OTHER           = 1,
    UNKNOWN         = 2,
    SAFE            = 3,
    WARNING         = 4,
    CRITICAL        = 5,
    NON_RECOVERABLE = 6
};



inline const char8* enumToString(DmiChassisState state) // TEST: NO
{
    // COMMON_LT((" | state = %u", state)); // Commented to avoid bad looking logs



    switch (state)
    {
        case DmiChassisState::NONE:            return "NONE";
        case DmiChassisState::OTHER:           return "OTHER";
        case DmiChassisState::UNKNOWN:         return "UNKNOWN";
        case DmiChassisState::SAFE:            return "SAFE";
        case DmiChassisState::WARNING:         return "WARNING";
        case DmiChassisState::CRITICAL:        return "CRITICAL";
        case DmiChassisState::NON_RECOVERABLE: return "NON_RECOVERABLE";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(DmiChassisState state) // TEST: NO
{
    // COMMON_LT((" | state = %u", state)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%02X (%s)", state, enumToString(state));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICHASSISSTATE_H
