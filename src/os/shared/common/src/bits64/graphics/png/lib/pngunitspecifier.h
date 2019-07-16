#ifndef OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_PNG_LIB_PNGUNITSPECIFIER_H
#define OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_PNG_LIB_PNGUNITSPECIFIER_H



#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>
#include <ngos/types.h>



enum class PngUnitSpecifier: u8
{
    UNKNOWN = 0,
    METER   = 1
};



inline const char* pngUnitSpecifierToString(PngUnitSpecifier specifier) // TEST: NO
{
    // COMMON_LT((" | specifier = %u", specifier)); // Commented to avoid bad looking logs



    switch (specifier)
    {
        case PngUnitSpecifier::UNKNOWN: return "UNKNOWN";
        case PngUnitSpecifier::METER:   return "METER";

        default: return "UNKNOWN";
    }
}



#endif // OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_PNG_LIB_PNGUNITSPECIFIER_H
