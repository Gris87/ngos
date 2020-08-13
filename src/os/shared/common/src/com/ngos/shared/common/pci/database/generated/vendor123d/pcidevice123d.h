// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR123D_PCIDEVICE123D_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR123D_PCIDEVICE123D_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice123D: u16 // Ignore CppEnumVerifier
{
    DEVICE_0000 = 0x0000,
    DEVICE_0002 = 0x0002,
    DEVICE_0003 = 0x0003
};



inline const char8* enumToString(PciDevice123D device123D) // TEST: NO
{
    // COMMON_LT((" | device123D = %u", device123D)); // Commented to avoid bad looking logs



    switch (device123D)
    {
        case PciDevice123D::DEVICE_0000: return "DEVICE_0000";
        case PciDevice123D::DEVICE_0002: return "DEVICE_0002";
        case PciDevice123D::DEVICE_0003: return "DEVICE_0003";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice123D device123D) // TEST: NO
{
    // COMMON_LT((" | device123D = %u", device123D)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device123D, enumToString(device123D));

    return res;
}



inline const char8* enumToHumanString(PciDevice123D device123D) // TEST: NO
{
    // COMMON_LT((" | device123D = %u", device123D)); // Commented to avoid bad looking logs



    switch (device123D)
    {
        case PciDevice123D::DEVICE_0000: return "EasyConnect 8/32";
        case PciDevice123D::DEVICE_0002: return "EasyConnect 8/64";
        case PciDevice123D::DEVICE_0003: return "EasyIO";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR123D_PCIDEVICE123D_H
