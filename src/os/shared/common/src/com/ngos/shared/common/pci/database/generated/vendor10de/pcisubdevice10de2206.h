// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE2206_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE2206_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE2206: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10DE1467 = 0x10DE1467,
    SUBDEVICE_10DE146D = 0x10DE146D,
    SUBDEVICE_14623892 = 0x14623892
};



inline const char8* enumToString(PciSubDevice10DE2206 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE2206::NONE:               return "NONE";
        case PciSubDevice10DE2206::SUBDEVICE_10DE1467: return "SUBDEVICE_10DE1467";
        case PciSubDevice10DE2206::SUBDEVICE_10DE146D: return "SUBDEVICE_10DE146D";
        case PciSubDevice10DE2206::SUBDEVICE_14623892: return "SUBDEVICE_14623892";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE2206 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE2206 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE2206::SUBDEVICE_10DE1467: return "GA102 [GeForce RTX 3080]";
        case PciSubDevice10DE2206::SUBDEVICE_10DE146D: return "GA102 [GeForce RTX 3080 20GB]";
        case PciSubDevice10DE2206::SUBDEVICE_14623892: return "RTX 3080 10GB GAMING X TRIO";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE2206_H
