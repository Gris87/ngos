// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861521_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861521_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80861521: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10280602 = 0x10280602,
    SUBDEVICE_10280693 = 0x10280693,
    SUBDEVICE_102806E2 = 0x102806E2,
    SUBDEVICE_10280757 = 0x10280757,
    SUBDEVICE_1028075A = 0x1028075A,
    SUBDEVICE_10281F60 = 0x10281F60,
    SUBDEVICE_10281F62 = 0x10281F62,
    SUBDEVICE_10281FA8 = 0x10281FA8,
    SUBDEVICE_10281FA9 = 0x10281FA9,
    SUBDEVICE_10281FAA = 0x10281FAA,
    SUBDEVICE_1028FF9A = 0x1028FF9A,
    SUBDEVICE_103C17D1 = 0x103C17D1,
    SUBDEVICE_103C2003 = 0x103C2003,
    SUBDEVICE_103C2226 = 0x103C2226,
    SUBDEVICE_103C337F = 0x103C337F,
    SUBDEVICE_103C3380 = 0x103C3380,
    SUBDEVICE_103C339E = 0x103C339E,
    SUBDEVICE_103C8157 = 0x103C8157,
    SUBDEVICE_108E7B16 = 0x108E7B16,
    SUBDEVICE_108E7B18 = 0x108E7B18,
    SUBDEVICE_10937648 = 0x10937648,
    SUBDEVICE_10937649 = 0x10937649,
    SUBDEVICE_109376B1 = 0x109376B1,
    SUBDEVICE_1093775B = 0x1093775B,
    SUBDEVICE_10A9802A = 0x10A9802A,
    SUBDEVICE_1137023E = 0x1137023E,
    SUBDEVICE_15D90000 = 0x15D90000,
    SUBDEVICE_15D90652 = 0x15D90652,
    SUBDEVICE_17AA1074 = 0x17AA1074,
    SUBDEVICE_17AA4005 = 0x17AA4005,
    SUBDEVICE_18D40C07 = 0x18D40C07,
    SUBDEVICE_193D1005 = 0x193D1005,
    SUBDEVICE_193D1007 = 0x193D1007,
    SUBDEVICE_193D1080 = 0x193D1080,
    SUBDEVICE_1BD4001D = 0x1BD4001D,
    SUBDEVICE_1BD40035 = 0x1BD40035,
    SUBDEVICE_1BD40066 = 0x1BD40066,
    SUBDEVICE_80860001 = 0x80860001,
    SUBDEVICE_80860002 = 0x80860002,
    SUBDEVICE_80860003 = 0x80860003,
    SUBDEVICE_808600A1 = 0x808600A1,
    SUBDEVICE_808600A2 = 0x808600A2,
    SUBDEVICE_808600A3 = 0x808600A3,
    SUBDEVICE_808600AA = 0x808600AA,
    SUBDEVICE_80864017 = 0x80864017,
    SUBDEVICE_80865001 = 0x80865001,
    SUBDEVICE_80865002 = 0x80865002,
    SUBDEVICE_80865003 = 0x80865003
};



