#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIBASEBOARDFEATUREFLAGS_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIBASEBOARDFEATUREFLAGS_H



#include <com/ngos/shared/common/ngos/flags.h>
#include <com/ngos/shared/common/ngos/linkage.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>
#include <com/ngos/shared/common/string/string.h>



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

DEFINE_FLAGS(DmiBaseboardFeatureFlags, dmi_baseboard_feature_flags); // TEST: NO



inline const char8* flagToString(DmiBaseboardFeatureFlag flag) // TEST: NO
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



inline const char8* flagToFullString(DmiBaseboardFeatureFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    static char8 res[30];

    sprintf(res, "0x%02X (%s)", (dmi_baseboard_feature_flags)flag, flagToString(flag));

    return res;
}



inline const char8* flagsToString(const DmiBaseboardFeatureFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[94];

    FLAGS_TO_STRING(res, flags.flags, DmiBaseboardFeatureFlag);

    return res;
}



inline const char8* flagsToFullString(const DmiBaseboardFeatureFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[101];

    FLAGS_TO_FULL_STRING(res, flags.flags, DmiBaseboardFeatureFlag, "0x%02X");

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIBASEBOARDFEATUREFLAGS_H
