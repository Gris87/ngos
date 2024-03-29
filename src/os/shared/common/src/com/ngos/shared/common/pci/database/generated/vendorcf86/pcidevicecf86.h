// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORCF86_PCIDEVICECF86_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORCF86_PCIDEVICECF86_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDeviceCF86: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0276 = 0x0276
};



inline const char8* enumToString(PciDeviceCF86 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDeviceCF86::NONE:        return "NONE";
        case PciDeviceCF86::DEVICE_0276: return "DEVICE_0276";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDeviceCF86 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDeviceCF86 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDeviceCF86::DEVICE_0276: return "Spectrum-4TOR in Flash Recovery Mode";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORCF86_PCIDEVICECF86_H
