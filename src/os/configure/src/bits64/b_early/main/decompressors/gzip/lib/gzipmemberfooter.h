#ifndef CONFIGURE_SRC_BITS64_B_EARLY_MAIN_DECOMPRESSORS_GZIP_LIB_GZIPMEMBERFOOTER_H
#define CONFIGURE_SRC_BITS64_B_EARLY_MAIN_DECOMPRESSORS_GZIP_LIB_GZIPMEMBERFOOTER_H



#include <buildconfig.h>
#include <ngos/types.h>



#if NGOS_BUILD_KERNEL_COMPRESSION == OPTION_KERNEL_COMPRESSION_GZIP



struct GzipMemberFooter
{
    u32 crc32;
    u32 inputSize;
} __attribute__((packed));



#endif



#endif // CONFIGURE_SRC_BITS64_B_EARLY_MAIN_DECOMPRESSORS_GZIP_LIB_GZIPMEMBERFOOTER_H