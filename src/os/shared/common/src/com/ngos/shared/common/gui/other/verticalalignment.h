#ifndef OS_SHARED_COMMON_SRC_BITS64_GUI_OTHER_VERTICALALIGNMENT_H
#define OS_SHARED_COMMON_SRC_BITS64_GUI_OTHER_VERTICALALIGNMENT_H



#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>
#include <common/src/bits64/printf/printf.h>
#include <ngos/types.h>



enum class VerticalAlignment: u8
{
    NONE   = 0,
    TOP    = 1,
    MIDDLE = 2,
    BOTTOM = 3
};



inline const char8* enumToString(VerticalAlignment alignment) // TEST: NO
{
    // COMMON_LT((" | alignment = %u", alignment)); // Commented to avoid bad looking logs



    switch (alignment)
    {
        case VerticalAlignment::NONE:   return "NONE";
        case VerticalAlignment::TOP:    return "TOP";
        case VerticalAlignment::MIDDLE: return "MIDDLE";
        case VerticalAlignment::BOTTOM: return "BOTTOM";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(VerticalAlignment alignment) // TEST: NO
{
    // COMMON_LT((" | alignment = %u", alignment)); // Commented to avoid bad looking logs



    static char8 res[15];

    sprintf(res, "0x%02X (%s)", alignment, enumToString(alignment));

    return res;
}



#endif // OS_SHARED_COMMON_SRC_BITS64_GUI_OTHER_VERTICALALIGNMENT_H
