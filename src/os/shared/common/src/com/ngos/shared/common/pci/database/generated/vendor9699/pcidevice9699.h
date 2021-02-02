// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9699_PCIDEVICE9699_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9699_PCIDEVICE9699_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice9699: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_6565 = 0x6565
};



inline const char8* enumToString(PciDevice9699 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice9699::NONE:        return "NONE";
        case PciDevice9699::DEVICE_6565: return "DEVICE_6565";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice9699 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice9699 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice9699::DEVICE_6565: return "6565";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9699_PCIDEVICE9699_H
