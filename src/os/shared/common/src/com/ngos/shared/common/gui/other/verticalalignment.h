#ifndef COM_NGOS_SHARED_COMMON_GUI_OTHER_VERTICALALIGNMENT_H
#define COM_NGOS_SHARED_COMMON_GUI_OTHER_VERTICALALIGNMENT_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class VerticalAlignment: bad_uint8
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

    sprintf(res, "0x%02X (%s)", (bad_uint8)alignment, enumToString(alignment));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_GUI_OTHER_VERTICALALIGNMENT_H
