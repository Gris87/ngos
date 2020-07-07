#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_GUI_OTHER_WIDGETSTATE_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_GUI_OTHER_WIDGETSTATE_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class WidgetState: u8
{
    NONE             = 0,
    NORMAL           = 1,
    HOVERED          = 2,
    PRESSED          = 3,
    FOCUSED          = 4,
    FOCUSED_HOVERED  = 5,
    INACTIVE         = 6,
    INACTIVE_HOVERED = 7
};



inline const char8* enumToString(WidgetState state) // TEST: NO
{
    // COMMON_LT((" | state = %u", state)); // Commented to avoid bad looking logs



    switch (state)
    {
        case WidgetState::NONE:             return "NONE";
        case WidgetState::NORMAL:           return "NORMAL";
        case WidgetState::HOVERED:          return "HOVERED";
        case WidgetState::PRESSED:          return "PRESSED";
        case WidgetState::FOCUSED:          return "FOCUSED";
        case WidgetState::FOCUSED_HOVERED:  return "FOCUSED_HOVERED";
        case WidgetState::INACTIVE:         return "INACTIVE";
        case WidgetState::INACTIVE_HOVERED: return "INACTIVE_HOVERED";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(WidgetState state) // TEST: NO
{
    // COMMON_LT((" | state = %u", state)); // Commented to avoid bad looking logs



    static char8 res[24];

    sprintf(res, "0x%02X (%s)", state, enumToString(state));

    return res;
}



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_GUI_OTHER_WIDGETSTATE_H
