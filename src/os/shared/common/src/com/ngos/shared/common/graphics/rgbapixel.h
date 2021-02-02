#ifndef COM_NGOS_SHARED_COMMON_GRAPHICS_RGBAPIXEL_H
#define COM_NGOS_SHARED_COMMON_GRAPHICS_RGBAPIXEL_H



#include <com/ngos/shared/common/ngos/types.h>



struct RgbaPixel
{
    RgbaPixel()
    {
        // COMMON_LT(("")); // Commented to avoid infinite loop



        value32 = 0x00000000;
    }

    RgbaPixel(bad_uint8 r, bad_uint8 g, bad_uint8 b, bad_uint8 a)
    {
        // COMMON_LT((" | r = %u, g = %u, b = %u, a = %u", r, g, b, a)); // Commented to avoid infinite loop



        red   = r;
        green = g;
        blue  = b;
        alpha = a;
    }

    RgbaPixel(bad_uint32 value)
    {
        // COMMON_LT((" | value = %u", value)); // Commented to avoid infinite loop



        value32 = value;
    }

    union
    {
        struct
        {
            bad_uint8 blue;
            bad_uint8 green;
            bad_uint8 red;
            bad_uint8 alpha;
        };

        bad_uint32 value32;
    };
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_GRAPHICS_RGBAPIXEL_H
