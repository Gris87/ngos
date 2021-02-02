// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808637D2_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808637D2_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice808637D2: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10590180 = 0x10590180,
    SUBDEVICE_117037D2 = 0x117037D2,
    SUBDEVICE_14CD0030 = 0x14CD0030,
    SUBDEVICE_15900218 = 0x15900218,
    SUBDEVICE_17AA4020 = 0x17AA4020,
    SUBDEVICE_17AA4021 = 0x17AA4021,
    SUBDEVICE_17AA4022 = 0x17AA4022,
    SUBDEVICE_17AA4024 = 0x17AA4024,
    SUBDEVICE_17AA4025 = 0x17AA4025
};



inline const char8* enumToString(PciSubDevice808637D2 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808637D2::NONE:               return "NONE";
        case PciSubDevice808637D2::SUBDEVICE_10590180: return "SUBDEVICE_10590180";
        case PciSubDevice808637D2::SUBDEVICE_117037D2: return "SUBDEVICE_117037D2";
        case PciSubDevice808637D2::SUBDEVICE_14CD0030: return "SUBDEVICE_14CD0030";
        case PciSubDevice808637D2::SUBDEVICE_15900218: return "SUBDEVICE_15900218";
        case PciSubDevice808637D2::SUBDEVICE_17AA4020: return "SUBDEVICE_17AA4020";
        case PciSubDevice808637D2::SUBDEVICE_17AA4021: return "SUBDEVICE_17AA4021";
        case PciSubDevice808637D2::SUBDEVICE_17AA4022: return "SUBDEVICE_17AA4022";
        case PciSubDevice808637D2::SUBDEVICE_17AA4024: return "SUBDEVICE_17AA4024";
        case PciSubDevice808637D2::SUBDEVICE_17AA4025: return "SUBDEVICE_17AA4025";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice808637D2 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice808637D2 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808637D2::SUBDEVICE_10590180: return "RD10019 10GbE interface";
        case PciSubDevice808637D2::SUBDEVICE_117037D2: return "Ethernet Connection X722 for 10GBASE-T";
        case PciSubDevice808637D2::SUBDEVICE_14CD0030: return "Ethernet OCP 2x10G RJ45 Phy Card [USI-X557-10GbaseT]";
        case PciSubDevice808637D2::SUBDEVICE_15900218: return "Ethernet 10Gb 2-port 568FLR-MMT Adapter";
        case PciSubDevice808637D2::SUBDEVICE_17AA4020: return "Ethernet Connection X722 for 10GBASE-T";
        case PciSubDevice808637D2::SUBDEVICE_17AA4021: return "Ethernet Connection X722 for 10GBASE-T";
        case PciSubDevice808637D2::SUBDEVICE_17AA4022: return "Ethernet Connection X722 for 10GBASE-T";
        case PciSubDevice808637D2::SUBDEVICE_17AA4024: return "Ethernet Connection X722 for 10GBASE-T";
        case PciSubDevice808637D2::SUBDEVICE_17AA4025: return "Ethernet Connection X722 for 10GBASE-T";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808637D2_H
