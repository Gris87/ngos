#ifndef CONFIGURE_SRC_BITS64_B_EARLY_MAIN_DECOMPRESSORS_GZIP_LIB_MEMBEREXTRAFLAGS_H
#define CONFIGURE_SRC_BITS64_B_EARLY_MAIN_DECOMPRESSORS_GZIP_LIB_MEMBEREXTRAFLAGS_H



#include <buildconfig.h>
#include <common/src/bits64/early/earlyassert.h>
#include <common/src/bits64/early/earlylog.h>
#include <common/src/bits64/printf/printf.h>
#include <common/src/bits64/string/string.h>
#include <ngos/types.h>



#if NGOS_BUILD_KERNEL_COMPRESSION == OPTION_KERNEL_COMPRESSION_GZIP



typedef u8 gzip_member_extra_flags;

enum class MemberExtraFlag: gzip_member_extra_flags
{
    NONE         = 0,
    DEFLATE_SLOW = 0x02,
    DEFLATE_FAST = 0x04
};



inline const char* memberExtraFlagToString(MemberExtraFlag flag) // TEST: NO
{
    // EARLY_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    switch (flag)
    {
        case MemberExtraFlag::NONE:         return "NONE";
        case MemberExtraFlag::DEFLATE_SLOW: return "DEFLATE_SLOW";
        case MemberExtraFlag::DEFLATE_FAST: return "DEFLATE_FAST";

        default: return "UNKNOWN";
    }
}



inline const char* memberExtraFlagsToString(gzip_member_extra_flags flags) // TEST: NO
{
    // EARLY_LT((" | flags = %u", flags)); // Commented to avoid bad looking logs



    if (!flags)
    {
        return "NONE";
    }



    static char res[45];

    char *cur = res;
    *cur      = 0;

    u8 unknownCount = 0;



    for (i64 i = 0; i < sizeof(flags) << 3; ++i) // "<< 3" == "* 8"
    {
        u64 flag = (1ULL << i);

        if (flags & flag)
        {
            const char *flagString = memberExtraFlagToString((MemberExtraFlag)flag);

            if (!strcmp(flagString, "UNKNOWN")) // strcmp(flagString, "UNKNOWN") == 0
            {
                ++unknownCount;
            }
            else
            {
                if (cur != res)
                {
                    cur = strapp(cur, " | ");
                }

                cur = strapp(cur, flagString);
            }
        }
    }



    if (unknownCount) // unknownCount != 0
    {
        sprintf(cur, " | (UNKNOWN x %u)", unknownCount);
    }



    return res;
}



#endif



#endif // CONFIGURE_SRC_BITS64_B_EARLY_MAIN_DECOMPRESSORS_GZIP_LIB_MEMBEREXTRAFLAGS_H
