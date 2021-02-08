#ifndef COM_NGOS_SHARED_COMMON_GRAPHICS_BMP_LIB_BMPHEADER_H
#define COM_NGOS_SHARED_COMMON_GRAPHICS_BMP_LIB_BMPHEADER_H



#include <com/ngos/shared/common/ngos/types.h>



#define BMP_HEADER_SIGNATURE 0x4D42 // "BM"



struct BmpHeader
{
    u16 signature;
    u32 size;
    u16 __reserved[2];
    u16 imageOffset;
    u16 __pad;
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_GRAPHICS_BMP_LIB_BMPHEADER_H
