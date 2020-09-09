// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR6374_PCIDEVICE6374_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR6374_PCIDEVICE6374_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice6374: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_6773 = 0x6773
};



inline const char8* enumToString(PciDevice6374 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice6374::NONE:        return "NONE";
        case PciDevice6374::DEVICE_6773: return "DEVICE_6773";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice6374 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice6374 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice6374::DEVICE_6773: return "GPPCI";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR6374_PCIDEVICE6374_H
