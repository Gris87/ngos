#ifndef COM_NGOS_SHARED_COMMON_FPU_XFEATUREFLAGS_H
#define COM_NGOS_SHARED_COMMON_FPU_XFEATUREFLAGS_H



#include <com/ngos/shared/common/bits/flags.h>
#include <com/ngos/shared/common/bits/macros.h>
#include <com/ngos/shared/common/ngos/linkage.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>
#include <com/ngos/shared/common/string/string.h>



typedef u32 x_feature_flags;

enum class XFeatureFlag: x_feature_flags
{
    NONE       = 0,
    SUPERVISOR = BIT_0,
    ALIGNED    = BIT_1
};

DEFINE_FLAGS(XFeatureFlags, x_feature_flags); // TEST: NO



inline const char8* flagToString(XFeatureFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    switch (flag)
    {
        case XFeatureFlag::NONE:       return "NONE";
        case XFeatureFlag::SUPERVISOR: return "SUPERVISOR";
        case XFeatureFlag::ALIGNED:    return "ALIGNED";

        default: return "UNKNOWN";
    }
}



inline const char8* flagToFullString(XFeatureFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    static char8 res[24];

    sprintf(res, "0x%08X (%s)", (x_feature_flags)flag, flagToString(flag));

    return res;
}



inline const char8* flagsToString(const XFeatureFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[36];

    FLAGS_TO_STRING(res, flags.flags, XFeatureFlag);

    return res;
}



inline const char8* flagsToFullString(const XFeatureFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[49];

    FLAGS_TO_FULL_STRING(res, flags.flags, XFeatureFlag, "0x%08X");

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_FPU_XFEATUREFLAGS_H
