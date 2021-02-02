// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14DC_PCIDEVICE14DC_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14DC_PCIDEVICE14DC_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice14DC: bad_uint16 // Ignore CppEnumVerifier
{
    DEVICE_0000 = 0x0000,
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
    DEVICE_000B = 0x000B
};



inline const char8* enumToString(PciDevice14DC device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice14DC::DEVICE_0000: return "DEVICE_0000";
        case PciDevice14DC::DEVICE_0001: return "DEVICE_0001";
        case PciDevice14DC::DEVICE_0002: return "DEVICE_0002";
        case PciDevice14DC::DEVICE_0003: return "DEVICE_0003";
        case PciDevice14DC::DEVICE_0004: return "DEVICE_0004";
        case PciDevice14DC::DEVICE_0005: return "DEVICE_0005";
        case PciDevice14DC::DEVICE_0006: return "DEVICE_0006";
        case PciDevice14DC::DEVICE_0007: return "DEVICE_0007";
        case PciDevice14DC::DEVICE_0008: return "DEVICE_0008";
        case PciDevice14DC::DEVICE_0009: return "DEVICE_0009";
        case PciDevice14DC::DEVICE_000A: return "DEVICE_000A";
        case PciDevice14DC::DEVICE_000B: return "DEVICE_000B";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice14DC device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice14DC device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice14DC::DEVICE_0000: return "PCI230";
        case PciDevice14DC::DEVICE_0001: return "PCI242";
        case PciDevice14DC::DEVICE_0002: return "PCI244";
        case PciDevice14DC::DEVICE_0003: return "PCI247";
        case PciDevice14DC::DEVICE_0004: return "PCI248";
        case PciDevice14DC::DEVICE_0005: return "PCI249";
        case PciDevice14DC::DEVICE_0006: return "PCI260";
        case PciDevice14DC::DEVICE_0007: return "PCI224";
        case PciDevice14DC::DEVICE_0008: return "PCI234";
        case PciDevice14DC::DEVICE_0009: return "PCI236";
        case PciDevice14DC::DEVICE_000A: return "PCI272";
        case PciDevice14DC::DEVICE_000B: return "PCI215";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14DC_PCIDEVICE14DC_H
