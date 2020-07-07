#ifndef CONFIGURE_SRC_COM_NGOS_CONFIGURE_B_EARLY_MAIN_DECOMPRESSORS_GZIP_LIB_GZIPMEMBERHEADER_H
#define CONFIGURE_SRC_COM_NGOS_CONFIGURE_B_EARLY_MAIN_DECOMPRESSORS_GZIP_LIB_GZIPMEMBERHEADER_H



#include <buildconfig.h>
#include <com/ngos/configure/b_early/main/decompressors/gzip/lib/gzipcompressionmethod.h>
#include <com/ngos/configure/b_early/main/decompressors/gzip/lib/gzipmemberextraflags.h>
#include <com/ngos/configure/b_early/main/decompressors/gzip/lib/gzipmemberflags.h>
#include <com/ngos/configure/b_early/main/decompressors/gzip/lib/gzipoperatingsystem.h>
#include <com/ngos/shared/common/ngos/types.h>



#if NGOS_BUILD_KERNEL_COMPRESSION == OPTION_KERNEL_COMPRESSION_GZIP



#define GZIP_MEMBER_HEADER_SIGNATURE 0x8B1F



struct GzipMemberHeader
{
    u16                   signature;
    GzipCompressionMethod compressionMethod;
    GzipMemberFlags       flags;
    u32                   modificationTime;
    GzipMemberExtraFlags  extraFlags;
    GzipOperatingSystem   operatingSystem;
} __attribute__((packed));



#endif



#endif // CONFIGURE_SRC_COM_NGOS_CONFIGURE_B_EARLY_MAIN_DECOMPRESSORS_GZIP_LIB_GZIPMEMBERHEADER_H