inline const char8* enumToString(PciSubDevice80861521 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861521::NONE:               return "NONE";
        case PciSubDevice80861521::SUBDEVICE_10280602: return "SUBDEVICE_10280602";
        case PciSubDevice80861521::SUBDEVICE_10280693: return "SUBDEVICE_10280693";
        case PciSubDevice80861521::SUBDEVICE_102806E2: return "SUBDEVICE_102806E2";
        case PciSubDevice80861521::SUBDEVICE_10280757: return "SUBDEVICE_10280757";
        case PciSubDevice80861521::SUBDEVICE_1028075A: return "SUBDEVICE_1028075A";
        case PciSubDevice80861521::SUBDEVICE_10281F60: return "SUBDEVICE_10281F60";
        case PciSubDevice80861521::SUBDEVICE_10281F62: return "SUBDEVICE_10281F62";
        case PciSubDevice80861521::SUBDEVICE_10281FA8: return "SUBDEVICE_10281FA8";
        case PciSubDevice80861521::SUBDEVICE_10281FA9: return "SUBDEVICE_10281FA9";
        case PciSubDevice80861521::SUBDEVICE_10281FAA: return "SUBDEVICE_10281FAA";
        case PciSubDevice80861521::SUBDEVICE_1028FF9A: return "SUBDEVICE_1028FF9A";
        case PciSubDevice80861521::SUBDEVICE_103C17D1: return "SUBDEVICE_103C17D1";
        case PciSubDevice80861521::SUBDEVICE_103C2003: return "SUBDEVICE_103C2003";
        case PciSubDevice80861521::SUBDEVICE_103C2226: return "SUBDEVICE_103C2226";
        case PciSubDevice80861521::SUBDEVICE_103C337F: return "SUBDEVICE_103C337F";
        case PciSubDevice80861521::SUBDEVICE_103C3380: return "SUBDEVICE_103C3380";
        case PciSubDevice80861521::SUBDEVICE_103C339E: return "SUBDEVICE_103C339E";
        case PciSubDevice80861521::SUBDEVICE_103C8157: return "SUBDEVICE_103C8157";
        case PciSubDevice80861521::SUBDEVICE_108E7B16: return "SUBDEVICE_108E7B16";
        case PciSubDevice80861521::SUBDEVICE_108E7B18: return "SUBDEVICE_108E7B18";
        case PciSubDevice80861521::SUBDEVICE_10937648: return "SUBDEVICE_10937648";
        case PciSubDevice80861521::SUBDEVICE_10937649: return "SUBDEVICE_10937649";
        case PciSubDevice80861521::SUBDEVICE_109376B1: return "SUBDEVICE_109376B1";
        case PciSubDevice80861521::SUBDEVICE_1093775B: return "SUBDEVICE_1093775B";
        case PciSubDevice80861521::SUBDEVICE_10A9802A: return "SUBDEVICE_10A9802A";
        case PciSubDevice80861521::SUBDEVICE_1137023E: return "SUBDEVICE_1137023E";
        case PciSubDevice80861521::SUBDEVICE_15D90000: return "SUBDEVICE_15D90000";
        case PciSubDevice80861521::SUBDEVICE_15D90652: return "SUBDEVICE_15D90652";
        case PciSubDevice80861521::SUBDEVICE_17AA1074: return "SUBDEVICE_17AA1074";
        case PciSubDevice80861521::SUBDEVICE_17AA4005: return "SUBDEVICE_17AA4005";
        case PciSubDevice80861521::SUBDEVICE_18D40C07: return "SUBDEVICE_18D40C07";
        case PciSubDevice80861521::SUBDEVICE_193D1005: return "SUBDEVICE_193D1005";
        case PciSubDevice80861521::SUBDEVICE_193D1007: return "SUBDEVICE_193D1007";
        case PciSubDevice80861521::SUBDEVICE_193D1080: return "SUBDEVICE_193D1080";
        case PciSubDevice80861521::SUBDEVICE_1BD4001D: return "SUBDEVICE_1BD4001D";
        case PciSubDevice80861521::SUBDEVICE_1BD40035: return "SUBDEVICE_1BD40035";
        case PciSubDevice80861521::SUBDEVICE_1BD40066: return "SUBDEVICE_1BD40066";
        case PciSubDevice80861521::SUBDEVICE_80860001: return "SUBDEVICE_80860001";
        case PciSubDevice80861521::SUBDEVICE_80860002: return "SUBDEVICE_80860002";
        case PciSubDevice80861521::SUBDEVICE_80860003: return "SUBDEVICE_80860003";
        case PciSubDevice80861521::SUBDEVICE_808600A1: return "SUBDEVICE_808600A1";
        case PciSubDevice80861521::SUBDEVICE_808600A2: return "SUBDEVICE_808600A2";
        case PciSubDevice80861521::SUBDEVICE_808600A3: return "SUBDEVICE_808600A3";
        case PciSubDevice80861521::SUBDEVICE_808600AA: return "SUBDEVICE_808600AA";
        case PciSubDevice80861521::SUBDEVICE_80864017: return "SUBDEVICE_80864017";
        case PciSubDevice80861521::SUBDEVICE_80865001: return "SUBDEVICE_80865001";
        case PciSubDevice80861521::SUBDEVICE_80865002: return "SUBDEVICE_80865002";
        case PciSubDevice80861521::SUBDEVICE_80865003: return "SUBDEVICE_80865003";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80861521 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80861521 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861521::SUBDEVICE_10280602: return "Gigabit 2P I350-t LOM";
        case PciSubDevice80861521::SUBDEVICE_10280693: return "Gigabit 2P I350-t LOM";
        case PciSubDevice80861521::SUBDEVICE_102806E2: return "Gigabit 2P I350-t LOM";
        case PciSubDevice80861521::SUBDEVICE_10280757: return "Gigabit I350-t LOM";
        case PciSubDevice80861521::SUBDEVICE_1028075A: return "Gigabit I350-t LOM";
        case PciSubDevice80861521::SUBDEVICE_10281F60: return "Gigabit 4P I350-t rNDC";
        case PciSubDevice80861521::SUBDEVICE_10281F62: return "Gigabit 4P X540/I350 rNDC";
        case PciSubDevice80861521::SUBDEVICE_10281FA8: return "Ethernet 10G 4P X550/I350 rNDC";
        case PciSubDevice80861521::SUBDEVICE_10281FA9: return "Ethernet 10G 4P X550 rNDC";
        case PciSubDevice80861521::SUBDEVICE_10281FAA: return "Gigabit 4P X550/I350 rNDC";
        case PciSubDevice80861521::SUBDEVICE_1028FF9A: return "Gigabit 4P X710/I350 rNDC";
        case PciSubDevice80861521::SUBDEVICE_103C17D1: return "Ethernet 1Gb 4-port 366FLR Adapter";
        case PciSubDevice80861521::SUBDEVICE_103C2003: return "Ethernet 1Gb 2-port 367i Adapter";
        case PciSubDevice80861521::SUBDEVICE_103C2226: return "Ethernet 1Gb 1-port 364i Adapter";
        case PciSubDevice80861521::SUBDEVICE_103C337F: return "Ethernet 1Gb 2-port 361i Adapter";
        case PciSubDevice80861521::SUBDEVICE_103C3380: return "Ethernet 1Gb 4-port 366i Adapter";
        case PciSubDevice80861521::SUBDEVICE_103C339E: return "Ethernet 1Gb 2-port 361T Adapter";
        case PciSubDevice80861521::SUBDEVICE_103C8157: return "Ethernet 1Gb 4-port 366T Adapter";
        case PciSubDevice80861521::SUBDEVICE_108E7B16: return "Quad Port GbE PCIe 2.0 ExpressModule, UTP";
        case PciSubDevice80861521::SUBDEVICE_108E7B18: return "Quad Port GbE PCIe 2.0 Low Profile Adapter, UTP";
        case PciSubDevice80861521::SUBDEVICE_10937648: return "PCIe-8237R Ethernet Adapter";
        case PciSubDevice80861521::SUBDEVICE_10937649: return "PCIe-8236 Ethernet Adapter";
        case PciSubDevice80861521::SUBDEVICE_109376B1: return "PCIe-8237R-S Ethernet Adapter";
        case PciSubDevice80861521::SUBDEVICE_1093775B: return "PCIe-8237 Ethernet Adapter";
        case PciSubDevice80861521::SUBDEVICE_10A9802A: return "UV2-BaseIO dual-port GbE";
        case PciSubDevice80861521::SUBDEVICE_1137023E: return "1GigE I350 LOM";
        case PciSubDevice80861521::SUBDEVICE_15D90000: return "AOC-SGP-i4";
        case PciSubDevice80861521::SUBDEVICE_15D90652: return "Dual Port i350 GbE MicroLP [AOC-CGP-i2]";
        case PciSubDevice80861521::SUBDEVICE_17AA1074: return "ThinkServer I350-T4 AnyFabric";
        case PciSubDevice80861521::SUBDEVICE_17AA4005: return "I350 Gigabit Network Connection";
        case PciSubDevice80861521::SUBDEVICE_18D40C07: return "I350 1Gb 2-port RJ45 OCP Mezz Card MOP41-I-1GT2";
        case PciSubDevice80861521::SUBDEVICE_193D1005: return "360T-B";
        case PciSubDevice80861521::SUBDEVICE_193D1007: return "360T-L";
        case PciSubDevice80861521::SUBDEVICE_193D1080: return "NIC-ETH360T-3S-4P";
        case PciSubDevice80861521::SUBDEVICE_1BD4001D: return "1G base-T QP EP014Ti1 Adapter";
        case PciSubDevice80861521::SUBDEVICE_1BD40035: return "1G base-T QP EP014Ti1 Adapter";
        case PciSubDevice80861521::SUBDEVICE_1BD40066: return "F014I350";
        case PciSubDevice80861521::SUBDEVICE_80860001: return "Ethernet Server Adapter I350-T4";
        case PciSubDevice80861521::SUBDEVICE_80860002: return "Ethernet Server Adapter I350-T2";
        case PciSubDevice80861521::SUBDEVICE_80860003: return "Ethernet Network Adapter I350-T4 for OCP NIC 3.0";
        case PciSubDevice80861521::SUBDEVICE_808600A1: return "Ethernet Server Adapter I350-T4";
        case PciSubDevice80861521::SUBDEVICE_808600A2: return "Ethernet Server Adapter I350-T2";
        case PciSubDevice80861521::SUBDEVICE_808600A3: return "Ethernet Network Adapter I350-T4 for OCP NIC 3.0";
        case PciSubDevice80861521::SUBDEVICE_808600AA: return "Ethernet Network Adapter I350-T4 for OCP NIC 3.0";
        case PciSubDevice80861521::SUBDEVICE_80864017: return "Ethernet Network Adapter I350-T4 for OCP NIC 3.0";
        case PciSubDevice80861521::SUBDEVICE_80865001: return "Ethernet Server Adapter I350-T4";
        case PciSubDevice80861521::SUBDEVICE_80865002: return "Ethernet Server Adapter I350-T2";
        case PciSubDevice80861521::SUBDEVICE_80865003: return "Ethernet 1G 4P I350-t OCP";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861521_H
