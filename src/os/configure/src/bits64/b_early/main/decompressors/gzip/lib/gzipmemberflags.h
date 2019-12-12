#ifndef CONFIGURE_SRC_BITS64_B_EARLY_MAIN_DECOMPRESSORS_GZIP_LIB_GZIPMEMBERFLAGS_H
#define CONFIGURE_SRC_BITS64_B_EARLY_MAIN_DECOMPRESSORS_GZIP_LIB_GZIPMEMBERFLAGS_H



#include <buildconfig.h>
#include <common/src/bits64/early/earlyassert.h>
#include <common/src/bits64/early/earlylog.h>
#include <common/src/bits64/printf/printf.h>
#include <common/src/bits64/string/string.h>
#include <ngos/flags.h>
#include <ngos/linkage.h>
#include <ngos/types.h>



#if NGOS_BUILD_KERNEL_COMPRESSION == OPTION_KERNEL_COMPRESSION_GZIP



typedef u8 gzip_member_flags;

enum class GzipMemberFlag: gzip_member_flags
{
    NONE        = 0,
    TEXT        = (1ULL << 0),
    HEADER_CRC  = (1ULL << 1),
    EXTRA       = (1ULL << 2),
    NAME        = (1ULL << 3),
    COMMENT     = (1ULL << 4)
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

    sprintf(res, "0x%02X (%s)", flag, flagToString(flag));

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



#endif // CONFIGURE_SRC_BITS64_B_EARLY_MAIN_DECOMPRESSORS_GZIP_LIB_GZIPMEMBERFLAGS_H
