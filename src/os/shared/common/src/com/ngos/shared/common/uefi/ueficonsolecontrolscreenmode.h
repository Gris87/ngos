#ifndef COM_NGOS_SHARED_COMMON_UEFI_UEFICONSOLECONTROLSCREENMODE_H
#define COM_NGOS_SHARED_COMMON_UEFI_UEFICONSOLECONTROLSCREENMODE_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class UefiConsoleControlScreenMode: u32
{
    TEXT,
    GRAPHICS,
    MAXIMUM
};



inline const char8* enumToString(UefiConsoleControlScreenMode mode) // TEST: NO
{
    // COMMON_LT((" | mode = %u", mode)); // Commented to avoid bad looking logs



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
    // COMMON_LT((" | mode = %u", mode)); // Commented to avoid bad looking logs



    static char8 res[22];

    sprintf(res, "0x%08X (%s)", (u32)mode, enumToString(mode));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_UEFI_UEFICONSOLECONTROLSCREENMODE_H
