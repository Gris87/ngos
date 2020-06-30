#ifndef CONFIGURE_SRC_COM_NGOS_CONFIGURE_B_EARLY_MAIN_DECOMPRESSORS_XZ_LIB_XZ_XZBLOCKFLAGS_H
#define CONFIGURE_SRC_COM_NGOS_CONFIGURE_B_EARLY_MAIN_DECOMPRESSORS_XZ_LIB_XZ_XZBLOCKFLAGS_H



#include <buildconfig.h>
#include <common/src/bits64/early/earlyassert.h>
#include <common/src/bits64/early/earlylog.h>
#include <common/src/bits64/printf/printf.h>
#include <common/src/bits64/string/string.h>
#include <ngos/flags.h>
#include <ngos/linkage.h>
#include <ngos/types.h>



#if NGOS_BUILD_KERNEL_COMPRESSION == OPTION_KERNEL_COMPRESSION_XZ



#define NUMBER_OF_FILTERS_MASK 0x03



typedef u8 xz_block_flags;

enum class XzBlockFlag: xz_block_flags // Ignore CppEnumVerifier
{
    NONE                      = 0,
    COMPRESSED_SIZE_PRESENT   = (1ULL << 6),
    UNCOMPRESSED_SIZE_PRESENT = (1ULL << 7)
};

DEFINE_FLAGS(XzBlockFlags, xz_block_flags); // TEST: NO



inline const char8* flagToString(XzBlockFlag flag) // TEST: NO
{
    // EARLY_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    switch (flag)
    {
        case XzBlockFlag::NONE:                      return "NONE";
        case XzBlockFlag::COMPRESSED_SIZE_PRESENT:   return "COMPRESSED_SIZE_PRESENT";
        case XzBlockFlag::UNCOMPRESSED_SIZE_PRESENT: return "UNCOMPRESSED_SIZE_PRESENT";

        default: return "UNKNOWN";
    }
}



inline const char8* flagToFullString(XzBlockFlag flag) // TEST: NO
{
    // EARLY_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    static char8 res[33];

    sprintf(res, "0x%02X (%s)", flag, flagToString(flag));

    return res;
}



inline const char8* flagsToString(const XzBlockFlags &flags) // TEST: NO
{
    // EARLY_LT((" | flags = ...")); // Commented to avoid bad looking logs



    xz_block_flags temp = flags & ~NUMBER_OF_FILTERS_MASK;



    static char8 res[67];

    FLAGS_TO_STRING(res, temp, XzBlockFlag);

    return res;
}



inline const char8* flagsToFullString(const XzBlockFlags &flags) // TEST: NO
{
    // EARLY_LT((" | flags = ...")); // Commented to avoid bad looking logs



    xz_block_flags temp = flags & ~NUMBER_OF_FILTERS_MASK;



    static char8 res[74];

    FLAGS_TO_FULL_STRING(res, temp, XzBlockFlag, "0x%02X");

    return res;
}



#endif



#endif // CONFIGURE_SRC_COM_NGOS_CONFIGURE_B_EARLY_MAIN_DECOMPRESSORS_XZ_LIB_XZ_XZBLOCKFLAGS_H
