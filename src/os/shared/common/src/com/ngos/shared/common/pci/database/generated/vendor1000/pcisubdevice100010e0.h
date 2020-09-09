// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE100010E0_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE100010E0_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice100010E0: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10281AE0 = 0x10281AE0,
    SUBDEVICE_10281AE1 = 0x10281AE1,
    SUBDEVICE_10281AE2 = 0x10281AE2,
    SUBDEVICE_10281AE3 = 0x10281AE3
};



inline const char8* enumToString(PciSubDevice100010E0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100010E0::NONE:               return "NONE";
        case PciSubDevice100010E0::SUBDEVICE_10281AE0: return "SUBDEVICE_10281AE0";
        case PciSubDevice100010E0::SUBDEVICE_10281AE1: return "SUBDEVICE_10281AE1";
        case PciSubDevice100010E0::SUBDEVICE_10281AE2: return "SUBDEVICE_10281AE2";
        case PciSubDevice100010E0::SUBDEVICE_10281AE3: return "SUBDEVICE_10281AE3";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice100010E0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice100010E0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100010E0::SUBDEVICE_10281AE0: return "PERC H755 Adapter - Invalid Device";
        case PciSubDevice100010E0::SUBDEVICE_10281AE1: return "PERC H755 Front - Invalid Device";
        case PciSubDevice100010E0::SUBDEVICE_10281AE2: return "PERC H755N Front - Invalid Device";
        case PciSubDevice100010E0::SUBDEVICE_10281AE3: return "PERC H755 MX - Invalid Device";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE100010E0_H
