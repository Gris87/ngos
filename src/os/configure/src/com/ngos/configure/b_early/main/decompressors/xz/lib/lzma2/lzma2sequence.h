#ifndef CONFIGURE_SRC_COM_NGOS_CONFIGURE_B_EARLY_MAIN_DECOMPRESSORS_XZ_LIB_LZMA2_LZMA2SEQUENCE_H
#define CONFIGURE_SRC_COM_NGOS_CONFIGURE_B_EARLY_MAIN_DECOMPRESSORS_XZ_LIB_LZMA2_LZMA2SEQUENCE_H



#include <buildconfig.h>
#include <common/src/com/ngos/shared/common/early/earlyassert.h>
#include <common/src/com/ngos/shared/common/early/earlylog.h>
#include <common/src/com/ngos/shared/common/printf/printf.h>
#include <common/src/com/ngos/shared/common/ngos/types.h>



#if NGOS_BUILD_KERNEL_COMPRESSION == OPTION_KERNEL_COMPRESSION_XZ



enum class Lzma2Sequence: u8
{
    SEQ_CONTROL        = 0,
    SEQ_UNCOMPRESSED_1 = 1,
    SEQ_UNCOMPRESSED_2 = 2,
    SEQ_COMPRESSED_0   = 3,
    SEQ_COMPRESSED_1   = 4,
    SEQ_PROPERTIES     = 5,
    SEQ_LZMA_PREPARE   = 6,
    SEQ_LZMA_RUN       = 7,
    SEQ_COPY           = 8
};



inline const char8* enumToString(Lzma2Sequence sequence) // TEST: NO
{
    // EARLY_LT((" | sequence = %u", sequence)); // Commented to avoid bad looking logs



    switch (sequence)
    {
        case Lzma2Sequence::SEQ_CONTROL:        return "SEQ_CONTROL";
        case Lzma2Sequence::SEQ_UNCOMPRESSED_1: return "SEQ_UNCOMPRESSED_1";
        case Lzma2Sequence::SEQ_UNCOMPRESSED_2: return "SEQ_UNCOMPRESSED_2";
        case Lzma2Sequence::SEQ_COMPRESSED_0:   return "SEQ_COMPRESSED_0";
        case Lzma2Sequence::SEQ_COMPRESSED_1:   return "SEQ_COMPRESSED_1";
        case Lzma2Sequence::SEQ_PROPERTIES:     return "SEQ_PROPERTIES";
        case Lzma2Sequence::SEQ_LZMA_PREPARE:   return "SEQ_LZMA_PREPARE";
        case Lzma2Sequence::SEQ_LZMA_RUN:       return "SEQ_LZMA_RUN";
        case Lzma2Sequence::SEQ_COPY:           return "SEQ_COPY";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(Lzma2Sequence sequence) // TEST: NO
{
    // EARLY_LT((" | sequence = %u", sequence)); // Commented to avoid bad looking logs



    static char8 res[26];

    sprintf(res, "0x%02X (%s)", sequence, enumToString(sequence));

    return res;
}



#endif



#endif // CONFIGURE_SRC_COM_NGOS_CONFIGURE_B_EARLY_MAIN_DECOMPRESSORS_XZ_LIB_LZMA2_LZMA2SEQUENCE_H
