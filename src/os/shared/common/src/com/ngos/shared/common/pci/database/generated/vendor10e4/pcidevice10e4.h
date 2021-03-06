// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10E4_PCIDEVICE10E4_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10E4_PCIDEVICE10E4_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice10E4: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_8029 = 0x8029
};



inline const char8* enumToString(PciDevice10E4 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice10E4::NONE:        return "NONE";
        case PciDevice10E4::DEVICE_8029: return "DEVICE_8029";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice10E4 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice10E4 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice10E4::DEVICE_8029: return "Realtek 8029 Network Card";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10E4_PCIDEVICE10E4_H
