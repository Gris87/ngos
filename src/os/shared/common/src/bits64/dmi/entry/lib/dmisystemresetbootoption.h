#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMISYSTEMRESETBOOTOPTION_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMISYSTEMRESETBOOTOPTION_H



#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>
#include <common/src/bits64/printf/printf.h>
#include <ngos/types.h>



enum class DmiSystemResetBootOption: u8
{
    NONE             = 0,
    OPERATION_SYSTEM = 1,
    SYSTEM_UTILITIES = 2,
    DO_NOT_REBOOT    = 3
};



inline const char8* enumToString(DmiSystemResetBootOption option) // TEST: NO
{
    // COMMON_LT((" | option = %u", option)); // Commented to avoid bad looking logs



    switch (option)
    {
        case DmiSystemResetBootOption::NONE:             return "NONE";
        case DmiSystemResetBootOption::OPERATION_SYSTEM: return "OPERATION_SYSTEM";
        case DmiSystemResetBootOption::SYSTEM_UTILITIES: return "SYSTEM_UTILITIES";
        case DmiSystemResetBootOption::DO_NOT_REBOOT:    return "DO_NOT_REBOOT";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(DmiSystemResetBootOption option) // TEST: NO
{
    // COMMON_LT((" | option = %u", option)); // Commented to avoid bad looking logs



    static char8 res[24];

    sprintf(res, "0x%02X (%s)", option, enumToString(option));

    return res;
}



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMISYSTEMRESETBOOTOPTION_H
