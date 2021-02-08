// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808627C1_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808627C1_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice808627C1: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_102801DF = 0x102801DF,
    SUBDEVICE_103C2A3B = 0x103C2A3B,
    SUBDEVICE_104383AD = 0x104383AD,
    SUBDEVICE_105B0D7C = 0x105B0D7C,
    SUBDEVICE_144DC072 = 0x144DC072,
    SUBDEVICE_1458B005 = 0x1458B005,
    SUBDEVICE_177511CC = 0x177511CC,
    SUBDEVICE_80864F4D = 0x80864F4D,
    SUBDEVICE_80865842 = 0x80865842
};



inline const char8* enumToString(PciSubDevice808627C1 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808627C1::NONE:               return "NONE";
        case PciSubDevice808627C1::SUBDEVICE_102801DF: return "SUBDEVICE_102801DF";
        case PciSubDevice808627C1::SUBDEVICE_103C2A3B: return "SUBDEVICE_103C2A3B";
        case PciSubDevice808627C1::SUBDEVICE_104383AD: return "SUBDEVICE_104383AD";
        case PciSubDevice808627C1::SUBDEVICE_105B0D7C: return "SUBDEVICE_105B0D7C";
        case PciSubDevice808627C1::SUBDEVICE_144DC072: return "SUBDEVICE_144DC072";
        case PciSubDevice808627C1::SUBDEVICE_1458B005: return "SUBDEVICE_1458B005";
        case PciSubDevice808627C1::SUBDEVICE_177511CC: return "SUBDEVICE_177511CC";
        case PciSubDevice808627C1::SUBDEVICE_80864F4D: return "SUBDEVICE_80864F4D";
        case PciSubDevice808627C1::SUBDEVICE_80865842: return "SUBDEVICE_80865842";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice808627C1 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice808627C1 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808627C1::SUBDEVICE_102801DF: return "PowerEdge SC440";
        case PciSubDevice808627C1::SUBDEVICE_103C2A3B: return "Pavilion A1512X";
        case PciSubDevice808627C1::SUBDEVICE_104383AD: return "Eee PC 1015PX";
        case PciSubDevice808627C1::SUBDEVICE_105B0D7C: return "D270S/D250S Motherboard";
        case PciSubDevice808627C1::SUBDEVICE_144DC072: return "Notebook N150P";
        case PciSubDevice808627C1::SUBDEVICE_1458B005: return "GA-D525TUD";
        case PciSubDevice808627C1::SUBDEVICE_177511CC: return "CC11/CL11";
        case PciSubDevice808627C1::SUBDEVICE_80864F4D: return "DeskTop Board D510MO";
        case PciSubDevice808627C1::SUBDEVICE_80865842: return "DeskTop Board D975XBX";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808627C1_H
