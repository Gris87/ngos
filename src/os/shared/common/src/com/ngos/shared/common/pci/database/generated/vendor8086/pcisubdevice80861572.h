// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861572_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861572_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80861572: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10280000 = 0x10280000,
    SUBDEVICE_10281F99 = 0x10281F99,
    SUBDEVICE_10281F9C = 0x10281F9C,
    SUBDEVICE_103C0000 = 0x103C0000,
    SUBDEVICE_103C22FC = 0x103C22FC,
    SUBDEVICE_103C22FD = 0x103C22FD,
    SUBDEVICE_11370000 = 0x11370000,
    SUBDEVICE_1137013B = 0x1137013B,
    SUBDEVICE_1137020A = 0x1137020A,
    SUBDEVICE_15900000 = 0x15900000,
    SUBDEVICE_15900225 = 0x15900225,
    SUBDEVICE_1590022F = 0x1590022F,
    SUBDEVICE_17AA0000 = 0x17AA0000,
    SUBDEVICE_17AA4001 = 0x17AA4001,
    SUBDEVICE_17AA4002 = 0x17AA4002,
    SUBDEVICE_19E5D11C = 0x19E5D11C,
    SUBDEVICE_1BD40056 = 0x1BD40056,
    SUBDEVICE_80860000 = 0x80860000,
    SUBDEVICE_80860001 = 0x80860001,
    SUBDEVICE_80860002 = 0x80860002,
    SUBDEVICE_80860004 = 0x80860004,
    SUBDEVICE_80860005 = 0x80860005,
    SUBDEVICE_80860006 = 0x80860006,
    SUBDEVICE_80860007 = 0x80860007,
    SUBDEVICE_80860008 = 0x80860008,
    SUBDEVICE_80860009 = 0x80860009,
    SUBDEVICE_8086000A = 0x8086000A,
    SUBDEVICE_8086000B = 0x8086000B,
    SUBDEVICE_8086000D = 0x8086000D,
    SUBDEVICE_8086000E = 0x8086000E,
    SUBDEVICE_8086000F = 0x8086000F,
    SUBDEVICE_80860010 = 0x80860010,
    SUBDEVICE_80860011 = 0x80860011,
    SUBDEVICE_80860012 = 0x80860012,
    SUBDEVICE_80860013 = 0x80860013,
    SUBDEVICE_80860014 = 0x80860014,
    SUBDEVICE_80860015 = 0x80860015,
    SUBDEVICE_808600A1 = 0x808600A1,
    SUBDEVICE_808600A2 = 0x808600A2,
    SUBDEVICE_80864005 = 0x80864005,
    SUBDEVICE_80864006 = 0x80864006,
    SUBDEVICE_80864007 = 0x80864007
};



