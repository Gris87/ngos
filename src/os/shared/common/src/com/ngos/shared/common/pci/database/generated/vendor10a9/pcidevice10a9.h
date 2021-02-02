// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10A9_PCIDEVICE10A9_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10A9_PCIDEVICE10A9_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor10a9/pcisubdevice10a90009.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice10A9: bad_uint16 // Ignore CppEnumVerifier
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
    DEVICE_0010 = 0x0010,
    DEVICE_0011 = 0x0011,
    DEVICE_0012 = 0x0012,
    DEVICE_0208 = 0x0208,
    DEVICE_1001 = 0x1001,
    DEVICE_1002 = 0x1002,
    DEVICE_1003 = 0x1003,
    DEVICE_1004 = 0x1004,
    DEVICE_1005 = 0x1005,
    DEVICE_1006 = 0x1006,
    DEVICE_1007 = 0x1007,
    DEVICE_1008 = 0x1008,
    DEVICE_100A = 0x100A,
    DEVICE_1504 = 0x1504,
    DEVICE_2001 = 0x2001,
    DEVICE_2002 = 0x2002,
    DEVICE_4001 = 0x4001,
    DEVICE_4002 = 0x4002,
    DEVICE_8001 = 0x8001,
    DEVICE_8002 = 0x8002,
    DEVICE_802B = 0x802B
};



