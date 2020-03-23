#ifndef OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_RGBAPIXEL_H
#define OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_RGBAPIXEL_H



#include <ngos/types.h>



// Ignore CppAlignmentVerifier [BEGIN]
#define RGBA_FROM_HEX(value) \
    (u32)( \
        ((((value) >> 24) & 0xFF) << 8 ) | \
        ((((value) >> 16) & 0xFF) << 16) | \
        ((((value) >> 8 ) & 0xFF) << 24) | \
        ((((value)      ) & 0xFF)      ) \
    )
// Ignore CppAlignmentVerifier [END]



struct RgbaPixel
{
    RgbaPixel()
    {
        value32 = 0;
    }

    RgbaPixel(u8 r, u8 g, u8 b, u8 a)
    {
        red   = r;
        green = g;
        blue  = b;
        alpha = a;
    }

    RgbaPixel(u32 value)
    {
        value32 = RGBA_FROM_HEX(value);
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
