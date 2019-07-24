#ifndef CONFIGURE_SRC_BITS64_B_EARLY_MAIN_DECOMPRESSORS_XZ_LIB_STREAMFLAGS_H
#define CONFIGURE_SRC_BITS64_B_EARLY_MAIN_DECOMPRESSORS_XZ_LIB_STREAMFLAGS_H



#include <buildconfig.h>
#include <common/src/bits64/early/earlyassert.h>
#include <common/src/bits64/early/earlylog.h>
#include <common/src/bits64/printf/printf.h>
#include <common/src/bits64/string/string.h>
#include <ngos/linkage.h>
#include <ngos/types.h>



#if NGOS_BUILD_KERNEL_COMPRESSION == OPTION_KERNEL_COMPRESSION_XZ



#define TYPE_OF_CHECK_MASK 0x0F00



typedef u16 xz_stream_flags;

enum class StreamFlag: xz_stream_flags
{
    NONE                 = 0,
    TYPE_OF_CHECK_CRC32  = (1ULL << 8),
    TYPE_OF_CHECK_CRC64  = (1ULL << 10),
    TYPE_OF_CHECK_SHA256 = (1ULL << 9 | 1ULL << 11)
};



inline const char* streamFlagToString(StreamFlag flag) // TEST: NO
{
    // EARLY_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    switch (flag)
    {
        case StreamFlag::NONE:                 return "NONE";
        case StreamFlag::TYPE_OF_CHECK_CRC32:  return "TYPE_OF_CHECK_CRC32";
        case StreamFlag::TYPE_OF_CHECK_CRC64:  return "TYPE_OF_CHECK_CRC64";
        case StreamFlag::TYPE_OF_CHECK_SHA256: return "TYPE_OF_CHECK_SHA256";

        default: return "UNKNOWN";
    }
}



inline const char* streamFlagsToString(xz_stream_flags flags) // TEST: NO
{
    // EARLY_LT((" | flags = %u", flags)); // Commented to avoid bad looking logs



    if (!flags)
    {
        return "NONE";
    }



    static char res[80];

    FLAGS_TO_STRING(res, flags, streamFlagToString, StreamFlag);

    return res;
}



#endif



#endif // CONFIGURE_SRC_BITS64_B_EARLY_MAIN_DECOMPRESSORS_XZ_LIB_STREAMFLAGS_H
