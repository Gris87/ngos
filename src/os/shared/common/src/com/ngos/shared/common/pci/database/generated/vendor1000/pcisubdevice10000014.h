// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE10000014_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE10000014_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10000014: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10009460 = 0x10009460,
    SUBDEVICE_10009480 = 0x10009480,
    SUBDEVICE_10009481 = 0x10009481,
    SUBDEVICE_10281F3A = 0x10281F3A,
    SUBDEVICE_10281F3B = 0x10281F3B,
    SUBDEVICE_10281FD4 = 0x10281FD4,
    SUBDEVICE_1137020E = 0x1137020E,
    SUBDEVICE_1D490602 = 0x1D490602,
    SUBDEVICE_1D490604 = 0x1D490604,
    SUBDEVICE_1D490607 = 0x1D490607,
    SUBDEVICE_8086352D = 0x8086352D,
    SUBDEVICE_80869460 = 0x80869460,
    SUBDEVICE_80869480 = 0x80869480
};



inline const char8* enumToString(PciSubDevice10000014 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10000014::NONE:               return "NONE";
        case PciSubDevice10000014::SUBDEVICE_10009460: return "SUBDEVICE_10009460";
        case PciSubDevice10000014::SUBDEVICE_10009480: return "SUBDEVICE_10009480";
        case PciSubDevice10000014::SUBDEVICE_10009481: return "SUBDEVICE_10009481";
        case PciSubDevice10000014::SUBDEVICE_10281F3A: return "SUBDEVICE_10281F3A";
        case PciSubDevice10000014::SUBDEVICE_10281F3B: return "SUBDEVICE_10281F3B";
        case PciSubDevice10000014::SUBDEVICE_10281FD4: return "SUBDEVICE_10281FD4";
        case PciSubDevice10000014::SUBDEVICE_1137020E: return "SUBDEVICE_1137020E";
        case PciSubDevice10000014::SUBDEVICE_1D490602: return "SUBDEVICE_1D490602";
        case PciSubDevice10000014::SUBDEVICE_1D490604: return "SUBDEVICE_1D490604";
        case PciSubDevice10000014::SUBDEVICE_1D490607: return "SUBDEVICE_1D490607";
        case PciSubDevice10000014::SUBDEVICE_8086352D: return "SUBDEVICE_8086352D";
        case PciSubDevice10000014::SUBDEVICE_80869460: return "SUBDEVICE_80869460";
        case PciSubDevice10000014::SUBDEVICE_80869480: return "SUBDEVICE_80869480";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10000014 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10000014 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10000014::SUBDEVICE_10009460: return "MegaRAID 9460-16i";
        case PciSubDevice10000014::SUBDEVICE_10009480: return "MegaRAID 9480-8bad_int8e";
        case PciSubDevice10000014::SUBDEVICE_10009481: return "MegaRAID 9480-8e";
        case PciSubDevice10000014::SUBDEVICE_10281F3A: return "PERC H745 Adapter";
        case PciSubDevice10000014::SUBDEVICE_10281F3B: return "PERC H745 Front";
        case PciSubDevice10000014::SUBDEVICE_10281FD4: return "PERC H745P MX";
        case PciSubDevice10000014::SUBDEVICE_1137020E: return "UCSC-RAID-M5 12G Modular RAID Controller";
        case PciSubDevice10000014::SUBDEVICE_1D490602: return "ThinkSystem RAID 930-16i 4GB Flash PCIe 12Gb Adapter";
        case PciSubDevice10000014::SUBDEVICE_1D490604: return "ThinkSystem RAID 930-8e 4GB Flash PCIe 12Gb Adapter";
        case PciSubDevice10000014::SUBDEVICE_1D490607: return "ThinkSystem RAID 930-16i 8GB Flash PCIe 12Gb Adapter";
        case PciSubDevice10000014::SUBDEVICE_8086352D: return "Integrated RAID Module RMSP3AD160F";
        case PciSubDevice10000014::SUBDEVICE_80869460: return "RAID Controller RSP3TD160F";
        case PciSubDevice10000014::SUBDEVICE_80869480: return "RAID Controller RSP3MD088F";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE10000014_H
