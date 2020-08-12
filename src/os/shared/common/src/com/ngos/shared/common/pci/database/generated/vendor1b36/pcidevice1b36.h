// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1B36_PCIDEVICE1B36_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1B36_PCIDEVICE1B36_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1B36: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001,
    DEVICE_0002 = 0x0002,
    DEVICE_0003 = 0x0003,
    DEVICE_0004 = 0x0004,
    DEVICE_0005 = 0x0005,
    DEVICE_0006 = 0x0006,
    DEVICE_0007 = 0x0007,
    DEVICE_0008 = 0x0008,
    DEVICE_0009 = 0x0009,
    DEVICE_000A = 0x000A,
    DEVICE_000B = 0x000B,
    DEVICE_000C = 0x000C,
    DEVICE_000D = 0x000D,
    DEVICE_0100 = 0x0100
};



inline const char8* enumToString(PciDevice1B36 device1B36) // TEST: NO
{
    // COMMON_LT((" | device1B36 = %u", device1B36)); // Commented to avoid bad looking logs



    switch (device1B36)
    {
        case PciDevice1B36::NONE:        return "NONE";
        case PciDevice1B36::DEVICE_0001: return "DEVICE_0001";
        case PciDevice1B36::DEVICE_0002: return "DEVICE_0002";
        case PciDevice1B36::DEVICE_0003: return "DEVICE_0003";
        case PciDevice1B36::DEVICE_0004: return "DEVICE_0004";
        case PciDevice1B36::DEVICE_0005: return "DEVICE_0005";
        case PciDevice1B36::DEVICE_0006: return "DEVICE_0006";
        case PciDevice1B36::DEVICE_0007: return "DEVICE_0007";
        case PciDevice1B36::DEVICE_0008: return "DEVICE_0008";
        case PciDevice1B36::DEVICE_0009: return "DEVICE_0009";
        case PciDevice1B36::DEVICE_000A: return "DEVICE_000A";
        case PciDevice1B36::DEVICE_000B: return "DEVICE_000B";
        case PciDevice1B36::DEVICE_000C: return "DEVICE_000C";
        case PciDevice1B36::DEVICE_000D: return "DEVICE_000D";
        case PciDevice1B36::DEVICE_0100: return "DEVICE_0100";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1B36 device1B36) // TEST: NO
{
    // COMMON_LT((" | device1B36 = %u", device1B36)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1B36, enumToString(device1B36));

    return res;
}



inline const char8* enumToHumanString(PciDevice1B36 device1B36) // TEST: NO
{
    // COMMON_LT((" | device1B36 = %u", device1B36)); // Commented to avoid bad looking logs



    switch (device1B36)
    {
        case PciDevice1B36::DEVICE_0001: return "QEMU PCI-PCI bridge";
        case PciDevice1B36::DEVICE_0002: return "QEMU PCI 16550A Adapter";
        case PciDevice1B36::DEVICE_0003: return "QEMU PCI Dual-port 16550A Adapter";
        case PciDevice1B36::DEVICE_0004: return "QEMU PCI Quad-port 16550A Adapter";
        case PciDevice1B36::DEVICE_0005: return "QEMU PCI Test Device";
        case PciDevice1B36::DEVICE_0006: return "PCI Rocker Ethernet switch device";
        case PciDevice1B36::DEVICE_0007: return "PCI SD Card Host Controller Interface";
        case PciDevice1B36::DEVICE_0008: return "QEMU PCIe Host bridge";
        case PciDevice1B36::DEVICE_0009: return "QEMU PCI Expander bridge";
        case PciDevice1B36::DEVICE_000A: return "PCI-PCI bridge (multiseat)";
        case PciDevice1B36::DEVICE_000B: return "QEMU PCIe Expander bridge";
        case PciDevice1B36::DEVICE_000C: return "QEMU PCIe Root port";
        case PciDevice1B36::DEVICE_000D: return "QEMU XHCI Host Controller";
        case PciDevice1B36::DEVICE_0100: return "QXL paravirtual graphic card";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1B36_PCIDEVICE1B36_H
