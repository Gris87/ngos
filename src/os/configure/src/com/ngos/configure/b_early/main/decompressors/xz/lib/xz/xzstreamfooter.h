#ifndef COM_NGOS_CONFIGURE_B_EARLY_MAIN_DECOMPRESSORS_XZ_LIB_XZ_XZSTREAMFOOTER_H
#define COM_NGOS_CONFIGURE_B_EARLY_MAIN_DECOMPRESSORS_XZ_LIB_XZ_XZSTREAMFOOTER_H



#include <buildconfig.h>
#include <com/ngos/configure/b_early/main/decompressors/xz/lib/xz/xzstreamflags.h>
#include <com/ngos/shared/common/ngos/types.h>



#if NGOS_BUILD_KERNEL_COMPRESSION == OPTION_KERNEL_COMPRESSION_XZ



#define XZ_STREAM_FOOTER_SIGNATURE 0x5A59   // YZ



struct XzStreamFooter
{
    bad_uint32           crc32;
    bad_uint32           backwardSize;
    XzStreamFlags streamFlags;
    bad_uint16           signature;
} __attribute__((packed));



#endif



#endif // COM_NGOS_CONFIGURE_B_EARLY_MAIN_DECOMPRESSORS_XZ_LIB_XZ_XZSTREAMFOOTER_H
