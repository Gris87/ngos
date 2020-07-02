#ifndef CONFIGURE_SRC_COM_NGOS_CONFIGURE_B_EARLY_MAIN_DECOMPRESSORS_GZIP_LIB_GZIPMEMBEREXTRAFLAGS_H
#define CONFIGURE_SRC_COM_NGOS_CONFIGURE_B_EARLY_MAIN_DECOMPRESSORS_GZIP_LIB_GZIPMEMBEREXTRAFLAGS_H



#include <buildconfig.h>
#include <common/src/com/ngos/shared/common/early/earlyassert.h>
#include <common/src/com/ngos/shared/common/early/earlylog.h>
#include <common/src/com/ngos/shared/common/printf/printf.h>
#include <common/src/com/ngos/shared/common/string/string.h>
#include <common/src/com/ngos/shared/common/ngos/flags.h>
#include <common/src/com/ngos/shared/common/ngos/linkage.h>
#include <common/src/com/ngos/shared/common/ngos/types.h>



#if NGOS_BUILD_KERNEL_COMPRESSION == OPTION_KERNEL_COMPRESSION_GZIP



typedef u8 gzip_member_extra_flags;

enum class GzipMemberExtraFlag: gzip_member_extra_flags
{
    NONE         = 0,
    DEFLATE_SLOW = (1ULL << 1),
    DEFLATE_FAST = (1ULL << 2)
};

DEFINE_FLAGS(GzipMemberExtraFlags, gzip_member_extra_flags); // TEST: NO



inline const char8* flagToString(GzipMemberExtraFlag flag) // TEST: NO
{
    // EARLY_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    switch (flag)
    {
        case GzipMemberExtraFlag::NONE:         return "NONE";
        case GzipMemberExtraFlag::DEFLATE_SLOW: return "DEFLATE_SLOW";
        case GzipMemberExtraFlag::DEFLATE_FAST: return "DEFLATE_FAST";

        default: return "UNKNOWN";
    }
}



inline const char8* flagToFullString(GzipMemberExtraFlag flag) // TEST: NO
{
    // EARLY_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    static char8 res[20];

    sprintf(res, "0x%02X (%s)", flag, flagToString(flag));

    return res;
}



inline const char8* flagsToString(const GzipMemberExtraFlags &flags) // TEST: NO
{
    // EARLY_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[43];

    FLAGS_TO_STRING(res, flags.flags, GzipMemberExtraFlag);

    return res;
}



inline const char8* flagsToFullString(const GzipMemberExtraFlags &flags) // TEST: NO
{
    // EARLY_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[50];

    FLAGS_TO_FULL_STRING(res, flags.flags, GzipMemberExtraFlag, "0x%02X");

    return res;
}



#endif



#endif // CONFIGURE_SRC_COM_NGOS_CONFIGURE_B_EARLY_MAIN_DECOMPRESSORS_GZIP_LIB_GZIPMEMBEREXTRAFLAGS_H
