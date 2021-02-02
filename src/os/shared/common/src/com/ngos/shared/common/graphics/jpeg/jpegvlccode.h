#ifndef COM_NGOS_SHARED_COMMON_GRAPHICS_JPEG_JPEGVLCCODE_H
#define COM_NGOS_SHARED_COMMON_GRAPHICS_JPEG_JPEGVLCCODE_H



#include <com/ngos/shared/common/ngos/types.h>



struct JpegVlcCode
{
    bad_uint8 bits;
    bad_uint8 code;
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_GRAPHICS_JPEG_JPEGVLCCODE_H
