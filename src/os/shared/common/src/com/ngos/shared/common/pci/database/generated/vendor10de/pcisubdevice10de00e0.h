// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE00E0_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE00E0_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE00E0: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1043813F = 0x1043813F,
    SUBDEVICE_10DE0C11 = 0x10DE0C11,
    SUBDEVICE_14627030 = 0x14627030,
    SUBDEVICE_147B1C0B = 0x147B1C0B,
    SUBDEVICE_184900E0 = 0x184900E0
};



inline const char8* enumToString(PciSubDevice10DE00E0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE00E0::NONE:               return "NONE";
        case PciSubDevice10DE00E0::SUBDEVICE_1043813F: return "SUBDEVICE_1043813F";
        case PciSubDevice10DE00E0::SUBDEVICE_10DE0C11: return "SUBDEVICE_10DE0C11";
        case PciSubDevice10DE00E0::SUBDEVICE_14627030: return "SUBDEVICE_14627030";
        case PciSubDevice10DE00E0::SUBDEVICE_147B1C0B: return "SUBDEVICE_147B1C0B";
        case PciSubDevice10DE00E0::SUBDEVICE_184900E0: return "SUBDEVICE_184900E0";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE00E0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE00E0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE00E0::SUBDEVICE_1043813F: return "K8N-E";
        case PciSubDevice10DE00E0::SUBDEVICE_10DE0C11: return "Winfast NF3250K8AA";
        case PciSubDevice10DE00E0::SUBDEVICE_14627030: return "K8N Neo-FSR v2.0";
        case PciSubDevice10DE00E0::SUBDEVICE_147B1C0B: return "NF8 Mainboard";
        case PciSubDevice10DE00E0::SUBDEVICE_184900E0: return "Motherboard (one of many)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE00E0_H
