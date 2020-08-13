// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1C1F_PCIDEVICE1C1F_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1C1F_PCIDEVICE1C1F_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1C1F: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0015 = 0x0015,
    DEVICE_0019 = 0x0019,
    DEVICE_001A = 0x001A,
    DEVICE_001B = 0x001B,
    DEVICE_001C = 0x001C,
    DEVICE_001D = 0x001D
};



inline const char8* enumToString(PciDevice1C1F device1C1F) // TEST: NO
{
    // COMMON_LT((" | device1C1F = %u", device1C1F)); // Commented to avoid bad looking logs



    switch (device1C1F)
    {
        case PciDevice1C1F::NONE:        return "NONE";
        case PciDevice1C1F::DEVICE_0015: return "DEVICE_0015";
        case PciDevice1C1F::DEVICE_0019: return "DEVICE_0019";
        case PciDevice1C1F::DEVICE_001A: return "DEVICE_001A";
        case PciDevice1C1F::DEVICE_001B: return "DEVICE_001B";
        case PciDevice1C1F::DEVICE_001C: return "DEVICE_001C";
        case PciDevice1C1F::DEVICE_001D: return "DEVICE_001D";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1C1F device1C1F) // TEST: NO
{
    // COMMON_LT((" | device1C1F = %u", device1C1F)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1C1F, enumToString(device1C1F));

    return res;
}



inline const char8* enumToHumanString(PciDevice1C1F device1C1F) // TEST: NO
{
    // COMMON_LT((" | device1C1F = %u", device1C1F)); // Commented to avoid bad looking logs



    switch (device1C1F)
    {
        case PciDevice1C1F::DEVICE_0015: return "FD842";
        case PciDevice1C1F::DEVICE_0019: return "FD722";
        case PciDevice1C1F::DEVICE_001A: return "FD788";
        case PciDevice1C1F::DEVICE_001B: return "FD720";
        case PciDevice1C1F::DEVICE_001C: return "FD922";
        case PciDevice1C1F::DEVICE_001D: return "Vega";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1C1F_PCIDEVICE1C1F_H
