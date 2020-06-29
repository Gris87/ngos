#ifndef DEVICEMANAGER_SRC_COM_NGOS_BOOTLOADER_TOOLS_DEVICEMANAGER_OTHER_DEVICEMANAGERMODE_H
#define DEVICEMANAGER_SRC_COM_NGOS_BOOTLOADER_TOOLS_DEVICEMANAGER_OTHER_DEVICEMANAGERMODE_H



#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>



enum class DeviceManagerMode: u8
{
    BASIC,
    EXPERT,
    TECHNICAL,
    MAXIMUM
};



inline const char8* enumToString(DeviceManagerMode mode) // TEST: NO
{
    // UEFI_LT((" | mode = %u", mode)); // Commented to avoid bad looking logs



    switch (mode)
    {
        case DeviceManagerMode::BASIC:     return "BASIC";
        case DeviceManagerMode::EXPERT:    return "EXPERT";
        case DeviceManagerMode::TECHNICAL: return "TECHNICAL";
        case DeviceManagerMode::MAXIMUM:   return "MAXIMUM";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(DeviceManagerMode mode) // TEST: NO
{
    // UEFI_LT((" | mode = %u", mode)); // Commented to avoid bad looking logs



    static char8 res[17];

    sprintf(res, "0x%02X (%s)", mode, enumToString(mode));

    return res;
}



inline const char8* enumToHumanString(DeviceManagerMode mode) // TEST: NO
{
    // UEFI_LT((" | mode = %u", mode)); // Commented to avoid bad looking logs



    switch (mode)
    {
        case DeviceManagerMode::BASIC:     return "Basic";
        case DeviceManagerMode::EXPERT:    return "Expert";
        case DeviceManagerMode::TECHNICAL: return "Technical";
        case DeviceManagerMode::MAXIMUM:   return "MAXIMUM";

        default: return "UNKNOWN";
    }
}



#endif // DEVICEMANAGER_SRC_COM_NGOS_BOOTLOADER_TOOLS_DEVICEMANAGER_OTHER_DEVICEMANAGERMODE_H
