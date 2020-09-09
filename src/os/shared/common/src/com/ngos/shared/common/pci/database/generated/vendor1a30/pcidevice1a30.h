// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1A30_PCIDEVICE1A30_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1A30_PCIDEVICE1A30_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1A30: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0680 = 0x0680,
    DEVICE_0700 = 0x0700,
    DEVICE_0710 = 0x0710
};



inline const char8* enumToString(PciDevice1A30 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1A30::NONE:        return "NONE";
        case PciDevice1A30::DEVICE_0680: return "DEVICE_0680";
        case PciDevice1A30::DEVICE_0700: return "DEVICE_0700";
        case PciDevice1A30::DEVICE_0710: return "DEVICE_0710";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1A30 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1A30 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1A30::DEVICE_0680: return "MtW8171 [Hyperion II]";
        case PciDevice1A30::DEVICE_0700: return "Wave300 PSB8224 [Hyperion III]";
        case PciDevice1A30::DEVICE_0710: return "Wave300 PSB8231 [Hyperion III]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1A30_PCIDEVICE1A30_H
