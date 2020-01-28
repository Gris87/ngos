#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMICACHESRAMTYPEFLAGS_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMICACHESRAMTYPEFLAGS_H



#include <common/src/bits64/early/earlyassert.h>
#include <common/src/bits64/early/earlylog.h>
#include <common/src/bits64/printf/printf.h>
#include <common/src/bits64/string/string.h>
#include <ngos/flags.h>
#include <ngos/linkage.h>
#include <ngos/types.h>



typedef u16 dmi_cache_sram_type_flags;

enum class DmiCacheSramTypeFlag: dmi_cache_sram_type_flags
{
    NONE           = 0,
    OTHER          = (1ULL << 1),
    UNKNOWN        = (1ULL << 2),
    NON_BURST      = (1ULL << 3),
    BURST          = (1ULL << 4),
    PIPELINE_BURST = (1ULL << 5),
    SYNCHRONOUS    = (1ULL << 6),
    ASYNCHRONOUS   = (1ULL << 7)
};

DEFINE_FLAGS(DmiCacheSramTypeFlags, dmi_cache_sram_type_flags); // TEST: NO



inline const char8* flagToString(DmiCacheSramTypeFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    switch (flag)
    {
        case DmiCacheSramTypeFlag::NONE:           return "NONE";
        case DmiCacheSramTypeFlag::OTHER:          return "OTHER";
        case DmiCacheSramTypeFlag::UNKNOWN:        return "UNKNOWN";
        case DmiCacheSramTypeFlag::NON_BURST:      return "NON_BURST";
        case DmiCacheSramTypeFlag::BURST:          return "BURST";
        case DmiCacheSramTypeFlag::PIPELINE_BURST: return "PIPELINE_BURST";
        case DmiCacheSramTypeFlag::SYNCHRONOUS:    return "SYNCHRONOUS";
        case DmiCacheSramTypeFlag::ASYNCHRONOUS:   return "ASYNCHRONOUS";

        default: return "UNKNOWN";
    }
}



inline const char8* flagToFullString(DmiCacheSramTypeFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    static char8 res[24];

    sprintf(res, "0x%04X (%s)", flag, flagToString(flag));

    return res;
}



inline const char8* flagsToString(const DmiCacheSramTypeFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[97];

    FLAGS_TO_STRING(res, flags.flags, DmiCacheSramTypeFlag);

    return res;
}



inline const char8* flagsToFullString(const DmiCacheSramTypeFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[106];

    FLAGS_TO_FULL_STRING(res, flags.flags, DmiCacheSramTypeFlag, "0x%04X");

    return res;
}



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMICACHESRAMTYPEFLAGS_H
