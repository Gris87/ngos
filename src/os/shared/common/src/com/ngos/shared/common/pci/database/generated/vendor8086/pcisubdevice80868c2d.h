// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80868C2D_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80868C2D_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80868C2D: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_102805D7 = 0x102805D7,
    SUBDEVICE_103C1909 = 0x103C1909,
    SUBDEVICE_103C1998 = 0x103C1998,
    SUBDEVICE_17AA220E = 0x17AA220E,
    SUBDEVICE_17AA3098 = 0x17AA3098,
    SUBDEVICE_17AA309F = 0x17AA309F
};



inline const char8* enumToString(PciSubDevice80868C2D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80868C2D::NONE:               return "NONE";
        case PciSubDevice80868C2D::SUBDEVICE_102805D7: return "SUBDEVICE_102805D7";
        case PciSubDevice80868C2D::SUBDEVICE_103C1909: return "SUBDEVICE_103C1909";
        case PciSubDevice80868C2D::SUBDEVICE_103C1998: return "SUBDEVICE_103C1998";
        case PciSubDevice80868C2D::SUBDEVICE_17AA220E: return "SUBDEVICE_17AA220E";
        case PciSubDevice80868C2D::SUBDEVICE_17AA3098: return "SUBDEVICE_17AA3098";
        case PciSubDevice80868C2D::SUBDEVICE_17AA309F: return "SUBDEVICE_17AA309F";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80868C2D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80868C2D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80868C2D::SUBDEVICE_102805D7: return "Alienware X51 R2";
        case PciSubDevice80868C2D::SUBDEVICE_103C1909: return "ZBook 15";
        case PciSubDevice80868C2D::SUBDEVICE_103C1998: return "EliteDesk 800 G1";
        case PciSubDevice80868C2D::SUBDEVICE_17AA220E: return "ThinkPad T440p";
        case PciSubDevice80868C2D::SUBDEVICE_17AA3098: return "ThinkCentre E73";
        case PciSubDevice80868C2D::SUBDEVICE_17AA309F: return "ThinkCentre M83";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80868C2D_H
