// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR17D3_PCISUBDEVICE17D3188A_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR17D3_PCISUBDEVICE17D3188A_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice17D3188A: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_17D31217 = 0x17D31217,
    SUBDEVICE_17D31227 = 0x17D31227,
    SUBDEVICE_17D31686 = 0x17D31686,
    SUBDEVICE_17D31886 = 0x17D31886
};



inline const char8* enumToString(PciSubDevice17D3188A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice17D3188A::NONE:               return "NONE";
        case PciSubDevice17D3188A::SUBDEVICE_17D31217: return "SUBDEVICE_17D31217";
        case PciSubDevice17D3188A::SUBDEVICE_17D31227: return "SUBDEVICE_17D31227";
        case PciSubDevice17D3188A::SUBDEVICE_17D31686: return "SUBDEVICE_17D31686";
        case PciSubDevice17D3188A::SUBDEVICE_17D31886: return "SUBDEVICE_17D31886";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice17D3188A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice17D3188A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice17D3188A::SUBDEVICE_17D31217: return "ARC-1217 4-Port PCIe 4.0 to SAS/SATA 12/6Gb RAID Controller";
        case PciSubDevice17D3188A::SUBDEVICE_17D31227: return "ARC-1227 8-Port PCIe 4.0 to SAS/SATA 12/6Gb RAID Controller";
        case PciSubDevice17D3188A::SUBDEVICE_17D31686: return "ARC-1686 PCIe 4.0 to SAS/SATA 12/6Gb Tape drive Controller";
        case PciSubDevice17D3188A::SUBDEVICE_17D31886: return "ARC-1886 PCIe 4.0 to NVMe/SAS/SATA 16/12/6Gb RAID Controller";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR17D3_PCISUBDEVICE17D3188A_H
