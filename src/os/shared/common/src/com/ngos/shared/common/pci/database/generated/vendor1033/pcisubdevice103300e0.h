// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1033_PCISUBDEVICE103300E0_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1033_PCISUBDEVICE103300E0_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice103300E0: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1186F100 = 0x1186F100,
    SUBDEVICE_12EE7001 = 0x12EE7001,
    SUBDEVICE_14C20205 = 0x14C20205,
    SUBDEVICE_17990002 = 0x17990002,
    SUBDEVICE_807D1043 = 0x807D1043
};



inline const char8* enumToString(PciSubDevice103300E0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice103300E0::NONE:               return "NONE";
        case PciSubDevice103300E0::SUBDEVICE_1186F100: return "SUBDEVICE_1186F100";
        case PciSubDevice103300E0::SUBDEVICE_12EE7001: return "SUBDEVICE_12EE7001";
        case PciSubDevice103300E0::SUBDEVICE_14C20205: return "SUBDEVICE_14C20205";
        case PciSubDevice103300E0::SUBDEVICE_17990002: return "SUBDEVICE_17990002";
        case PciSubDevice103300E0::SUBDEVICE_807D1043: return "SUBDEVICE_807D1043";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice103300E0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice103300E0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice103300E0::SUBDEVICE_1186F100: return "DUB-C2 USB 2.0 2-port 32-bit cardbus controller";
        case PciSubDevice103300E0::SUBDEVICE_12EE7001: return "Root hub";
        case PciSubDevice103300E0::SUBDEVICE_14C20205: return "PTI-205N USB 2.0 Host Controller";
        case PciSubDevice103300E0::SUBDEVICE_17990002: return "Root Hub";
        case PciSubDevice103300E0::SUBDEVICE_807D1043: return "PCI-USB2 (EHCI subsystem)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1033_PCISUBDEVICE103300E0_H
