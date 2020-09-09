// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE100010E1_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE100010E1_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice100010E1: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10281AE0 = 0x10281AE0,
    SUBDEVICE_10281AE1 = 0x10281AE1,
    SUBDEVICE_10281AE2 = 0x10281AE2,
    SUBDEVICE_10281AE3 = 0x10281AE3,
    SUBDEVICE_1D49060A = 0x1D49060A,
    SUBDEVICE_1D49060B = 0x1D49060B,
    SUBDEVICE_1D49060C = 0x1D49060C,
    SUBDEVICE_1D49060D = 0x1D49060D,
    SUBDEVICE_1D49060E = 0x1D49060E,
    SUBDEVICE_1D49060F = 0x1D49060F
};



inline const char8* enumToString(PciSubDevice100010E1 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100010E1::NONE:               return "NONE";
        case PciSubDevice100010E1::SUBDEVICE_10281AE0: return "SUBDEVICE_10281AE0";
        case PciSubDevice100010E1::SUBDEVICE_10281AE1: return "SUBDEVICE_10281AE1";
        case PciSubDevice100010E1::SUBDEVICE_10281AE2: return "SUBDEVICE_10281AE2";
        case PciSubDevice100010E1::SUBDEVICE_10281AE3: return "SUBDEVICE_10281AE3";
        case PciSubDevice100010E1::SUBDEVICE_1D49060A: return "SUBDEVICE_1D49060A";
        case PciSubDevice100010E1::SUBDEVICE_1D49060B: return "SUBDEVICE_1D49060B";
        case PciSubDevice100010E1::SUBDEVICE_1D49060C: return "SUBDEVICE_1D49060C";
        case PciSubDevice100010E1::SUBDEVICE_1D49060D: return "SUBDEVICE_1D49060D";
        case PciSubDevice100010E1::SUBDEVICE_1D49060E: return "SUBDEVICE_1D49060E";
        case PciSubDevice100010E1::SUBDEVICE_1D49060F: return "SUBDEVICE_1D49060F";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice100010E1 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice100010E1 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100010E1::SUBDEVICE_10281AE0: return "PERC H755 Adapter";
        case PciSubDevice100010E1::SUBDEVICE_10281AE1: return "PERC H755 Front";
        case PciSubDevice100010E1::SUBDEVICE_10281AE2: return "PERC H755N Front";
        case PciSubDevice100010E1::SUBDEVICE_10281AE3: return "PERC H755 MX";
        case PciSubDevice100010E1::SUBDEVICE_1D49060A: return "ThinkSystem RAID 940-8i 4GB Flash PCIe Gen4 12Gb Adapter";
        case PciSubDevice100010E1::SUBDEVICE_1D49060B: return "ThinkSystem RAID 940-8i 8GB Flash PCIe Gen4 12Gb Adapter";
        case PciSubDevice100010E1::SUBDEVICE_1D49060C: return "ThinkSystem RAID 940-16i 8GB Flash PCIe Gen4 12Gb Adapter";
        case PciSubDevice100010E1::SUBDEVICE_1D49060D: return "ThinkSystem RAID 940-16i 8GB Flash PCIe Gen4 12Gb Internal Adapter";
        case PciSubDevice100010E1::SUBDEVICE_1D49060E: return "ThinkSystem RAID 940-32i 8GB Flash PCIe Gen4 12Gb Adapter";
        case PciSubDevice100010E1::SUBDEVICE_1D49060F: return "ThinkSystem RAID 940-8e 4GB Flash PCIe Gen4 12Gb Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE100010E1_H
