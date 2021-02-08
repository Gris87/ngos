// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862651_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862651_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80862651: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10280179 = 0x10280179,
    SUBDEVICE_10432601 = 0x10432601,
    SUBDEVICE_1734105C = 0x1734105C,
    SUBDEVICE_80864147 = 0x80864147,
    SUBDEVICE_E4BF0CCD = 0xE4BF0CCD,
    SUBDEVICE_E4BF0CD3 = 0xE4BF0CD3,
    SUBDEVICE_E4BF58B1 = 0xE4BF58B1
};



inline const char8* enumToString(PciSubDevice80862651 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80862651::NONE:               return "NONE";
        case PciSubDevice80862651::SUBDEVICE_10280179: return "SUBDEVICE_10280179";
        case PciSubDevice80862651::SUBDEVICE_10432601: return "SUBDEVICE_10432601";
        case PciSubDevice80862651::SUBDEVICE_1734105C: return "SUBDEVICE_1734105C";
        case PciSubDevice80862651::SUBDEVICE_80864147: return "SUBDEVICE_80864147";
        case PciSubDevice80862651::SUBDEVICE_E4BF0CCD: return "SUBDEVICE_E4BF0CCD";
        case PciSubDevice80862651::SUBDEVICE_E4BF0CD3: return "SUBDEVICE_E4BF0CD3";
        case PciSubDevice80862651::SUBDEVICE_E4BF58B1: return "SUBDEVICE_E4BF58B1";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80862651 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80862651 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80862651::SUBDEVICE_10280179: return "Optiplex GX280";
        case PciSubDevice80862651::SUBDEVICE_10432601: return "P5GD1-VW Mainboard";
        case PciSubDevice80862651::SUBDEVICE_1734105C: return "Scenic W620";
        case PciSubDevice80862651::SUBDEVICE_80864147: return "D915GAG Motherboard";
        case PciSubDevice80862651::SUBDEVICE_E4BF0CCD: return "CCD-CALYPSO";
        case PciSubDevice80862651::SUBDEVICE_E4BF0CD3: return "CD3-JIVE";
        case PciSubDevice80862651::SUBDEVICE_E4BF58B1: return "XB1";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862651_H
