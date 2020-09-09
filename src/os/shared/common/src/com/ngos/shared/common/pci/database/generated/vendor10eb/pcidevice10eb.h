// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10EB_PCIDEVICE10EB_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10EB_PCIDEVICE10EB_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice10EB: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0101 = 0x0101,
    DEVICE_8111 = 0x8111
};



inline const char8* enumToString(PciDevice10EB device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice10EB::NONE:        return "NONE";
        case PciDevice10EB::DEVICE_0101: return "DEVICE_0101";
        case PciDevice10EB::DEVICE_8111: return "DEVICE_8111";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice10EB device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice10EB device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice10EB::DEVICE_0101: return "3GA";
        case PciDevice10EB::DEVICE_8111: return "Twist3 Frame Grabber";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10EB_PCIDEVICE10EB_H
