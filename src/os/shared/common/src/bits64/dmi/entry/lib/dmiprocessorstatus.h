#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIPROCESSORSTATUS_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIPROCESSORSTATUS_H



#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>
#include <common/src/bits64/printf/printf.h>
#include <ngos/types.h>



enum class DmiProcessorStatus: u8
{
    UNKNOWN          = 0,
    ENABLED          = 1,
    DISABLED_BY_USER = 2,
    DISABLED_BY_BIOS = 3,
    IDLE             = 4,
    OTHER            = 7
};



inline const char8* enumToString(DmiProcessorStatus status) // TEST: NO
{
    // COMMON_LT((" | status = %u", status)); // Commented to avoid bad looking logs



    switch (status)
    {
        case DmiProcessorStatus::UNKNOWN:          return "UNKNOWN";
        case DmiProcessorStatus::ENABLED:          return "ENABLED";
        case DmiProcessorStatus::DISABLED_BY_USER: return "DISABLED_BY_USER";
        case DmiProcessorStatus::DISABLED_BY_BIOS: return "DISABLED_BY_BIOS";
        case DmiProcessorStatus::IDLE:             return "IDLE";
        case DmiProcessorStatus::OTHER:            return "OTHER";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(DmiProcessorStatus status) // TEST: NO
{
    // COMMON_LT((" | status = %u", status)); // Commented to avoid bad looking logs



    static char8 res[24];

    sprintf(res, "0x%02X (%s)", status, enumToString(status));

    return res;
}



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIPROCESSORSTATUS_H
