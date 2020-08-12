// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR18F7_PCIDEVICE18F7_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR18F7_PCIDEVICE18F7_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice18F7: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001,
    DEVICE_0002 = 0x0002,
    DEVICE_0003 = 0x0003,
    DEVICE_0004 = 0x0004,
    DEVICE_0005 = 0x0005,
    DEVICE_000A = 0x000A,
    DEVICE_000B = 0x000B,
    DEVICE_000F = 0x000F,
    DEVICE_0010 = 0x0010,
    DEVICE_0011 = 0x0011,
    DEVICE_0014 = 0x0014,
    DEVICE_0015 = 0x0015,
    DEVICE_0016 = 0x0016,
    DEVICE_0017 = 0x0017,
    DEVICE_0018 = 0x0018,
    DEVICE_0019 = 0x0019,
    DEVICE_001A = 0x001A,
    DEVICE_001B = 0x001B,
    DEVICE_001C = 0x001C,
    DEVICE_001D = 0x001D,
    DEVICE_001E = 0x001E,
    DEVICE_001F = 0x001F,
    DEVICE_0020 = 0x0020,
    DEVICE_0021 = 0x0021,
    DEVICE_0022 = 0x0022,
    DEVICE_0023 = 0x0023,
    DEVICE_0025 = 0x0025,
    DEVICE_0026 = 0x0026,
    DEVICE_0027 = 0x0027
};



