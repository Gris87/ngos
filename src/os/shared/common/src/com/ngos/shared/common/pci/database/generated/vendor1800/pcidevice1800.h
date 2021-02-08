// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1800_PCIDEVICE1800_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1800_PCIDEVICE1800_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1800: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1100 = 0x1100
};



inline const char8* enumToString(PciDevice1800 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1800::NONE:        return "NONE";
        case PciDevice1800::DEVICE_1100: return "DEVICE_1100";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1800 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1800 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1800::DEVICE_1100: return "Nanospeed Trading Gateway";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1800_PCIDEVICE1800_H
