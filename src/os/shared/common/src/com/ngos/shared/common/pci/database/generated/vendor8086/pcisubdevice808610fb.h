// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808610FB_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808610FB_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice808610FB: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10281F72 = 0x10281F72,
    SUBDEVICE_103C17D0 = 0x103C17D0,
    SUBDEVICE_103C17D2 = 0x103C17D2,
    SUBDEVICE_103C17D3 = 0x103C17D3,
    SUBDEVICE_103C211B = 0x103C211B,
    SUBDEVICE_103C2147 = 0x103C2147,
    SUBDEVICE_103C2159 = 0x103C2159,
    SUBDEVICE_108E7B11 = 0x108E7B11,
    SUBDEVICE_1170004C = 0x1170004C,
    SUBDEVICE_15D90611 = 0x15D90611,
    SUBDEVICE_173411A9 = 0x173411A9,
    SUBDEVICE_17AA1071 = 0x17AA1071,
    SUBDEVICE_17AA4007 = 0x17AA4007,
    SUBDEVICE_17AA402B = 0x17AA402B,
    SUBDEVICE_17AA402F = 0x17AA402F,
    SUBDEVICE_18D40C09 = 0x18D40C09,
    SUBDEVICE_193D1004 = 0x193D1004,
    SUBDEVICE_1BD4001B = 0x1BD4001B,
    SUBDEVICE_1BD4002F = 0x1BD4002F,
    SUBDEVICE_1BD40032 = 0x1BD40032,
    SUBDEVICE_80860002 = 0x80860002,
    SUBDEVICE_80860003 = 0x80860003,
    SUBDEVICE_80860006 = 0x80860006,
    SUBDEVICE_80860008 = 0x80860008,
    SUBDEVICE_8086000A = 0x8086000A,
    SUBDEVICE_8086000C = 0x8086000C,
    SUBDEVICE_808610A6 = 0x808610A6,
    SUBDEVICE_80867A11 = 0x80867A11,
    SUBDEVICE_80867A12 = 0x80867A12
};



