#ifndef OS_SHARED_COMMON_SRC_BITS64_FPU_XFEATUREFLAGS_H
#define OS_SHARED_COMMON_SRC_BITS64_FPU_XFEATUREFLAGS_H



#include <common/src/bits64/early/earlyassert.h>
#include <common/src/bits64/early/earlylog.h>
#include <common/src/bits64/printf/printf.h>
#include <common/src/bits64/string/string.h>
#include <ngos/linkage.h>
#include <ngos/types.h>



typedef u32 x_feature_flags;

enum class XFeatureFlag: x_feature_flags
{
    NONE       = 0,
    SUPERVISOR = (1ULL << 0),
    ALIGNED    = (1ULL << 1)
};



inline const char* xFeatureFlagToString(XFeatureFlag flag) // TEST: NO
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



inline const char* xFeatureFlagsToString(x_feature_flags flags) // TEST: NO
{
    // COMMON_LT((" | flags = %u", flags)); // Commented to avoid bad looking logs



    if (!flags)
    {
        return "NONE";
    }



    static char res[36];

    FLAGS_TO_STRING(res, flags, xFeatureFlagToString, XFeatureFlag);

    return res;
}



#endif // OS_SHARED_COMMON_SRC_BITS64_FPU_XFEATUREFLAGS_H
