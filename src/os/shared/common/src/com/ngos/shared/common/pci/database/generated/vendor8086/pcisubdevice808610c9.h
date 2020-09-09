// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808610C9_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808610C9_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice808610C9: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C31EF = 0x103C31EF,
    SUBDEVICE_103C323F = 0x103C323F,
    SUBDEVICE_10A98028 = 0x10A98028,
    SUBDEVICE_13A30037 = 0x13A30037,
    SUBDEVICE_15D9A811 = 0x15D9A811,
    SUBDEVICE_8086A01C = 0x8086A01C,
    SUBDEVICE_8086A03C = 0x8086A03C,
    SUBDEVICE_8086A04C = 0x8086A04C
};



inline const char8* enumToString(PciSubDevice808610C9 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808610C9::NONE:               return "NONE";
        case PciSubDevice808610C9::SUBDEVICE_103C31EF: return "SUBDEVICE_103C31EF";
        case PciSubDevice808610C9::SUBDEVICE_103C323F: return "SUBDEVICE_103C323F";
        case PciSubDevice808610C9::SUBDEVICE_10A98028: return "SUBDEVICE_10A98028";
        case PciSubDevice808610C9::SUBDEVICE_13A30037: return "SUBDEVICE_13A30037";
        case PciSubDevice808610C9::SUBDEVICE_15D9A811: return "SUBDEVICE_15D9A811";
        case PciSubDevice808610C9::SUBDEVICE_8086A01C: return "SUBDEVICE_8086A01C";
        case PciSubDevice808610C9::SUBDEVICE_8086A03C: return "SUBDEVICE_8086A03C";
        case PciSubDevice808610C9::SUBDEVICE_8086A04C: return "SUBDEVICE_8086A04C";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice808610C9 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice808610C9 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808610C9::SUBDEVICE_103C31EF: return "NC362i Integrated Dual port Gigabit Server Adapter";
        case PciSubDevice808610C9::SUBDEVICE_103C323F: return "NC362i Integrated Dual port Gigabit Server Adapter";
        case PciSubDevice808610C9::SUBDEVICE_10A98028: return "UV-BaseIO dual-port GbE";
        case PciSubDevice808610C9::SUBDEVICE_13A30037: return "DS4100 Secure Multi-Gigabit Server Adapter with Compression";
        case PciSubDevice808610C9::SUBDEVICE_15D9A811: return "H8DGU";
        case PciSubDevice808610C9::SUBDEVICE_8086A01C: return "Gigabit ET Dual Port Server Adapter";
        case PciSubDevice808610C9::SUBDEVICE_8086A03C: return "Gigabit ET Dual Port Server Adapter";
        case PciSubDevice808610C9::SUBDEVICE_8086A04C: return "Gigabit ET Dual Port Server Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808610C9_H
