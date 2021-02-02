// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1B37_PCIDEVICE1B37_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1B37_PCIDEVICE1B37_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1B37: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001,
    DEVICE_0003 = 0x0003,
    DEVICE_0005 = 0x0005,
    DEVICE_000E = 0x000E,
    DEVICE_000F = 0x000F,
    DEVICE_0014 = 0x0014,
    DEVICE_0015 = 0x0015,
    DEVICE_001B = 0x001B,
    DEVICE_001C = 0x001C,
    DEVICE_001E = 0x001E,
    DEVICE_001F = 0x001F,
    DEVICE_0020 = 0x0020,
    DEVICE_0023 = 0x0023,
    DEVICE_0026 = 0x0026,
    DEVICE_2014 = 0x2014,
    DEVICE_2019 = 0x2019
};



inline const char8* enumToString(PciDevice1B37 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1B37::NONE:        return "NONE";
        case PciDevice1B37::DEVICE_0001: return "DEVICE_0001";
        case PciDevice1B37::DEVICE_0003: return "DEVICE_0003";
        case PciDevice1B37::DEVICE_0005: return "DEVICE_0005";
        case PciDevice1B37::DEVICE_000E: return "DEVICE_000E";
        case PciDevice1B37::DEVICE_000F: return "DEVICE_000F";
        case PciDevice1B37::DEVICE_0014: return "DEVICE_0014";
        case PciDevice1B37::DEVICE_0015: return "DEVICE_0015";
        case PciDevice1B37::DEVICE_001B: return "DEVICE_001B";
        case PciDevice1B37::DEVICE_001C: return "DEVICE_001C";
        case PciDevice1B37::DEVICE_001E: return "DEVICE_001E";
        case PciDevice1B37::DEVICE_001F: return "DEVICE_001F";
        case PciDevice1B37::DEVICE_0020: return "DEVICE_0020";
        case PciDevice1B37::DEVICE_0023: return "DEVICE_0023";
        case PciDevice1B37::DEVICE_0026: return "DEVICE_0026";
        case PciDevice1B37::DEVICE_2014: return "DEVICE_2014";
        case PciDevice1B37::DEVICE_2019: return "DEVICE_2019";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1B37 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1B37 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1B37::DEVICE_0001: return "ADQ214";
        case PciDevice1B37::DEVICE_0003: return "ADQ114";
        case PciDevice1B37::DEVICE_0005: return "ADQ112";
        case PciDevice1B37::DEVICE_000E: return "ADQ108";
        case PciDevice1B37::DEVICE_000F: return "ADQDSP";
        case PciDevice1B37::DEVICE_0014: return "ADQ412";
        case PciDevice1B37::DEVICE_0015: return "ADQ212";
        case PciDevice1B37::DEVICE_001B: return "SDR14";
        case PciDevice1B37::DEVICE_001C: return "ADQ1600";
        case PciDevice1B37::DEVICE_001E: return "ADQ208";
        case PciDevice1B37::DEVICE_001F: return "DSU";
        case PciDevice1B37::DEVICE_0020: return "ADQ14";
        case PciDevice1B37::DEVICE_0023: return "ADQ7";
        case PciDevice1B37::DEVICE_0026: return "ADQ8";
        case PciDevice1B37::DEVICE_2014: return "TX320";
        case PciDevice1B37::DEVICE_2019: return "S6000";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1B37_PCIDEVICE1B37_H
