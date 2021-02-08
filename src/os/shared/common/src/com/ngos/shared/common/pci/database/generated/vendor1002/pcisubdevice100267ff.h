// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE100267FF_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE100267FF_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice100267FF: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10020B04 = 0x10020B04,
    SUBDEVICE_10281721 = 0x10281721,
    SUBDEVICE_10281726 = 0x10281726,
    SUBDEVICE_103C8479 = 0x103C8479,
    SUBDEVICE_104304BC = 0x104304BC,
    SUBDEVICE_1043052F = 0x1043052F,
    SUBDEVICE_145822ED = 0x145822ED,
    SUBDEVICE_148C2381 = 0x148C2381,
    SUBDEVICE_16829560 = 0x16829560,
    SUBDEVICE_1DA2E348 = 0x1DA2E348,
    SUBDEVICE_1DA2E367 = 0x1DA2E367
};



inline const char8* enumToString(PciSubDevice100267FF subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100267FF::NONE:               return "NONE";
        case PciSubDevice100267FF::SUBDEVICE_10020B04: return "SUBDEVICE_10020B04";
        case PciSubDevice100267FF::SUBDEVICE_10281721: return "SUBDEVICE_10281721";
        case PciSubDevice100267FF::SUBDEVICE_10281726: return "SUBDEVICE_10281726";
        case PciSubDevice100267FF::SUBDEVICE_103C8479: return "SUBDEVICE_103C8479";
        case PciSubDevice100267FF::SUBDEVICE_104304BC: return "SUBDEVICE_104304BC";
        case PciSubDevice100267FF::SUBDEVICE_1043052F: return "SUBDEVICE_1043052F";
        case PciSubDevice100267FF::SUBDEVICE_145822ED: return "SUBDEVICE_145822ED";
        case PciSubDevice100267FF::SUBDEVICE_148C2381: return "SUBDEVICE_148C2381";
        case PciSubDevice100267FF::SUBDEVICE_16829560: return "SUBDEVICE_16829560";
        case PciSubDevice100267FF::SUBDEVICE_1DA2E348: return "SUBDEVICE_1DA2E348";
        case PciSubDevice100267FF::SUBDEVICE_1DA2E367: return "SUBDEVICE_1DA2E367";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice100267FF subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice100267FF subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100267FF::SUBDEVICE_10020B04: return "Radeon RX 560";
        case PciSubDevice100267FF::SUBDEVICE_10281721: return "Radeon RX 560X";
        case PciSubDevice100267FF::SUBDEVICE_10281726: return "Radeon RX 560DX";
        case PciSubDevice100267FF::SUBDEVICE_103C8479: return "Radeon RX 560X Mobile";
        case PciSubDevice100267FF::SUBDEVICE_104304BC: return "Radeon RX 560";
        case PciSubDevice100267FF::SUBDEVICE_1043052F: return "Radeon RX 560";
        case PciSubDevice100267FF::SUBDEVICE_145822ED: return "Radeon RX 560";
        case PciSubDevice100267FF::SUBDEVICE_148C2381: return "Radeon RX 560";
        case PciSubDevice100267FF::SUBDEVICE_16829560: return "Radeon RX 560";
        case PciSubDevice100267FF::SUBDEVICE_1DA2E348: return "Radeon RX 560";
        case PciSubDevice100267FF::SUBDEVICE_1DA2E367: return "Radeon RX 550 640SP";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE100267FF_H
