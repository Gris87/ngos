#ifndef UEFI_UEFICONSOLECONTROLSCREENMODE_H
#define UEFI_UEFICONSOLECONTROLSCREENMODE_H



#include <ngos/types.h>



enum class UefiConsoleControlScreenMode: u32
{
    TEXT,
    GRAPHICS,
    MAXIMUM
};



inline const char8* uefiConsoleControlScreenModeToString(UefiConsoleControlScreenMode mode) // TEST: NO
{
    switch (mode)
    {
        case UefiConsoleControlScreenMode::TEXT:     return "TEXT";
        case UefiConsoleControlScreenMode::GRAPHICS: return "GRAPHICS";
        case UefiConsoleControlScreenMode::MAXIMUM:  return "MAXIMUM";

        default: return "UNKNOWN";
    }
}



#endif // UEFI_UEFICONSOLECONTROLSCREENMODE_H
