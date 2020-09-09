// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR17D3_PCISUBDEVICE17D31214_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR17D3_PCISUBDEVICE17D31214_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice17D31214: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_17D31214 = 0x17D31214,
    SUBDEVICE_17D31224 = 0x17D31224,
    SUBDEVICE_17D31264 = 0x17D31264,
    SUBDEVICE_17D31284 = 0x17D31284
};



inline const char8* enumToString(PciSubDevice17D31214 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice17D31214::NONE:               return "NONE";
        case PciSubDevice17D31214::SUBDEVICE_17D31214: return "SUBDEVICE_17D31214";
        case PciSubDevice17D31214::SUBDEVICE_17D31224: return "SUBDEVICE_17D31224";
        case PciSubDevice17D31214::SUBDEVICE_17D31264: return "SUBDEVICE_17D31264";
        case PciSubDevice17D31214::SUBDEVICE_17D31284: return "SUBDEVICE_17D31284";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice17D31214 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice17D31214 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice17D31214::SUBDEVICE_17D31214: return "ARC-1214 4-Port PCIe 2.0 to SAS/SATA 6Gb RAID Controller";
        case PciSubDevice17D31214::SUBDEVICE_17D31224: return "ARC-1224 8-Port PCIe 2.0 to SAS/SATA 6Gb RAID Controller";
        case PciSubDevice17D31214::SUBDEVICE_17D31264: return "ARC-1264 12/16 Port PCIe 2.0 to SATA 6Gb RAID Controller";
        case PciSubDevice17D31214::SUBDEVICE_17D31284: return "ARC-1284 24 Port PCIe 2.0 to SATA 6Gb RAID Controller";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR17D3_PCISUBDEVICE17D31214_H
