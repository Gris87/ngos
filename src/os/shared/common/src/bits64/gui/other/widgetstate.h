#ifndef WIDGETSTATE_H
#define WIDGETSTATE_H



#include <ngos/types.h>



enum class WidgetState: u8
{
    NONE    = 0,
    NORMAL  = 1,
    HOVERED = 2,
    PRESSED = 3,
    FOCUSED = 4
};



inline const char8* widgetStateToString(WidgetState type) // TEST: NO
{
    switch (type)
    {
        case WidgetState::NONE:    return "NONE";
        case WidgetState::NORMAL:  return "NORMAL";
        case WidgetState::HOVERED: return "HOVERED";
        case WidgetState::PRESSED: return "PRESSED";
        case WidgetState::FOCUSED: return "FOCUSED";

        default: return "UNKNOWN";
    }
}



#endif // WIDGETSTATE_H
