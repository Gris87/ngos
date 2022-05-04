// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE100273BF_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE100273BF_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice100273BF: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10020E3A = 0x10020E3A,
    SUBDEVICE_148C2408 = 0x148C2408,
    SUBDEVICE_1DA2440F = 0x1DA2440F,
    SUBDEVICE_1EAE6701 = 0x1EAE6701
};



inline const char8* enumToString(PciSubDevice100273BF subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100273BF::NONE:               return "NONE";
        case PciSubDevice100273BF::SUBDEVICE_10020E3A: return "SUBDEVICE_10020E3A";
        case PciSubDevice100273BF::SUBDEVICE_148C2408: return "SUBDEVICE_148C2408";
        case PciSubDevice100273BF::SUBDEVICE_1DA2440F: return "SUBDEVICE_1DA2440F";
        case PciSubDevice100273BF::SUBDEVICE_1EAE6701: return "SUBDEVICE_1EAE6701";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice100273BF subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice100273BF subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100273BF::SUBDEVICE_10020E3A: return "Radeon RX 6900 XT";
        case PciSubDevice100273BF::SUBDEVICE_148C2408: return "Red Devil AMD Radeon RX 6900 XT";
        case PciSubDevice100273BF::SUBDEVICE_1DA2440F: return "TOXIC RX 6900 XT";
        case PciSubDevice100273BF::SUBDEVICE_1EAE6701: return "XFX Speedster MERC 319 AMD Radeon RX 6800 XT Black";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE100273BF_H
