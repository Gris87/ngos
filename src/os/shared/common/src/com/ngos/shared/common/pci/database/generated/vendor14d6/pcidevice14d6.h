// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14D6_PCIDEVICE14D6_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14D6_PCIDEVICE14D6_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice14D6: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_6101 = 0x6101,
    DEVICE_6201 = 0x6201
};



inline const char8* enumToString(PciDevice14D6 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice14D6::NONE:        return "NONE";
        case PciDevice14D6::DEVICE_6101: return "DEVICE_6101";
        case PciDevice14D6::DEVICE_6201: return "DEVICE_6201";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice14D6 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice14D6 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice14D6::DEVICE_6101: return "ACS-61xxx, PCIe to SAS/SATA RAID HBA";
        case PciDevice14D6::DEVICE_6201: return "ACS-62xxx, External PCIe to SAS/SATA RAID controller";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14D6_PCIDEVICE14D6_H
