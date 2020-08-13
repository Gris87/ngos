// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1CE4_PCIDEVICE1CE4_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1CE4_PCIDEVICE1CE4_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1CE4: u16 // Ignore CppEnumVerifier
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
    DEVICE_0100 = 0x0100
};



inline const char8* enumToString(PciDevice1CE4 device1CE4) // TEST: NO
{
    // COMMON_LT((" | device1CE4 = %u", device1CE4)); // Commented to avoid bad looking logs



    switch (device1CE4)
    {
        case PciDevice1CE4::NONE:        return "NONE";
        case PciDevice1CE4::DEVICE_0001: return "DEVICE_0001";
        case PciDevice1CE4::DEVICE_0002: return "DEVICE_0002";
        case PciDevice1CE4::DEVICE_0003: return "DEVICE_0003";
        case PciDevice1CE4::DEVICE_0004: return "DEVICE_0004";
        case PciDevice1CE4::DEVICE_0005: return "DEVICE_0005";
        case PciDevice1CE4::DEVICE_0006: return "DEVICE_0006";
        case PciDevice1CE4::DEVICE_0007: return "DEVICE_0007";
        case PciDevice1CE4::DEVICE_0008: return "DEVICE_0008";
        case PciDevice1CE4::DEVICE_0009: return "DEVICE_0009";
        case PciDevice1CE4::DEVICE_000A: return "DEVICE_000A";
        case PciDevice1CE4::DEVICE_000B: return "DEVICE_000B";
        case PciDevice1CE4::DEVICE_0100: return "DEVICE_0100";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1CE4 device1CE4) // TEST: NO
{
    // COMMON_LT((" | device1CE4 = %u", device1CE4)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1CE4, enumToString(device1CE4));

    return res;
}



inline const char8* enumToHumanString(PciDevice1CE4 device1CE4) // TEST: NO
{
    // COMMON_LT((" | device1CE4 = %u", device1CE4)); // Commented to avoid bad looking logs



    switch (device1CE4)
    {
        case PciDevice1CE4::DEVICE_0001: return "ExaNIC X4";
        case PciDevice1CE4::DEVICE_0002: return "ExaNIC X2";
        case PciDevice1CE4::DEVICE_0003: return "ExaNIC X10";
        case PciDevice1CE4::DEVICE_0004: return "ExaNIC X10-GM";
        case PciDevice1CE4::DEVICE_0005: return "ExaNIC X40";
        case PciDevice1CE4::DEVICE_0006: return "ExaNIC X10-HPT";
        case PciDevice1CE4::DEVICE_0007: return "ExaNIC X40";
        case PciDevice1CE4::DEVICE_0008: return "ExaNIC V5P";
        case PciDevice1CE4::DEVICE_0009: return "ExaNIC X25";
        case PciDevice1CE4::DEVICE_000A: return "ExaNIC X100";
        case PciDevice1CE4::DEVICE_000B: return "ExaNIC V9P";
        case PciDevice1CE4::DEVICE_0100: return "ExaDISK FX1";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1CE4_PCIDEVICE1CE4_H