inline const char8* enumToString(PciSubDevice80861572 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861572::NONE:               return "NONE";
        case PciSubDevice80861572::SUBDEVICE_10280000: return "SUBDEVICE_10280000";
        case PciSubDevice80861572::SUBDEVICE_10281F99: return "SUBDEVICE_10281F99";
        case PciSubDevice80861572::SUBDEVICE_10281F9C: return "SUBDEVICE_10281F9C";
        case PciSubDevice80861572::SUBDEVICE_103C0000: return "SUBDEVICE_103C0000";
        case PciSubDevice80861572::SUBDEVICE_103C22FC: return "SUBDEVICE_103C22FC";
        case PciSubDevice80861572::SUBDEVICE_103C22FD: return "SUBDEVICE_103C22FD";
        case PciSubDevice80861572::SUBDEVICE_11370000: return "SUBDEVICE_11370000";
        case PciSubDevice80861572::SUBDEVICE_1137013B: return "SUBDEVICE_1137013B";
        case PciSubDevice80861572::SUBDEVICE_1137020A: return "SUBDEVICE_1137020A";
        case PciSubDevice80861572::SUBDEVICE_15900000: return "SUBDEVICE_15900000";
        case PciSubDevice80861572::SUBDEVICE_15900225: return "SUBDEVICE_15900225";
        case PciSubDevice80861572::SUBDEVICE_1590022F: return "SUBDEVICE_1590022F";
        case PciSubDevice80861572::SUBDEVICE_17AA0000: return "SUBDEVICE_17AA0000";
        case PciSubDevice80861572::SUBDEVICE_17AA4001: return "SUBDEVICE_17AA4001";
        case PciSubDevice80861572::SUBDEVICE_17AA4002: return "SUBDEVICE_17AA4002";
        case PciSubDevice80861572::SUBDEVICE_19E5D11C: return "SUBDEVICE_19E5D11C";
        case PciSubDevice80861572::SUBDEVICE_1BD40056: return "SUBDEVICE_1BD40056";
        case PciSubDevice80861572::SUBDEVICE_80860000: return "SUBDEVICE_80860000";
        case PciSubDevice80861572::SUBDEVICE_80860001: return "SUBDEVICE_80860001";
        case PciSubDevice80861572::SUBDEVICE_80860002: return "SUBDEVICE_80860002";
        case PciSubDevice80861572::SUBDEVICE_80860004: return "SUBDEVICE_80860004";
        case PciSubDevice80861572::SUBDEVICE_80860005: return "SUBDEVICE_80860005";
        case PciSubDevice80861572::SUBDEVICE_80860006: return "SUBDEVICE_80860006";
        case PciSubDevice80861572::SUBDEVICE_80860007: return "SUBDEVICE_80860007";
        case PciSubDevice80861572::SUBDEVICE_80860008: return "SUBDEVICE_80860008";
        case PciSubDevice80861572::SUBDEVICE_80860009: return "SUBDEVICE_80860009";
        case PciSubDevice80861572::SUBDEVICE_8086000A: return "SUBDEVICE_8086000A";
        case PciSubDevice80861572::SUBDEVICE_8086000B: return "SUBDEVICE_8086000B";
        case PciSubDevice80861572::SUBDEVICE_8086000D: return "SUBDEVICE_8086000D";
        case PciSubDevice80861572::SUBDEVICE_8086000E: return "SUBDEVICE_8086000E";
        case PciSubDevice80861572::SUBDEVICE_8086000F: return "SUBDEVICE_8086000F";
        case PciSubDevice80861572::SUBDEVICE_80860010: return "SUBDEVICE_80860010";
        case PciSubDevice80861572::SUBDEVICE_80860011: return "SUBDEVICE_80860011";
        case PciSubDevice80861572::SUBDEVICE_80860012: return "SUBDEVICE_80860012";
        case PciSubDevice80861572::SUBDEVICE_80860013: return "SUBDEVICE_80860013";
        case PciSubDevice80861572::SUBDEVICE_80860014: return "SUBDEVICE_80860014";
        case PciSubDevice80861572::SUBDEVICE_80860015: return "SUBDEVICE_80860015";
        case PciSubDevice80861572::SUBDEVICE_808600A1: return "SUBDEVICE_808600A1";
        case PciSubDevice80861572::SUBDEVICE_808600A2: return "SUBDEVICE_808600A2";
        case PciSubDevice80861572::SUBDEVICE_80864005: return "SUBDEVICE_80864005";
        case PciSubDevice80861572::SUBDEVICE_80864006: return "SUBDEVICE_80864006";
        case PciSubDevice80861572::SUBDEVICE_80864007: return "SUBDEVICE_80864007";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80861572 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80861572 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861572::SUBDEVICE_10280000: return "Ethernet 10G X710 rNDC";
        case PciSubDevice80861572::SUBDEVICE_10281F99: return "Ethernet 10G 4P X710/I350 rNDC";
        case PciSubDevice80861572::SUBDEVICE_10281F9C: return "Ethernet 10G 4P X710 SFP+ rNDC";
        case PciSubDevice80861572::SUBDEVICE_103C0000: return "Ethernet 10Gb 562SFP+ Adapter";
        case PciSubDevice80861572::SUBDEVICE_103C22FC: return "Ethernet 10Gb 2-port 562FLR-SFP+ Adapter";
        case PciSubDevice80861572::SUBDEVICE_103C22FD: return "Ethernet 10Gb 2-port 562SFP+ Adapter";
        case PciSubDevice80861572::SUBDEVICE_11370000: return "Ethernet Converged NIC X710-DA";
        case PciSubDevice80861572::SUBDEVICE_1137013B: return "Ethernet Converged NIC X710-DA4";
        case PciSubDevice80861572::SUBDEVICE_1137020A: return "Ethernet Converged NIC X710-DA2";
        case PciSubDevice80861572::SUBDEVICE_15900000: return "Ethernet Controller X710 for 10GbE SFP+";
        case PciSubDevice80861572::SUBDEVICE_15900225: return "Ethernet 10GbE 4P 563SFP+ Adapter";
        case PciSubDevice80861572::SUBDEVICE_1590022F: return "Ethernet 10Gb 2-port 564i Communication Board";
        case PciSubDevice80861572::SUBDEVICE_17AA0000: return "ThinkServer X710 AnyFabric for 10GbE SFP+";
        case PciSubDevice80861572::SUBDEVICE_17AA4001: return "ThinkServer X710-4 AnyFabric for 10GbE SFP+";
        case PciSubDevice80861572::SUBDEVICE_17AA4002: return "ThinkServer X710-2 AnyFabric for 10GbE SFP+";
        case PciSubDevice80861572::SUBDEVICE_19E5D11C: return "Ethernet 2-port X710 10Gb SFP+ Adapter SP330";
        case PciSubDevice80861572::SUBDEVICE_1BD40056: return "Ethernet Network Adapter X710-BM2 for OCP NIC 3.0";
        case PciSubDevice80861572::SUBDEVICE_80860000: return "Ethernet Converged Network Adapter X710";
        case PciSubDevice80861572::SUBDEVICE_80860001: return "Ethernet Converged Network Adapter X710-4";
        case PciSubDevice80861572::SUBDEVICE_80860002: return "Ethernet Converged Network Adapter X710-4";
        case PciSubDevice80861572::SUBDEVICE_80860004: return "Ethernet Converged Network Adapter X710-4";
        case PciSubDevice80861572::SUBDEVICE_80860005: return "Ethernet 10G 4P X710 Adapter";
        case PciSubDevice80861572::SUBDEVICE_80860006: return "Ethernet 10G 2P X710 Adapter";
        case PciSubDevice80861572::SUBDEVICE_80860007: return "Ethernet Converged Network Adapter X710-2";
        case PciSubDevice80861572::SUBDEVICE_80860008: return "Ethernet Converged Network Adapter X710-2";
        case PciSubDevice80861572::SUBDEVICE_80860009: return "Ethernet Controller X710 for 10GbE SFP+";
        case PciSubDevice80861572::SUBDEVICE_8086000A: return "Ethernet Controller X710 for 10GbE SFP+";
        case PciSubDevice80861572::SUBDEVICE_8086000B: return "Ethernet Server Adapter X710-DA2 for OCP";
        case PciSubDevice80861572::SUBDEVICE_8086000D: return "Ethernet Controller X710 for 10GbE SFP+";
        case PciSubDevice80861572::SUBDEVICE_8086000E: return "Ethernet Server Adapter OCP X710-2";
        case PciSubDevice80861572::SUBDEVICE_8086000F: return "Ethernet Server Adapter OCP X710-2";
        case PciSubDevice80861572::SUBDEVICE_80860010: return "Ethernet Converged Network Adapter X710";
        case PciSubDevice80861572::SUBDEVICE_80860011: return "Ethernet Network Adapter X710-2 for OCP NIC 3.0";
        case PciSubDevice80861572::SUBDEVICE_80860012: return "Ethernet Network Adapter X710-4 for OCP NIC 3.0";
        case PciSubDevice80861572::SUBDEVICE_80860013: return "Ethernet 10G 2P X710 OCP";
        case PciSubDevice80861572::SUBDEVICE_80860014: return "Ethernet 10G 4P X710 OCP";
        case PciSubDevice80861572::SUBDEVICE_80860015: return "Ethernet Server Adapter X710-DA2 for OCP";
        case PciSubDevice80861572::SUBDEVICE_808600A1: return "Ethernet Network Adapter X710-2 for OCP NIC 3.0";
        case PciSubDevice80861572::SUBDEVICE_808600A2: return "Ethernet Network Adapter X710-4 for OCP NIC 3.0";
        case PciSubDevice80861572::SUBDEVICE_80864005: return "Ethernet Controller X710 for 10GbE SFP+";
        case PciSubDevice80861572::SUBDEVICE_80864006: return "Ethernet Controller X710 for 10GbE SFP+";
        case PciSubDevice80861572::SUBDEVICE_80864007: return "Ethernet Controller X710 for 10GbE SFP+";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861572_H
