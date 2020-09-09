// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808637D0_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808637D0_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice808637D0: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_17AA4020 = 0x17AA4020,
    SUBDEVICE_17AA4021 = 0x17AA4021,
    SUBDEVICE_17AA4022 = 0x17AA4022,
    SUBDEVICE_80860001 = 0x80860001,
    SUBDEVICE_80860002 = 0x80860002,
    SUBDEVICE_80860003 = 0x80860003,
    SUBDEVICE_80860004 = 0x80860004
};



inline const char8* enumToString(PciSubDevice808637D0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808637D0::NONE:               return "NONE";
        case PciSubDevice808637D0::SUBDEVICE_17AA4020: return "SUBDEVICE_17AA4020";
        case PciSubDevice808637D0::SUBDEVICE_17AA4021: return "SUBDEVICE_17AA4021";
        case PciSubDevice808637D0::SUBDEVICE_17AA4022: return "SUBDEVICE_17AA4022";
        case PciSubDevice808637D0::SUBDEVICE_80860001: return "SUBDEVICE_80860001";
        case PciSubDevice808637D0::SUBDEVICE_80860002: return "SUBDEVICE_80860002";
        case PciSubDevice808637D0::SUBDEVICE_80860003: return "SUBDEVICE_80860003";
        case PciSubDevice808637D0::SUBDEVICE_80860004: return "SUBDEVICE_80860004";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice808637D0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice808637D0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808637D0::SUBDEVICE_17AA4020: return "Intel Ethernet Connection X722 for 10G SFP+";
        case PciSubDevice808637D0::SUBDEVICE_17AA4021: return "Intel Ethernet Connection X722 for 10G SFP+";
        case PciSubDevice808637D0::SUBDEVICE_17AA4022: return "Ethernet Connection X722 for 10GbE SFP+";
        case PciSubDevice808637D0::SUBDEVICE_80860001: return "Ethernet Network Adapter X722-2";
        case PciSubDevice808637D0::SUBDEVICE_80860002: return "Ethernet Network Adapter X722-2";
        case PciSubDevice808637D0::SUBDEVICE_80860003: return "Ethernet Network Adapter X722-4";
        case PciSubDevice808637D0::SUBDEVICE_80860004: return "Ethernet Network Adapter X722-4";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808637D0_H
