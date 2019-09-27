#ifndef OS_SHARED_COMMON_SRC_BITS64_GUI_OTHER_WIDGETSTATE_H
#define OS_SHARED_COMMON_SRC_BITS64_GUI_OTHER_WIDGETSTATE_H



#include <ngos/types.h>



enum class WidgetState: u8
{
    NONE    = 0,
    NORMAL  = 1,
    HOVERED = 2,
    PRESSED = 3,
    FOCUSED = 4
};



inline const char8* widgetStateToString(WidgetState state) // TEST: NO
{
    // COMMON_LT((" | state = %u", state)); // Commented to avoid bad looking logs



    switch (state)
    {
        case WidgetState::NONE:    return "NONE";
        case WidgetState::NORMAL:  return "NORMAL";
        case WidgetState::HOVERED: return "HOVERED";
        case WidgetState::PRESSED: return "PRESSED";
        case WidgetState::FOCUSED: return "FOCUSED";

        default: return "UNKNOWN";
    }
}



#endif // OS_SHARED_COMMON_SRC_BITS64_GUI_OTHER_WIDGETSTATE_H