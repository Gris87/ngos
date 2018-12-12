#ifndef CONFIGURE_SRC_BITS64_B_EARLY_MAIN_DECOMPRESSORS_XZ_LIB_STREAMFOOTER_H
#define CONFIGURE_SRC_BITS64_B_EARLY_MAIN_DECOMPRESSORS_XZ_LIB_STREAMFOOTER_H



#include <buildconfig.h>
#include <ngos/types.h>

#include "src/bits64/b_early/main/decompressors/xz/lib/streamflags.h"



#if NGOS_BUILD_KERNEL_COMPRESSION == OPTION_KERNEL_COMPRESSION_XZ



#define XZ_STREAM_FOOTER_SIGNATURE "YZ"



struct StreamFooter
{
    u32             crc32;
    u32             backwardSize;
    xz_stream_flags streamFlags;
    char            signature[2];
} __attribute__((packed));



#endif



#endif // CONFIGURE_SRC_BITS64_B_EARLY_MAIN_DECOMPRESSORS_XZ_LIB_STREAMFOOTER_H
