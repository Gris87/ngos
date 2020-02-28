#ifndef OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_RGBAPIXEL_H
#define OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_RGBAPIXEL_H



#include <ngos/types.h>



struct RgbaPixel
{
    u8 blue;
    u8 green;
    u8 red;
    u8 alpha; // TODO: Set with u32
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_RGBAPIXEL_H
