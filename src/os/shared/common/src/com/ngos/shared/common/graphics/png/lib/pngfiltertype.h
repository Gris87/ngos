#ifndef COM_NGOS_SHARED_COMMON_GRAPHICS_PNG_LIB_PNGFILTERTYPE_H
#define COM_NGOS_SHARED_COMMON_GRAPHICS_PNG_LIB_PNGFILTERTYPE_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PngFilterType: bad_uint8
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

    sprintf(res, "0x%02X (%s)", (bad_uint8)type, enumToString(type));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_GRAPHICS_PNG_LIB_PNGFILTERTYPE_H
