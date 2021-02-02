// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1912_PCIDEVICE1912_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1912_PCIDEVICE1912_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1912: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0002 = 0x0002,
    DEVICE_0011 = 0x0011,
    DEVICE_0012 = 0x0012,
    DEVICE_0013 = 0x0013,
    DEVICE_0014 = 0x0014,
    DEVICE_0015 = 0x0015,
    DEVICE_001A = 0x001A,
    DEVICE_001B = 0x001B,
    DEVICE_001D = 0x001D
};



inline const char8* enumToString(PciDevice1912 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1912::NONE:        return "NONE";
        case PciDevice1912::DEVICE_0002: return "DEVICE_0002";
        case PciDevice1912::DEVICE_0011: return "DEVICE_0011";
        case PciDevice1912::DEVICE_0012: return "DEVICE_0012";
        case PciDevice1912::DEVICE_0013: return "DEVICE_0013";
        case PciDevice1912::DEVICE_0014: return "DEVICE_0014";
        case PciDevice1912::DEVICE_0015: return "DEVICE_0015";
        case PciDevice1912::DEVICE_001A: return "DEVICE_001A";
        case PciDevice1912::DEVICE_001B: return "DEVICE_001B";
        case PciDevice1912::DEVICE_001D: return "DEVICE_001D";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1912 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1912 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1912::DEVICE_0002: return "SH7780 PCI Controller (PCIC)";
        case PciDevice1912::DEVICE_0011: return "SH7757 PCIe End-Point [PBI]";
        case PciDevice1912::DEVICE_0012: return "SH7757 PCIe-PCI Bridge [PPB]";
        case PciDevice1912::DEVICE_0013: return "SH7757 PCIe Switch [PS]";
        case PciDevice1912::DEVICE_0014: return "uPD720201 USB 3.0 Host Controller";
        case PciDevice1912::DEVICE_0015: return "uPD720202 USB 3.0 Host Controller";
        case PciDevice1912::DEVICE_001A: return "SH7758 PCIe-PCI Bridge [PPB]";
        case PciDevice1912::DEVICE_001B: return "SH7758 PCIe End-Point [PBI]";
        case PciDevice1912::DEVICE_001D: return "SH7758 PCIe Switch [PS]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1912_PCIDEVICE1912_H
