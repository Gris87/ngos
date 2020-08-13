// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1B1A_PCIDEVICE1B1A_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1B1A_PCIDEVICE1B1A_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1B1A: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0E70 = 0x0E70
};



inline const char8* enumToString(PciDevice1B1A device1B1A) // TEST: NO
{
    // COMMON_LT((" | device1B1A = %u", device1B1A)); // Commented to avoid bad looking logs



    switch (device1B1A)
    {
        case PciDevice1B1A::NONE:        return "NONE";
        case PciDevice1B1A::DEVICE_0E70: return "DEVICE_0E70";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1B1A device1B1A) // TEST: NO
{
    // COMMON_LT((" | device1B1A = %u", device1B1A)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1B1A, enumToString(device1B1A));

    return res;
}



inline const char8* enumToHumanString(PciDevice1B1A device1B1A) // TEST: NO
{
    // COMMON_LT((" | device1B1A = %u", device1B1A)); // Commented to avoid bad looking logs



    switch (device1B1A)
    {
        case PciDevice1B1A::DEVICE_0E70: return "GRAPE";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1B1A_PCIDEVICE1B1A_H
