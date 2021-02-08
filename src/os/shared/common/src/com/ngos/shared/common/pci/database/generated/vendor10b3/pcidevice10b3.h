// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B3_PCIDEVICE10B3_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B3_PCIDEVICE10B3_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice10B3: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_3106 = 0x3106,
    DEVICE_B106 = 0xB106
};



inline const char8* enumToString(PciDevice10B3 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice10B3::NONE:        return "NONE";
        case PciDevice10B3::DEVICE_3106: return "DEVICE_3106";
        case PciDevice10B3::DEVICE_B106: return "DEVICE_B106";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice10B3 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice10B3 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice10B3::DEVICE_3106: return "DB87144";
        case PciDevice10B3::DEVICE_B106: return "DB87144";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B3_PCIDEVICE10B3_H
