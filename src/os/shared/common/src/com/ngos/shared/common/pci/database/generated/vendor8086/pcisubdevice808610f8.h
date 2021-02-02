// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808610F8_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808610F8_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice808610F8: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10281F63 = 0x10281F63,
    SUBDEVICE_103C17D2 = 0x103C17D2,
    SUBDEVICE_103C18D0 = 0x103C18D0,
    SUBDEVICE_10590111 = 0x10590111,
    SUBDEVICE_10590130 = 0x10590130,
    SUBDEVICE_8086000C = 0x8086000C
};



inline const char8* enumToString(PciSubDevice808610F8 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808610F8::NONE:               return "NONE";
        case PciSubDevice808610F8::SUBDEVICE_10281F63: return "SUBDEVICE_10281F63";
        case PciSubDevice808610F8::SUBDEVICE_103C17D2: return "SUBDEVICE_103C17D2";
        case PciSubDevice808610F8::SUBDEVICE_103C18D0: return "SUBDEVICE_103C18D0";
        case PciSubDevice808610F8::SUBDEVICE_10590111: return "SUBDEVICE_10590111";
        case PciSubDevice808610F8::SUBDEVICE_10590130: return "SUBDEVICE_10590130";
        case PciSubDevice808610F8::SUBDEVICE_8086000C: return "SUBDEVICE_8086000C";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice808610F8 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice808610F8 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808610F8::SUBDEVICE_10281F63: return "10GbE 2P X520k bNDC";
        case PciSubDevice808610F8::SUBDEVICE_103C17D2: return "Ethernet 10Gb 2-port 560M Adapter";
        case PciSubDevice808610F8::SUBDEVICE_103C18D0: return "Ethernet 10Gb 2-port 560FLB Adapter";
        case PciSubDevice808610F8::SUBDEVICE_10590111: return "T4007 10GbE interface";
        case PciSubDevice808610F8::SUBDEVICE_10590130: return "T4009 10GbE interface";
        case PciSubDevice808610F8::SUBDEVICE_8086000C: return "Ethernet X520 10GbE Dual Port KX4-KR Mezz";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808610F8_H
