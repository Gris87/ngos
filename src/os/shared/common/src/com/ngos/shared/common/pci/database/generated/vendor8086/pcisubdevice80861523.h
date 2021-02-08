// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861523_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861523_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80861523: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10280060 = 0x10280060,
    SUBDEVICE_10281F9B = 0x10281F9B,
    SUBDEVICE_103C1784 = 0x103C1784,
    SUBDEVICE_103C18D1 = 0x103C18D1,
    SUBDEVICE_103C1989 = 0x103C1989,
    SUBDEVICE_103C339F = 0x103C339F,
    SUBDEVICE_80861F52 = 0x80861F52
};



inline const char8* enumToString(PciSubDevice80861523 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861523::NONE:               return "NONE";
        case PciSubDevice80861523::SUBDEVICE_10280060: return "SUBDEVICE_10280060";
        case PciSubDevice80861523::SUBDEVICE_10281F9B: return "SUBDEVICE_10281F9B";
        case PciSubDevice80861523::SUBDEVICE_103C1784: return "SUBDEVICE_103C1784";
        case PciSubDevice80861523::SUBDEVICE_103C18D1: return "SUBDEVICE_103C18D1";
        case PciSubDevice80861523::SUBDEVICE_103C1989: return "SUBDEVICE_103C1989";
        case PciSubDevice80861523::SUBDEVICE_103C339F: return "SUBDEVICE_103C339F";
        case PciSubDevice80861523::SUBDEVICE_80861F52: return "SUBDEVICE_80861F52";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80861523 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80861523 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861523::SUBDEVICE_10280060: return "Gigabit 2P I350 LOM";
        case PciSubDevice80861523::SUBDEVICE_10281F9B: return "Gigabit 4P I350-t bNDC";
        case PciSubDevice80861523::SUBDEVICE_103C1784: return "Ethernet 1Gb 2-port 361FLB Adapter";
        case PciSubDevice80861523::SUBDEVICE_103C18D1: return "Ethernet 1Gb 2-port 361FLB Adapter";
        case PciSubDevice80861523::SUBDEVICE_103C1989: return "Ethernet 1Gb 2-port 363i Adapter";
        case PciSubDevice80861523::SUBDEVICE_103C339F: return "Ethernet 1Gb 4-port 366M Adapter";
        case PciSubDevice80861523::SUBDEVICE_80861F52: return "1GbE 4P I350 Mezz";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861523_H
