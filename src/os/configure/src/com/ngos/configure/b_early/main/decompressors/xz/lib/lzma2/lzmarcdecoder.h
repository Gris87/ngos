#ifndef COM_NGOS_CONFIGURE_B_EARLY_MAIN_DECOMPRESSORS_XZ_LIB_LZMA2_LZMARCDECODER_H
#define COM_NGOS_CONFIGURE_B_EARLY_MAIN_DECOMPRESSORS_XZ_LIB_LZMA2_LZMARCDECODER_H



#include <buildconfig.h>
#include <com/ngos/shared/common/ngos/types.h>



#if NGOS_BUILD_KERNEL_COMPRESSION == OPTION_KERNEL_COMPRESSION_XZ



// Range decoder
struct LzmaRcDecoder
{
    bad_uint32 range;
    bad_uint32 code;

    // Number of initializing bytes remaining to be read
    // by rcReadInit().
    bad_uint32 initialBytesLeft;

    // Buffer from which we read our input. It can be either
    // temp.buffer or the caller-provided input buffer.
    bad_uint8 *in;
    bad_uint64 inPosition;
    bad_uint64 inLimit;
};



#endif



#endif // COM_NGOS_CONFIGURE_B_EARLY_MAIN_DECOMPRESSORS_XZ_LIB_LZMA2_LZMARCDECODER_H
