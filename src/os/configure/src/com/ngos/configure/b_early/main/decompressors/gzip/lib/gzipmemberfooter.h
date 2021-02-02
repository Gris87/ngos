#ifndef COM_NGOS_CONFIGURE_B_EARLY_MAIN_DECOMPRESSORS_GZIP_LIB_GZIPMEMBERFOOTER_H
#define COM_NGOS_CONFIGURE_B_EARLY_MAIN_DECOMPRESSORS_GZIP_LIB_GZIPMEMBERFOOTER_H



#include <buildconfig.h>
#include <com/ngos/shared/common/ngos/types.h>



#if NGOS_BUILD_KERNEL_COMPRESSION == OPTION_KERNEL_COMPRESSION_GZIP



struct GzipMemberFooter
{
    bad_uint32 crc32;
    bad_uint32 inputSize;
} __attribute__((packed));



#endif



#endif // COM_NGOS_CONFIGURE_B_EARLY_MAIN_DECOMPRESSORS_GZIP_LIB_GZIPMEMBERFOOTER_H
