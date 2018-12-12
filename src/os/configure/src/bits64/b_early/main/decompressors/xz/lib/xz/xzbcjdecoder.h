#ifndef CONFIGURE_SRC_BITS64_B_EARLY_MAIN_DECOMPRESSORS_XZ_LIB_XZ_XZBCJDECODER_H
#define CONFIGURE_SRC_BITS64_B_EARLY_MAIN_DECOMPRESSORS_XZ_LIB_XZ_XZBCJDECODER_H



#include <buildconfig.h>
#include <ngos/types.h>

#include "src/bits64/b_early/main/decompressors/xz/lib/xz/xzbuffer.h"
#include "src/bits64/b_early/main/decompressors/xz/lib/xz/xzresult.h"



#if NGOS_BUILD_KERNEL_COMPRESSION == OPTION_KERNEL_COMPRESSION_XZ



struct XzBcjDecoder
{
    // x86 filter state
    u32 x86PreviousMask;
};



XzResult runXzBcjDecoder(XzBcjDecoder *decoder, XzBuffer *buffer); // TEST: NO



#endif



#endif // CONFIGURE_SRC_BITS64_B_EARLY_MAIN_DECOMPRESSORS_XZ_LIB_XZ_XZBCJDECODER_H
