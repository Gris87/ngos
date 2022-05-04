// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1E95_PCIDEVICE1E95_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1E95_PCIDEVICE1E95_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1e95/pcisubdevice1e951002.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1E95: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1002 = 0x1002
};



inline const char8* enumToString(PciDevice1E95 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1E95::NONE:        return "NONE";
        case PciDevice1E95::DEVICE_1002: return "DEVICE_1002";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1E95 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1E95 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1E95::DEVICE_1002: return "NVMe Datacenter LJ1 SSD [3DNAND, Rainier Controller]";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice1E95 device, u16 subsystemVendorID, u16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1E95::DEVICE_1002: return enumToHumanString((PciSubDevice1E951002)(subsystemVendorID << 16 | subDeviceId));

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1E95_PCIDEVICE1E95_H
