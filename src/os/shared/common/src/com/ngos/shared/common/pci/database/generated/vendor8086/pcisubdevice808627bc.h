// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808627BC_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808627BC_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice808627BC: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_104383AD = 0x104383AD,
    SUBDEVICE_105B0D7C = 0x105B0D7C,
    SUBDEVICE_144DC072 = 0x144DC072,
    SUBDEVICE_14585001 = 0x14585001,
    SUBDEVICE_80864F4D = 0x80864F4D,
    SUBDEVICE_8086544B = 0x8086544B
};



inline const char8* enumToString(PciSubDevice808627BC subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808627BC::NONE:               return "NONE";
        case PciSubDevice808627BC::SUBDEVICE_104383AD: return "SUBDEVICE_104383AD";
        case PciSubDevice808627BC::SUBDEVICE_105B0D7C: return "SUBDEVICE_105B0D7C";
        case PciSubDevice808627BC::SUBDEVICE_144DC072: return "SUBDEVICE_144DC072";
        case PciSubDevice808627BC::SUBDEVICE_14585001: return "SUBDEVICE_14585001";
        case PciSubDevice808627BC::SUBDEVICE_80864F4D: return "SUBDEVICE_80864F4D";
        case PciSubDevice808627BC::SUBDEVICE_8086544B: return "SUBDEVICE_8086544B";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice808627BC subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice808627BC subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808627BC::SUBDEVICE_104383AD: return "Eee PC 1015PX";
        case PciSubDevice808627BC::SUBDEVICE_105B0D7C: return "D270S/D250S Motherboard";
        case PciSubDevice808627BC::SUBDEVICE_144DC072: return "Notebook N150P";
        case PciSubDevice808627BC::SUBDEVICE_14585001: return "GA-D525TUD";
        case PciSubDevice808627BC::SUBDEVICE_80864F4D: return "DeskTop Board D510MO";
        case PciSubDevice808627BC::SUBDEVICE_8086544B: return "Desktop Board D425KT";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808627BC_H
