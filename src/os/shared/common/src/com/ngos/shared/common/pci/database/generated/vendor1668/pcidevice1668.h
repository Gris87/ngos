// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1668_PCIDEVICE1668_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1668_PCIDEVICE1668_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1668: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0100 = 0x0100
};



inline const char8* enumToString(PciDevice1668 device1668) // TEST: NO
{
    // COMMON_LT((" | device1668 = %u", device1668)); // Commented to avoid bad looking logs



    switch (device1668)
    {
        case PciDevice1668::NONE:        return "NONE";
        case PciDevice1668::DEVICE_0100: return "DEVICE_0100";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1668 device1668) // TEST: NO
{
    // COMMON_LT((" | device1668 = %u", device1668)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1668, enumToString(device1668));

    return res;
}



inline const char8* enumToHumanString(PciDevice1668 device1668) // TEST: NO
{
    // COMMON_LT((" | device1668 = %u", device1668)); // Commented to avoid bad looking logs



    switch (device1668)
    {
        case PciDevice1668::DEVICE_0100: return "Mini-PCI bridge";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1668_PCIDEVICE1668_H
