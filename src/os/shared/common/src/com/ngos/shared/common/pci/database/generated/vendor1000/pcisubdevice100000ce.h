// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE100000CE_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE100000CE_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice100000CE: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10009371 = 0x10009371,
    SUBDEVICE_10009390 = 0x10009390
};



inline const char8* enumToString(PciSubDevice100000CE subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100000CE::NONE:               return "NONE";
        case PciSubDevice100000CE::SUBDEVICE_10009371: return "SUBDEVICE_10009371";
        case PciSubDevice100000CE::SUBDEVICE_10009390: return "SUBDEVICE_10009390";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice100000CE subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice100000CE subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100000CE::SUBDEVICE_10009371: return "MegaRAID SAS 9361-16i";
        case PciSubDevice100000CE::SUBDEVICE_10009390: return "MegaRAID SAS 9380-8i8e";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE100000CE_H
