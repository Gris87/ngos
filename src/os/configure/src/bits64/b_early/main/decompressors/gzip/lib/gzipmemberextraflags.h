#ifndef CONFIGURE_SRC_BITS64_B_EARLY_MAIN_DECOMPRESSORS_GZIP_LIB_GZIPMEMBEREXTRAFLAGS_H
#define CONFIGURE_SRC_BITS64_B_EARLY_MAIN_DECOMPRESSORS_GZIP_LIB_GZIPMEMBEREXTRAFLAGS_H



#include <buildconfig.h>
#include <common/src/bits64/early/earlyassert.h>
#include <common/src/bits64/early/earlylog.h>
#include <common/src/bits64/printf/printf.h>
#include <common/src/bits64/string/string.h>
#include <ngos/linkage.h>
#include <ngos/types.h>



#if NGOS_BUILD_KERNEL_COMPRESSION == OPTION_KERNEL_COMPRESSION_GZIP



typedef u8 gzip_member_extra_flags;

enum class GzipMemberExtraFlag: gzip_member_extra_flags
{
    NONE         = 0,
    DEFLATE_SLOW = (1ULL << 1),
    DEFLATE_FAST = (1ULL << 2)
};



inline const char* gzipMemberExtraFlagToString(GzipMemberExtraFlag flag) // TEST: NO
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



inline const char* gzipMemberExtraFlagsToString(gzip_member_extra_flags flags) // TEST: NO
{
    // EARLY_LT((" | flags = %u", flags)); // Commented to avoid bad looking logs



    if (!flags)
    {
        return "NONE";
    }



    static char res[43];

    FLAGS_TO_STRING(res, flags, gzipMemberExtraFlagToString, GzipMemberExtraFlag);

    return res;
}



#endif



#endif // CONFIGURE_SRC_BITS64_B_EARLY_MAIN_DECOMPRESSORS_GZIP_LIB_GZIPMEMBEREXTRAFLAGS_H
