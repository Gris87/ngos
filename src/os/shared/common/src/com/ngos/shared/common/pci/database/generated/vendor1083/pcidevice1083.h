// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1083_PCIDEVICE1083_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1083_PCIDEVICE1083_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1083: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001
};



inline const char8* enumToString(PciDevice1083 device1083) // TEST: NO
{
    // COMMON_LT((" | device1083 = %u", device1083)); // Commented to avoid bad looking logs



    switch (device1083)
    {
        case PciDevice1083::NONE:        return "NONE";
        case PciDevice1083::DEVICE_0001: return "DEVICE_0001";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1083 device1083) // TEST: NO
{
    // COMMON_LT((" | device1083 = %u", device1083)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1083, enumToString(device1083));

    return res;
}



inline const char8* enumToHumanString(PciDevice1083 device1083) // TEST: NO
{
    // COMMON_LT((" | device1083 = %u", device1083)); // Commented to avoid bad looking logs



    switch (device1083)
    {
        case PciDevice1083::DEVICE_0001: return "FR710";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1083_PCIDEVICE1083_H