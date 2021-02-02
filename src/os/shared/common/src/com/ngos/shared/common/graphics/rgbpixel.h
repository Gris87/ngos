#ifndef COM_NGOS_SHARED_COMMON_GRAPHICS_RGBPIXEL_H
#define COM_NGOS_SHARED_COMMON_GRAPHICS_RGBPIXEL_H



#include <com/ngos/shared/common/ngos/types.h>



struct RgbPixel
{
    bad_uint8 blue;
    bad_uint8 green;
    bad_uint8 red; // TODO: Set with bad_uint32
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_GRAPHICS_RGBPIXEL_H
