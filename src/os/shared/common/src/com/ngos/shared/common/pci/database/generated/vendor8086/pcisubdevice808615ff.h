// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808615FF_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808615FF_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice808615FF: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_11370000 = 0x11370000,
    SUBDEVICE_113702C1 = 0x113702C1,
    SUBDEVICE_113702C2 = 0x113702C2,
    SUBDEVICE_113702D9 = 0x113702D9,
    SUBDEVICE_113702DA = 0x113702DA,
    SUBDEVICE_193D1082 = 0x193D1082,
    SUBDEVICE_80860000 = 0x80860000,
    SUBDEVICE_80860001 = 0x80860001,
    SUBDEVICE_80860002 = 0x80860002,
    SUBDEVICE_80860003 = 0x80860003,
    SUBDEVICE_80860004 = 0x80860004,
    SUBDEVICE_80860005 = 0x80860005,
    SUBDEVICE_80860006 = 0x80860006,
    SUBDEVICE_80860007 = 0x80860007,
    SUBDEVICE_80860008 = 0x80860008,
    SUBDEVICE_80860009 = 0x80860009,
    SUBDEVICE_8086000A = 0x8086000A,
    SUBDEVICE_8086000B = 0x8086000B,
    SUBDEVICE_8086000C = 0x8086000C,
    SUBDEVICE_8086000F = 0x8086000F
};



inline const char8* enumToString(PciSubDevice808615FF subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808615FF::NONE:               return "NONE";
        case PciSubDevice808615FF::SUBDEVICE_11370000: return "SUBDEVICE_11370000";
        case PciSubDevice808615FF::SUBDEVICE_113702C1: return "SUBDEVICE_113702C1";
        case PciSubDevice808615FF::SUBDEVICE_113702C2: return "SUBDEVICE_113702C2";
        case PciSubDevice808615FF::SUBDEVICE_113702D9: return "SUBDEVICE_113702D9";
        case PciSubDevice808615FF::SUBDEVICE_113702DA: return "SUBDEVICE_113702DA";
        case PciSubDevice808615FF::SUBDEVICE_193D1082: return "SUBDEVICE_193D1082";
        case PciSubDevice808615FF::SUBDEVICE_80860000: return "SUBDEVICE_80860000";
        case PciSubDevice808615FF::SUBDEVICE_80860001: return "SUBDEVICE_80860001";
        case PciSubDevice808615FF::SUBDEVICE_80860002: return "SUBDEVICE_80860002";
        case PciSubDevice808615FF::SUBDEVICE_80860003: return "SUBDEVICE_80860003";
        case PciSubDevice808615FF::SUBDEVICE_80860004: return "SUBDEVICE_80860004";
        case PciSubDevice808615FF::SUBDEVICE_80860005: return "SUBDEVICE_80860005";
        case PciSubDevice808615FF::SUBDEVICE_80860006: return "SUBDEVICE_80860006";
        case PciSubDevice808615FF::SUBDEVICE_80860007: return "SUBDEVICE_80860007";
        case PciSubDevice808615FF::SUBDEVICE_80860008: return "SUBDEVICE_80860008";
        case PciSubDevice808615FF::SUBDEVICE_80860009: return "SUBDEVICE_80860009";
        case PciSubDevice808615FF::SUBDEVICE_8086000A: return "SUBDEVICE_8086000A";
        case PciSubDevice808615FF::SUBDEVICE_8086000B: return "SUBDEVICE_8086000B";
        case PciSubDevice808615FF::SUBDEVICE_8086000C: return "SUBDEVICE_8086000C";
        case PciSubDevice808615FF::SUBDEVICE_8086000F: return "SUBDEVICE_8086000F";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice808615FF subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice808615FF subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808615FF::SUBDEVICE_11370000: return "X710TLG GbE RJ45 PCIe NIC";
        case PciSubDevice808615FF::SUBDEVICE_113702C1: return "X710T2LG 2x10 GbE RJ45 PCIe NIC";
        case PciSubDevice808615FF::SUBDEVICE_113702C2: return "X710T4LG 4x10 GbE RJ45 PCIe NIC";
        case PciSubDevice808615FF::SUBDEVICE_113702D9: return "Ethernet Network Adapter X710-T2L OCP 3.0";
        case PciSubDevice808615FF::SUBDEVICE_113702DA: return "Ethernet Network Adapter X710-T4L OCP 3.0";
        case PciSubDevice808615FF::SUBDEVICE_193D1082: return "NIC-ETH565T-3S-2P";
        case PciSubDevice808615FF::SUBDEVICE_80860000: return "Ethernet Network Adapter X710-TL";
        case PciSubDevice808615FF::SUBDEVICE_80860001: return "Ethernet Network Adapter X710-T4L";
        case PciSubDevice808615FF::SUBDEVICE_80860002: return "Ethernet Network Adapter X710-T4L";
        case PciSubDevice808615FF::SUBDEVICE_80860003: return "Ethernet Network Adapter X710-T2L";
        case PciSubDevice808615FF::SUBDEVICE_80860004: return "Ethernet Network Adapter X710-T2L";
        case PciSubDevice808615FF::SUBDEVICE_80860005: return "Ethernet 10G 2P X710-T2L-t Adapter";
        case PciSubDevice808615FF::SUBDEVICE_80860006: return "Ethernet 10G 4P X710-T4L-t Adapter";
        case PciSubDevice808615FF::SUBDEVICE_80860007: return "Ethernet 10G 2P X710-T2L-t OCP";
        case PciSubDevice808615FF::SUBDEVICE_80860008: return "Ethernet 10G 4P X710-T4L-t OCP";
        case PciSubDevice808615FF::SUBDEVICE_80860009: return "Ethernet Network Adapter X710-T4L for OCP 3.0";
        case PciSubDevice808615FF::SUBDEVICE_8086000A: return "Ethernet Network Adapter X710-T4L for OCP 3.0";
        case PciSubDevice808615FF::SUBDEVICE_8086000B: return "Ethernet Network Adapter X710-T2L for OCP 3.0";
        case PciSubDevice808615FF::SUBDEVICE_8086000C: return "Ethernet Network Adapter X710-T2L for OCP 3.0";
        case PciSubDevice808615FF::SUBDEVICE_8086000F: return "Ethernet Network Adapter X710-T2L for OCP 3.0";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808615FF_H
