// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE1000005D_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE1000005D_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1000005D: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10009361 = 0x10009361,
    SUBDEVICE_10009363 = 0x10009363,
    SUBDEVICE_10009364 = 0x10009364,
    SUBDEVICE_1000936A = 0x1000936A,
    SUBDEVICE_10281F41 = 0x10281F41,
    SUBDEVICE_10281F42 = 0x10281F42,
    SUBDEVICE_10281F43 = 0x10281F43,
    SUBDEVICE_10281F47 = 0x10281F47,
    SUBDEVICE_10281F48 = 0x10281F48,
    SUBDEVICE_10281F49 = 0x10281F49,
    SUBDEVICE_10281F4A = 0x10281F4A,
    SUBDEVICE_10281F4D = 0x10281F4D,
    SUBDEVICE_10281F4F = 0x10281F4F,
    SUBDEVICE_10281F54 = 0x10281F54,
    SUBDEVICE_10281FD1 = 0x10281FD1,
    SUBDEVICE_17AA1052 = 0x17AA1052,
    SUBDEVICE_17AA1053 = 0x17AA1053,
    SUBDEVICE_1BD40014 = 0x1BD40014,
    SUBDEVICE_1BD40015 = 0x1BD40015,
    SUBDEVICE_1D490600 = 0x1D490600,
    SUBDEVICE_1D490608 = 0x1D490608,
    SUBDEVICE_1D490609 = 0x1D490609,
    SUBDEVICE_8086351E = 0x8086351E,
    SUBDEVICE_8086351F = 0x8086351F,
    SUBDEVICE_80869360 = 0x80869360,
    SUBDEVICE_80869362 = 0x80869362,
    SUBDEVICE_80869380 = 0x80869380,
    SUBDEVICE_80869381 = 0x80869381
};



