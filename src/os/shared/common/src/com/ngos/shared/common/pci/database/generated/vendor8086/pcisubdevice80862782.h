// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862782_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862782_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80862782: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10432582 = 0x10432582,
    SUBDEVICE_1734105B = 0x1734105B
};



inline const char8* enumToString(PciSubDevice80862782 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80862782::NONE:               return "NONE";
        case PciSubDevice80862782::SUBDEVICE_10432582: return "SUBDEVICE_10432582";
        case PciSubDevice80862782::SUBDEVICE_1734105B: return "SUBDEVICE_1734105B";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80862782 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80862782 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80862782::SUBDEVICE_10432582: return "P5GD1-VW Mainboard";
        case PciSubDevice80862782::SUBDEVICE_1734105B: return "Scenic W620";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862782_H
