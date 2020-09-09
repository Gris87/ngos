// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808637D1_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808637D1_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice808637D1: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_14CD0010 = 0x14CD0010,
    SUBDEVICE_15900216 = 0x15900216,
    SUBDEVICE_15900217 = 0x15900217,
    SUBDEVICE_15900247 = 0x15900247,
    SUBDEVICE_17AA4020 = 0x17AA4020,
    SUBDEVICE_17AA4021 = 0x17AA4021,
    SUBDEVICE_17AA4022 = 0x17AA4022,
    SUBDEVICE_17AA4024 = 0x17AA4024
};



inline const char8* enumToString(PciSubDevice808637D1 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808637D1::NONE:               return "NONE";
        case PciSubDevice808637D1::SUBDEVICE_14CD0010: return "SUBDEVICE_14CD0010";
        case PciSubDevice808637D1::SUBDEVICE_15900216: return "SUBDEVICE_15900216";
        case PciSubDevice808637D1::SUBDEVICE_15900217: return "SUBDEVICE_15900217";
        case PciSubDevice808637D1::SUBDEVICE_15900247: return "SUBDEVICE_15900247";
        case PciSubDevice808637D1::SUBDEVICE_17AA4020: return "SUBDEVICE_17AA4020";
        case PciSubDevice808637D1::SUBDEVICE_17AA4021: return "SUBDEVICE_17AA4021";
        case PciSubDevice808637D1::SUBDEVICE_17AA4022: return "SUBDEVICE_17AA4022";
        case PciSubDevice808637D1::SUBDEVICE_17AA4024: return "SUBDEVICE_17AA4024";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice808637D1 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice808637D1 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808637D1::SUBDEVICE_14CD0010: return "88E1514 Ethernet OCP 2x1G RJ45 Phy Card [USI-1514-1GbaseT]";
        case PciSubDevice808637D1::SUBDEVICE_15900216: return "Ethernet 1Gb 2-port 368i Adapter";
        case PciSubDevice808637D1::SUBDEVICE_15900217: return "Ethernet 1Gb 2-port 368FLR-MMT Adapter";
        case PciSubDevice808637D1::SUBDEVICE_15900247: return "Ethernet 1Gb 4-port 369i Adapter";
        case PciSubDevice808637D1::SUBDEVICE_17AA4020: return "Ethernet Connection X722 for 1GbE";
        case PciSubDevice808637D1::SUBDEVICE_17AA4021: return "Ethernet Connection X722 for 1GbE";
        case PciSubDevice808637D1::SUBDEVICE_17AA4022: return "Ethernet Connection X722 for 1GbE";
        case PciSubDevice808637D1::SUBDEVICE_17AA4024: return "Ethernet Connection X722 for 1GbE";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808637D1_H
