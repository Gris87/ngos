// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861533_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861533_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80861533: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10280B35 = 0x10280B35,
    SUBDEVICE_103C0003 = 0x103C0003,
    SUBDEVICE_10590180 = 0x10590180,
    SUBDEVICE_10937706 = 0x10937706,
    SUBDEVICE_10A9802C = 0x10A9802C,
    SUBDEVICE_10A9802D = 0x10A9802D,
    SUBDEVICE_17AA1100 = 0x17AA1100,
    SUBDEVICE_80860001 = 0x80860001,
    SUBDEVICE_80860002 = 0x80860002
};



inline const char8* enumToString(PciSubDevice80861533 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861533::NONE:               return "NONE";
        case PciSubDevice80861533::SUBDEVICE_10280B35: return "SUBDEVICE_10280B35";
        case PciSubDevice80861533::SUBDEVICE_103C0003: return "SUBDEVICE_103C0003";
        case PciSubDevice80861533::SUBDEVICE_10590180: return "SUBDEVICE_10590180";
        case PciSubDevice80861533::SUBDEVICE_10937706: return "SUBDEVICE_10937706";
        case PciSubDevice80861533::SUBDEVICE_10A9802C: return "SUBDEVICE_10A9802C";
        case PciSubDevice80861533::SUBDEVICE_10A9802D: return "SUBDEVICE_10A9802D";
        case PciSubDevice80861533::SUBDEVICE_17AA1100: return "SUBDEVICE_17AA1100";
        case PciSubDevice80861533::SUBDEVICE_80860001: return "SUBDEVICE_80860001";
        case PciSubDevice80861533::SUBDEVICE_80860002: return "SUBDEVICE_80860002";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80861533 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80861533 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861533::SUBDEVICE_10280B35: return "I210 Gigabit Network Connection";
        case PciSubDevice80861533::SUBDEVICE_103C0003: return "Ethernet I210-T1 GbE NIC";
        case PciSubDevice80861533::SUBDEVICE_10590180: return "RD10019 1GbE interface";
        case PciSubDevice80861533::SUBDEVICE_10937706: return "Compact Vision System Ethernet Adapter";
        case PciSubDevice80861533::SUBDEVICE_10A9802C: return "UV300 BaseIO single-port GbE";
        case PciSubDevice80861533::SUBDEVICE_10A9802D: return "UV3000 BaseIO GbE Network";
        case PciSubDevice80861533::SUBDEVICE_17AA1100: return "ThinkServer Ethernet Server Adapter";
        case PciSubDevice80861533::SUBDEVICE_80860001: return "Ethernet Server Adapter I210-T1";
        case PciSubDevice80861533::SUBDEVICE_80860002: return "Ethernet Server Adapter I210-T1";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861533_H
