#ifndef CONFIGURE_SRC_BITS64_B_EARLY_MAIN_DECOMPRESSORS_GZIP_LIB_INFLATE_INFLATEDECODER_H
#define CONFIGURE_SRC_BITS64_B_EARLY_MAIN_DECOMPRESSORS_GZIP_LIB_INFLATE_INFLATEDECODER_H



#include <ngos/types.h>



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



#endif // CONFIGURE_SRC_BITS64_B_EARLY_MAIN_DECOMPRESSORS_GZIP_LIB_INFLATE_INFLATEDECODER_H
