// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR5145_PCIDEVICE5145_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR5145_PCIDEVICE5145_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice5145: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_3031 = 0x3031
};



inline const char8* enumToString(PciDevice5145 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice5145::NONE:        return "NONE";
        case PciDevice5145::DEVICE_3031: return "DEVICE_3031";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice5145 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice5145 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice5145::DEVICE_3031: return "Concert AudioPCI";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR5145_PCIDEVICE5145_H
