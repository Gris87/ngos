// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0101_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0101_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE0101: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10430202 = 0x10430202,
    SUBDEVICE_1043400A = 0x1043400A,
    SUBDEVICE_1043400B = 0x1043400B,
    SUBDEVICE_10480C42 = 0x10480C42,
    SUBDEVICE_107D2822 = 0x107D2822,
    SUBDEVICE_1102102E = 0x1102102E,
    SUBDEVICE_14AF5021 = 0x14AF5021
};



inline const char8* enumToString(PciSubDevice10DE0101 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0101::NONE:               return "NONE";
        case PciSubDevice10DE0101::SUBDEVICE_10430202: return "SUBDEVICE_10430202";
        case PciSubDevice10DE0101::SUBDEVICE_1043400A: return "SUBDEVICE_1043400A";
        case PciSubDevice10DE0101::SUBDEVICE_1043400B: return "SUBDEVICE_1043400B";
        case PciSubDevice10DE0101::SUBDEVICE_10480C42: return "SUBDEVICE_10480C42";
        case PciSubDevice10DE0101::SUBDEVICE_107D2822: return "SUBDEVICE_107D2822";
        case PciSubDevice10DE0101::SUBDEVICE_1102102E: return "SUBDEVICE_1102102E";
        case PciSubDevice10DE0101::SUBDEVICE_14AF5021: return "SUBDEVICE_14AF5021";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE0101 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE0101 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0101::SUBDEVICE_10430202: return "AGP-V6800 DDR";
        case PciSubDevice10DE0101::SUBDEVICE_1043400A: return "AGP-V6800 DDR SGRAM";
        case PciSubDevice10DE0101::SUBDEVICE_1043400B: return "AGP-V6800 DDR SDRAM";
        case PciSubDevice10DE0101::SUBDEVICE_10480C42: return "Erazor X";
        case PciSubDevice10DE0101::SUBDEVICE_107D2822: return "WinFast GeForce 256";
        case PciSubDevice10DE0101::SUBDEVICE_1102102E: return "CT6970/CT6971";
        case PciSubDevice10DE0101::SUBDEVICE_14AF5021: return "3D Prophet DDR-DVI";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0101_H
