// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861528_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861528_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80861528: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10281F61 = 0x10281F61,
    SUBDEVICE_103C192D = 0x103C192D,
    SUBDEVICE_103C2004 = 0x103C2004,
    SUBDEVICE_103C211A = 0x103C211A,
    SUBDEVICE_108E4853 = 0x108E4853,
    SUBDEVICE_108E7B14 = 0x108E7B14,
    SUBDEVICE_108E7B15 = 0x108E7B15,
    SUBDEVICE_113700BF = 0x113700BF,
    SUBDEVICE_11700052 = 0x11700052,
    SUBDEVICE_15D90734 = 0x15D90734,
    SUBDEVICE_17AA1073 = 0x17AA1073,
    SUBDEVICE_17AA4006 = 0x17AA4006,
    SUBDEVICE_1BD4001A = 0x1BD4001A,
    SUBDEVICE_1BD40033 = 0x1BD40033,
    SUBDEVICE_1BD40034 = 0x1BD40034,
    SUBDEVICE_80860001 = 0x80860001,
    SUBDEVICE_80860002 = 0x80860002,
    SUBDEVICE_8086001A = 0x8086001A,
    SUBDEVICE_808600A2 = 0x808600A2,
    SUBDEVICE_80861F61 = 0x80861F61,
    SUBDEVICE_80865003 = 0x80865003,
    SUBDEVICE_80865004 = 0x80865004
};



inline const char8* enumToString(PciSubDevice80861528 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861528::NONE:               return "NONE";
        case PciSubDevice80861528::SUBDEVICE_10281F61: return "SUBDEVICE_10281F61";
        case PciSubDevice80861528::SUBDEVICE_103C192D: return "SUBDEVICE_103C192D";
        case PciSubDevice80861528::SUBDEVICE_103C2004: return "SUBDEVICE_103C2004";
        case PciSubDevice80861528::SUBDEVICE_103C211A: return "SUBDEVICE_103C211A";
        case PciSubDevice80861528::SUBDEVICE_108E4853: return "SUBDEVICE_108E4853";
        case PciSubDevice80861528::SUBDEVICE_108E7B14: return "SUBDEVICE_108E7B14";
        case PciSubDevice80861528::SUBDEVICE_108E7B15: return "SUBDEVICE_108E7B15";
        case PciSubDevice80861528::SUBDEVICE_113700BF: return "SUBDEVICE_113700BF";
        case PciSubDevice80861528::SUBDEVICE_11700052: return "SUBDEVICE_11700052";
        case PciSubDevice80861528::SUBDEVICE_15D90734: return "SUBDEVICE_15D90734";
        case PciSubDevice80861528::SUBDEVICE_17AA1073: return "SUBDEVICE_17AA1073";
        case PciSubDevice80861528::SUBDEVICE_17AA4006: return "SUBDEVICE_17AA4006";
        case PciSubDevice80861528::SUBDEVICE_1BD4001A: return "SUBDEVICE_1BD4001A";
        case PciSubDevice80861528::SUBDEVICE_1BD40033: return "SUBDEVICE_1BD40033";
        case PciSubDevice80861528::SUBDEVICE_1BD40034: return "SUBDEVICE_1BD40034";
        case PciSubDevice80861528::SUBDEVICE_80860001: return "SUBDEVICE_80860001";
        case PciSubDevice80861528::SUBDEVICE_80860002: return "SUBDEVICE_80860002";
        case PciSubDevice80861528::SUBDEVICE_8086001A: return "SUBDEVICE_8086001A";
        case PciSubDevice80861528::SUBDEVICE_808600A2: return "SUBDEVICE_808600A2";
        case PciSubDevice80861528::SUBDEVICE_80861F61: return "SUBDEVICE_80861F61";
        case PciSubDevice80861528::SUBDEVICE_80865003: return "SUBDEVICE_80865003";
        case PciSubDevice80861528::SUBDEVICE_80865004: return "SUBDEVICE_80865004";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80861528 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80861528 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861528::SUBDEVICE_10281F61: return "Ethernet 10G 4P X540/I350 rNDC";
        case PciSubDevice80861528::SUBDEVICE_103C192D: return "561FLR-T 2-port 10Gb Ethernet Adapter";
        case PciSubDevice80861528::SUBDEVICE_103C2004: return "Ethernet 10Gb 2-port 561i Adapter";
        case PciSubDevice80861528::SUBDEVICE_103C211A: return "Ethernet 10Gb 2-port 561T Adapter";
        case PciSubDevice80861528::SUBDEVICE_108E4853: return "Ethernet Controller 10-Gigabit X540-AT2";
        case PciSubDevice80861528::SUBDEVICE_108E7B14: return "Sun Dual Port 10 GbE PCIe 2.0 ExpressModule, Base-T";
        case PciSubDevice80861528::SUBDEVICE_108E7B15: return "Sun Dual Port 10 GbE PCIe 2.0 Low Profile Adapter, Base-T";
        case PciSubDevice80861528::SUBDEVICE_113700BF: return "Ethernet Converged Network Adapter X540-T2";
        case PciSubDevice80861528::SUBDEVICE_11700052: return "Ethernet Controller 10-Gigabit X540-AT2";
        case PciSubDevice80861528::SUBDEVICE_15D90734: return "AOC-STG-I2T";
        case PciSubDevice80861528::SUBDEVICE_17AA1073: return "ThinkServer X540-T2 AnyFabric";
        case PciSubDevice80861528::SUBDEVICE_17AA4006: return "Ethernet Controller 10-Gigabit X540-AT2";
        case PciSubDevice80861528::SUBDEVICE_1BD4001A: return "10G base-T DP ER102Ti3 Rack Adapter";
        case PciSubDevice80861528::SUBDEVICE_1BD40033: return "10G base-T DP EP102Ti3 Adapter";
        case PciSubDevice80861528::SUBDEVICE_1BD40034: return "10G base-T DP EP102Ti3A Adapter";
        case PciSubDevice80861528::SUBDEVICE_80860001: return "Ethernet Converged Network Adapter X540-T2";
        case PciSubDevice80861528::SUBDEVICE_80860002: return "Ethernet Converged Network Adapter X540-T1";
        case PciSubDevice80861528::SUBDEVICE_8086001A: return "Ethernet Converged Network Adapter X540-T2";
        case PciSubDevice80861528::SUBDEVICE_808600A2: return "Ethernet Converged Network Adapter X540-T1";
        case PciSubDevice80861528::SUBDEVICE_80861F61: return "Ethernet 10G 4P X540/I350 rNDC";
        case PciSubDevice80861528::SUBDEVICE_80865003: return "Ethernet 10G 2P X540-t Adapter";
        case PciSubDevice80861528::SUBDEVICE_80865004: return "Ethernet 10G 2P X540-t Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861528_H
