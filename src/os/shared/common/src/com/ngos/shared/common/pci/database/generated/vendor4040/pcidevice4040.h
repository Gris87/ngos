// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR4040_PCIDEVICE4040_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR4040_PCIDEVICE4040_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor4040/pcisubdevice40400001.h>
#include <com/ngos/shared/common/pci/database/generated/vendor4040/pcisubdevice40400002.h>
#include <com/ngos/shared/common/pci/database/generated/vendor4040/pcisubdevice40400005.h>
#include <com/ngos/shared/common/pci/database/generated/vendor4040/pcisubdevice40400100.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice4040: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001,
    DEVICE_0002 = 0x0002,
    DEVICE_0003 = 0x0003,
    DEVICE_0004 = 0x0004,
    DEVICE_0005 = 0x0005,
    DEVICE_0024 = 0x0024,
    DEVICE_0025 = 0x0025,
    DEVICE_0100 = 0x0100
};



inline const char8* enumToString(PciDevice4040 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice4040::NONE:        return "NONE";
        case PciDevice4040::DEVICE_0001: return "DEVICE_0001";
        case PciDevice4040::DEVICE_0002: return "DEVICE_0002";
        case PciDevice4040::DEVICE_0003: return "DEVICE_0003";
        case PciDevice4040::DEVICE_0004: return "DEVICE_0004";
        case PciDevice4040::DEVICE_0005: return "DEVICE_0005";
        case PciDevice4040::DEVICE_0024: return "DEVICE_0024";
        case PciDevice4040::DEVICE_0025: return "DEVICE_0025";
        case PciDevice4040::DEVICE_0100: return "DEVICE_0100";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice4040 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice4040 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice4040::DEVICE_0001: return "NXB-10GXSR 10-Gigabit Ethernet PCIe Adapter with SR-XFP optical interface";
        case PciDevice4040::DEVICE_0002: return "NXB-10GCX4 10-Gigabit Ethernet PCIe Adapter with CX4 copper interface";
        case PciDevice4040::DEVICE_0003: return "NXB-4GCU Quad Gigabit Ethernet PCIe Adapter with 1000-BASE-T interface";
        case PciDevice4040::DEVICE_0004: return "BladeCenter-H 10-Gigabit Ethernet High Speed Daughter Card";
        case PciDevice4040::DEVICE_0005: return "NetXen Dual Port 10GbE Multifunction Adapter for c-Class";
        case PciDevice4040::DEVICE_0024: return "XG Mgmt";
        case PciDevice4040::DEVICE_0025: return "XG Mgmt";
        case PciDevice4040::DEVICE_0100: return "NX3031 Multifunction 1/10-Gigabit Server Adapter";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice4040 device, u16 subsystemVendorID, u16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice4040::DEVICE_0001: return enumToHumanString((PciSubDevice40400001)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice4040::DEVICE_0002: return enumToHumanString((PciSubDevice40400002)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice4040::DEVICE_0003: return "Unknown device";
        case PciDevice4040::DEVICE_0004: return "Unknown device";
        case PciDevice4040::DEVICE_0005: return enumToHumanString((PciSubDevice40400005)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice4040::DEVICE_0024: return "Unknown device";
        case PciDevice4040::DEVICE_0025: return "Unknown device";
        case PciDevice4040::DEVICE_0100: return enumToHumanString((PciSubDevice40400100)(subsystemVendorID << 16 | subDeviceId));

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR4040_PCIDEVICE4040_H