inline const char8* enumToString(PciDevice10A9 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice10A9::NONE:        return "NONE";
        case PciDevice10A9::DEVICE_0001: return "DEVICE_0001";
        case PciDevice10A9::DEVICE_0002: return "DEVICE_0002";
        case PciDevice10A9::DEVICE_0003: return "DEVICE_0003";
        case PciDevice10A9::DEVICE_0004: return "DEVICE_0004";
        case PciDevice10A9::DEVICE_0005: return "DEVICE_0005";
        case PciDevice10A9::DEVICE_0006: return "DEVICE_0006";
        case PciDevice10A9::DEVICE_0007: return "DEVICE_0007";
        case PciDevice10A9::DEVICE_0008: return "DEVICE_0008";
        case PciDevice10A9::DEVICE_0009: return "DEVICE_0009";
        case PciDevice10A9::DEVICE_0010: return "DEVICE_0010";
        case PciDevice10A9::DEVICE_0011: return "DEVICE_0011";
        case PciDevice10A9::DEVICE_0012: return "DEVICE_0012";
        case PciDevice10A9::DEVICE_0208: return "DEVICE_0208";
        case PciDevice10A9::DEVICE_1001: return "DEVICE_1001";
        case PciDevice10A9::DEVICE_1002: return "DEVICE_1002";
        case PciDevice10A9::DEVICE_1003: return "DEVICE_1003";
        case PciDevice10A9::DEVICE_1004: return "DEVICE_1004";
        case PciDevice10A9::DEVICE_1005: return "DEVICE_1005";
        case PciDevice10A9::DEVICE_1006: return "DEVICE_1006";
        case PciDevice10A9::DEVICE_1007: return "DEVICE_1007";
        case PciDevice10A9::DEVICE_1008: return "DEVICE_1008";
        case PciDevice10A9::DEVICE_100A: return "DEVICE_100A";
        case PciDevice10A9::DEVICE_1504: return "DEVICE_1504";
        case PciDevice10A9::DEVICE_2001: return "DEVICE_2001";
        case PciDevice10A9::DEVICE_2002: return "DEVICE_2002";
        case PciDevice10A9::DEVICE_4001: return "DEVICE_4001";
        case PciDevice10A9::DEVICE_4002: return "DEVICE_4002";
        case PciDevice10A9::DEVICE_8001: return "DEVICE_8001";
        case PciDevice10A9::DEVICE_8002: return "DEVICE_8002";
        case PciDevice10A9::DEVICE_802B: return "DEVICE_802B";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice10A9 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice10A9 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice10A9::DEVICE_0001: return "Crosstalk to PCI Bridge";
        case PciDevice10A9::DEVICE_0002: return "Linc I/O controller";
        case PciDevice10A9::DEVICE_0003: return "IOC3 I/O controller";
        case PciDevice10A9::DEVICE_0004: return "O2 MACE";
        case PciDevice10A9::DEVICE_0005: return "RAD Audio";
        case PciDevice10A9::DEVICE_0006: return "HPCEX";
        case PciDevice10A9::DEVICE_0007: return "RPCEX";
        case PciDevice10A9::DEVICE_0008: return "DiVO VIP";
        case PciDevice10A9::DEVICE_0009: return "AceNIC Gigabit Ethernet";
        case PciDevice10A9::DEVICE_0010: return "AMP Video I/O";
        case PciDevice10A9::DEVICE_0011: return "GRIP";
        case PciDevice10A9::DEVICE_0012: return "SGH PSHAC GSN";
        case PciDevice10A9::DEVICE_0208: return "SSIM1 SAS Adapter";
        case PciDevice10A9::DEVICE_1001: return "Magic Carpet";
        case PciDevice10A9::DEVICE_1002: return "Lithium";
        case PciDevice10A9::DEVICE_1003: return "Dual JPEG 1";
        case PciDevice10A9::DEVICE_1004: return "Dual JPEG 2";
        case PciDevice10A9::DEVICE_1005: return "Dual JPEG 3";
        case PciDevice10A9::DEVICE_1006: return "Dual JPEG 4";
        case PciDevice10A9::DEVICE_1007: return "Dual JPEG 5";
        case PciDevice10A9::DEVICE_1008: return "Cesium";
        case PciDevice10A9::DEVICE_100A: return "IOC4 I/O controller";
        case PciDevice10A9::DEVICE_1504: return "SSIM1 Fibre Channel Adapter";
        case PciDevice10A9::DEVICE_2001: return "Fibre Channel";
        case PciDevice10A9::DEVICE_2002: return "ASDE";
        case PciDevice10A9::DEVICE_4001: return "TIO-CE PCI Express Bridge";
        case PciDevice10A9::DEVICE_4002: return "TIO-CE PCI Express Port";
        case PciDevice10A9::DEVICE_8001: return "O2 1394";
        case PciDevice10A9::DEVICE_8002: return "G-net NT";
        case PciDevice10A9::DEVICE_802B: return "REACT external interrupt controller";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice10A9 device, bad_uint16 subsystemVendorID, bad_uint16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice10A9::DEVICE_0001: return "Unknown device";
        case PciDevice10A9::DEVICE_0002: return "Unknown device";
        case PciDevice10A9::DEVICE_0003: return "Unknown device";
        case PciDevice10A9::DEVICE_0004: return "Unknown device";
        case PciDevice10A9::DEVICE_0005: return "Unknown device";
        case PciDevice10A9::DEVICE_0006: return "Unknown device";
        case PciDevice10A9::DEVICE_0007: return "Unknown device";
        case PciDevice10A9::DEVICE_0008: return "Unknown device";
        case PciDevice10A9::DEVICE_0009: return enumToHumanString((PciSubDevice10A90009)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice10A9::DEVICE_0010: return "Unknown device";
        case PciDevice10A9::DEVICE_0011: return "Unknown device";
        case PciDevice10A9::DEVICE_0012: return "Unknown device";
        case PciDevice10A9::DEVICE_0208: return "Unknown device";
        case PciDevice10A9::DEVICE_1001: return "Unknown device";
        case PciDevice10A9::DEVICE_1002: return "Unknown device";
        case PciDevice10A9::DEVICE_1003: return "Unknown device";
        case PciDevice10A9::DEVICE_1004: return "Unknown device";
        case PciDevice10A9::DEVICE_1005: return "Unknown device";
        case PciDevice10A9::DEVICE_1006: return "Unknown device";
        case PciDevice10A9::DEVICE_1007: return "Unknown device";
        case PciDevice10A9::DEVICE_1008: return "Unknown device";
        case PciDevice10A9::DEVICE_100A: return "Unknown device";
        case PciDevice10A9::DEVICE_1504: return "Unknown device";
        case PciDevice10A9::DEVICE_2001: return "Unknown device";
        case PciDevice10A9::DEVICE_2002: return "Unknown device";
        case PciDevice10A9::DEVICE_4001: return "Unknown device";
        case PciDevice10A9::DEVICE_4002: return "Unknown device";
        case PciDevice10A9::DEVICE_8001: return "Unknown device";
        case PciDevice10A9::DEVICE_8002: return "Unknown device";
        case PciDevice10A9::DEVICE_802B: return "Unknown device";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10A9_PCIDEVICE10A9_H
