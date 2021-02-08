// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1064_PCIDEVICE1064_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1064_PCIDEVICE1064_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1064: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1102 = 0x1102
};



inline const char8* enumToString(PciDevice1064 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1064::NONE:        return "NONE";
        case PciDevice1064::DEVICE_1102: return "DEVICE_1102";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1064 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1064 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1064::DEVICE_1102: return "Dynamite 2840 (ADSL PCI modem)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1064_PCIDEVICE1064_H
