#ifndef OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_BMP_BMPCOMPRESSIONMETHOD_H
#define OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_BMP_BMPCOMPRESSIONMETHOD_H



#include <ngos/types.h>



enum class BmpCompressionMethod: u32
{
    RGB              = 0,
    RLE8             = 1,
    RLE4             = 2,
    BIT_FIELDS       = 3,
    JPEG             = 4,
    PNG              = 5,
    ALPHA_BIT_FIELDS = 6,
    CMYK             = 11,
    CMYK_RLE8        = 12,
    CMYK_RLE4        = 13
};



inline const char* bmpCompressionMethodToString(BmpCompressionMethod method) // TEST: NO
{
    // COMMON_LT((" | method = %u", method)); // Commented to avoid bad looking logs



    switch (method)
    {
        case BmpCompressionMethod::RGB:              return "RGB";
        case BmpCompressionMethod::RLE8:             return "RLE8";
        case BmpCompressionMethod::RLE4:             return "RLE4";
        case BmpCompressionMethod::BIT_FIELDS:       return "BIT_FIELDS";
        case BmpCompressionMethod::JPEG:             return "JPEG";
        case BmpCompressionMethod::PNG:              return "PNG";
        case BmpCompressionMethod::ALPHA_BIT_FIELDS: return "ALPHA_BIT_FIELDS";
        case BmpCompressionMethod::CMYK:             return "CMYK";
        case BmpCompressionMethod::CMYK_RLE8:        return "CMYK_RLE8";
        case BmpCompressionMethod::CMYK_RLE4:        return "CMYK_RLE4";

        default: return "UNKNOWN";
    }
}



#endif // OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_BMP_BMPCOMPRESSIONMETHOD_H
