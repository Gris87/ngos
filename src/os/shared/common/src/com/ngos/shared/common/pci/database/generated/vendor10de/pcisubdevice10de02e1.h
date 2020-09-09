// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE02E1_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE02E1_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE02E1: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1682222B = 0x1682222B,
    SUBDEVICE_16822247 = 0x16822247
};



inline const char8* enumToString(PciSubDevice10DE02E1 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE02E1::NONE:               return "NONE";
        case PciSubDevice10DE02E1::SUBDEVICE_1682222B: return "SUBDEVICE_1682222B";
        case PciSubDevice10DE02E1::SUBDEVICE_16822247: return "SUBDEVICE_16822247";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE02E1 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE02E1 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE02E1::SUBDEVICE_1682222B: return "PV-T73K-UAL3 (256MB)";
        case PciSubDevice10DE02E1::SUBDEVICE_16822247: return "GF 7600GS 512MB DDR2";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE02E1_H
