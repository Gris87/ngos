// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1DEF_PCIDEVICE1DEF_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1DEF_PCIDEVICE1DEF_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1DEF: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_E005 = 0xE005,
    DEVICE_E006 = 0xE006,
    DEVICE_E007 = 0xE007,
    DEVICE_E008 = 0xE008,
    DEVICE_E009 = 0xE009,
    DEVICE_E00A = 0xE00A,
    DEVICE_E00B = 0xE00B,
    DEVICE_E00C = 0xE00C
};



inline const char8* enumToString(PciDevice1DEF device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1DEF::NONE:        return "NONE";
        case PciDevice1DEF::DEVICE_E005: return "DEVICE_E005";
        case PciDevice1DEF::DEVICE_E006: return "DEVICE_E006";
        case PciDevice1DEF::DEVICE_E007: return "DEVICE_E007";
        case PciDevice1DEF::DEVICE_E008: return "DEVICE_E008";
        case PciDevice1DEF::DEVICE_E009: return "DEVICE_E009";
        case PciDevice1DEF::DEVICE_E00A: return "DEVICE_E00A";
        case PciDevice1DEF::DEVICE_E00B: return "DEVICE_E00B";
        case PciDevice1DEF::DEVICE_E00C: return "DEVICE_E00C";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1DEF device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1DEF device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1DEF::DEVICE_E005: return "eMAG PCI Express Root Port 0";
        case PciDevice1DEF::DEVICE_E006: return "eMAG PCI Express Root Port 1";
        case PciDevice1DEF::DEVICE_E007: return "eMAG PCI Express Root Port 2";
        case PciDevice1DEF::DEVICE_E008: return "eMAG PCI Express Root Port 3";
        case PciDevice1DEF::DEVICE_E009: return "eMAG PCI Express Root Port 4";
        case PciDevice1DEF::DEVICE_E00A: return "eMAG PCI Express Root Port 5";
        case PciDevice1DEF::DEVICE_E00B: return "eMAG PCI Express Root Port 6";
        case PciDevice1DEF::DEVICE_E00C: return "eMAG PCI Express Root Port 7";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1DEF_PCIDEVICE1DEF_H
