#ifndef CONFIGURE_SRC_BITS64_B_EARLY_MAIN_DECOMPRESSORS_GZIP_LIB_GZIPMEMBERHEADER_H
#define CONFIGURE_SRC_BITS64_B_EARLY_MAIN_DECOMPRESSORS_GZIP_LIB_GZIPMEMBERHEADER_H



#include <buildconfig.h>
#include <ngos/types.h>

#include "src/bits64/b_early/main/decompressors/gzip/lib/gzipcompressionmethod.h"
#include "src/bits64/b_early/main/decompressors/gzip/lib/gzipmemberextraflags.h"
#include "src/bits64/b_early/main/decompressors/gzip/lib/gzipmemberflags.h"
#include "src/bits64/b_early/main/decompressors/gzip/lib/gzipoperatingsystem.h"



#if NGOS_BUILD_KERNEL_COMPRESSION == OPTION_KERNEL_COMPRESSION_GZIP



#define GZIP_MEMBER_HEADER_SIGNATURE 0x8B1F



struct GzipMemberHeader
{
    u16                     signature;
    GzipCompressionMethod   compressionMethod;
    gzip_member_flags       flags;
    u32                     modificationTime;
    gzip_member_extra_flags extraFlags;
    GzipOperatingSystem     operatingSystem;
} __attribute__((packed));



#endif



#endif // CONFIGURE_SRC_BITS64_B_EARLY_MAIN_DECOMPRESSORS_GZIP_LIB_GZIPMEMBERHEADER_H
