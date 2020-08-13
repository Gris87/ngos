// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1223_PCIDEVICE1223_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1223_PCIDEVICE1223_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1223: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0003 = 0x0003,
    DEVICE_0004 = 0x0004,
    DEVICE_0005 = 0x0005,
    DEVICE_0008 = 0x0008,
    DEVICE_0009 = 0x0009,
    DEVICE_000A = 0x000A,
    DEVICE_000B = 0x000B,
    DEVICE_000C = 0x000C,
    DEVICE_000D = 0x000D,
    DEVICE_000E = 0x000E
};



inline const char8* enumToString(PciDevice1223 device1223) // TEST: NO
{
    // COMMON_LT((" | device1223 = %u", device1223)); // Commented to avoid bad looking logs



    switch (device1223)
    {
        case PciDevice1223::NONE:        return "NONE";
        case PciDevice1223::DEVICE_0003: return "DEVICE_0003";
        case PciDevice1223::DEVICE_0004: return "DEVICE_0004";
        case PciDevice1223::DEVICE_0005: return "DEVICE_0005";
        case PciDevice1223::DEVICE_0008: return "DEVICE_0008";
        case PciDevice1223::DEVICE_0009: return "DEVICE_0009";
        case PciDevice1223::DEVICE_000A: return "DEVICE_000A";
        case PciDevice1223::DEVICE_000B: return "DEVICE_000B";
        case PciDevice1223::DEVICE_000C: return "DEVICE_000C";
        case PciDevice1223::DEVICE_000D: return "DEVICE_000D";
        case PciDevice1223::DEVICE_000E: return "DEVICE_000E";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1223 device1223) // TEST: NO
{
    // COMMON_LT((" | device1223 = %u", device1223)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1223, enumToString(device1223));

    return res;
}



inline const char8* enumToHumanString(PciDevice1223 device1223) // TEST: NO
{
    // COMMON_LT((" | device1223 = %u", device1223)); // Commented to avoid bad looking logs



    switch (device1223)
    {
        case PciDevice1223::DEVICE_0003: return "PM/Link";
        case PciDevice1223::DEVICE_0004: return "PM/T1";
        case PciDevice1223::DEVICE_0005: return "PM/E1";
        case PciDevice1223::DEVICE_0008: return "PM/SLS";
        case PciDevice1223::DEVICE_0009: return "BajaSpan Resource Target";
        case PciDevice1223::DEVICE_000A: return "BajaSpan Section 0";
        case PciDevice1223::DEVICE_000B: return "BajaSpan Section 1";
        case PciDevice1223::DEVICE_000C: return "BajaSpan Section 2";
        case PciDevice1223::DEVICE_000D: return "BajaSpan Section 3";
        case PciDevice1223::DEVICE_000E: return "PM/PPC";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1223_PCIDEVICE1223_H
