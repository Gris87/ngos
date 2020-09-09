// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808637D3_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808637D3_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice808637D3: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_15900219 = 0x15900219,
    SUBDEVICE_17AA4020 = 0x17AA4020,
    SUBDEVICE_17AA4021 = 0x17AA4021,
    SUBDEVICE_17AA4025 = 0x17AA4025
};



inline const char8* enumToString(PciSubDevice808637D3 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808637D3::NONE:               return "NONE";
        case PciSubDevice808637D3::SUBDEVICE_15900219: return "SUBDEVICE_15900219";
        case PciSubDevice808637D3::SUBDEVICE_17AA4020: return "SUBDEVICE_17AA4020";
        case PciSubDevice808637D3::SUBDEVICE_17AA4021: return "SUBDEVICE_17AA4021";
        case PciSubDevice808637D3::SUBDEVICE_17AA4025: return "SUBDEVICE_17AA4025";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice808637D3 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice808637D3 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808637D3::SUBDEVICE_15900219: return "Ethernet 10Gb 2-port 568FLR-MMSFP+ Adapter";
        case PciSubDevice808637D3::SUBDEVICE_17AA4020: return "Ethernet Connection X722 for 10GbE SFP+";
        case PciSubDevice808637D3::SUBDEVICE_17AA4021: return "Ethernet Connection X722 for 10GbE SFP+";
        case PciSubDevice808637D3::SUBDEVICE_17AA4025: return "Ethernet Connection X722 for 10GbE SFP+";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808637D3_H
