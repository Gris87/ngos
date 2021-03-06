// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR119B_PCIDEVICE119B_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR119B_PCIDEVICE119B_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice119B: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1221 = 0x1221
};



inline const char8* enumToString(PciDevice119B device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice119B::NONE:        return "NONE";
        case PciDevice119B::DEVICE_1221: return "DEVICE_1221";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice119B device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice119B device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice119B::DEVICE_1221: return "82C092G";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR119B_PCIDEVICE119B_H
