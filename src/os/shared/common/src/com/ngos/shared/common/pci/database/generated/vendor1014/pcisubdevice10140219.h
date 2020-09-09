// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1014_PCISUBDEVICE10140219_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1014_PCISUBDEVICE10140219_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10140219: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1014021A = 0x1014021A,
    SUBDEVICE_10140251 = 0x10140251,
    SUBDEVICE_10140252 = 0x10140252
};



inline const char8* enumToString(PciSubDevice10140219 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10140219::NONE:               return "NONE";
        case PciSubDevice10140219::SUBDEVICE_1014021A: return "SUBDEVICE_1014021A";
        case PciSubDevice10140219::SUBDEVICE_10140251: return "SUBDEVICE_10140251";
        case PciSubDevice10140219::SUBDEVICE_10140252: return "SUBDEVICE_10140252";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10140219 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10140219 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10140219::SUBDEVICE_1014021A: return "Dual RVX";
        case PciSubDevice10140219::SUBDEVICE_10140251: return "Internal Modem/RVX";
        case PciSubDevice10140219::SUBDEVICE_10140252: return "Quad Internal Modem";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1014_PCISUBDEVICE10140219_H
