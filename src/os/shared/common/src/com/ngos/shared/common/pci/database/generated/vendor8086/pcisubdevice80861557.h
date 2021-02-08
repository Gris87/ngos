// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861557_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861557_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80861557: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_17AA4008 = 0x17AA4008,
    SUBDEVICE_1BD4001C = 0x1BD4001C,
    SUBDEVICE_1BD40030 = 0x1BD40030,
    SUBDEVICE_80860001 = 0x80860001
};



inline const char8* enumToString(PciSubDevice80861557 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861557::NONE:               return "NONE";
        case PciSubDevice80861557::SUBDEVICE_17AA4008: return "SUBDEVICE_17AA4008";
        case PciSubDevice80861557::SUBDEVICE_1BD4001C: return "SUBDEVICE_1BD4001C";
        case PciSubDevice80861557::SUBDEVICE_1BD40030: return "SUBDEVICE_1BD40030";
        case PciSubDevice80861557::SUBDEVICE_80860001: return "SUBDEVICE_80860001";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80861557 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80861557 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861557::SUBDEVICE_17AA4008: return "82599EN 10 Gigabit Network Connection";
        case PciSubDevice80861557::SUBDEVICE_1BD4001C: return "10G SFP+ SP ER101Fi4 Rack Adapter";
        case PciSubDevice80861557::SUBDEVICE_1BD40030: return "10G SFP+ SP EP101Fi4A Adapter";
        case PciSubDevice80861557::SUBDEVICE_80860001: return "Ethernet OCP Server Adapter X520-1";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861557_H
