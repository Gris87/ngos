// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR124D_PCIDEVICE124D_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR124D_PCIDEVICE124D_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice124D: u16 // Ignore CppEnumVerifier
{
    DEVICE_0000 = 0x0000,
    DEVICE_0002 = 0x0002,
    DEVICE_0003 = 0x0003,
    DEVICE_0004 = 0x0004
};



inline const char8* enumToString(PciDevice124D device124D) // TEST: NO
{
    // COMMON_LT((" | device124D = %u", device124D)); // Commented to avoid bad looking logs



    switch (device124D)
    {
        case PciDevice124D::DEVICE_0000: return "DEVICE_0000";
        case PciDevice124D::DEVICE_0002: return "DEVICE_0002";
        case PciDevice124D::DEVICE_0003: return "DEVICE_0003";
        case PciDevice124D::DEVICE_0004: return "DEVICE_0004";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice124D device124D) // TEST: NO
{
    // COMMON_LT((" | device124D = %u", device124D)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device124D, enumToString(device124D));

    return res;
}



inline const char8* enumToHumanString(PciDevice124D device124D) // TEST: NO
{
    // COMMON_LT((" | device124D = %u", device124D)); // Commented to avoid bad looking logs



    switch (device124D)
    {
        case PciDevice124D::DEVICE_0000: return "EasyConnection 8/32";
        case PciDevice124D::DEVICE_0002: return "EasyConnection 8/64";
        case PciDevice124D::DEVICE_0003: return "EasyIO";
        case PciDevice124D::DEVICE_0004: return "EasyConnection/RA";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR124D_PCIDEVICE124D_H
