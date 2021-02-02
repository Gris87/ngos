// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1073_PCIDEVICE1073_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1073_PCIDEVICE1073_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1073/pcisubdevice10730004.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1073/pcisubdevice10730005.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1073/pcisubdevice10730008.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1073/pcisubdevice1073000a.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1073/pcisubdevice1073000c.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1073/pcisubdevice1073000d.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1073/pcisubdevice10730010.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1073/pcisubdevice10730012.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1073/pcisubdevice10732000.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1073: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001,
    DEVICE_0002 = 0x0002,
    DEVICE_0003 = 0x0003,
    DEVICE_0004 = 0x0004,
    DEVICE_0005 = 0x0005,
    DEVICE_0006 = 0x0006,
    DEVICE_0008 = 0x0008,
    DEVICE_000A = 0x000A,
    DEVICE_000C = 0x000C,
    DEVICE_000D = 0x000D,
    DEVICE_0010 = 0x0010,
    DEVICE_0012 = 0x0012,
    DEVICE_0020 = 0x0020,
    DEVICE_1000 = 0x1000,
    DEVICE_2000 = 0x2000
};



inline const char8* enumToString(PciDevice1073 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1073::NONE:        return "NONE";
        case PciDevice1073::DEVICE_0001: return "DEVICE_0001";
        case PciDevice1073::DEVICE_0002: return "DEVICE_0002";
        case PciDevice1073::DEVICE_0003: return "DEVICE_0003";
        case PciDevice1073::DEVICE_0004: return "DEVICE_0004";
        case PciDevice1073::DEVICE_0005: return "DEVICE_0005";
        case PciDevice1073::DEVICE_0006: return "DEVICE_0006";
        case PciDevice1073::DEVICE_0008: return "DEVICE_0008";
        case PciDevice1073::DEVICE_000A: return "DEVICE_000A";
        case PciDevice1073::DEVICE_000C: return "DEVICE_000C";
        case PciDevice1073::DEVICE_000D: return "DEVICE_000D";
        case PciDevice1073::DEVICE_0010: return "DEVICE_0010";
        case PciDevice1073::DEVICE_0012: return "DEVICE_0012";
        case PciDevice1073::DEVICE_0020: return "DEVICE_0020";
        case PciDevice1073::DEVICE_1000: return "DEVICE_1000";
        case PciDevice1073::DEVICE_2000: return "DEVICE_2000";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1073 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1073 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1073::DEVICE_0001: return "3D GUI Accelerator";
        case PciDevice1073::DEVICE_0002: return "YGV615 [RPA3 3D-Graphics Controller]";
        case PciDevice1073::DEVICE_0003: return "YMF-740";
        case PciDevice1073::DEVICE_0004: return "YMF-724";
        case PciDevice1073::DEVICE_0005: return "DS1 Audio";
        case PciDevice1073::DEVICE_0006: return "DS1 Audio";
        case PciDevice1073::DEVICE_0008: return "DS1 Audio";
        case PciDevice1073::DEVICE_000A: return "DS1L Audio";
        case PciDevice1073::DEVICE_000C: return "YMF-740C [DS-1L Audio Controller]";
        case PciDevice1073::DEVICE_000D: return "YMF-724F [DS-1 Audio Controller]";
        case PciDevice1073::DEVICE_0010: return "YMF-744B [DS-1S Audio Controller]";
        case PciDevice1073::DEVICE_0012: return "YMF-754 [DS-1E Audio Controller]";
        case PciDevice1073::DEVICE_0020: return "DS-1 Audio";
        case PciDevice1073::DEVICE_1000: return "SW1000XG [XG Factory]";
        case PciDevice1073::DEVICE_2000: return "DS2416 Digital Mixing Card";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice1073 device, bad_uint16 subsystemVendorID, bad_uint16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1073::DEVICE_0001: return "Unknown device";
        case PciDevice1073::DEVICE_0002: return "Unknown device";
        case PciDevice1073::DEVICE_0003: return "Unknown device";
        case PciDevice1073::DEVICE_0004: return enumToHumanString((PciSubDevice10730004)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1073::DEVICE_0005: return enumToHumanString((PciSubDevice10730005)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1073::DEVICE_0006: return "Unknown device";
        case PciDevice1073::DEVICE_0008: return enumToHumanString((PciSubDevice10730008)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1073::DEVICE_000A: return enumToHumanString((PciSubDevice1073000A)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1073::DEVICE_000C: return enumToHumanString((PciSubDevice1073000C)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1073::DEVICE_000D: return enumToHumanString((PciSubDevice1073000D)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1073::DEVICE_0010: return enumToHumanString((PciSubDevice10730010)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1073::DEVICE_0012: return enumToHumanString((PciSubDevice10730012)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1073::DEVICE_0020: return "Unknown device";
        case PciDevice1073::DEVICE_1000: return "Unknown device";
        case PciDevice1073::DEVICE_2000: return enumToHumanString((PciSubDevice10732000)(subsystemVendorID << 16 | subDeviceId));

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1073_PCIDEVICE1073_H
