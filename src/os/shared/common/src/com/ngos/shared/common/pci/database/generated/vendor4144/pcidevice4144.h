// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR4144_PCIDEVICE4144_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR4144_PCIDEVICE4144_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice4144: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0044 = 0x0044
};



inline const char8* enumToString(PciDevice4144 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice4144::NONE:        return "NONE";
        case PciDevice4144::DEVICE_0044: return "DEVICE_0044";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice4144 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice4144 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice4144::DEVICE_0044: return "ADM-XRCIIPro";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR4144_PCIDEVICE4144_H
