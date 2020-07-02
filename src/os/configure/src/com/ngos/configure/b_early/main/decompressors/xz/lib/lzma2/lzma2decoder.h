#ifndef CONFIGURE_SRC_COM_NGOS_CONFIGURE_B_EARLY_MAIN_DECOMPRESSORS_XZ_LIB_LZMA2_LZMA2DECODER_H
#define CONFIGURE_SRC_COM_NGOS_CONFIGURE_B_EARLY_MAIN_DECOMPRESSORS_XZ_LIB_LZMA2_LZMA2DECODER_H



#include <buildconfig.h>
#include <common/src/com/ngos/shared/common/ngos/types.h>

#include "src/com/ngos/configure/b_early/main/decompressors/xz/lib/lzma2/lzma2sequence.h"



#if NGOS_BUILD_KERNEL_COMPRESSION == OPTION_KERNEL_COMPRESSION_XZ



struct Lzma2Decoder
{
    // Uncompressed size of LZMA chunk (2 MiB at maximum)
    u32 uncompressed;

    // Compressed size of LZMA chunk or compressed/uncompressed
    // size of uncompressed chunk (64 KiB at maximum)
    u32 compressed;

    // Position in runXzLzma2Decoder().
    Lzma2Sequence sequence;

    // Next position after decoding the compressed size of the chunk.
    Lzma2Sequence nextSequence;

    // True if dictionary reset is needed. This is false before
    // the first chunk (LZMA or uncompressed).
    bool needDictionaryReset;

    // True if new LZMA properties are needed. This is false
    // before the first LZMA chunk.
    bool needProperties;
};



#endif



#endif // CONFIGURE_SRC_COM_NGOS_CONFIGURE_B_EARLY_MAIN_DECOMPRESSORS_XZ_LIB_LZMA2_LZMA2DECODER_H
