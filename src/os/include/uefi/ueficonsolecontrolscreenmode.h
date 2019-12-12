#ifndef UEFI_UEFICONSOLECONTROLSCREENMODE_H
#define UEFI_UEFICONSOLECONTROLSCREENMODE_H



#include <common/src/bits64/printf/printf.h>
#include <ngos/types.h>



enum class UefiConsoleControlScreenMode: u32
{
    TEXT,
    GRAPHICS,
    MAXIMUM
};



inline const char8* enumToString(UefiConsoleControlScreenMode mode) // TEST: NO
{
    switch (mode)
    {
        case UefiConsoleControlScreenMode::TEXT:     return "TEXT";
        case UefiConsoleControlScreenMode::GRAPHICS: return "GRAPHICS";
        case UefiConsoleControlScreenMode::MAXIMUM:  return "MAXIMUM";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(UefiConsoleControlScreenMode mode) // TEST: NO
{
    static char8 res[22];

    sprintf(res, "0x%08X (%s)", mode, enumToString(mode));

    return res;
}



#endif // UEFI_UEFICONSOLECONTROLSCREENMODE_H
