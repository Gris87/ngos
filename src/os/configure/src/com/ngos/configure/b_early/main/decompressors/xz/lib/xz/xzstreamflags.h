#ifndef CONFIGURE_SRC_COM_NGOS_CONFIGURE_B_EARLY_MAIN_DECOMPRESSORS_XZ_LIB_XZ_XZSTREAMFLAGS_H
#define CONFIGURE_SRC_COM_NGOS_CONFIGURE_B_EARLY_MAIN_DECOMPRESSORS_XZ_LIB_XZ_XZSTREAMFLAGS_H



#include <buildconfig.h>
#include <common/src/bits64/early/earlyassert.h>
#include <common/src/bits64/early/earlylog.h>
#include <common/src/bits64/printf/printf.h>
#include <common/src/bits64/string/string.h>
#include <ngos/flags.h>
#include <ngos/linkage.h>
#include <ngos/types.h>



#if NGOS_BUILD_KERNEL_COMPRESSION == OPTION_KERNEL_COMPRESSION_XZ



#define TYPE_OF_CHECK_MASK 0x0F00



typedef u16 xz_stream_flags;

enum class XzStreamFlag: xz_stream_flags
{
    NONE                 = 0,
    TYPE_OF_CHECK_CRC32  = (1ULL << 8),
    TYPE_OF_CHECK_CRC64  = (1ULL << 10),
    TYPE_OF_CHECK_SHA256 = (1ULL << 9) | (1ULL << 11)
};

DEFINE_FLAGS(XzStreamFlags, xz_stream_flags); // TEST: NO



inline const char8* flagToString(XzStreamFlag flag) // TEST: NO
{
    // EARLY_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    switch (flag)
    {
        case XzStreamFlag::NONE:                 return "NONE";
        case XzStreamFlag::TYPE_OF_CHECK_CRC32:  return "TYPE_OF_CHECK_CRC32";
        case XzStreamFlag::TYPE_OF_CHECK_CRC64:  return "TYPE_OF_CHECK_CRC64";
        case XzStreamFlag::TYPE_OF_CHECK_SHA256: return "TYPE_OF_CHECK_SHA256";

        default: return "UNKNOWN";
    }
}



inline const char8* flagToFullString(XzStreamFlag flag) // TEST: NO
{
    // EARLY_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    static char8 res[30];

    sprintf(res, "0x%04X (%s)", flag, flagToString(flag));

    return res;
}



inline const char8* flagsToString(const XzStreamFlags &flags) // TEST: NO
{
    // EARLY_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[80];

    FLAGS_TO_STRING(res, flags.flags, XzStreamFlag);

    return res;
}



inline const char8* flagsToFullString(const XzStreamFlags &flags) // TEST: NO
{
    // EARLY_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[89];

    FLAGS_TO_FULL_STRING(res, flags.flags, XzStreamFlag, "0x%04X");

    return res;
}



#endif



#endif // CONFIGURE_SRC_COM_NGOS_CONFIGURE_B_EARLY_MAIN_DECOMPRESSORS_XZ_LIB_XZ_XZSTREAMFLAGS_H