inline const char8* enumToString(PciSubDevice808610FB subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808610FB::NONE:               return "NONE";
        case PciSubDevice808610FB::SUBDEVICE_10281F72: return "SUBDEVICE_10281F72";
        case PciSubDevice808610FB::SUBDEVICE_103C17D0: return "SUBDEVICE_103C17D0";
        case PciSubDevice808610FB::SUBDEVICE_103C17D2: return "SUBDEVICE_103C17D2";
        case PciSubDevice808610FB::SUBDEVICE_103C17D3: return "SUBDEVICE_103C17D3";
        case PciSubDevice808610FB::SUBDEVICE_103C211B: return "SUBDEVICE_103C211B";
        case PciSubDevice808610FB::SUBDEVICE_103C2147: return "SUBDEVICE_103C2147";
        case PciSubDevice808610FB::SUBDEVICE_103C2159: return "SUBDEVICE_103C2159";
        case PciSubDevice808610FB::SUBDEVICE_108E7B11: return "SUBDEVICE_108E7B11";
        case PciSubDevice808610FB::SUBDEVICE_1170004C: return "SUBDEVICE_1170004C";
        case PciSubDevice808610FB::SUBDEVICE_15D90611: return "SUBDEVICE_15D90611";
        case PciSubDevice808610FB::SUBDEVICE_173411A9: return "SUBDEVICE_173411A9";
        case PciSubDevice808610FB::SUBDEVICE_17AA1071: return "SUBDEVICE_17AA1071";
        case PciSubDevice808610FB::SUBDEVICE_17AA4007: return "SUBDEVICE_17AA4007";
        case PciSubDevice808610FB::SUBDEVICE_17AA402B: return "SUBDEVICE_17AA402B";
        case PciSubDevice808610FB::SUBDEVICE_17AA402F: return "SUBDEVICE_17AA402F";
        case PciSubDevice808610FB::SUBDEVICE_18D40C09: return "SUBDEVICE_18D40C09";
        case PciSubDevice808610FB::SUBDEVICE_193D1004: return "SUBDEVICE_193D1004";
        case PciSubDevice808610FB::SUBDEVICE_1BD4001B: return "SUBDEVICE_1BD4001B";
        case PciSubDevice808610FB::SUBDEVICE_1BD4002F: return "SUBDEVICE_1BD4002F";
        case PciSubDevice808610FB::SUBDEVICE_1BD40032: return "SUBDEVICE_1BD40032";
        case PciSubDevice808610FB::SUBDEVICE_80860002: return "SUBDEVICE_80860002";
        case PciSubDevice808610FB::SUBDEVICE_80860003: return "SUBDEVICE_80860003";
        case PciSubDevice808610FB::SUBDEVICE_80860006: return "SUBDEVICE_80860006";
        case PciSubDevice808610FB::SUBDEVICE_80860008: return "SUBDEVICE_80860008";
        case PciSubDevice808610FB::SUBDEVICE_8086000A: return "SUBDEVICE_8086000A";
        case PciSubDevice808610FB::SUBDEVICE_8086000C: return "SUBDEVICE_8086000C";
        case PciSubDevice808610FB::SUBDEVICE_808610A6: return "SUBDEVICE_808610A6";
        case PciSubDevice808610FB::SUBDEVICE_80867A11: return "SUBDEVICE_80867A11";
        case PciSubDevice808610FB::SUBDEVICE_80867A12: return "SUBDEVICE_80867A12";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice808610FB subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice808610FB subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808610FB::SUBDEVICE_10281F72: return "Ethernet 10G 4P X520/I350 rNDC";
        case PciSubDevice808610FB::SUBDEVICE_103C17D0: return "Ethernet 10Gb 2-port 560FLR-SFP+ Adapter";
        case PciSubDevice808610FB::SUBDEVICE_103C17D2: return "Ethernet 10Gb 2-port 560M Adapter";
        case PciSubDevice808610FB::SUBDEVICE_103C17D3: return "Ethernet 10Gb 2-port 560SFP+ Adapter";
        case PciSubDevice808610FB::SUBDEVICE_103C211B: return "Ethernet 10Gb 1-port P560FLR-SFP+ Adapter";
        case PciSubDevice808610FB::SUBDEVICE_103C2147: return "Ethernet 10Gb 1-port 561i Adapter";
        case PciSubDevice808610FB::SUBDEVICE_103C2159: return "Ethernet 10Gb 2-port 562i Adapter";
        case PciSubDevice808610FB::SUBDEVICE_108E7B11: return "Ethernet Server Adapter X520-2";
        case PciSubDevice808610FB::SUBDEVICE_1170004C: return "82599 DP 10G Mezzanine Adapter";
        case PciSubDevice808610FB::SUBDEVICE_15D90611: return "AOC-STGN-I2S [REV 1.01]";
        case PciSubDevice808610FB::SUBDEVICE_173411A9: return "10 Gigabit Dual Port Network Connection";
        case PciSubDevice808610FB::SUBDEVICE_17AA1071: return "ThinkServer X520-2 AnyFabric";
        case PciSubDevice808610FB::SUBDEVICE_17AA4007: return "82599ES 10-Gigabit SFI/SFP+ Network Connection";
        case PciSubDevice808610FB::SUBDEVICE_17AA402B: return "82599ES 10Gb 2-port Server Adapter X520-DA2";
        case PciSubDevice808610FB::SUBDEVICE_17AA402F: return "FPGA Card XC7VX690T-3FFG1157E";
        case PciSubDevice808610FB::SUBDEVICE_18D40C09: return "82599ES 10Gb 2-port SFP+ OCP Mezz Card MOP81-I-10GS2";
        case PciSubDevice808610FB::SUBDEVICE_193D1004: return "560F-B";
        case PciSubDevice808610FB::SUBDEVICE_1BD4001B: return "10G SFP+ DP ER102Fi4 Rack Adapter";
        case PciSubDevice808610FB::SUBDEVICE_1BD4002F: return "10G SFP+ DP EP102Fi4A Adapter";
        case PciSubDevice808610FB::SUBDEVICE_1BD40032: return "10G SFP+ DP EP102Fi4 Adapter";
        case PciSubDevice808610FB::SUBDEVICE_80860002: return "Ethernet Server Adapter X520-DA2";
        case PciSubDevice808610FB::SUBDEVICE_80860003: return "Ethernet Server Adapter X520-2";
        case PciSubDevice808610FB::SUBDEVICE_80860006: return "Ethernet Server Adapter X520-1";
        case PciSubDevice808610FB::SUBDEVICE_80860008: return "Ethernet OCP Server Adapter X520-2";
        case PciSubDevice808610FB::SUBDEVICE_8086000A: return "Ethernet Server Adapter X520-1";
        case PciSubDevice808610FB::SUBDEVICE_8086000C: return "Ethernet Server Adapter X520-2";
        case PciSubDevice808610FB::SUBDEVICE_808610A6: return "82599ES 10Gb 2 port Server Adapter X520-DA2";
        case PciSubDevice808610FB::SUBDEVICE_80867A11: return "Ethernet Server Adapter X520-2";
        case PciSubDevice808610FB::SUBDEVICE_80867A12: return "Ethernet Server Adapter X520-2";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808610FB_H
