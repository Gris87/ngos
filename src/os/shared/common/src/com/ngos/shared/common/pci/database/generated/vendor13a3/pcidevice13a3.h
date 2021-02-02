// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR13A3_PCIDEVICE13A3_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR13A3_PCIDEVICE13A3_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor13a3/pcisubdevice13a3002f.h>
#include <com/ngos/shared/common/pci/database/generated/vendor13a3/pcisubdevice13a30033.h>
#include <com/ngos/shared/common/pci/database/generated/vendor13a3/pcisubdevice13a30034.h>
#include <com/ngos/shared/common/pci/database/generated/vendor13a3/pcisubdevice13a30035.h>
#include <com/ngos/shared/common/pci/database/generated/vendor13a3/pcisubdevice13a30037.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice13A3: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0005 = 0x0005,
    DEVICE_0006 = 0x0006,
    DEVICE_0007 = 0x0007,
    DEVICE_0012 = 0x0012,
    DEVICE_0014 = 0x0014,
    DEVICE_0016 = 0x0016,
    DEVICE_0017 = 0x0017,
    DEVICE_0018 = 0x0018,
    DEVICE_001D = 0x001D,
    DEVICE_001F = 0x001F,
    DEVICE_0020 = 0x0020,
    DEVICE_0026 = 0x0026,
    DEVICE_002E = 0x002E,
    DEVICE_002F = 0x002F,
    DEVICE_0033 = 0x0033,
    DEVICE_0034 = 0x0034,
    DEVICE_0035 = 0x0035,
    DEVICE_0037 = 0x0037
};



inline const char8* enumToString(PciDevice13A3 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice13A3::NONE:        return "NONE";
        case PciDevice13A3::DEVICE_0005: return "DEVICE_0005";
        case PciDevice13A3::DEVICE_0006: return "DEVICE_0006";
        case PciDevice13A3::DEVICE_0007: return "DEVICE_0007";
        case PciDevice13A3::DEVICE_0012: return "DEVICE_0012";
        case PciDevice13A3::DEVICE_0014: return "DEVICE_0014";
        case PciDevice13A3::DEVICE_0016: return "DEVICE_0016";
        case PciDevice13A3::DEVICE_0017: return "DEVICE_0017";
        case PciDevice13A3::DEVICE_0018: return "DEVICE_0018";
        case PciDevice13A3::DEVICE_001D: return "DEVICE_001D";
        case PciDevice13A3::DEVICE_001F: return "DEVICE_001F";
        case PciDevice13A3::DEVICE_0020: return "DEVICE_0020";
        case PciDevice13A3::DEVICE_0026: return "DEVICE_0026";
        case PciDevice13A3::DEVICE_002E: return "DEVICE_002E";
        case PciDevice13A3::DEVICE_002F: return "DEVICE_002F";
        case PciDevice13A3::DEVICE_0033: return "DEVICE_0033";
        case PciDevice13A3::DEVICE_0034: return "DEVICE_0034";
        case PciDevice13A3::DEVICE_0035: return "DEVICE_0035";
        case PciDevice13A3::DEVICE_0037: return "DEVICE_0037";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice13A3 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice13A3 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice13A3::DEVICE_0005: return "7751 Security Processor";
        case PciDevice13A3::DEVICE_0006: return "6500 Public Key Processor";
        case PciDevice13A3::DEVICE_0007: return "7811 Security Processor";
        case PciDevice13A3::DEVICE_0012: return "7951 Security Processor";
        case PciDevice13A3::DEVICE_0014: return "78XX Security Processor";
        case PciDevice13A3::DEVICE_0016: return "8065 Security Processor";
        case PciDevice13A3::DEVICE_0017: return "8165 Security Processor";
        case PciDevice13A3::DEVICE_0018: return "8154 Security Processor";
        case PciDevice13A3::DEVICE_001D: return "7956 Security Processor";
        case PciDevice13A3::DEVICE_001F: return "7855 Security Processor";
        case PciDevice13A3::DEVICE_0020: return "7955 Security Processor";
        case PciDevice13A3::DEVICE_0026: return "8155 Security Processor";
        case PciDevice13A3::DEVICE_002E: return "9630 Compression Processor";
        case PciDevice13A3::DEVICE_002F: return "9725 Compression and Security Processor";
        case PciDevice13A3::DEVICE_0033: return "8201 Acceleration Processor";
        case PciDevice13A3::DEVICE_0034: return "8202 Acceleration Processor";
        case PciDevice13A3::DEVICE_0035: return "8203 Acceleration Processor";
        case PciDevice13A3::DEVICE_0037: return "8204 Acceleration Processor";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice13A3 device, bad_uint16 subsystemVendorID, bad_uint16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice13A3::DEVICE_0005: return "Unknown device";
        case PciDevice13A3::DEVICE_0006: return "Unknown device";
        case PciDevice13A3::DEVICE_0007: return "Unknown device";
        case PciDevice13A3::DEVICE_0012: return "Unknown device";
        case PciDevice13A3::DEVICE_0014: return "Unknown device";
        case PciDevice13A3::DEVICE_0016: return "Unknown device";
        case PciDevice13A3::DEVICE_0017: return "Unknown device";
        case PciDevice13A3::DEVICE_0018: return "Unknown device";
        case PciDevice13A3::DEVICE_001D: return "Unknown device";
        case PciDevice13A3::DEVICE_001F: return "Unknown device";
        case PciDevice13A3::DEVICE_0020: return "Unknown device";
        case PciDevice13A3::DEVICE_0026: return "Unknown device";
        case PciDevice13A3::DEVICE_002E: return "Unknown device";
        case PciDevice13A3::DEVICE_002F: return enumToHumanString((PciSubDevice13A3002F)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice13A3::DEVICE_0033: return enumToHumanString((PciSubDevice13A30033)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice13A3::DEVICE_0034: return enumToHumanString((PciSubDevice13A30034)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice13A3::DEVICE_0035: return enumToHumanString((PciSubDevice13A30035)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice13A3::DEVICE_0037: return enumToHumanString((PciSubDevice13A30037)(subsystemVendorID << 16 | subDeviceId));

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR13A3_PCIDEVICE13A3_H
