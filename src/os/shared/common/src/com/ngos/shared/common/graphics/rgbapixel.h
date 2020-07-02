#ifndef OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_RGBAPIXEL_H
#define OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_RGBAPIXEL_H



#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>
#include <ngos/types.h>



struct RgbaPixel
{
    RgbaPixel()
    {
        COMMON_LT((""));



        value32 = 0x00000000;
    }

    RgbaPixel(u8 r, u8 g, u8 b, u8 a)
    {
        COMMON_LT((" | r = %u, g = %u, b = %u, a = %u", r, g, b, a));



        red   = r;
        green = g;
        blue  = b;
        alpha = a;
    }

    RgbaPixel(u32 value)
    {
        COMMON_LT((" | value = %u", value));



        value32 = value;
    }

    union
    {
        struct
        {
            u8 blue;
            u8 green;
            u8 red;
            u8 alpha;
        };

        u32 value32;
    };
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_RGBAPIXEL_H
