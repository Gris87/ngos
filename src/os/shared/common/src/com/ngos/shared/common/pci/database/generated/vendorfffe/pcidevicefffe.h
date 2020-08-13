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



inline const char8* enumToString(PciDeviceFFFE deviceFFFE) // TEST: NO
{
    // COMMON_LT((" | deviceFFFE = %u", deviceFFFE)); // Commented to avoid bad looking logs



    switch (deviceFFFE)
    {
        case PciDeviceFFFE::NONE:        return "NONE";
        case PciDeviceFFFE::DEVICE_0710: return "DEVICE_0710";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDeviceFFFE deviceFFFE) // TEST: NO
{
    // COMMON_LT((" | deviceFFFE = %u", deviceFFFE)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)deviceFFFE, enumToString(deviceFFFE));

    return res;
}



inline const char8* enumToHumanString(PciDeviceFFFE deviceFFFE) // TEST: NO
{
    // COMMON_LT((" | deviceFFFE = %u", deviceFFFE)); // Commented to avoid bad looking logs



    switch (deviceFFFE)
    {
        case PciDeviceFFFE::DEVICE_0710: return "Virtual SVGA";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORFFFE_PCIDEVICEFFFE_H
