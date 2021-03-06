// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11A9_PCIDEVICE11A9_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11A9_PCIDEVICE11A9_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice11A9: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_4240 = 0x4240
};



inline const char8* enumToString(PciDevice11A9 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice11A9::NONE:        return "NONE";
        case PciDevice11A9::DEVICE_4240: return "DEVICE_4240";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice11A9 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice11A9 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice11A9::DEVICE_4240: return "AMCC S933Q Intelligent Serial Card";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11A9_PCIDEVICE11A9_H
