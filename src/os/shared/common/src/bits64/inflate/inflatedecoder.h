#ifndef CONFIGURE_SRC_BITS64_B_EARLY_MAIN_DECOMPRESSORS_GZIP_LIB_INFLATE_INFLATEDECODER_H
#define CONFIGURE_SRC_BITS64_B_EARLY_MAIN_DECOMPRESSORS_GZIP_LIB_INFLATE_INFLATEDECODER_H



#include <buildconfig.h>
#include <ngos/types.h>



#if NGOS_BUILD_KERNEL_COMPRESSION == OPTION_KERNEL_COMPRESSION_GZIP



struct InflateDecoder
{
    u8  *in;
    u64  inPosition;

    u8  *out;
    u64  outPosition;

    struct
    {
        u32 bitBuffer;
        u8  bitsAvailable;
    } temp;
};



#endif



#endif // CONFIGURE_SRC_BITS64_B_EARLY_MAIN_DECOMPRESSORS_GZIP_LIB_INFLATE_INFLATEDECODER_H
