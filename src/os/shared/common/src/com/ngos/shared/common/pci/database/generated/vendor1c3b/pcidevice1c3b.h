// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1C3B_PCIDEVICE1C3B_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1C3B_PCIDEVICE1C3B_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1C3B: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0200 = 0x0200,
    DEVICE_0300 = 0x0300
};



inline const char8* enumToString(PciDevice1C3B device1C3B) // TEST: NO
{
    // COMMON_LT((" | device1C3B = %u", device1C3B)); // Commented to avoid bad looking logs



    switch (device1C3B)
    {
        case PciDevice1C3B::NONE:        return "NONE";
        case PciDevice1C3B::DEVICE_0200: return "DEVICE_0200";
        case PciDevice1C3B::DEVICE_0300: return "DEVICE_0300";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1C3B device1C3B) // TEST: NO
{
    // COMMON_LT((" | device1C3B = %u", device1C3B)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1C3B, enumToString(device1C3B));

    return res;
}



inline const char8* enumToHumanString(PciDevice1C3B device1C3B) // TEST: NO
{
    // COMMON_LT((" | device1C3B = %u", device1C3B)); // Commented to avoid bad looking logs



    switch (device1C3B)
    {
        case PciDevice1C3B::DEVICE_0200: return "Telas2";
        case PciDevice1C3B::DEVICE_0300: return "Telas 2.V";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1C3B_PCIDEVICE1C3B_H
