// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1E0F_PCIDEVICE1E0F_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1E0F_PCIDEVICE1E0F_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1e0f/pcisubdevice1e0f0007.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1e0f/pcisubdevice1e0f0009.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1e0f/pcisubdevice1e0f0011.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1E0F: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0007 = 0x0007,
    DEVICE_0009 = 0x0009,
    DEVICE_0011 = 0x0011
};



inline const char8* enumToString(PciDevice1E0F device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1E0F::NONE:        return "NONE";
        case PciDevice1E0F::DEVICE_0007: return "DEVICE_0007";
        case PciDevice1E0F::DEVICE_0009: return "DEVICE_0009";
        case PciDevice1E0F::DEVICE_0011: return "DEVICE_0011";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1E0F device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1E0F device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1E0F::DEVICE_0007: return "NVMe SSD Controller Cx6";
        case PciDevice1E0F::DEVICE_0009: return "NVMe SSD";
        case PciDevice1E0F::DEVICE_0011: return "NVMe SSD Controller CD7";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice1E0F device, u16 subsystemVendorID, u16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1E0F::DEVICE_0007: return enumToHumanString((PciSubDevice1E0F0007)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1E0F::DEVICE_0009: return enumToHumanString((PciSubDevice1E0F0009)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1E0F::DEVICE_0011: return enumToHumanString((PciSubDevice1E0F0011)(subsystemVendorID << 16 | subDeviceId));

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1E0F_PCIDEVICE1E0F_H
