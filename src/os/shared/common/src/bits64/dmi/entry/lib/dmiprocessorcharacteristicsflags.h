#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIPROCESSORCHARACTERISTICSFLAGS_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIPROCESSORCHARACTERISTICSFLAGS_H



#include <common/src/bits64/early/earlyassert.h>
#include <common/src/bits64/early/earlylog.h>
#include <common/src/bits64/printf/printf.h>
#include <common/src/bits64/string/string.h>
#include <ngos/flags.h>
#include <ngos/linkage.h>
#include <ngos/types.h>



typedef u16 dmi_processor_characteristics_flags;

enum class DmiProcessorCharacteristicsFlag: dmi_processor_characteristics_flags
{
    NONE                      = 0,
    UNKNOWN                   = (1ULL << 1),
    SUPPORT_64_BIT            = (1ULL << 2),
    MULTI_CORE                = (1ULL << 3),
    HARDWARE_THREAD           = (1ULL << 4),
    EXECUTE_PROTECTION        = (1ULL << 5),
    ENHANCED_VIRTUALIZATION   = (1ULL << 6),
    POWER_PERFORMANCE_CONTROL = (1ULL << 7),
    SUPPORT_128_BIT           = (1ULL << 8)
};

DEFINE_FLAGS(DmiProcessorCharacteristicsFlags, dmi_processor_characteristics_flags); // TEST: NO



inline const char8* flagToString(DmiProcessorCharacteristicsFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    switch (flag)
    {
        case DmiProcessorCharacteristicsFlag::NONE:                      return "NONE";
        case DmiProcessorCharacteristicsFlag::UNKNOWN:                   return "UNKNOWN";
        case DmiProcessorCharacteristicsFlag::SUPPORT_64_BIT:            return "SUPPORT_64_BIT";
        case DmiProcessorCharacteristicsFlag::MULTI_CORE:                return "MULTI_CORE";
        case DmiProcessorCharacteristicsFlag::HARDWARE_THREAD:           return "HARDWARE_THREAD";
        case DmiProcessorCharacteristicsFlag::EXECUTE_PROTECTION:        return "EXECUTE_PROTECTION";
        case DmiProcessorCharacteristicsFlag::ENHANCED_VIRTUALIZATION:   return "ENHANCED_VIRTUALIZATION";
        case DmiProcessorCharacteristicsFlag::POWER_PERFORMANCE_CONTROL: return "POWER_PERFORMANCE_CONTROL";
        case DmiProcessorCharacteristicsFlag::SUPPORT_128_BIT:           return "SUPPORT_128_BIT";

        default: return "UNKNOWN";
    }
}



inline const char8* flagToFullString(DmiProcessorCharacteristicsFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    static char8 res[35];

    sprintf(res, "0x%04X (%s)", flag, flagToString(flag));

    return res;
}



inline const char8* flagsToString(const DmiProcessorCharacteristicsFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[164];

    FLAGS_TO_STRING(res, flags.flags, DmiProcessorCharacteristicsFlag);

    return res;
}



inline const char8* flagsToFullString(const DmiProcessorCharacteristicsFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[173];

    FLAGS_TO_FULL_STRING(res, flags.flags, DmiProcessorCharacteristicsFlag, "0x%04X");

    return res;
}



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIPROCESSORCHARACTERISTICSFLAGS_H
