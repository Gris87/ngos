#ifndef COM_NGOS_CONFIGURE_B_EARLY_MAIN_DECOMPRESSORS_XZ_LIB_XZ_XZSTREAMHEADER_H
#define COM_NGOS_CONFIGURE_B_EARLY_MAIN_DECOMPRESSORS_XZ_LIB_XZ_XZSTREAMHEADER_H



#include <buildconfig.h>
#include <com/ngos/configure/b_early/main/decompressors/xz/lib/xz/xzstreamflags.h>
#include <com/ngos/shared/common/ngos/types.h>



#if NGOS_BUILD_KERNEL_COMPRESSION == OPTION_KERNEL_COMPRESSION_XZ



#define XZ_STREAM_HEADER_SIGNATURE 0x0000005A587A37FD   // 0xFD 7zXZ 0x00



struct XzStreamHeader
{
    u8            signature[6];
    XzStreamFlags streamFlags;
    u32           crc32;
} __attribute__((packed));



#endif



#endif // COM_NGOS_CONFIGURE_B_EARLY_MAIN_DECOMPRESSORS_XZ_LIB_XZ_XZSTREAMHEADER_H
