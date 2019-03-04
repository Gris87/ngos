#ifndef CONFIGURE_SRC_BITS64_B_EARLY_MAIN_DECOMPRESSORS_GZIP_LIB_MEMBERHEADER_H
#define CONFIGURE_SRC_BITS64_B_EARLY_MAIN_DECOMPRESSORS_GZIP_LIB_MEMBERHEADER_H



#include <buildconfig.h>
#include <ngos/types.h>

#include "src/bits64/b_early/main/decompressors/gzip/lib/compressionmethod.h"
#include "src/bits64/b_early/main/decompressors/gzip/lib/memberextraflags.h"
#include "src/bits64/b_early/main/decompressors/gzip/lib/memberflags.h"
#include "src/bits64/b_early/main/decompressors/gzip/lib/operatingsystem.h"



#if NGOS_BUILD_KERNEL_COMPRESSION == OPTION_KERNEL_COMPRESSION_GZIP



#define GZIP_MEMBER_HEADER_SIGNATURE 0x8B1F



struct MemberHeader
{
    u16                     signature;
    CompressionMethod       compressionMethod;
    gzip_member_flags       flags;
    u32                     modificationTime;
    gzip_member_extra_flags extraFlags;
    OperatingSystem         operatingSystem;
} __attribute__((packed));



#endif



#endif // CONFIGURE_SRC_BITS64_B_EARLY_MAIN_DECOMPRESSORS_GZIP_LIB_MEMBERHEADER_H
