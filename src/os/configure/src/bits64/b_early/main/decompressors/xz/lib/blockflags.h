#ifndef CONFIGURE_SRC_BITS64_B_EARLY_MAIN_DECOMPRESSORS_XZ_LIB_BLOCKFLAGS_H
#define CONFIGURE_SRC_BITS64_B_EARLY_MAIN_DECOMPRESSORS_XZ_LIB_BLOCKFLAGS_H



#include <buildconfig.h>
#include <common/src/bits64/early/earlyassert.h>
#include <common/src/bits64/early/earlylog.h>
#include <common/src/bits64/printf/printf.h>
#include <common/src/bits64/string/string.h>
#include <ngos/linkage.h>
#include <ngos/types.h>



#if NGOS_BUILD_KERNEL_COMPRESSION == OPTION_KERNEL_COMPRESSION_XZ



#define NUMBER_OF_FILTERS_MASK 0x03



typedef u8 xz_block_flags;

enum class BlockFlag: xz_block_flags // Ignore CppEnumVerifier
{
    NONE                      = 0,
    COMPRESSED_SIZE_PRESENT   = (1ULL << 6),
    UNCOMPRESSED_SIZE_PRESENT = (1ULL << 7)
};



inline const char* blockFlagToString(BlockFlag flag) // TEST: NO
{
    // EARLY_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    switch (flag)
    {
        case BlockFlag::NONE:                      return "NONE";
        case BlockFlag::COMPRESSED_SIZE_PRESENT:   return "COMPRESSED_SIZE_PRESENT";
        case BlockFlag::UNCOMPRESSED_SIZE_PRESENT: return "UNCOMPRESSED_SIZE_PRESENT";

        default: return "UNKNOWN";
    }
}



inline const char* blockFlagsToString(xz_block_flags flags) // TEST: NO
{
    // EARLY_LT((" | flags = %u", flags)); // Commented to avoid bad looking logs



    flags &= ~NUMBER_OF_FILTERS_MASK;

    if (!flags)
    {
        return "NONE";
    }



    static char res[67];

    FLAGS_TO_STRING(res, flags, blockFlagToString, BlockFlag);

    return res;
}



#endif



#endif // CONFIGURE_SRC_BITS64_B_EARLY_MAIN_DECOMPRESSORS_XZ_LIB_BLOCKFLAGS_H
