// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0060_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0060_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE0060: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_104380AD = 0x104380AD,
    SUBDEVICE_147B1C02 = 0x147B1C02,
    SUBDEVICE_A0A003BA = 0xA0A003BA
};



inline const char8* enumToString(PciSubDevice10DE0060 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0060::NONE:               return "NONE";
        case PciSubDevice10DE0060::SUBDEVICE_104380AD: return "SUBDEVICE_104380AD";
        case PciSubDevice10DE0060::SUBDEVICE_147B1C02: return "SUBDEVICE_147B1C02";
        case PciSubDevice10DE0060::SUBDEVICE_A0A003BA: return "SUBDEVICE_A0A003BA";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE0060 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE0060 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0060::SUBDEVICE_104380AD: return "A7N8X Mainboard";
        case PciSubDevice10DE0060::SUBDEVICE_147B1C02: return "NF7-S/NF7 (nVidia-nForce2) 2.X";
        case PciSubDevice10DE0060::SUBDEVICE_A0A003BA: return "UK79G-1394 motherboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0060_H
