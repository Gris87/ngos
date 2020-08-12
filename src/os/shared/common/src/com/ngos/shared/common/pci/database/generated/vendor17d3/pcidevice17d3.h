// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR17D3_PCIDEVICE17D3_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR17D3_PCIDEVICE17D3_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice17D3: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1110 = 0x1110,
    DEVICE_1120 = 0x1120,
    DEVICE_1130 = 0x1130,
    DEVICE_1160 = 0x1160,
    DEVICE_1170 = 0x1170,
    DEVICE_1201 = 0x1201,
    DEVICE_1203 = 0x1203,
    DEVICE_1210 = 0x1210,
    DEVICE_1214 = 0x1214,
    DEVICE_1220 = 0x1220,
    DEVICE_1222 = 0x1222,
    DEVICE_1230 = 0x1230,
    DEVICE_1260 = 0x1260,
    DEVICE_1280 = 0x1280,
    DEVICE_1300 = 0x1300,
    DEVICE_1320 = 0x1320,
    DEVICE_1330 = 0x1330,
    DEVICE_1680 = 0x1680,
    DEVICE_1880 = 0x1880,
    DEVICE_1884 = 0x1884,
    DEVICE_188A = 0x188A
};



inline const char8* enumToString(PciDevice17D3 device17D3) // TEST: NO
{
    // COMMON_LT((" | device17D3 = %u", device17D3)); // Commented to avoid bad looking logs



    switch (device17D3)
    {
        case PciDevice17D3::NONE:        return "NONE";
        case PciDevice17D3::DEVICE_1110: return "DEVICE_1110";
        case PciDevice17D3::DEVICE_1120: return "DEVICE_1120";
        case PciDevice17D3::DEVICE_1130: return "DEVICE_1130";
        case PciDevice17D3::DEVICE_1160: return "DEVICE_1160";
        case PciDevice17D3::DEVICE_1170: return "DEVICE_1170";
        case PciDevice17D3::DEVICE_1201: return "DEVICE_1201";
        case PciDevice17D3::DEVICE_1203: return "DEVICE_1203";
        case PciDevice17D3::DEVICE_1210: return "DEVICE_1210";
        case PciDevice17D3::DEVICE_1214: return "DEVICE_1214";
        case PciDevice17D3::DEVICE_1220: return "DEVICE_1220";
        case PciDevice17D3::DEVICE_1222: return "DEVICE_1222";
        case PciDevice17D3::DEVICE_1230: return "DEVICE_1230";
        case PciDevice17D3::DEVICE_1260: return "DEVICE_1260";
        case PciDevice17D3::DEVICE_1280: return "DEVICE_1280";
        case PciDevice17D3::DEVICE_1300: return "DEVICE_1300";
        case PciDevice17D3::DEVICE_1320: return "DEVICE_1320";
        case PciDevice17D3::DEVICE_1330: return "DEVICE_1330";
        case PciDevice17D3::DEVICE_1680: return "DEVICE_1680";
        case PciDevice17D3::DEVICE_1880: return "DEVICE_1880";
        case PciDevice17D3::DEVICE_1884: return "DEVICE_1884";
        case PciDevice17D3::DEVICE_188A: return "DEVICE_188A";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice17D3 device17D3) // TEST: NO
{
    // COMMON_LT((" | device17D3 = %u", device17D3)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device17D3, enumToString(device17D3));

    return res;
}



inline const char8* enumToHumanString(PciDevice17D3 device17D3) // TEST: NO
{
    // COMMON_LT((" | device17D3 = %u", device17D3)); // Commented to avoid bad looking logs



    switch (device17D3)
    {
        case PciDevice17D3::DEVICE_1110: return "ARC-1110 4-Port PCI-X to SATA RAID Controller";
        case PciDevice17D3::DEVICE_1120: return "ARC-1120 8-Port PCI-X to SATA RAID Controller";
        case PciDevice17D3::DEVICE_1130: return "ARC-1130 12-Port PCI-X to SATA RAID Controller";
        case PciDevice17D3::DEVICE_1160: return "ARC-1160 16-Port PCI-X to SATA RAID Controller";
        case PciDevice17D3::DEVICE_1170: return "ARC-1170 24-Port PCI-X to SATA RAID Controller";
        case PciDevice17D3::DEVICE_1201: return "ARC-1200 2-Port PCI-Express to SATA II RAID Controller";
        case PciDevice17D3::DEVICE_1203: return "ARC-1203 2/4/8 Port PCIe 2.0 to SATA 6Gb RAID Controller";
        case PciDevice17D3::DEVICE_1210: return "ARC-1210 4-Port PCI-Express to SATA RAID Controller";
        case PciDevice17D3::DEVICE_1214: return "ARC-12x4 PCIe 2.0 to SAS/SATA 6Gb RAID Controller";
        case PciDevice17D3::DEVICE_1220: return "ARC-1220 8-Port PCI-Express to SATA RAID Controller";
        case PciDevice17D3::DEVICE_1222: return "ARC-1222 8-Port PCI-Express to SAS/SATA II RAID Controller";
        case PciDevice17D3::DEVICE_1230: return "ARC-1230 12-Port PCI-Express to SATA RAID Controller";
        case PciDevice17D3::DEVICE_1260: return "ARC-1260 16-Port PCI-Express to SATA RAID Controller";
        case PciDevice17D3::DEVICE_1280: return "ARC-1280/1280ML 24-Port PCI-Express to SATA II RAID Controller";
        case PciDevice17D3::DEVICE_1300: return "ARC-1300ix-16 16-Port PCI-Express to SAS Non-RAID Host Adapter";
        case PciDevice17D3::DEVICE_1320: return "ARC-1320 8/16 Port PCIe 2.0 to SAS/SATA 6Gb Non-RAID Host Adapter";
        case PciDevice17D3::DEVICE_1330: return "ARC-1330 16 Port PCIe 3.0 to SAS/SATA 12Gb Non-RAID Host Adapter";
        case PciDevice17D3::DEVICE_1680: return "ARC-1680 series PCIe to SAS/SATA 3Gb RAID Controller";
        case PciDevice17D3::DEVICE_1880: return "ARC-188x series PCIe 2.0/3.0 to SAS/SATA 6/12Gb RAID Controller";
        case PciDevice17D3::DEVICE_1884: return "ARC-1884 series PCIe 3.0 to SAS/SATA 12/6Gb RAID Controller";
        case PciDevice17D3::DEVICE_188A: return "ARC-1886 series PCIe 4.0 to NVMe/SAS/SATA 16/12/6Gb RAID Controller";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR17D3_PCIDEVICE17D3_H
