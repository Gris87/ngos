// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808627A0_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808627A0_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice808627A0: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1025006C = 0x1025006C,
    SUBDEVICE_102801D7 = 0x102801D7,
    SUBDEVICE_103C309F = 0x103C309F,
    SUBDEVICE_103C30A1 = 0x103C30A1,
    SUBDEVICE_103C30A3 = 0x103C30A3,
    SUBDEVICE_103C30D5 = 0x103C30D5,
    SUBDEVICE_10431237 = 0x10431237,
    SUBDEVICE_10718209 = 0x10718209,
    SUBDEVICE_17AA2015 = 0x17AA2015,
    SUBDEVICE_17AA2017 = 0x17AA2017
};



inline const char8* enumToString(PciSubDevice808627A0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808627A0::NONE:               return "NONE";
        case PciSubDevice808627A0::SUBDEVICE_1025006C: return "SUBDEVICE_1025006C";
        case PciSubDevice808627A0::SUBDEVICE_102801D7: return "SUBDEVICE_102801D7";
        case PciSubDevice808627A0::SUBDEVICE_103C309F: return "SUBDEVICE_103C309F";
        case PciSubDevice808627A0::SUBDEVICE_103C30A1: return "SUBDEVICE_103C30A1";
        case PciSubDevice808627A0::SUBDEVICE_103C30A3: return "SUBDEVICE_103C30A3";
        case PciSubDevice808627A0::SUBDEVICE_103C30D5: return "SUBDEVICE_103C30D5";
        case PciSubDevice808627A0::SUBDEVICE_10431237: return "SUBDEVICE_10431237";
        case PciSubDevice808627A0::SUBDEVICE_10718209: return "SUBDEVICE_10718209";
        case PciSubDevice808627A0::SUBDEVICE_17AA2015: return "SUBDEVICE_17AA2015";
        case PciSubDevice808627A0::SUBDEVICE_17AA2017: return "SUBDEVICE_17AA2017";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice808627A0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice808627A0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808627A0::SUBDEVICE_1025006C: return "9814 WKMI";
        case PciSubDevice808627A0::SUBDEVICE_102801D7: return "XPS M1210";
        case PciSubDevice808627A0::SUBDEVICE_103C309F: return "Compaq nx9420 Notebook";
        case PciSubDevice808627A0::SUBDEVICE_103C30A1: return "NC2400";
        case PciSubDevice808627A0::SUBDEVICE_103C30A3: return "Compaq nw8440";
        case PciSubDevice808627A0::SUBDEVICE_103C30D5: return "530 Laptop";
        case PciSubDevice808627A0::SUBDEVICE_10431237: return "A6J-Q008";
        case PciSubDevice808627A0::SUBDEVICE_10718209: return "Medion MIM 2240 Notebook PC [MD98100]";
        case PciSubDevice808627A0::SUBDEVICE_17AA2015: return "ThinkPad T60";
        case PciSubDevice808627A0::SUBDEVICE_17AA2017: return "ThinkPad R60/T60/X60 series";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808627A0_H
