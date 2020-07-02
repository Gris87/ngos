#ifndef OS_SHARED_COMMON_SRC_BITS64_GUI_OTHER_HORIZONTALALIGNMENT_H
#define OS_SHARED_COMMON_SRC_BITS64_GUI_OTHER_HORIZONTALALIGNMENT_H



#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>
#include <common/src/bits64/printf/printf.h>
#include <ngos/types.h>



enum class HorizontalAlignment: u8
{
    NONE            = 0,
    LEFT_JUSTIFIED  = 1,
    CENTER          = 2,
    RIGHT_JUSTIFIED = 3
};



inline const char8* enumToString(HorizontalAlignment alignment) // TEST: NO
{
    // COMMON_LT((" | alignment = %u", alignment)); // Commented to avoid bad looking logs



    switch (alignment)
    {
        case HorizontalAlignment::NONE:            return "NONE";
        case HorizontalAlignment::LEFT_JUSTIFIED:  return "LEFT_JUSTIFIED";
        case HorizontalAlignment::CENTER:          return "CENTER";
        case HorizontalAlignment::RIGHT_JUSTIFIED: return "RIGHT_JUSTIFIED";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(HorizontalAlignment alignment) // TEST: NO
{
    // COMMON_LT((" | alignment = %u", alignment)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%02X (%s)", alignment, enumToString(alignment));

    return res;
}



#endif // OS_SHARED_COMMON_SRC_BITS64_GUI_OTHER_HORIZONTALALIGNMENT_H
