#ifndef OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_RGBPIXEL_H
#define OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_RGBPIXEL_H



#include <common/src/com/ngos/shared/common/ngos/types.h>



struct RgbPixel
{
    u8 blue;
    u8 green;
    u8 red; // TODO: Set with u32
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_RGBPIXEL_H
