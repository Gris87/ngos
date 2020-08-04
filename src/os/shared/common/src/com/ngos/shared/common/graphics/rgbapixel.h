#ifndef COM_NGOS_SHARED_COMMON_GRAPHICS_RGBAPIXEL_H
#define COM_NGOS_SHARED_COMMON_GRAPHICS_RGBAPIXEL_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>



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



#endif // COM_NGOS_SHARED_COMMON_GRAPHICS_RGBAPIXEL_H
