#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICACHESRAMTYPEFLAGS_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICACHESRAMTYPEFLAGS_H



#include <com/ngos/shared/common/early/earlyassert.h>
#include <com/ngos/shared/common/early/earlylog.h>
#include <com/ngos/shared/common/ngos/flags.h>
#include <com/ngos/shared/common/ngos/linkage.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>
#include <com/ngos/shared/common/string/string.h>



typedef u16 dmi_cache_sram_type_flags;

enum class DmiCacheSramTypeFlag: dmi_cache_sram_type_flags
{
    NONE           = 0,
    OTHER          = (1ULL << 0),
    UNKNOWN        = (1ULL << 1),
    NON_BURST      = (1ULL << 2),
    BURST          = (1ULL << 3),
    PIPELINE_BURST = (1ULL << 4),
    SYNCHRONOUS    = (1ULL << 5),
    ASYNCHRONOUS   = (1ULL << 6)
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



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICACHESRAMTYPEFLAGS_H
