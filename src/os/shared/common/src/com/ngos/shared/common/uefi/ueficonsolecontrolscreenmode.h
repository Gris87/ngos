#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFICONSOLECONTROLSCREENMODE_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFICONSOLECONTROLSCREENMODE_H



#include <com/ngos/shared/common/printf/printf.h>
#include <com/ngos/shared/common/ngos/types.h>



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

    sprintf(res, "0x%08X (%s)", mode, enumToString(mode));

    return res;
}



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFICONSOLECONTROLSCREENMODE_H
