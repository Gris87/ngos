// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1C1C_PCIDEVICE1C1C_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1C1C_PCIDEVICE1C1C_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1C1C: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001
};



inline const char8* enumToString(PciDevice1C1C device1C1C) // TEST: NO
{
    // COMMON_LT((" | device1C1C = %u", device1C1C)); // Commented to avoid bad looking logs



    switch (device1C1C)
    {
        case PciDevice1C1C::NONE:        return "NONE";
        case PciDevice1C1C::DEVICE_0001: return "DEVICE_0001";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1C1C device1C1C) // TEST: NO
{
    // COMMON_LT((" | device1C1C = %u", device1C1C)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1C1C, enumToString(device1C1C));

    return res;
}



inline const char8* enumToHumanString(PciDevice1C1C device1C1C) // TEST: NO
{
    // COMMON_LT((" | device1C1C = %u", device1C1C)); // Commented to avoid bad looking logs



    switch (device1C1C)
    {
        case PciDevice1C1C::DEVICE_0001: return "82C101";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1C1C_PCIDEVICE1C1C_H