inline const char8* enumToString(PciSubDevice1000005D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1000005D::NONE:               return "NONE";
        case PciSubDevice1000005D::SUBDEVICE_10009361: return "SUBDEVICE_10009361";
        case PciSubDevice1000005D::SUBDEVICE_10009363: return "SUBDEVICE_10009363";
        case PciSubDevice1000005D::SUBDEVICE_10009364: return "SUBDEVICE_10009364";
        case PciSubDevice1000005D::SUBDEVICE_1000936A: return "SUBDEVICE_1000936A";
        case PciSubDevice1000005D::SUBDEVICE_10281F41: return "SUBDEVICE_10281F41";
        case PciSubDevice1000005D::SUBDEVICE_10281F42: return "SUBDEVICE_10281F42";
        case PciSubDevice1000005D::SUBDEVICE_10281F43: return "SUBDEVICE_10281F43";
        case PciSubDevice1000005D::SUBDEVICE_10281F47: return "SUBDEVICE_10281F47";
        case PciSubDevice1000005D::SUBDEVICE_10281F48: return "SUBDEVICE_10281F48";
        case PciSubDevice1000005D::SUBDEVICE_10281F49: return "SUBDEVICE_10281F49";
        case PciSubDevice1000005D::SUBDEVICE_10281F4A: return "SUBDEVICE_10281F4A";
        case PciSubDevice1000005D::SUBDEVICE_10281F4D: return "SUBDEVICE_10281F4D";
        case PciSubDevice1000005D::SUBDEVICE_10281F4F: return "SUBDEVICE_10281F4F";
        case PciSubDevice1000005D::SUBDEVICE_10281F54: return "SUBDEVICE_10281F54";
        case PciSubDevice1000005D::SUBDEVICE_10281FD1: return "SUBDEVICE_10281FD1";
        case PciSubDevice1000005D::SUBDEVICE_17AA1052: return "SUBDEVICE_17AA1052";
        case PciSubDevice1000005D::SUBDEVICE_17AA1053: return "SUBDEVICE_17AA1053";
        case PciSubDevice1000005D::SUBDEVICE_1BD40014: return "SUBDEVICE_1BD40014";
        case PciSubDevice1000005D::SUBDEVICE_1BD40015: return "SUBDEVICE_1BD40015";
        case PciSubDevice1000005D::SUBDEVICE_1D490600: return "SUBDEVICE_1D490600";
        case PciSubDevice1000005D::SUBDEVICE_1D490608: return "SUBDEVICE_1D490608";
        case PciSubDevice1000005D::SUBDEVICE_1D490609: return "SUBDEVICE_1D490609";
        case PciSubDevice1000005D::SUBDEVICE_8086351E: return "SUBDEVICE_8086351E";
        case PciSubDevice1000005D::SUBDEVICE_8086351F: return "SUBDEVICE_8086351F";
        case PciSubDevice1000005D::SUBDEVICE_80869360: return "SUBDEVICE_80869360";
        case PciSubDevice1000005D::SUBDEVICE_80869362: return "SUBDEVICE_80869362";
        case PciSubDevice1000005D::SUBDEVICE_80869380: return "SUBDEVICE_80869380";
        case PciSubDevice1000005D::SUBDEVICE_80869381: return "SUBDEVICE_80869381";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1000005D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1000005D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1000005D::SUBDEVICE_10009361: return "MegaRAID SAS 9361-8i";
        case PciSubDevice1000005D::SUBDEVICE_10009363: return "MegaRAID SAS 9361-4i";
        case PciSubDevice1000005D::SUBDEVICE_10009364: return "MegaRAID SAS 9364-8i";
        case PciSubDevice1000005D::SUBDEVICE_1000936A: return "MegaRAID SAS 9364-8i";
        case PciSubDevice1000005D::SUBDEVICE_10281F41: return "PERC H830 Adapter";
        case PciSubDevice1000005D::SUBDEVICE_10281F42: return "PERC H730P Adapter";
        case PciSubDevice1000005D::SUBDEVICE_10281F43: return "PERC H730 Adapter";
        case PciSubDevice1000005D::SUBDEVICE_10281F47: return "PERC H730P Mini";
        case PciSubDevice1000005D::SUBDEVICE_10281F48: return "PERC H730P Mini (for blades)";
        case PciSubDevice1000005D::SUBDEVICE_10281F49: return "PERC H730 Mini";
        case PciSubDevice1000005D::SUBDEVICE_10281F4A: return "PERC H730 Mini (for blades)";
        case PciSubDevice1000005D::SUBDEVICE_10281F4D: return "PERC FD33xS";
        case PciSubDevice1000005D::SUBDEVICE_10281F4F: return "PERC H730P Slim";
        case PciSubDevice1000005D::SUBDEVICE_10281F54: return "PERC FD33xD";
        case PciSubDevice1000005D::SUBDEVICE_10281FD1: return "PERC H730P MX";
        case PciSubDevice1000005D::SUBDEVICE_17AA1052: return "ThinkServer RAID 720i";
        case PciSubDevice1000005D::SUBDEVICE_17AA1053: return "ThinkServer RAID 720ix";
        case PciSubDevice1000005D::SUBDEVICE_1BD40014: return "12G SAS3108 2G";
        case PciSubDevice1000005D::SUBDEVICE_1BD40015: return "12G SAS3108 4G";
        case PciSubDevice1000005D::SUBDEVICE_1D490600: return "ThinkSystem RAID 730-8i 1GB Cache PCIe 12Gb Adapter";
        case PciSubDevice1000005D::SUBDEVICE_1D490608: return "ThinkSystem RAID 730-8i 2GB Flash PCIe 12Gb Adapter";
        case PciSubDevice1000005D::SUBDEVICE_1D490609: return "ThinkSystem RAID 730-8i 4GB Flash PCIe 12Gb Adapter";
        case PciSubDevice1000005D::SUBDEVICE_8086351E: return "RMS3CC080 RAID Controller";
        case PciSubDevice1000005D::SUBDEVICE_8086351F: return "RMS3CC040 RAID Controller";
        case PciSubDevice1000005D::SUBDEVICE_80869360: return "RS3DC080 RAID Controller";
        case PciSubDevice1000005D::SUBDEVICE_80869362: return "RS3DC040 RAID Controller";
        case PciSubDevice1000005D::SUBDEVICE_80869380: return "RS3SC008 RAID Controller";
        case PciSubDevice1000005D::SUBDEVICE_80869381: return "RS3MC044 RAID Controller";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE1000005D_H
