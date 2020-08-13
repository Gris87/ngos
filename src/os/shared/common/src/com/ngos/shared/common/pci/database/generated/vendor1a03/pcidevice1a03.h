// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1A03_PCIDEVICE1A03_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1A03_PCIDEVICE1A03_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1A03: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1150 = 0x1150,
    DEVICE_2000 = 0x2000
};



inline const char8* enumToString(PciDevice1A03 device1A03) // TEST: NO
{
    // COMMON_LT((" | device1A03 = %u", device1A03)); // Commented to avoid bad looking logs



    switch (device1A03)
    {
        case PciDevice1A03::NONE:        return "NONE";
        case PciDevice1A03::DEVICE_1150: return "DEVICE_1150";
        case PciDevice1A03::DEVICE_2000: return "DEVICE_2000";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1A03 device1A03) // TEST: NO
{
    // COMMON_LT((" | device1A03 = %u", device1A03)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1A03, enumToString(device1A03));

    return res;
}



inline const char8* enumToHumanString(PciDevice1A03 device1A03) // TEST: NO
{
    // COMMON_LT((" | device1A03 = %u", device1A03)); // Commented to avoid bad looking logs



    switch (device1A03)
    {
        case PciDevice1A03::DEVICE_1150: return "AST1150 PCI-to-PCI Bridge";
        case PciDevice1A03::DEVICE_2000: return "ASPEED Graphics Family";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1A03_PCIDEVICE1A03_H
