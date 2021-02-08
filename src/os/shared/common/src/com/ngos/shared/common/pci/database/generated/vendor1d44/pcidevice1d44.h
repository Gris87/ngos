// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1D44_PCIDEVICE1D44_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1D44_PCIDEVICE1D44_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1D44: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_A400 = 0xA400
};



inline const char8* enumToString(PciDevice1D44 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1D44::NONE:        return "NONE";
        case PciDevice1D44::DEVICE_A400: return "DEVICE_A400";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1D44 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1D44 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1D44::DEVICE_A400: return "PM2x24/PM3224";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1D44_PCIDEVICE1D44_H
