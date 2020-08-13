// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1CB5_PCIDEVICE1CB5_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1CB5_PCIDEVICE1CB5_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1CB5: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0002 = 0x0002
};



inline const char8* enumToString(PciDevice1CB5 device1CB5) // TEST: NO
{
    // COMMON_LT((" | device1CB5 = %u", device1CB5)); // Commented to avoid bad looking logs



    switch (device1CB5)
    {
        case PciDevice1CB5::NONE:        return "NONE";
        case PciDevice1CB5::DEVICE_0002: return "DEVICE_0002";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1CB5 device1CB5) // TEST: NO
{
    // COMMON_LT((" | device1CB5 = %u", device1CB5)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1CB5, enumToString(device1CB5));

    return res;
}



inline const char8* enumToHumanString(PciDevice1CB5 device1CB5) // TEST: NO
{
    // COMMON_LT((" | device1CB5 = %u", device1CB5)); // Commented to avoid bad looking logs



    switch (device1CB5)
    {
        case PciDevice1CB5::DEVICE_0002: return "Clarett";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1CB5_PCIDEVICE1CB5_H
