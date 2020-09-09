// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1039_PCISUBDEVICE10396300_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1039_PCISUBDEVICE10396300_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10396300: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10190970 = 0x10190970,
    SUBDEVICE_10438035 = 0x10438035,
    SUBDEVICE_104D80E2 = 0x104D80E2
};



inline const char8* enumToString(PciSubDevice10396300 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10396300::NONE:               return "NONE";
        case PciSubDevice10396300::SUBDEVICE_10190970: return "SUBDEVICE_10190970";
        case PciSubDevice10396300::SUBDEVICE_10438035: return "SUBDEVICE_10438035";
        case PciSubDevice10396300::SUBDEVICE_104D80E2: return "SUBDEVICE_104D80E2";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10396300 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10396300 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10396300::SUBDEVICE_10190970: return "P6STP-FL motherboard";
        case PciSubDevice10396300::SUBDEVICE_10438035: return "CUSI-FX motherboard";
        case PciSubDevice10396300::SUBDEVICE_104D80E2: return "VAIO PCV-J200";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1039_PCISUBDEVICE10396300_H
