// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808627B9_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808627B9_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice808627B9: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_102801D7 = 0x102801D7,
    SUBDEVICE_103C309F = 0x103C309F,
    SUBDEVICE_103C30A1 = 0x103C30A1,
    SUBDEVICE_103C30A3 = 0x103C30A3,
    SUBDEVICE_103C30D5 = 0x103C30D5,
    SUBDEVICE_10718209 = 0x10718209,
    SUBDEVICE_10F78338 = 0x10F78338,
    SUBDEVICE_17AA2009 = 0x17AA2009
};



inline const char8* enumToString(PciSubDevice808627B9 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808627B9::NONE:               return "NONE";
        case PciSubDevice808627B9::SUBDEVICE_102801D7: return "SUBDEVICE_102801D7";
        case PciSubDevice808627B9::SUBDEVICE_103C309F: return "SUBDEVICE_103C309F";
        case PciSubDevice808627B9::SUBDEVICE_103C30A1: return "SUBDEVICE_103C30A1";
        case PciSubDevice808627B9::SUBDEVICE_103C30A3: return "SUBDEVICE_103C30A3";
        case PciSubDevice808627B9::SUBDEVICE_103C30D5: return "SUBDEVICE_103C30D5";
        case PciSubDevice808627B9::SUBDEVICE_10718209: return "SUBDEVICE_10718209";
        case PciSubDevice808627B9::SUBDEVICE_10F78338: return "SUBDEVICE_10F78338";
        case PciSubDevice808627B9::SUBDEVICE_17AA2009: return "SUBDEVICE_17AA2009";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice808627B9 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice808627B9 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808627B9::SUBDEVICE_102801D7: return "XPS M1210";
        case PciSubDevice808627B9::SUBDEVICE_103C309F: return "Compaq nx9420 Notebook";
        case PciSubDevice808627B9::SUBDEVICE_103C30A1: return "NC2400";
        case PciSubDevice808627B9::SUBDEVICE_103C30A3: return "Compaq nw8440";
        case PciSubDevice808627B9::SUBDEVICE_103C30D5: return "530 Laptop";
        case PciSubDevice808627B9::SUBDEVICE_10718209: return "Medion MIM 2240 Notebook PC [MD98100]";
        case PciSubDevice808627B9::SUBDEVICE_10F78338: return "Panasonic CF-Y5 laptop";
        case PciSubDevice808627B9::SUBDEVICE_17AA2009: return "ThinkPad R60/T60/X60 series";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808627B9_H
