// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1134_PCIDEVICE1134_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1134_PCIDEVICE1134_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1134: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001,
    DEVICE_0002 = 0x0002,
    DEVICE_000B = 0x000B,
    DEVICE_000D = 0x000D
};



inline const char8* enumToString(PciDevice1134 device1134) // TEST: NO
{
    // COMMON_LT((" | device1134 = %u", device1134)); // Commented to avoid bad looking logs



    switch (device1134)
    {
        case PciDevice1134::NONE:        return "NONE";
        case PciDevice1134::DEVICE_0001: return "DEVICE_0001";
        case PciDevice1134::DEVICE_0002: return "DEVICE_0002";
        case PciDevice1134::DEVICE_000B: return "DEVICE_000B";
        case PciDevice1134::DEVICE_000D: return "DEVICE_000D";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1134 device1134) // TEST: NO
{
    // COMMON_LT((" | device1134 = %u", device1134)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1134, enumToString(device1134));

    return res;
}



inline const char8* enumToHumanString(PciDevice1134 device1134) // TEST: NO
{
    // COMMON_LT((" | device1134 = %u", device1134)); // Commented to avoid bad looking logs



    switch (device1134)
    {
        case PciDevice1134::DEVICE_0001: return "Raceway Bridge";
        case PciDevice1134::DEVICE_0002: return "Dual PCI to RapidIO Bridge";
        case PciDevice1134::DEVICE_000B: return "POET Serial RapidIO Bridge";
        case PciDevice1134::DEVICE_000D: return "POET PSDMS Device";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1134_PCIDEVICE1134_H