inline const char8* enumToString(PciDevice18F7 device18F7) // TEST: NO
{
    // COMMON_LT((" | device18F7 = %u", device18F7)); // Commented to avoid bad looking logs



    switch (device18F7)
    {
        case PciDevice18F7::NONE:        return "NONE";
        case PciDevice18F7::DEVICE_0001: return "DEVICE_0001";
        case PciDevice18F7::DEVICE_0002: return "DEVICE_0002";
        case PciDevice18F7::DEVICE_0003: return "DEVICE_0003";
        case PciDevice18F7::DEVICE_0004: return "DEVICE_0004";
        case PciDevice18F7::DEVICE_0005: return "DEVICE_0005";
        case PciDevice18F7::DEVICE_000A: return "DEVICE_000A";
        case PciDevice18F7::DEVICE_000B: return "DEVICE_000B";
        case PciDevice18F7::DEVICE_000F: return "DEVICE_000F";
        case PciDevice18F7::DEVICE_0010: return "DEVICE_0010";
        case PciDevice18F7::DEVICE_0011: return "DEVICE_0011";
        case PciDevice18F7::DEVICE_0014: return "DEVICE_0014";
        case PciDevice18F7::DEVICE_0015: return "DEVICE_0015";
        case PciDevice18F7::DEVICE_0016: return "DEVICE_0016";
        case PciDevice18F7::DEVICE_0017: return "DEVICE_0017";
        case PciDevice18F7::DEVICE_0018: return "DEVICE_0018";
        case PciDevice18F7::DEVICE_0019: return "DEVICE_0019";
        case PciDevice18F7::DEVICE_001A: return "DEVICE_001A";
        case PciDevice18F7::DEVICE_001B: return "DEVICE_001B";
        case PciDevice18F7::DEVICE_001C: return "DEVICE_001C";
        case PciDevice18F7::DEVICE_001D: return "DEVICE_001D";
        case PciDevice18F7::DEVICE_001E: return "DEVICE_001E";
        case PciDevice18F7::DEVICE_001F: return "DEVICE_001F";
        case PciDevice18F7::DEVICE_0020: return "DEVICE_0020";
        case PciDevice18F7::DEVICE_0021: return "DEVICE_0021";
        case PciDevice18F7::DEVICE_0022: return "DEVICE_0022";
        case PciDevice18F7::DEVICE_0023: return "DEVICE_0023";
        case PciDevice18F7::DEVICE_0025: return "DEVICE_0025";
        case PciDevice18F7::DEVICE_0026: return "DEVICE_0026";
        case PciDevice18F7::DEVICE_0027: return "DEVICE_0027";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice18F7 device18F7) // TEST: NO
{
    // COMMON_LT((" | device18F7 = %u", device18F7)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device18F7, enumToString(device18F7));

    return res;
}



inline const char8* enumToHumanString(PciDevice18F7 device18F7) // TEST: NO
{
    // COMMON_LT((" | device18F7 = %u", device18F7)); // Commented to avoid bad looking logs



    switch (device18F7)
    {
        case PciDevice18F7::DEVICE_0001: return "ESCC-PCI-335 Serial PCI Adapter [Fastcom]";
        case PciDevice18F7::DEVICE_0002: return "422/4-PCI-335 Serial PCI Adapter [Fastcom]";
        case PciDevice18F7::DEVICE_0003: return "232/4-1M-PCI Serial PCI Adapter [Fastcom]";
        case PciDevice18F7::DEVICE_0004: return "422/2-PCI-335 Serial PCI Adapter [Fastcom]";
        case PciDevice18F7::DEVICE_0005: return "IGESCC-PCI-ISO/1 Serial PCI Adapter [Fastcom]";
        case PciDevice18F7::DEVICE_000A: return "232/4-PCI-335 Serial PCI Adapter [Fastcom]";
        case PciDevice18F7::DEVICE_000B: return "232/8-PCI-335 Serial PCI Adapter [Fastcom]";
        case PciDevice18F7::DEVICE_000F: return "FSCC Serial PCI Adapter [Fastcom]";
        case PciDevice18F7::DEVICE_0010: return "GSCC Serial PCI Adapter [Fastcom]";
        case PciDevice18F7::DEVICE_0011: return "QSSB Serial PCI Adapter [Fastcom]";
        case PciDevice18F7::DEVICE_0014: return "SuperFSCC Serial PCI Adapter [Fastcom]";
        case PciDevice18F7::DEVICE_0015: return "SuperFSCC-104-LVDS Serial PC/104+ Adapter [Fastcom]";
        case PciDevice18F7::DEVICE_0016: return "FSCC-232 RS-232 Serial PCI Adapter [Fastcom]";
        case PciDevice18F7::DEVICE_0017: return "SuperFSCC-104 Serial PC/104+ Adapter [Fastcom]";
        case PciDevice18F7::DEVICE_0018: return "SuperFSCC/4 Serial PCI Adapter [Fastcom]";
        case PciDevice18F7::DEVICE_0019: return "SuperFSCC Serial PCI Adapter [Fastcom]";
        case PciDevice18F7::DEVICE_001A: return "SuperFSCC-LVDS Serial PCI Adapter [Fastcom]";
        case PciDevice18F7::DEVICE_001B: return "FSCC/4 Serial PCI Adapter [Fastcom]";
        case PciDevice18F7::DEVICE_001C: return "SuperFSCC/4-LVDS Serial PCI Adapter [Fastcom]";
        case PciDevice18F7::DEVICE_001D: return "FSCC Serial PCI Adapter [Fastcom]";
        case PciDevice18F7::DEVICE_001E: return "SuperFSCC/4 Serial PCIe Adapter [Fastcom]";
        case PciDevice18F7::DEVICE_001F: return "SuperFSCC/4 Serial cPCI Adapter [Fastcom]";
        case PciDevice18F7::DEVICE_0020: return "422/4-PCIe Serial PCIe Adapter [Fastcom]";
        case PciDevice18F7::DEVICE_0021: return "422/8-PCIe Serial PCIe Adapter [Fastcom]";
        case PciDevice18F7::DEVICE_0022: return "SuperFSCC/4-LVDS Serial PCIe Adapter [Fastcom]";
        case PciDevice18F7::DEVICE_0023: return "SuperFSCC/4 Serial cPCI Adapter [Fastcom]";
        case PciDevice18F7::DEVICE_0025: return "SuperFSCC/4-LVDS Serial PCI Adapter [Fastcom]";
        case PciDevice18F7::DEVICE_0026: return "SuperFSCC-LVDS Serial PCI Adapter [Fastcom]";
        case PciDevice18F7::DEVICE_0027: return "FSCC/4 Serial PCIe Adapter [Fastcom]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR18F7_PCIDEVICE18F7_H
