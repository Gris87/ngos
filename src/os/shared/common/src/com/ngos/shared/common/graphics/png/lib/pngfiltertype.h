#ifndef OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_PNG_LIB_PNGFILTERTYPE_H
#define OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_PNG_LIB_PNGFILTERTYPE_H



#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>
#include <common/src/bits64/printf/printf.h>
#include <ngos/types.h>



enum class PngFilterType: u8
{
    NONE    = 0,
    SUB     = 1,
    UP      = 2,
    AVERAGE = 3,
    PAETH   = 4
};



inline const char8* enumToString(PngFilterType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    switch (type)
    {
        case PngFilterType::NONE:    return "NONE";
        case PngFilterType::SUB:     return "SUB";
        case PngFilterType::UP:      return "UP";
        case PngFilterType::AVERAGE: return "AVERAGE";
        case PngFilterType::PAETH:   return "PAETH";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PngFilterType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    static char8 res[15];

    sprintf(res, "0x%02X (%s)", type, enumToString(type));

    return res;
}



#endif // OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_PNG_LIB_PNGFILTERTYPE_H
