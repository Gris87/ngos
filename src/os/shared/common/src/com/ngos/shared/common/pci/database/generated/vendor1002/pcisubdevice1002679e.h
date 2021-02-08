// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002679E_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002679E_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1002679E: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_106B0125 = 0x106B0125,
    SUBDEVICE_106B0126 = 0x106B0126,
    SUBDEVICE_17872328 = 0x17872328
};



inline const char8* enumToString(PciSubDevice1002679E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1002679E::NONE:               return "NONE";
        case PciSubDevice1002679E::SUBDEVICE_106B0125: return "SUBDEVICE_106B0125";
        case PciSubDevice1002679E::SUBDEVICE_106B0126: return "SUBDEVICE_106B0126";
        case PciSubDevice1002679E::SUBDEVICE_17872328: return "SUBDEVICE_17872328";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1002679E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1002679E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1002679E::SUBDEVICE_106B0125: return "FirePro D500";
        case PciSubDevice1002679E::SUBDEVICE_106B0126: return "FirePro D500";
        case PciSubDevice1002679E::SUBDEVICE_17872328: return "Radeon HD 7870 Black Edition 2 GB GDDR5 [2GBD5-2DHV3E]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002679E_H
