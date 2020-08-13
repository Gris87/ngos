// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1066_PCIDEVICE1066_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1066_PCIDEVICE1066_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1066: u16 // Ignore CppEnumVerifier
{
    DEVICE_0000 = 0x0000,
    DEVICE_0001 = 0x0001,
    DEVICE_0002 = 0x0002,
    DEVICE_0003 = 0x0003,
    DEVICE_0004 = 0x0004,
    DEVICE_0005 = 0x0005,
    DEVICE_8002 = 0x8002
};



inline const char8* enumToString(PciDevice1066 device1066) // TEST: NO
{
    // COMMON_LT((" | device1066 = %u", device1066)); // Commented to avoid bad looking logs



    switch (device1066)
    {
        case PciDevice1066::DEVICE_0000: return "DEVICE_0000";
        case PciDevice1066::DEVICE_0001: return "DEVICE_0001";
        case PciDevice1066::DEVICE_0002: return "DEVICE_0002";
        case PciDevice1066::DEVICE_0003: return "DEVICE_0003";
        case PciDevice1066::DEVICE_0004: return "DEVICE_0004";
        case PciDevice1066::DEVICE_0005: return "DEVICE_0005";
        case PciDevice1066::DEVICE_8002: return "DEVICE_8002";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1066 device1066) // TEST: NO
{
    // COMMON_LT((" | device1066 = %u", device1066)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1066, enumToString(device1066));

    return res;
}



inline const char8* enumToHumanString(PciDevice1066 device1066) // TEST: NO
{
    // COMMON_LT((" | device1066 = %u", device1066)); // Commented to avoid bad looking logs



    switch (device1066)
    {
        case PciDevice1066::DEVICE_0000: return "PT80C826";
        case PciDevice1066::DEVICE_0001: return "PT86C521 [Vesuvius v1] Host Bridge";
        case PciDevice1066::DEVICE_0002: return "PT86C523 [Vesuvius v3] PCI-ISA Bridge Master";
        case PciDevice1066::DEVICE_0003: return "PT86C524 [Nile] PCI-to-PCI Bridge";
        case PciDevice1066::DEVICE_0004: return "PT86C525 [Nile-II] PCI-to-PCI Bridge";
        case PciDevice1066::DEVICE_0005: return "National PC87550 System Controller";
        case PciDevice1066::DEVICE_8002: return "PT86C523 [Vesuvius v3] PCI-ISA Bridge Slave";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1066_PCIDEVICE1066_H
