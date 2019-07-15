#ifndef OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_PNG_LIB_PNGFILTERTYPE_H
#define OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_PNG_LIB_PNGFILTERTYPE_H



#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>
#include <ngos/types.h>



enum class PngFilterType: u8
{
    NONE    = 0,
    SUB     = 1,
    UP      = 2,
    AVERAGE = 3,
    PAETH   = 4
};



inline const char* pngFilterTypeToString(PngFilterType type) 
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



#endif // OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_PNG_LIB_PNGFILTERTYPE_H
