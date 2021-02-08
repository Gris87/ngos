// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE10000016_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE10000016_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10000016: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10009461 = 0x10009461,
    SUBDEVICE_10009462 = 0x10009462,
    SUBDEVICE_10009463 = 0x10009463,
    SUBDEVICE_10009464 = 0x10009464,
    SUBDEVICE_10281FC9 = 0x10281FC9,
    SUBDEVICE_10281FCB = 0x10281FCB,
    SUBDEVICE_10281FCD = 0x10281FCD,
    SUBDEVICE_10281FCF = 0x10281FCF,
    SUBDEVICE_1D490601 = 0x1D490601,
    SUBDEVICE_1D490603 = 0x1D490603,
    SUBDEVICE_8086352E = 0x8086352E,
    SUBDEVICE_8086352F = 0x8086352F,
    SUBDEVICE_80869461 = 0x80869461
};



inline const char8* enumToString(PciSubDevice10000016 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10000016::NONE:               return "NONE";
        case PciSubDevice10000016::SUBDEVICE_10009461: return "SUBDEVICE_10009461";
        case PciSubDevice10000016::SUBDEVICE_10009462: return "SUBDEVICE_10009462";
        case PciSubDevice10000016::SUBDEVICE_10009463: return "SUBDEVICE_10009463";
        case PciSubDevice10000016::SUBDEVICE_10009464: return "SUBDEVICE_10009464";
        case PciSubDevice10000016::SUBDEVICE_10281FC9: return "SUBDEVICE_10281FC9";
        case PciSubDevice10000016::SUBDEVICE_10281FCB: return "SUBDEVICE_10281FCB";
        case PciSubDevice10000016::SUBDEVICE_10281FCD: return "SUBDEVICE_10281FCD";
        case PciSubDevice10000016::SUBDEVICE_10281FCF: return "SUBDEVICE_10281FCF";
        case PciSubDevice10000016::SUBDEVICE_1D490601: return "SUBDEVICE_1D490601";
        case PciSubDevice10000016::SUBDEVICE_1D490603: return "SUBDEVICE_1D490603";
        case PciSubDevice10000016::SUBDEVICE_8086352E: return "SUBDEVICE_8086352E";
        case PciSubDevice10000016::SUBDEVICE_8086352F: return "SUBDEVICE_8086352F";
        case PciSubDevice10000016::SUBDEVICE_80869461: return "SUBDEVICE_80869461";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10000016 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10000016 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10000016::SUBDEVICE_10009461: return "MegaRAID 9460-8i";
        case PciSubDevice10000016::SUBDEVICE_10009462: return "MegaRAID 9460-4i";
        case PciSubDevice10000016::SUBDEVICE_10009463: return "MegaRAID 9365-28i";
        case PciSubDevice10000016::SUBDEVICE_10009464: return "MegaRAID 9365-24i";
        case PciSubDevice10000016::SUBDEVICE_10281FC9: return "PERC H840 Adapter";
        case PciSubDevice10000016::SUBDEVICE_10281FCB: return "PERC H740P Adapter";
        case PciSubDevice10000016::SUBDEVICE_10281FCD: return "PERC H740P Mini";
        case PciSubDevice10000016::SUBDEVICE_10281FCF: return "PERC H740P Mini";
        case PciSubDevice10000016::SUBDEVICE_1D490601: return "ThinkSystem RAID 930-8i 2GB Flash PCIe 12Gb Adapter";
        case PciSubDevice10000016::SUBDEVICE_1D490603: return "ThinkSystem RAID 930-24i 4GB Flash PCIe 12Gb Adapter";
        case PciSubDevice10000016::SUBDEVICE_8086352E: return "Integrated RAID Module RMSP3CD080F";
        case PciSubDevice10000016::SUBDEVICE_8086352F: return "Integrated RAID Module RMSP3HD080E";
        case PciSubDevice10000016::SUBDEVICE_80869461: return "RAID Controller RSP3DD080F";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE10000016_H
