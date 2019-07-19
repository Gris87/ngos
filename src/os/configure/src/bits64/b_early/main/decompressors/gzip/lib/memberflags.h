#ifndef CONFIGURE_SRC_BITS64_B_EARLY_MAIN_DECOMPRESSORS_GZIP_LIB_MEMBERFLAGS_H
#define CONFIGURE_SRC_BITS64_B_EARLY_MAIN_DECOMPRESSORS_GZIP_LIB_MEMBERFLAGS_H



#include <buildconfig.h>
#include <common/src/bits64/early/earlyassert.h>
#include <common/src/bits64/early/earlylog.h>
#include <common/src/bits64/printf/printf.h>
#include <common/src/bits64/string/string.h>
#include <ngos/linkage.h>
#include <ngos/types.h>



#if NGOS_BUILD_KERNEL_COMPRESSION == OPTION_KERNEL_COMPRESSION_GZIP



typedef u8 gzip_member_flags;

enum class MemberFlag: gzip_member_flags
{
    NONE        = 0,
    TEXT        = (1ULL << 0),
    HEADER_CRC  = (1ULL << 1),
    EXTRA       = (1ULL << 2),
    NAME        = (1ULL << 3),
    COMMENT     = (1ULL << 4)
};



inline const char* memberFlagToString(MemberFlag flag) // TEST: NO
{
    // EARLY_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    switch (flag)
    {
        case MemberFlag::NONE:       return "NONE";
        case MemberFlag::TEXT:       return "TEXT";
        case MemberFlag::HEADER_CRC: return "HEADER_CRC";
        case MemberFlag::EXTRA:      return "EXTRA";
        case MemberFlag::NAME:       return "NAME";
        case MemberFlag::COMMENT:    return "COMMENT";

        default: return "UNKNOWN";
    }
}



inline const char* memberFlagsToString(gzip_member_flags flags) // TEST: NO
{
    // EARLY_LT((" | flags = %u", flags)); // Commented to avoid bad looking logs



    if (!flags)
    {
        return "NONE";
    }



    static char res[58];

    FLAGS_TO_STRING(res, flags, memberFlagToString, MemberFlag);

    return res;
}



#endif



#endif // CONFIGURE_SRC_BITS64_B_EARLY_MAIN_DECOMPRESSORS_GZIP_LIB_MEMBERFLAGS_H
