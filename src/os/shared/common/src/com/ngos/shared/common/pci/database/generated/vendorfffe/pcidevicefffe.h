// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORFFFE_PCIDEVICEFFFE_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORFFFE_PCIDEVICEFFFE_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDeviceFFFE: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0710 = 0x0710
};



inline const char8* enumToString(PciDeviceFFFE device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDeviceFFFE::NONE:        return "NONE";
        case PciDeviceFFFE::DEVICE_0710: return "DEVICE_0710";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDeviceFFFE device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDeviceFFFE device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDeviceFFFE::DEVICE_0710: return "Virtual SVGA";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORFFFE_PCIDEVICEFFFE_H
