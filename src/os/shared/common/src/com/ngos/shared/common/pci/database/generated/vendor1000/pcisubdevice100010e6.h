// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE100010E6_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE100010E6_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice100010E6: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10282172 = 0x10282172,
    SUBDEVICE_10282173 = 0x10282173,
    SUBDEVICE_10282174 = 0x10282174,
    SUBDEVICE_10282177 = 0x10282177,
    SUBDEVICE_10282199 = 0x10282199,
    SUBDEVICE_1D490505 = 0x1D490505,
    SUBDEVICE_1D490506 = 0x1D490506
};



inline const char8* enumToString(PciSubDevice100010E6 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100010E6::NONE:               return "NONE";
        case PciSubDevice100010E6::SUBDEVICE_10282172: return "SUBDEVICE_10282172";
        case PciSubDevice100010E6::SUBDEVICE_10282173: return "SUBDEVICE_10282173";
        case PciSubDevice100010E6::SUBDEVICE_10282174: return "SUBDEVICE_10282174";
        case PciSubDevice100010E6::SUBDEVICE_10282177: return "SUBDEVICE_10282177";
        case PciSubDevice100010E6::SUBDEVICE_10282199: return "SUBDEVICE_10282199";
        case PciSubDevice100010E6::SUBDEVICE_1D490505: return "SUBDEVICE_1D490505";
        case PciSubDevice100010E6::SUBDEVICE_1D490506: return "SUBDEVICE_1D490506";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice100010E6 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice100010E6 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100010E6::SUBDEVICE_10282172: return "PERC H355 Adapter";
        case PciSubDevice100010E6::SUBDEVICE_10282173: return "PERC H355 Front";
        case PciSubDevice100010E6::SUBDEVICE_10282174: return "PERC H350 Mini";
        case PciSubDevice100010E6::SUBDEVICE_10282177: return "PERC H350 Adapter";
        case PciSubDevice100010E6::SUBDEVICE_10282199: return "PERC H350 Mini LP";
        case PciSubDevice100010E6::SUBDEVICE_1D490505: return "ThinkSystem RAID 540-8i PCIe Gen4 12Gb Adapter";
        case PciSubDevice100010E6::SUBDEVICE_1D490506: return "ThinkSystem RAID 540-16i PCIe Gen4 12Gb Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE100010E6_H
