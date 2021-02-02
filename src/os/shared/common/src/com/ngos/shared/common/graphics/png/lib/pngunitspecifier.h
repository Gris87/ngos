#ifndef COM_NGOS_SHARED_COMMON_GRAPHICS_PNG_LIB_PNGUNITSPECIFIER_H
#define COM_NGOS_SHARED_COMMON_GRAPHICS_PNG_LIB_PNGUNITSPECIFIER_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PngUnitSpecifier: bad_uint8
{
    UNKNOWN = 0,
    METER   = 1
};



inline const char8* enumToString(PngUnitSpecifier specifier) // TEST: NO
{
    // COMMON_LT((" | specifier = %u", specifier)); // Commented to avoid bad looking logs



    switch (specifier)
    {
        case PngUnitSpecifier::UNKNOWN: return "UNKNOWN";
        case PngUnitSpecifier::METER:   return "METER";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PngUnitSpecifier specifier) // TEST: NO
{
    // COMMON_LT((" | specifier = %u", specifier)); // Commented to avoid bad looking logs



    static char8 res[15];

    sprintf(res, "0x%02X (%s)", (bad_uint8)specifier, enumToString(specifier));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_GRAPHICS_PNG_LIB_PNGUNITSPECIFIER_H
