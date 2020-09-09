// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10AA_PCIDEVICE10AA_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10AA_PCIDEVICE10AA_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice10AA: u16 // Ignore CppEnumVerifier
{
    DEVICE_0000 = 0x0000,
    DEVICE_2051 = 0x2051,
    DEVICE_5842 = 0x5842
};



inline const char8* enumToString(PciDevice10AA device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice10AA::DEVICE_0000: return "DEVICE_0000";
        case PciDevice10AA::DEVICE_2051: return "DEVICE_2051";
        case PciDevice10AA::DEVICE_5842: return "DEVICE_5842";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice10AA device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice10AA device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice10AA::DEVICE_0000: return "ACCM 2188";
        case PciDevice10AA::DEVICE_2051: return "2051 CPU bridge";
        case PciDevice10AA::DEVICE_5842: return "2051 ISA bridge";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10AA_PCIDEVICE10AA_H
