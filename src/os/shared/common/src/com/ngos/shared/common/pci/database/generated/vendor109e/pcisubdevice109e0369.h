// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR109E_PCISUBDEVICE109E0369_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR109E_PCISUBDEVICE109E0369_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice109E0369: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10020001 = 0x10020001,
    SUBDEVICE_10020003 = 0x10020003
};



inline const char8* enumToString(PciSubDevice109E0369 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice109E0369::NONE:               return "NONE";
        case PciSubDevice109E0369::SUBDEVICE_10020001: return "SUBDEVICE_10020001";
        case PciSubDevice109E0369::SUBDEVICE_10020003: return "SUBDEVICE_10020003";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice109E0369 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice109E0369 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice109E0369::SUBDEVICE_10020001: return "TV-Wonder";
        case PciSubDevice109E0369::SUBDEVICE_10020003: return "TV-Wonder/VE";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR109E_PCISUBDEVICE109E0369_H
