// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B6_PCIDEVICE10B6_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B6_PCIDEVICE10B6_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor10b6/pcisubdevice10b60002.h>
#include <com/ngos/shared/common/pci/database/generated/vendor10b6/pcisubdevice10b60003.h>
#include <com/ngos/shared/common/pci/database/generated/vendor10b6/pcisubdevice10b60006.h>
#include <com/ngos/shared/common/pci/database/generated/vendor10b6/pcisubdevice10b60007.h>
#include <com/ngos/shared/common/pci/database/generated/vendor10b6/pcisubdevice10b60009.h>
#include <com/ngos/shared/common/pci/database/generated/vendor10b6/pcisubdevice10b6000a.h>
#include <com/ngos/shared/common/pci/database/generated/vendor10b6/pcisubdevice10b6000b.h>
#include <com/ngos/shared/common/pci/database/generated/vendor10b6/pcisubdevice10b6000c.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice10B6: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001,
    DEVICE_0002 = 0x0002,
    DEVICE_0003 = 0x0003,
    DEVICE_0004 = 0x0004,
    DEVICE_0006 = 0x0006,
    DEVICE_0007 = 0x0007,
    DEVICE_0009 = 0x0009,
    DEVICE_000A = 0x000A,
    DEVICE_000B = 0x000B,
    DEVICE_000C = 0x000C,
    DEVICE_1000 = 0x1000,
    DEVICE_1001 = 0x1001
};



inline const char8* enumToString(PciDevice10B6 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice10B6::NONE:        return "NONE";
        case PciDevice10B6::DEVICE_0001: return "DEVICE_0001";
        case PciDevice10B6::DEVICE_0002: return "DEVICE_0002";
        case PciDevice10B6::DEVICE_0003: return "DEVICE_0003";
        case PciDevice10B6::DEVICE_0004: return "DEVICE_0004";
        case PciDevice10B6::DEVICE_0006: return "DEVICE_0006";
        case PciDevice10B6::DEVICE_0007: return "DEVICE_0007";
        case PciDevice10B6::DEVICE_0009: return "DEVICE_0009";
        case PciDevice10B6::DEVICE_000A: return "DEVICE_000A";
        case PciDevice10B6::DEVICE_000B: return "DEVICE_000B";
        case PciDevice10B6::DEVICE_000C: return "DEVICE_000C";
        case PciDevice10B6::DEVICE_1000: return "DEVICE_1000";
        case PciDevice10B6::DEVICE_1001: return "DEVICE_1001";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice10B6 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice10B6 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice10B6::DEVICE_0001: return "Smart 16/4 PCI Ringnode";
        case PciDevice10B6::DEVICE_0002: return "Smart 16/4 PCI Ringnode Mk2";
        case PciDevice10B6::DEVICE_0003: return "Smart 16/4 PCI Ringnode Mk3";
        case PciDevice10B6::DEVICE_0004: return "Smart 16/4 PCI Ringnode Mk1";
        case PciDevice10B6::DEVICE_0006: return "16/4 Cardbus Adapter";
        case PciDevice10B6::DEVICE_0007: return "Presto PCI Adapter";
        case PciDevice10B6::DEVICE_0009: return "Smart 100/16/4 PCI-HS Ringnode";
        case PciDevice10B6::DEVICE_000A: return "Token Ring 100/16/4 Ringnode/Ringrunner";
        case PciDevice10B6::DEVICE_000B: return "16/4 CardBus Adapter Mk2";
        case PciDevice10B6::DEVICE_000C: return "RapidFire 3140V2 16/4 TR Adapter";
        case PciDevice10B6::DEVICE_1000: return "Collage 25/155 ATM Client Adapter";
        case PciDevice10B6::DEVICE_1001: return "Collage 155 ATM Server Adapter";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice10B6 device, u16 subsystemVendorID, u16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice10B6::DEVICE_0001: return "Unknown device";
        case PciDevice10B6::DEVICE_0002: return enumToHumanString((PciSubDevice10B60002)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice10B6::DEVICE_0003: return enumToHumanString((PciSubDevice10B60003)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice10B6::DEVICE_0004: return "Unknown device";
        case PciDevice10B6::DEVICE_0006: return enumToHumanString((PciSubDevice10B60006)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice10B6::DEVICE_0007: return enumToHumanString((PciSubDevice10B60007)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice10B6::DEVICE_0009: return enumToHumanString((PciSubDevice10B60009)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice10B6::DEVICE_000A: return enumToHumanString((PciSubDevice10B6000A)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice10B6::DEVICE_000B: return enumToHumanString((PciSubDevice10B6000B)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice10B6::DEVICE_000C: return enumToHumanString((PciSubDevice10B6000C)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice10B6::DEVICE_1000: return "Unknown device";
        case PciDevice10B6::DEVICE_1001: return "Unknown device";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B6_PCIDEVICE10B6_H
