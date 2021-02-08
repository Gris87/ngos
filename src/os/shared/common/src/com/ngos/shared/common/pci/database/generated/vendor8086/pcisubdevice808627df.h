// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808627DF_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808627DF_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice808627DF: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_102801DF = 0x102801DF,
    SUBDEVICE_102801E6 = 0x102801E6,
    SUBDEVICE_103C2A3B = 0x103C2A3B,
    SUBDEVICE_103C2A8C = 0x103C2A8C,
    SUBDEVICE_103C309F = 0x103C309F,
    SUBDEVICE_103C30A1 = 0x103C30A1,
    SUBDEVICE_103C30A3 = 0x103C30A3,
    SUBDEVICE_103C30D5 = 0x103C30D5,
    SUBDEVICE_10431237 = 0x10431237,
    SUBDEVICE_10438179 = 0x10438179,
    SUBDEVICE_107B5048 = 0x107B5048,
    SUBDEVICE_10F78338 = 0x10F78338,
    SUBDEVICE_14627418 = 0x14627418,
    SUBDEVICE_177511CC = 0x177511CC,
    SUBDEVICE_17AA200C = 0x17AA200C,
    SUBDEVICE_8086544E = 0x8086544E
};



inline const char8* enumToString(PciSubDevice808627DF subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808627DF::NONE:               return "NONE";
        case PciSubDevice808627DF::SUBDEVICE_102801DF: return "SUBDEVICE_102801DF";
        case PciSubDevice808627DF::SUBDEVICE_102801E6: return "SUBDEVICE_102801E6";
        case PciSubDevice808627DF::SUBDEVICE_103C2A3B: return "SUBDEVICE_103C2A3B";
        case PciSubDevice808627DF::SUBDEVICE_103C2A8C: return "SUBDEVICE_103C2A8C";
        case PciSubDevice808627DF::SUBDEVICE_103C309F: return "SUBDEVICE_103C309F";
        case PciSubDevice808627DF::SUBDEVICE_103C30A1: return "SUBDEVICE_103C30A1";
        case PciSubDevice808627DF::SUBDEVICE_103C30A3: return "SUBDEVICE_103C30A3";
        case PciSubDevice808627DF::SUBDEVICE_103C30D5: return "SUBDEVICE_103C30D5";
        case PciSubDevice808627DF::SUBDEVICE_10431237: return "SUBDEVICE_10431237";
        case PciSubDevice808627DF::SUBDEVICE_10438179: return "SUBDEVICE_10438179";
        case PciSubDevice808627DF::SUBDEVICE_107B5048: return "SUBDEVICE_107B5048";
        case PciSubDevice808627DF::SUBDEVICE_10F78338: return "SUBDEVICE_10F78338";
        case PciSubDevice808627DF::SUBDEVICE_14627418: return "SUBDEVICE_14627418";
        case PciSubDevice808627DF::SUBDEVICE_177511CC: return "SUBDEVICE_177511CC";
        case PciSubDevice808627DF::SUBDEVICE_17AA200C: return "SUBDEVICE_17AA200C";
        case PciSubDevice808627DF::SUBDEVICE_8086544E: return "SUBDEVICE_8086544E";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice808627DF subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice808627DF subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808627DF::SUBDEVICE_102801DF: return "PowerEdge SC440";
        case PciSubDevice808627DF::SUBDEVICE_102801E6: return "PowerEdge 860";
        case PciSubDevice808627DF::SUBDEVICE_103C2A3B: return "Pavilion A1512X";
        case PciSubDevice808627DF::SUBDEVICE_103C2A8C: return "Compaq 500B Microtower";
        case PciSubDevice808627DF::SUBDEVICE_103C309F: return "Compaq nx9420 Notebook";
        case PciSubDevice808627DF::SUBDEVICE_103C30A1: return "NC2400";
        case PciSubDevice808627DF::SUBDEVICE_103C30A3: return "Compaq nw8440";
        case PciSubDevice808627DF::SUBDEVICE_103C30D5: return "530 Laptop";
        case PciSubDevice808627DF::SUBDEVICE_10431237: return "A6J-Q008";
        case PciSubDevice808627DF::SUBDEVICE_10438179: return "P5B-MX/WiFi-AP, P5KPL-VM Motherboard";
        case PciSubDevice808627DF::SUBDEVICE_107B5048: return "E4500";
        case PciSubDevice808627DF::SUBDEVICE_10F78338: return "Panasonic CF-Y5 laptop";
        case PciSubDevice808627DF::SUBDEVICE_14627418: return "Wind PC MS-7418";
        case PciSubDevice808627DF::SUBDEVICE_177511CC: return "CC11/CL11";
        case PciSubDevice808627DF::SUBDEVICE_17AA200C: return "ThinkPad R60/T60/X60 series";
        case PciSubDevice808627DF::SUBDEVICE_8086544E: return "DeskTop Board D945GTP";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808627DF_H
