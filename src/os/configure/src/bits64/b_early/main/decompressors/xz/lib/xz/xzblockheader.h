#ifndef CONFIGURE_SRC_BITS64_B_EARLY_MAIN_DECOMPRESSORS_XZ_LIB_XZ_XZBLOCKHEADER_H
#define CONFIGURE_SRC_BITS64_B_EARLY_MAIN_DECOMPRESSORS_XZ_LIB_XZ_XZBLOCKHEADER_H



#include <buildconfig.h>
#include <ngos/types.h>

#include "src/bits64/b_early/main/decompressors/xz/lib/xz/xzblockflags.h"



#if NGOS_BUILD_KERNEL_COMPRESSION == OPTION_KERNEL_COMPRESSION_XZ



struct XzBlockHeader
{
    // This field contains the size of the Block Header field,
    // including the Block Header Size field itself. Valid values are
    // in the range [0x01, 0xFF], which indicate the size of the Block
    // Header as multiples of four bytes, minimum size being eight
    // bytes

    u8             blockHeaderSize;
    xz_block_flags blockFlags;
} __attribute__((packed));



#endif



#endif // CONFIGURE_SRC_BITS64_B_EARLY_MAIN_DECOMPRESSORS_XZ_LIB_XZ_XZBLOCKHEADER_H
