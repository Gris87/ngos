// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862582_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862582_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80862582: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10281079 = 0x10281079,
    SUBDEVICE_103C3006 = 0x103C3006,
    SUBDEVICE_10432582 = 0x10432582,
    SUBDEVICE_14582582 = 0x14582582,
    SUBDEVICE_1734105B = 0x1734105B,
    SUBDEVICE_18492582 = 0x18492582
};



inline const char8* enumToString(PciSubDevice80862582 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80862582::NONE:               return "NONE";
        case PciSubDevice80862582::SUBDEVICE_10281079: return "SUBDEVICE_10281079";
        case PciSubDevice80862582::SUBDEVICE_103C3006: return "SUBDEVICE_103C3006";
        case PciSubDevice80862582::SUBDEVICE_10432582: return "SUBDEVICE_10432582";
        case PciSubDevice80862582::SUBDEVICE_14582582: return "SUBDEVICE_14582582";
        case PciSubDevice80862582::SUBDEVICE_1734105B: return "SUBDEVICE_1734105B";
        case PciSubDevice80862582::SUBDEVICE_18492582: return "SUBDEVICE_18492582";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80862582 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80862582 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80862582::SUBDEVICE_10281079: return "Optiplex GX280";
        case PciSubDevice80862582::SUBDEVICE_103C3006: return "DC7100 SFF(DX878AV)";
        case PciSubDevice80862582::SUBDEVICE_10432582: return "P5GD1-VW Mainboard";
        case PciSubDevice80862582::SUBDEVICE_14582582: return "GA-8I915ME-G Mainboard";
        case PciSubDevice80862582::SUBDEVICE_1734105B: return "Scenic W620";
        case PciSubDevice80862582::SUBDEVICE_18492582: return "ASRock P4Dual-915GL";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862582_H
