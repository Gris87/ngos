// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE00E3_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE00E3_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE00E3: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1043813F = 0x1043813F,
    SUBDEVICE_105B0C43 = 0x105B0C43,
    SUBDEVICE_147B1C0B = 0x147B1C0B,
    SUBDEVICE_184900E3 = 0x184900E3
};



inline const char8* enumToString(PciSubDevice10DE00E3 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE00E3::NONE:               return "NONE";
        case PciSubDevice10DE00E3::SUBDEVICE_1043813F: return "SUBDEVICE_1043813F";
        case PciSubDevice10DE00E3::SUBDEVICE_105B0C43: return "SUBDEVICE_105B0C43";
        case PciSubDevice10DE00E3::SUBDEVICE_147B1C0B: return "SUBDEVICE_147B1C0B";
        case PciSubDevice10DE00E3::SUBDEVICE_184900E3: return "SUBDEVICE_184900E3";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE00E3 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE00E3 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE00E3::SUBDEVICE_1043813F: return "K8N-E";
        case PciSubDevice10DE00E3::SUBDEVICE_105B0C43: return "Winfast NF3250K8AA";
        case PciSubDevice10DE00E3::SUBDEVICE_147B1C0B: return "NF8 Mainboard";
        case PciSubDevice10DE00E3::SUBDEVICE_184900E3: return "Motherboard (one of many)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE00E3_H
