#ifndef COM_NGOS_SHARED_COMMON_GRAPHICS_BMP_LIB_BMPHEADER_H
#define COM_NGOS_SHARED_COMMON_GRAPHICS_BMP_LIB_BMPHEADER_H



#include <com/ngos/shared/common/ngos/types.h>



#define BMP_HEADER_SIGNATURE 0x4D42 // "BM"



struct BmpHeader
{
    bad_uint16 signature;
    bad_uint32 size;
    bad_uint16 __reserved[2];
    bad_uint16 imageOffset;
    bad_uint16 __pad;
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_GRAPHICS_BMP_LIB_BMPHEADER_H
