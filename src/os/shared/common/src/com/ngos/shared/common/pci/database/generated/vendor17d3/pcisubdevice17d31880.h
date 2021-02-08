// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR17D3_PCISUBDEVICE17D31880_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR17D3_PCISUBDEVICE17D31880_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice17D31880: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_17D31213 = 0x17D31213,
    SUBDEVICE_17D31215 = 0x17D31215,
    SUBDEVICE_17D31216 = 0x17D31216,
    SUBDEVICE_17D31223 = 0x17D31223,
    SUBDEVICE_17D31225 = 0x17D31225,
    SUBDEVICE_17D31226 = 0x17D31226,
    SUBDEVICE_17D31880 = 0x17D31880,
    SUBDEVICE_17D31882 = 0x17D31882,
    SUBDEVICE_17D31883 = 0x17D31883
};



inline const char8* enumToString(PciSubDevice17D31880 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice17D31880::NONE:               return "NONE";
        case PciSubDevice17D31880::SUBDEVICE_17D31213: return "SUBDEVICE_17D31213";
        case PciSubDevice17D31880::SUBDEVICE_17D31215: return "SUBDEVICE_17D31215";
        case PciSubDevice17D31880::SUBDEVICE_17D31216: return "SUBDEVICE_17D31216";
        case PciSubDevice17D31880::SUBDEVICE_17D31223: return "SUBDEVICE_17D31223";
        case PciSubDevice17D31880::SUBDEVICE_17D31225: return "SUBDEVICE_17D31225";
        case PciSubDevice17D31880::SUBDEVICE_17D31226: return "SUBDEVICE_17D31226";
        case PciSubDevice17D31880::SUBDEVICE_17D31880: return "SUBDEVICE_17D31880";
        case PciSubDevice17D31880::SUBDEVICE_17D31882: return "SUBDEVICE_17D31882";
        case PciSubDevice17D31880::SUBDEVICE_17D31883: return "SUBDEVICE_17D31883";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice17D31880 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice17D31880 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice17D31880::SUBDEVICE_17D31213: return "ARC-1213 4-Port PCIe 2.0 to SAS/SATA 6Gb RAID Controller";
        case PciSubDevice17D31880::SUBDEVICE_17D31215: return "ARC-1215 4-Port PCIe 3.0 to SAS/SATA 6Gb RAID Controller";
        case PciSubDevice17D31880::SUBDEVICE_17D31216: return "ARC-1216 4-Port PCIe 3.0 to SAS/SATA 12Gb RAID Controller";
        case PciSubDevice17D31880::SUBDEVICE_17D31223: return "ARC-1223 8-Port PCIe 2.0 to SAS/SATA 6Gb RAID Controller";
        case PciSubDevice17D31880::SUBDEVICE_17D31225: return "ARC-1225 8-Port PCIe 3.0 to SAS/SATA 6Gb RAID Controller";
        case PciSubDevice17D31880::SUBDEVICE_17D31226: return "ARC-1226 8-Port PCIe 3.0 to SAS/SATA 12Gb RAID Controller";
        case PciSubDevice17D31880::SUBDEVICE_17D31880: return "ARC-1880 8/12/16/24 Port PCIe 2.0 to SAS/SATA 6Gb RAID Controller";
        case PciSubDevice17D31880::SUBDEVICE_17D31882: return "ARC-1882 8/12/16/24 Port PCIe 3.0 to SAS/SATA 6Gb RAID Controller";
        case PciSubDevice17D31880::SUBDEVICE_17D31883: return "ARC-1883 8/12/16/24 Port PCIe 3.0 to SAS/SATA 12Gb RAID Controller";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR17D3_PCISUBDEVICE17D31880_H
