// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1095_PCISUBDEVICE10953114_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1095_PCISUBDEVICE10953114_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10953114: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10438167 = 0x10438167,
    SUBDEVICE_10953114 = 0x10953114,
    SUBDEVICE_10956114 = 0x10956114
};



inline const char8* enumToString(PciSubDevice10953114 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10953114::NONE:               return "NONE";
        case PciSubDevice10953114::SUBDEVICE_10438167: return "SUBDEVICE_10438167";
        case PciSubDevice10953114::SUBDEVICE_10953114: return "SUBDEVICE_10953114";
        case PciSubDevice10953114::SUBDEVICE_10956114: return "SUBDEVICE_10956114";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10953114 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10953114 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10953114::SUBDEVICE_10438167: return "A8N-SLI Deluxe/Premium Mainboard";
        case PciSubDevice10953114::SUBDEVICE_10953114: return "SiI 3114 SATALink Controller";
        case PciSubDevice10953114::SUBDEVICE_10956114: return "SiI 3114 SATARaid Controller";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1095_PCISUBDEVICE10953114_H
