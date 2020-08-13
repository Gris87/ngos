// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR121A_PCIDEVICE121A_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR121A_PCIDEVICE121A_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice121A: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001,
    DEVICE_0002 = 0x0002,
    DEVICE_0003 = 0x0003,
    DEVICE_0004 = 0x0004,
    DEVICE_0005 = 0x0005,
    DEVICE_0009 = 0x0009,
    DEVICE_0057 = 0x0057
};



inline const char8* enumToString(PciDevice121A device121A) // TEST: NO
{
    // COMMON_LT((" | device121A = %u", device121A)); // Commented to avoid bad looking logs



    switch (device121A)
    {
        case PciDevice121A::NONE:        return "NONE";
        case PciDevice121A::DEVICE_0001: return "DEVICE_0001";
        case PciDevice121A::DEVICE_0002: return "DEVICE_0002";
        case PciDevice121A::DEVICE_0003: return "DEVICE_0003";
        case PciDevice121A::DEVICE_0004: return "DEVICE_0004";
        case PciDevice121A::DEVICE_0005: return "DEVICE_0005";
        case PciDevice121A::DEVICE_0009: return "DEVICE_0009";
        case PciDevice121A::DEVICE_0057: return "DEVICE_0057";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice121A device121A) // TEST: NO
{
    // COMMON_LT((" | device121A = %u", device121A)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device121A, enumToString(device121A));

    return res;
}



inline const char8* enumToHumanString(PciDevice121A device121A) // TEST: NO
{
    // COMMON_LT((" | device121A = %u", device121A)); // Commented to avoid bad looking logs



    switch (device121A)
    {
        case PciDevice121A::DEVICE_0001: return "Voodoo";
        case PciDevice121A::DEVICE_0002: return "Voodoo 2";
        case PciDevice121A::DEVICE_0003: return "Voodoo Banshee";
        case PciDevice121A::DEVICE_0004: return "Voodoo Banshee [Velocity 100]";
        case PciDevice121A::DEVICE_0005: return "Voodoo 3";
        case PciDevice121A::DEVICE_0009: return "Voodoo 4 / Voodoo 5";
        case PciDevice121A::DEVICE_0057: return "Voodoo 3/3000 [Avenger]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR121A_PCIDEVICE121A_H
