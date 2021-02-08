#ifndef COM_NGOS_SHARED_COMMON_GRAPHICS_RGBPIXEL_H
#define COM_NGOS_SHARED_COMMON_GRAPHICS_RGBPIXEL_H



#include <com/ngos/shared/common/ngos/types.h>



struct RgbPixel
{
    u8 blue;
    u8 green;
    u8 red; // TODO: Set with u32
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_GRAPHICS_RGBPIXEL_H
