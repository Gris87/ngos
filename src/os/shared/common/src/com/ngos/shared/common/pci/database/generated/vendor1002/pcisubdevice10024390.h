// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024390_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024390_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10024390: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_104382EF = 0x104382EF,
    SUBDEVICE_10438389 = 0x10438389,
    SUBDEVICE_105B0E13 = 0x105B0E13,
    SUBDEVICE_1458B002 = 0x1458B002,
    SUBDEVICE_18494390 = 0x18494390
};



inline const char8* enumToString(PciSubDevice10024390 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10024390::NONE:               return "NONE";
        case PciSubDevice10024390::SUBDEVICE_104382EF: return "SUBDEVICE_104382EF";
        case PciSubDevice10024390::SUBDEVICE_10438389: return "SUBDEVICE_10438389";
        case PciSubDevice10024390::SUBDEVICE_105B0E13: return "SUBDEVICE_105B0E13";
        case PciSubDevice10024390::SUBDEVICE_1458B002: return "SUBDEVICE_1458B002";
        case PciSubDevice10024390::SUBDEVICE_18494390: return "SUBDEVICE_18494390";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10024390 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10024390 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10024390::SUBDEVICE_104382EF: return "M3A78-EH Motherboard";
        case PciSubDevice10024390::SUBDEVICE_10438389: return "M4A785TD Motherboard";
        case PciSubDevice10024390::SUBDEVICE_105B0E13: return "N15235/A74MX mainboard / AMD SB700";
        case PciSubDevice10024390::SUBDEVICE_1458B002: return "GA-MA770-DS3rev2.0 Motherboard";
        case PciSubDevice10024390::SUBDEVICE_18494390: return "Motherboard (one of many)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024390_H
