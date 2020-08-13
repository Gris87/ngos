// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR115D_PCIDEVICE115D_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR115D_PCIDEVICE115D_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice115D: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0003 = 0x0003,
    DEVICE_0005 = 0x0005,
    DEVICE_0007 = 0x0007,
    DEVICE_000B = 0x000B,
    DEVICE_000C = 0x000C,
    DEVICE_000F = 0x000F,
    DEVICE_00D4 = 0x00D4,
    DEVICE_0101 = 0x0101,
    DEVICE_0103 = 0x0103
};



inline const char8* enumToString(PciDevice115D device115D) // TEST: NO
{
    // COMMON_LT((" | device115D = %u", device115D)); // Commented to avoid bad looking logs



    switch (device115D)
    {
        case PciDevice115D::NONE:        return "NONE";
        case PciDevice115D::DEVICE_0003: return "DEVICE_0003";
        case PciDevice115D::DEVICE_0005: return "DEVICE_0005";
        case PciDevice115D::DEVICE_0007: return "DEVICE_0007";
        case PciDevice115D::DEVICE_000B: return "DEVICE_000B";
        case PciDevice115D::DEVICE_000C: return "DEVICE_000C";
        case PciDevice115D::DEVICE_000F: return "DEVICE_000F";
        case PciDevice115D::DEVICE_00D4: return "DEVICE_00D4";
        case PciDevice115D::DEVICE_0101: return "DEVICE_0101";
        case PciDevice115D::DEVICE_0103: return "DEVICE_0103";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice115D device115D) // TEST: NO
{
    // COMMON_LT((" | device115D = %u", device115D)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device115D, enumToString(device115D));

    return res;
}



inline const char8* enumToHumanString(PciDevice115D device115D) // TEST: NO
{
    // COMMON_LT((" | device115D = %u", device115D)); // Commented to avoid bad looking logs



    switch (device115D)
    {
        case PciDevice115D::DEVICE_0003: return "Cardbus Ethernet 10/100";
        case PciDevice115D::DEVICE_0005: return "Cardbus Ethernet 10/100";
        case PciDevice115D::DEVICE_0007: return "Cardbus Ethernet 10/100";
        case PciDevice115D::DEVICE_000B: return "Cardbus Ethernet 10/100";
        case PciDevice115D::DEVICE_000C: return "Mini-PCI V.90 56k Modem";
        case PciDevice115D::DEVICE_000F: return "Cardbus Ethernet 10/100";
        case PciDevice115D::DEVICE_00D4: return "Mini-PCI K56Flex Modem";
        case PciDevice115D::DEVICE_0101: return "Cardbus 56k modem";
        case PciDevice115D::DEVICE_0103: return "Cardbus Ethernet + 56k Modem";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR115D_PCIDEVICE115D_H
