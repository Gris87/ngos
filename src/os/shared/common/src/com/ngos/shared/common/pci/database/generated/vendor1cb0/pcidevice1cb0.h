// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1CB0_PCIDEVICE1CB0_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1CB0_PCIDEVICE1CB0_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1cb0/pcisubdevice1cb0d000.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1CB0: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_D000 = 0xD000
};



inline const char8* enumToString(PciDevice1CB0 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1CB0::NONE:        return "NONE";
        case PciDevice1CB0::DEVICE_D000: return "DEVICE_D000";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1CB0 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1CB0 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1CB0::DEVICE_D000: return "Venice NVMe SSD";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice1CB0 device, u16 subsystemVendorID, u16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1CB0::DEVICE_D000: return enumToHumanString((PciSubDevice1CB0D000)(subsystemVendorID << 16 | subDeviceId));

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1CB0_PCIDEVICE1CB0_H
