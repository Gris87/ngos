#ifndef CONFIGURE_SRC_COM_NGOS_CONFIGURE_B_EARLY_MAIN_DECOMPRESSORS_XZ_LIB_LZMA2_LZMARCDECODER_H
#define CONFIGURE_SRC_COM_NGOS_CONFIGURE_B_EARLY_MAIN_DECOMPRESSORS_XZ_LIB_LZMA2_LZMARCDECODER_H



#include <buildconfig.h>
#include <com/ngos/shared/common/ngos/types.h>



#if NGOS_BUILD_KERNEL_COMPRESSION == OPTION_KERNEL_COMPRESSION_XZ



// Range decoder
struct LzmaRcDecoder
{
    u32 range;
    u32 code;

    // Number of initializing bytes remaining to be read
    // by rcReadInit().
    u32 initialBytesLeft;

    // Buffer from which we read our input. It can be either
    // temp.buffer or the caller-provided input buffer.
    u8 *in;
    u64 inPosition;
    u64 inLimit;
};



#endif



#endif // CONFIGURE_SRC_COM_NGOS_CONFIGURE_B_EARLY_MAIN_DECOMPRESSORS_XZ_LIB_LZMA2_LZMARCDECODER_H
