#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMICHASSISSTATE_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMICHASSISSTATE_H



#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>
#include <common/src/bits64/printf/printf.h>
#include <ngos/types.h>



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



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMICHASSISSTATE_H
