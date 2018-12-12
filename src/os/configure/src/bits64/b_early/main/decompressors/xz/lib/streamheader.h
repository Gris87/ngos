#ifndef CONFIGURE_SRC_BITS64_B_EARLY_MAIN_DECOMPRESSORS_XZ_LIB_STREAMHEADER_H
#define CONFIGURE_SRC_BITS64_B_EARLY_MAIN_DECOMPRESSORS_XZ_LIB_STREAMHEADER_H



#include <buildconfig.h>
#include <ngos/types.h>

#include "src/bits64/b_early/main/decompressors/xz/lib/streamflags.h"



#if NGOS_BUILD_KERNEL_COMPRESSION == OPTION_KERNEL_COMPRESSION_XZ



#define XZ_STREAM_HEADER_SIGNATURE "\xFD""7zXZ" // { 0xFD, '7', 'z', 'X', 'Z', 0x00 }



struct StreamHeader
{
    char            signature[6];
    xz_stream_flags streamFlags;
    u32             crc32;
} __attribute__((packed));



#endif



#endif // CONFIGURE_SRC_BITS64_B_EARLY_MAIN_DECOMPRESSORS_XZ_LIB_STREAMHEADER_H
