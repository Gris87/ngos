// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR101A_PCIDEVICE101A_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR101A_PCIDEVICE101A_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor101a/pcisubdevice101a0007.h>
#include <com/ngos/shared/common/pci/database/generated/vendor101a/pcisubdevice101a1dc1.h>
#include <com/ngos/shared/common/pci/database/generated/vendor101a/pcisubdevice101a1fa8.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice101A: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0005 = 0x0005,
    DEVICE_0007 = 0x0007,
    DEVICE_0009 = 0x0009,
    DEVICE_000A = 0x000A,
    DEVICE_000B = 0x000B,
    DEVICE_000C = 0x000C,
    DEVICE_0010 = 0x0010,
    DEVICE_1DC1 = 0x1DC1,
    DEVICE_1FA8 = 0x1FA8
};



inline const char8* enumToString(PciDevice101A device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice101A::NONE:        return "NONE";
        case PciDevice101A::DEVICE_0005: return "DEVICE_0005";
        case PciDevice101A::DEVICE_0007: return "DEVICE_0007";
        case PciDevice101A::DEVICE_0009: return "DEVICE_0009";
        case PciDevice101A::DEVICE_000A: return "DEVICE_000A";
        case PciDevice101A::DEVICE_000B: return "DEVICE_000B";
        case PciDevice101A::DEVICE_000C: return "DEVICE_000C";
        case PciDevice101A::DEVICE_0010: return "DEVICE_0010";
        case PciDevice101A::DEVICE_1DC1: return "DEVICE_1DC1";
        case PciDevice101A::DEVICE_1FA8: return "DEVICE_1FA8";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice101A device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice101A device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice101A::DEVICE_0005: return "100VG ethernet";
        case PciDevice101A::DEVICE_0007: return "BYNET BIC4G/2C/2G";
        case PciDevice101A::DEVICE_0009: return "PQS Memory Controller";
        case PciDevice101A::DEVICE_000A: return "BYNET BPCI Adapter";
        case PciDevice101A::DEVICE_000B: return "BYNET 4 Port BYA Switch (BYA4P)";
        case PciDevice101A::DEVICE_000C: return "BYNET 4 Port BYA Switch (BYA4G)";
        case PciDevice101A::DEVICE_0010: return "NCR AMC Memory Controller";
        case PciDevice101A::DEVICE_1DC1: return "BYNET BIC2M/BIC4M/BYA4M";
        case PciDevice101A::DEVICE_1FA8: return "BYNET Multi-port BIC Adapter (XBIC Based)";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice101A device, bad_uint16 subsystemVendorID, bad_uint16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice101A::DEVICE_0005: return "Unknown device";
        case PciDevice101A::DEVICE_0007: return enumToHumanString((PciSubDevice101A0007)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice101A::DEVICE_0009: return "Unknown device";
        case PciDevice101A::DEVICE_000A: return "Unknown device";
        case PciDevice101A::DEVICE_000B: return "Unknown device";
        case PciDevice101A::DEVICE_000C: return "Unknown device";
        case PciDevice101A::DEVICE_0010: return "Unknown device";
        case PciDevice101A::DEVICE_1DC1: return enumToHumanString((PciSubDevice101A1DC1)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice101A::DEVICE_1FA8: return enumToHumanString((PciSubDevice101A1FA8)(subsystemVendorID << 16 | subDeviceId));

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR101A_PCIDEVICE101A_H
