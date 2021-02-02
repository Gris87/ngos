// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808627DA_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808627DA_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice808627DA: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1025006C = 0x1025006C,
    SUBDEVICE_102801AD = 0x102801AD,
    SUBDEVICE_102801D7 = 0x102801D7,
    SUBDEVICE_102801DF = 0x102801DF,
    SUBDEVICE_102801E6 = 0x102801E6,
    SUBDEVICE_103C2A3B = 0x103C2A3B,
    SUBDEVICE_103C2A8C = 0x103C2A8C,
    SUBDEVICE_10438179 = 0x10438179,
    SUBDEVICE_105B0D7C = 0x105B0D7C,
    SUBDEVICE_10718209 = 0x10718209,
    SUBDEVICE_10F78338 = 0x10F78338,
    SUBDEVICE_144DC072 = 0x144DC072,
    SUBDEVICE_14585001 = 0x14585001,
    SUBDEVICE_14627418 = 0x14627418,
    SUBDEVICE_177511CC = 0x177511CC,
    SUBDEVICE_17AA200F = 0x17AA200F,
    SUBDEVICE_80864F4D = 0x80864F4D,
    SUBDEVICE_8086544B = 0x8086544B,
    SUBDEVICE_8086544E = 0x8086544E,
    SUBDEVICE_80865842 = 0x80865842
};



inline const char8* enumToString(PciSubDevice808627DA subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808627DA::NONE:               return "NONE";
        case PciSubDevice808627DA::SUBDEVICE_1025006C: return "SUBDEVICE_1025006C";
        case PciSubDevice808627DA::SUBDEVICE_102801AD: return "SUBDEVICE_102801AD";
        case PciSubDevice808627DA::SUBDEVICE_102801D7: return "SUBDEVICE_102801D7";
        case PciSubDevice808627DA::SUBDEVICE_102801DF: return "SUBDEVICE_102801DF";
        case PciSubDevice808627DA::SUBDEVICE_102801E6: return "SUBDEVICE_102801E6";
        case PciSubDevice808627DA::SUBDEVICE_103C2A3B: return "SUBDEVICE_103C2A3B";
        case PciSubDevice808627DA::SUBDEVICE_103C2A8C: return "SUBDEVICE_103C2A8C";
        case PciSubDevice808627DA::SUBDEVICE_10438179: return "SUBDEVICE_10438179";
        case PciSubDevice808627DA::SUBDEVICE_105B0D7C: return "SUBDEVICE_105B0D7C";
        case PciSubDevice808627DA::SUBDEVICE_10718209: return "SUBDEVICE_10718209";
        case PciSubDevice808627DA::SUBDEVICE_10F78338: return "SUBDEVICE_10F78338";
        case PciSubDevice808627DA::SUBDEVICE_144DC072: return "SUBDEVICE_144DC072";
        case PciSubDevice808627DA::SUBDEVICE_14585001: return "SUBDEVICE_14585001";
        case PciSubDevice808627DA::SUBDEVICE_14627418: return "SUBDEVICE_14627418";
        case PciSubDevice808627DA::SUBDEVICE_177511CC: return "SUBDEVICE_177511CC";
        case PciSubDevice808627DA::SUBDEVICE_17AA200F: return "SUBDEVICE_17AA200F";
        case PciSubDevice808627DA::SUBDEVICE_80864F4D: return "SUBDEVICE_80864F4D";
        case PciSubDevice808627DA::SUBDEVICE_8086544B: return "SUBDEVICE_8086544B";
        case PciSubDevice808627DA::SUBDEVICE_8086544E: return "SUBDEVICE_8086544E";
        case PciSubDevice808627DA::SUBDEVICE_80865842: return "SUBDEVICE_80865842";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice808627DA subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice808627DA subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808627DA::SUBDEVICE_1025006C: return "9814 WKMI";
        case PciSubDevice808627DA::SUBDEVICE_102801AD: return "OptiPlex GX620";
        case PciSubDevice808627DA::SUBDEVICE_102801D7: return "XPS M1210";
        case PciSubDevice808627DA::SUBDEVICE_102801DF: return "PowerEdge SC440";
        case PciSubDevice808627DA::SUBDEVICE_102801E6: return "PowerEdge 860";
        case PciSubDevice808627DA::SUBDEVICE_103C2A3B: return "Pavilion A1512X";
        case PciSubDevice808627DA::SUBDEVICE_103C2A8C: return "Compaq 500B Microtower";
        case PciSubDevice808627DA::SUBDEVICE_10438179: return "P5B-MX/WiFi-AP, P5KPL-VM Motherboard";
        case PciSubDevice808627DA::SUBDEVICE_105B0D7C: return "D270S/D250S Motherboard";
        case PciSubDevice808627DA::SUBDEVICE_10718209: return "Medion MIM 2240 Notebook PC [MD98100]";
        case PciSubDevice808627DA::SUBDEVICE_10F78338: return "Panasonic CF-Y5 laptop";
        case PciSubDevice808627DA::SUBDEVICE_144DC072: return "Notebook N150P";
        case PciSubDevice808627DA::SUBDEVICE_14585001: return "GA-8I945PG-RH/GA-D525TUD Mainboard";
        case PciSubDevice808627DA::SUBDEVICE_14627418: return "Wind PC MS-7418";
        case PciSubDevice808627DA::SUBDEVICE_177511CC: return "CC11/CL11";
        case PciSubDevice808627DA::SUBDEVICE_17AA200F: return "ThinkPad R60/T60/X60 series";
        case PciSubDevice808627DA::SUBDEVICE_80864F4D: return "DeskTop Board D510MO";
        case PciSubDevice808627DA::SUBDEVICE_8086544B: return "Desktop Board D425KT";
        case PciSubDevice808627DA::SUBDEVICE_8086544E: return "DeskTop Board D945GTP";
        case PciSubDevice808627DA::SUBDEVICE_80865842: return "DeskTop Board D975XBX";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808627DA_H
