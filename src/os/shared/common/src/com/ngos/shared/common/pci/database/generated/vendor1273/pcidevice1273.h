// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1273_PCIDEVICE1273_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1273_PCIDEVICE1273_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1273: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0002 = 0x0002
};



inline const char8* enumToString(PciDevice1273 device1273) // TEST: NO
{
    // COMMON_LT((" | device1273 = %u", device1273)); // Commented to avoid bad looking logs



    switch (device1273)
    {
        case PciDevice1273::NONE:        return "NONE";
        case PciDevice1273::DEVICE_0002: return "DEVICE_0002";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1273 device1273) // TEST: NO
{
    // COMMON_LT((" | device1273 = %u", device1273)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1273, enumToString(device1273));

    return res;
}



inline const char8* enumToHumanString(PciDevice1273 device1273) // TEST: NO
{
    // COMMON_LT((" | device1273 = %u", device1273)); // Commented to avoid bad looking logs



    switch (device1273)
    {
        case PciDevice1273::DEVICE_0002: return "DirecPC";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1273_PCIDEVICE1273_H