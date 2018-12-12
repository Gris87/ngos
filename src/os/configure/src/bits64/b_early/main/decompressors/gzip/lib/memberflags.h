#ifndef CONFIGURE_SRC_BITS64_B_EARLY_MAIN_DECOMPRESSORS_GZIP_LIB_MEMBERFLAGS_H
#define CONFIGURE_SRC_BITS64_B_EARLY_MAIN_DECOMPRESSORS_GZIP_LIB_MEMBERFLAGS_H



#include <buildconfig.h>
#include <ngos/types.h>



#if NGOS_BUILD_KERNEL_COMPRESSION == OPTION_KERNEL_COMPRESSION_GZIP



typedef u8 gzip_member_flags;

enum class MemberFlag: gzip_member_flags
{
    NONE        = 0,
    TEXT        = (1ULL << 0),
    HEADER_CRC  = (1ULL << 1),
    EXTRA       = (1ULL << 2),
    NAME        = (1ULL << 3),
    COMMENT     = (1ULL << 4)
};



#endif



#endif // CONFIGURE_SRC_BITS64_B_EARLY_MAIN_DECOMPRESSORS_GZIP_LIB_MEMBERFLAGS_H
