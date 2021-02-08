// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1737_PCIDEVICE1737_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1737_PCIDEVICE1737_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1737/pcisubdevice17371032.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1737/pcisubdevice17371064.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1737: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0029 = 0x0029,
    DEVICE_1032 = 0x1032,
    DEVICE_1064 = 0x1064,
    DEVICE_AB08 = 0xAB08,
    DEVICE_AB09 = 0xAB09
};



inline const char8* enumToString(PciDevice1737 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1737::NONE:        return "NONE";
        case PciDevice1737::DEVICE_0029: return "DEVICE_0029";
        case PciDevice1737::DEVICE_1032: return "DEVICE_1032";
        case PciDevice1737::DEVICE_1064: return "DEVICE_1064";
        case PciDevice1737::DEVICE_AB08: return "DEVICE_AB08";
        case PciDevice1737::DEVICE_AB09: return "DEVICE_AB09";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1737 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1737 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1737::DEVICE_0029: return "WPG54G ver. 4 PCI Card";
        case PciDevice1737::DEVICE_1032: return "Gigabit Network Adapter";
        case PciDevice1737::DEVICE_1064: return "Gigabit Network Adapter";
        case PciDevice1737::DEVICE_AB08: return "21x4x DEC-Tulip compatible 10/100 Ethernet";
        case PciDevice1737::DEVICE_AB09: return "21x4x DEC-Tulip compatible 10/100 Ethernet";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice1737 device, u16 subsystemVendorID, u16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1737::DEVICE_0029: return "Unknown device";
        case PciDevice1737::DEVICE_1032: return enumToHumanString((PciSubDevice17371032)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1737::DEVICE_1064: return enumToHumanString((PciSubDevice17371064)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1737::DEVICE_AB08: return "Unknown device";
        case PciDevice1737::DEVICE_AB09: return "Unknown device";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1737_PCIDEVICE1737_H
