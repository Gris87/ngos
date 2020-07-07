#ifndef CONFIGURE_SRC_COM_NGOS_CONFIGURE_B_EARLY_MAIN_DECOMPRESSORS_XZ_LIB_XZ_XZLZMA2DECODER_H
#define CONFIGURE_SRC_COM_NGOS_CONFIGURE_B_EARLY_MAIN_DECOMPRESSORS_XZ_LIB_XZ_XZLZMA2DECODER_H



#include <buildconfig.h>
#include <com/ngos/configure/b_early/main/decompressors/xz/lib/lzma2/lzma2.h>
#include <com/ngos/configure/b_early/main/decompressors/xz/lib/lzma2/lzma2decoder.h>
#include <com/ngos/configure/b_early/main/decompressors/xz/lib/lzma2/lzmadecoder.h>
#include <com/ngos/configure/b_early/main/decompressors/xz/lib/lzma2/lzmadictionary.h>
#include <com/ngos/configure/b_early/main/decompressors/xz/lib/lzma2/lzmarcdecoder.h>
#include <com/ngos/configure/b_early/main/decompressors/xz/lib/xz/xzbuffer.h>
#include <com/ngos/shared/common/ngos/status.h>
#include <com/ngos/shared/common/ngos/types.h>



#if NGOS_BUILD_KERNEL_COMPRESSION == OPTION_KERNEL_COMPRESSION_XZ



struct XzLzma2Decoder
{
    // The order below is important on x86 to reduce code size and
    // it shouldn't hurt on other platforms. Everything up to and
    // including lzma.positionMask are in the first 128 bytes on x86-32,
    // which allows using smaller instructions to access those
    // variables. On x86-64, fewer variables fit into the first 128
    // bytes, but this is still the best order without sacrificing
    // the readability by splitting the structures.

    LzmaRcDecoder  rc;
    LzmaDictionary dictionary;
    Lzma2Decoder   lzma2;
    LzmaDecoder    lzma;

    // Temporary buffer which holds small number of input bytes between
    // decoder calls. See lzma2DecodeLzma() for details.
    struct
    {
        u32 size;
        u8  buffer[3 * LZMA_IN_REQUIRED];
    } temp;
};



NgosStatus runXzLzma2Decoder(XzLzma2Decoder *s, XzBuffer *b); // TEST: NO



#endif



#endif // CONFIGURE_SRC_COM_NGOS_CONFIGURE_B_EARLY_MAIN_DECOMPRESSORS_XZ_LIB_XZ_XZLZMA2DECODER_H
