// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR114F_PCISUBDEVICE114F001D_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR114F_PCISUBDEVICE114F001D_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice114F001D: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_114F0050 = 0x114F0050,
    SUBDEVICE_114F0051 = 0x114F0051,
    SUBDEVICE_114F0052 = 0x114F0052,
    SUBDEVICE_114F0053 = 0x114F0053
};



inline const char8* enumToString(PciSubDevice114F001D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice114F001D::NONE:               return "NONE";
        case PciSubDevice114F001D::SUBDEVICE_114F0050: return "SUBDEVICE_114F0050";
        case PciSubDevice114F001D::SUBDEVICE_114F0051: return "SUBDEVICE_114F0051";
        case PciSubDevice114F001D::SUBDEVICE_114F0052: return "SUBDEVICE_114F0052";
        case PciSubDevice114F001D::SUBDEVICE_114F0053: return "SUBDEVICE_114F0053";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice114F001D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice114F001D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice114F001D::SUBDEVICE_114F0050: return "DataFire RAS E1 Adapter";
        case PciSubDevice114F001D::SUBDEVICE_114F0051: return "DataFire RAS Dual E1 Adapter";
        case PciSubDevice114F001D::SUBDEVICE_114F0052: return "DataFire RAS T1 Adapter";
        case PciSubDevice114F001D::SUBDEVICE_114F0053: return "DataFire RAS Dual T1 Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR114F_PCISUBDEVICE114F001D_H
