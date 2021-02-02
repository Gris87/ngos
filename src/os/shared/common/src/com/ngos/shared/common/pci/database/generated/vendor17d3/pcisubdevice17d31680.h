// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR17D3_PCISUBDEVICE17D31680_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR17D3_PCISUBDEVICE17D31680_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice17D31680: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_17D31212 = 0x17D31212,
    SUBDEVICE_17D31222 = 0x17D31222,
    SUBDEVICE_17D31680 = 0x17D31680
};



inline const char8* enumToString(PciSubDevice17D31680 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice17D31680::NONE:               return "NONE";
        case PciSubDevice17D31680::SUBDEVICE_17D31212: return "SUBDEVICE_17D31212";
        case PciSubDevice17D31680::SUBDEVICE_17D31222: return "SUBDEVICE_17D31222";
        case PciSubDevice17D31680::SUBDEVICE_17D31680: return "SUBDEVICE_17D31680";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice17D31680 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice17D31680 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice17D31680::SUBDEVICE_17D31212: return "ARC-1212 4-Port PCIe to SAS/SATA II RAID Controller";
        case PciSubDevice17D31680::SUBDEVICE_17D31222: return "ARC-1222 8-Port PCIe to SAS/SATA 3Gb RAID Controller";
        case PciSubDevice17D31680::SUBDEVICE_17D31680: return "ARC-1680 8/12/16/24 Port PCIe to SAS/SATA 3Gb RAID Controller";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR17D3_PCISUBDEVICE17D31680_H
