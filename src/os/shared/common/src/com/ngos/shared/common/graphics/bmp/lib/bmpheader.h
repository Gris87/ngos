#ifndef OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_BMP_LIB_BMPHEADER_H
#define OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_BMP_LIB_BMPHEADER_H



#include <common/src/com/ngos/shared/common/ngos/types.h>



#define BMP_HEADER_SIGNATURE 0x4D42 // "BM"



struct BmpHeader
{
    u16 signature;
    u32 size;
    u16 __reserved[2];
    u16 imageOffset;
    u16 __pad;
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_BMP_LIB_BMPHEADER_H
