// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808610F1_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808610F1_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice808610F1: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_8086A20F = 0x8086A20F,
    SUBDEVICE_8086A21F = 0x8086A21F
};



inline const char8* enumToString(PciSubDevice808610F1 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808610F1::NONE:               return "NONE";
        case PciSubDevice808610F1::SUBDEVICE_8086A20F: return "SUBDEVICE_8086A20F";
        case PciSubDevice808610F1::SUBDEVICE_8086A21F: return "SUBDEVICE_8086A21F";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice808610F1 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice808610F1 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808610F1::SUBDEVICE_8086A20F: return "10-Gigabit AF DA Dual Port Server Adapter";
        case PciSubDevice808610F1::SUBDEVICE_8086A21F: return "10-Gigabit AF DA Dual Port Server Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808610F1_H
