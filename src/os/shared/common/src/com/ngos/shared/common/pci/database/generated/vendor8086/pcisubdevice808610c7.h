// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808610C7_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808610C7_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice808610C7: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1014037F = 0x1014037F,
    SUBDEVICE_10140380 = 0x10140380,
    SUBDEVICE_8086A05F = 0x8086A05F,
    SUBDEVICE_8086A15F = 0x8086A15F,
    SUBDEVICE_8086A16F = 0x8086A16F
};



inline const char8* enumToString(PciSubDevice808610C7 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808610C7::NONE:               return "NONE";
        case PciSubDevice808610C7::SUBDEVICE_1014037F: return "SUBDEVICE_1014037F";
        case PciSubDevice808610C7::SUBDEVICE_10140380: return "SUBDEVICE_10140380";
        case PciSubDevice808610C7::SUBDEVICE_8086A05F: return "SUBDEVICE_8086A05F";
        case PciSubDevice808610C7::SUBDEVICE_8086A15F: return "SUBDEVICE_8086A15F";
        case PciSubDevice808610C7::SUBDEVICE_8086A16F: return "SUBDEVICE_8086A16F";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice808610C7 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice808610C7 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808610C7::SUBDEVICE_1014037F: return "10-Gigabit XF SR Server Adapter";
        case PciSubDevice808610C7::SUBDEVICE_10140380: return "10-Gigabit XF LR Server Adapter";
        case PciSubDevice808610C7::SUBDEVICE_8086A05F: return "10-Gigabit XF SR Server Adapter";
        case PciSubDevice808610C7::SUBDEVICE_8086A15F: return "10-Gigabit XF SR Server Adapter";
        case PciSubDevice808610C7::SUBDEVICE_8086A16F: return "10-Gigabit XF SR Server Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808610C7_H
