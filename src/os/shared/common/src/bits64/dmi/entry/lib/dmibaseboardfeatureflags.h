#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIBASEBOARDFEATUREFLAGS_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIBASEBOARDFEATUREFLAGS_H



#include <common/src/bits64/early/earlyassert.h>
#include <common/src/bits64/early/earlylog.h>
#include <common/src/bits64/printf/printf.h>
#include <common/src/bits64/string/string.h>
#include <ngos/linkage.h>
#include <ngos/types.h>



typedef u8 dmi_baseboard_feature_flags;

enum class DmiBaseboardFeatureFlag: dmi_baseboard_feature_flags
{
    NONE                   = 0,
    MOTHERBOARD            = (1ULL << 0),
    REQUIRES_DAUGHTER_CARD = (1ULL << 1),
    REMOVABLE              = (1ULL << 2),
    REPLACEABLE            = (1ULL << 3),
    HOT_SWAPPABLE          = (1ULL << 4)
};



inline const char8* dmiBaseboardFeatureFlagToString(DmiBaseboardFeatureFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    switch (flag)
    {
        case DmiBaseboardFeatureFlag::NONE:                   return "NONE";
        case DmiBaseboardFeatureFlag::MOTHERBOARD:            return "MOTHERBOARD";
        case DmiBaseboardFeatureFlag::REQUIRES_DAUGHTER_CARD: return "REQUIRES_DAUGHTER_CARD";
        case DmiBaseboardFeatureFlag::REMOVABLE:              return "REMOVABLE";
        case DmiBaseboardFeatureFlag::REPLACEABLE:            return "REPLACEABLE";
        case DmiBaseboardFeatureFlag::HOT_SWAPPABLE:          return "HOT_SWAPPABLE";

        default: return "UNKNOWN";
    }
}



inline const char8* dmiBaseboardFeatureFlagsToString(dmi_baseboard_feature_flags flags) // TEST: NO
{
    // COMMON_LT((" | flags = %u", flags)); // Commented to avoid bad looking logs



    if (!flags)
    {
        return "NONE";
    }



    static char8 res[94];

    FLAGS_TO_STRING(res, flags, dmiBaseboardFeatureFlagToString, DmiBaseboardFeatureFlag);

    return res;
}



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIBASEBOARDFEATUREFLAGS_H
