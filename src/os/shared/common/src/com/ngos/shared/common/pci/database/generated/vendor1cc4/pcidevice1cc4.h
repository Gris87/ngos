// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1CC4_PCIDEVICE1CC4_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1CC4_PCIDEVICE1CC4_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1cc4/pcisubdevice1cc41203.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1CC4: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1203 = 0x1203,
    DEVICE_17AB = 0x17AB,
    DEVICE_6303 = 0x6303
};



inline const char8* enumToString(PciDevice1CC4 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1CC4::NONE:        return "NONE";
        case PciDevice1CC4::DEVICE_1203: return "DEVICE_1203";
        case PciDevice1CC4::DEVICE_17AB: return "DEVICE_17AB";
        case PciDevice1CC4::DEVICE_6303: return "DEVICE_6303";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1CC4 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1CC4 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1CC4::DEVICE_1203: return "NVMe SSD Controller UHXXXa series";
        case PciDevice1CC4::DEVICE_17AB: return "NVMe 256G SSD device";
        case PciDevice1CC4::DEVICE_6303: return "AM630 PCIe 4.0 x4 NVMe SSD Controller";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice1CC4 device, u16 subsystemVendorID, u16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1CC4::DEVICE_1203: return enumToHumanString((PciSubDevice1CC41203)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1CC4::DEVICE_17AB: return "Unknown device";
        case PciDevice1CC4::DEVICE_6303: return "Unknown device";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1CC4_PCIDEVICE1CC4_H
