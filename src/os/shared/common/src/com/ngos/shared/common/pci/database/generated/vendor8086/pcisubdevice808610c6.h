// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808610C6_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808610C6_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice808610C6: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_8086A05F = 0x8086A05F,
    SUBDEVICE_8086A15F = 0x8086A15F
};



inline const char8* enumToString(PciSubDevice808610C6 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808610C6::NONE:               return "NONE";
        case PciSubDevice808610C6::SUBDEVICE_8086A05F: return "SUBDEVICE_8086A05F";
        case PciSubDevice808610C6::SUBDEVICE_8086A15F: return "SUBDEVICE_8086A15F";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice808610C6 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice808610C6 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808610C6::SUBDEVICE_8086A05F: return "10-Gigabit XF SR Dual Port Server Adapter";
        case PciSubDevice808610C6::SUBDEVICE_8086A15F: return "10-Gigabit XF SR Dual Port Server Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808610C6_H
