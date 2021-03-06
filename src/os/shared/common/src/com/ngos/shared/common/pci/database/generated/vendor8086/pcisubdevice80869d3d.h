// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80869D3D_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80869D3D_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80869D3D: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C8079 = 0x103C8079,
    SUBDEVICE_17AA2247 = 0x17AA2247
};



inline const char8* enumToString(PciSubDevice80869D3D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80869D3D::NONE:               return "NONE";
        case PciSubDevice80869D3D::SUBDEVICE_103C8079: return "SUBDEVICE_103C8079";
        case PciSubDevice80869D3D::SUBDEVICE_17AA2247: return "SUBDEVICE_17AA2247";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80869D3D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80869D3D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80869D3D::SUBDEVICE_103C8079: return "EliteBook 840 G3";
        case PciSubDevice80869D3D::SUBDEVICE_17AA2247: return "ThinkPad T570";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80869D3D_H
