// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR103C_PCISUBDEVICE103C3307_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR103C_PCISUBDEVICE103C3307_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice103C3307: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C3309 = 0x103C3309,
    SUBDEVICE_103C330E = 0x103C330E,
    SUBDEVICE_103C3381 = 0x103C3381
};



inline const char8* enumToString(PciSubDevice103C3307 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice103C3307::NONE:               return "NONE";
        case PciSubDevice103C3307::SUBDEVICE_103C3309: return "SUBDEVICE_103C3309";
        case PciSubDevice103C3307::SUBDEVICE_103C330E: return "SUBDEVICE_103C330E";
        case PciSubDevice103C3307::SUBDEVICE_103C3381: return "SUBDEVICE_103C3381";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice103C3307 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice103C3307 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice103C3307::SUBDEVICE_103C3309: return "iLO 2";
        case PciSubDevice103C3307::SUBDEVICE_103C330E: return "iLO3";
        case PciSubDevice103C3307::SUBDEVICE_103C3381: return "iLO4";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR103C_PCISUBDEVICE103C3307_H
