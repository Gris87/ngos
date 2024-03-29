#ifndef COM_NGOS_CONFIGURE_B_EARLY_MAIN_DECOMPRESSORS_GZIP_LIB_GZIPMEMBERFLAGS_H
#define COM_NGOS_CONFIGURE_B_EARLY_MAIN_DECOMPRESSORS_GZIP_LIB_GZIPMEMBERFLAGS_H



#include <buildconfig.h>
#include <com/ngos/shared/common/bits/flags.h>
#include <com/ngos/shared/common/bits/macros.h>
#include <com/ngos/shared/common/early/earlyassert.h>
#include <com/ngos/shared/common/early/earlylog.h>
#include <com/ngos/shared/common/ngos/linkage.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>
#include <com/ngos/shared/common/string/string.h>



#if NGOS_BUILD_KERNEL_COMPRESSION == OPTION_KERNEL_COMPRESSION_GZIP



typedef u8 gzip_member_flags;

enum class GzipMemberFlag: gzip_member_flags
{
    NONE        = 0,
    TEXT        = BIT_0,
    HEADER_CRC  = BIT_1,
    EXTRA       = BIT_2,
    NAME        = BIT_3,
    COMMENT     = BIT_4
};

DEFINE_FLAGS(GzipMemberFlags, gzip_member_flags); // TEST: NO



inline const char8* flagToString(GzipMemberFlag flag) // TEST: NO
{
    // EARLY_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    switch (flag)
    {
        case GzipMemberFlag::NONE:       return "NONE";
        case GzipMemberFlag::TEXT:       return "TEXT";
        case GzipMemberFlag::HEADER_CRC: return "HEADER_CRC";
        case GzipMemberFlag::EXTRA:      return "EXTRA";
        case GzipMemberFlag::NAME:       return "NAME";
        case GzipMemberFlag::COMMENT:    return "COMMENT";

        default: return "UNKNOWN";
    }
}



inline const char8* flagToFullString(GzipMemberFlag flag) // TEST: NO
{
    // EARLY_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    static char8 res[18];

    sprintf(res, "0x%02X (%s)", (gzip_member_flags)flag, flagToString(flag));

    return res;
}



inline const char8* flagsToString(const GzipMemberFlags &flags) // TEST: NO
{
    // EARLY_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[58];

    FLAGS_TO_STRING(res, flags.flags, GzipMemberFlag);

    return res;
}



inline const char8* flagsToFullString(const GzipMemberFlags &flags) // TEST: NO
{
    // EARLY_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[65];

    FLAGS_TO_FULL_STRING(res, flags.flags, GzipMemberFlag, "0x%02X");

    return res;
}



#endif



#endif // COM_NGOS_CONFIGURE_B_EARLY_MAIN_DECOMPRESSORS_GZIP_LIB_GZIPMEMBERFLAGS_H
