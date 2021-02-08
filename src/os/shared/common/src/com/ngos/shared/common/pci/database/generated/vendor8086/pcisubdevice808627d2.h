// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808627D2_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808627D2_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice808627D2: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C309F = 0x103C309F,
    SUBDEVICE_103C30A3 = 0x103C30A3,
    SUBDEVICE_10718209 = 0x10718209,
    SUBDEVICE_144DC072 = 0x144DC072,
    SUBDEVICE_14627418 = 0x14627418,
    SUBDEVICE_177511CC = 0x177511CC,
    SUBDEVICE_17AA2011 = 0x17AA2011,
    SUBDEVICE_8086544B = 0x8086544B
};



inline const char8* enumToString(PciSubDevice808627D2 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808627D2::NONE:               return "NONE";
        case PciSubDevice808627D2::SUBDEVICE_103C309F: return "SUBDEVICE_103C309F";
        case PciSubDevice808627D2::SUBDEVICE_103C30A3: return "SUBDEVICE_103C30A3";
        case PciSubDevice808627D2::SUBDEVICE_10718209: return "SUBDEVICE_10718209";
        case PciSubDevice808627D2::SUBDEVICE_144DC072: return "SUBDEVICE_144DC072";
        case PciSubDevice808627D2::SUBDEVICE_14627418: return "SUBDEVICE_14627418";
        case PciSubDevice808627D2::SUBDEVICE_177511CC: return "SUBDEVICE_177511CC";
        case PciSubDevice808627D2::SUBDEVICE_17AA2011: return "SUBDEVICE_17AA2011";
        case PciSubDevice808627D2::SUBDEVICE_8086544B: return "SUBDEVICE_8086544B";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice808627D2 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice808627D2 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808627D2::SUBDEVICE_103C309F: return "Compaq nx9420 Notebook";
        case PciSubDevice808627D2::SUBDEVICE_103C30A3: return "Compaq nw8440";
        case PciSubDevice808627D2::SUBDEVICE_10718209: return "Medion MIM 2240 Notebook PC [MD98100]";
        case PciSubDevice808627D2::SUBDEVICE_144DC072: return "Notebook N150P";
        case PciSubDevice808627D2::SUBDEVICE_14627418: return "Wind PC MS-7418";
        case PciSubDevice808627D2::SUBDEVICE_177511CC: return "CC11/CL11";
        case PciSubDevice808627D2::SUBDEVICE_17AA2011: return "ThinkPad R60e";
        case PciSubDevice808627D2::SUBDEVICE_8086544B: return "Desktop Board D425KT";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808627D2_H
