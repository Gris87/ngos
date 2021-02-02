// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086158B_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086158B_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice8086158B: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_11370000 = 0x11370000,
    SUBDEVICE_11370225 = 0x11370225,
    SUBDEVICE_113702B4 = 0x113702B4,
    SUBDEVICE_13740230 = 0x13740230,
    SUBDEVICE_13740231 = 0x13740231,
    SUBDEVICE_13740234 = 0x13740234,
    SUBDEVICE_13740235 = 0x13740235,
    SUBDEVICE_13740238 = 0x13740238,
    SUBDEVICE_13740239 = 0x13740239,
    SUBDEVICE_1374023A = 0x1374023A,
    SUBDEVICE_1374023B = 0x1374023B,
    SUBDEVICE_15900000 = 0x15900000,
    SUBDEVICE_15900253 = 0x15900253,
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
    SUBDEVICE_80864001 = 0x80864001
};



inline const char8* enumToString(PciSubDevice8086158B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086158B::NONE:               return "NONE";
        case PciSubDevice8086158B::SUBDEVICE_11370000: return "SUBDEVICE_11370000";
        case PciSubDevice8086158B::SUBDEVICE_11370225: return "SUBDEVICE_11370225";
        case PciSubDevice8086158B::SUBDEVICE_113702B4: return "SUBDEVICE_113702B4";
        case PciSubDevice8086158B::SUBDEVICE_13740230: return "SUBDEVICE_13740230";
        case PciSubDevice8086158B::SUBDEVICE_13740231: return "SUBDEVICE_13740231";
        case PciSubDevice8086158B::SUBDEVICE_13740234: return "SUBDEVICE_13740234";
        case PciSubDevice8086158B::SUBDEVICE_13740235: return "SUBDEVICE_13740235";
        case PciSubDevice8086158B::SUBDEVICE_13740238: return "SUBDEVICE_13740238";
        case PciSubDevice8086158B::SUBDEVICE_13740239: return "SUBDEVICE_13740239";
        case PciSubDevice8086158B::SUBDEVICE_1374023A: return "SUBDEVICE_1374023A";
        case PciSubDevice8086158B::SUBDEVICE_1374023B: return "SUBDEVICE_1374023B";
        case PciSubDevice8086158B::SUBDEVICE_15900000: return "SUBDEVICE_15900000";
        case PciSubDevice8086158B::SUBDEVICE_15900253: return "SUBDEVICE_15900253";
        case PciSubDevice8086158B::SUBDEVICE_80860000: return "SUBDEVICE_80860000";
        case PciSubDevice8086158B::SUBDEVICE_80860001: return "SUBDEVICE_80860001";
        case PciSubDevice8086158B::SUBDEVICE_80860002: return "SUBDEVICE_80860002";
        case PciSubDevice8086158B::SUBDEVICE_80860003: return "SUBDEVICE_80860003";
        case PciSubDevice8086158B::SUBDEVICE_80860004: return "SUBDEVICE_80860004";
        case PciSubDevice8086158B::SUBDEVICE_80860005: return "SUBDEVICE_80860005";
        case PciSubDevice8086158B::SUBDEVICE_80860006: return "SUBDEVICE_80860006";
        case PciSubDevice8086158B::SUBDEVICE_80860007: return "SUBDEVICE_80860007";
        case PciSubDevice8086158B::SUBDEVICE_80860008: return "SUBDEVICE_80860008";
        case PciSubDevice8086158B::SUBDEVICE_80860009: return "SUBDEVICE_80860009";
        case PciSubDevice8086158B::SUBDEVICE_8086000A: return "SUBDEVICE_8086000A";
        case PciSubDevice8086158B::SUBDEVICE_80864001: return "SUBDEVICE_80864001";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice8086158B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice8086158B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086158B::SUBDEVICE_11370000: return "Ethernet Network Adapter XXV710";
        case PciSubDevice8086158B::SUBDEVICE_11370225: return "Ethernet Network Adapter XXV710";
        case PciSubDevice8086158B::SUBDEVICE_113702B4: return "Ethernet Network Adapter XXV710 OCP 2.0";
        case PciSubDevice8086158B::SUBDEVICE_13740230: return "Single Port 25 Gigabit Ethernet PCI Express Server Adapter (PE325G1I71)";
        case PciSubDevice8086158B::SUBDEVICE_13740231: return "Single Port 25 Gigabit Ethernet PCI Express Server Adapter (PE325G1I71EU)";
        case PciSubDevice8086158B::SUBDEVICE_13740234: return "Dual Port 25 Gigabit Ethernet PCI Express Server Adapter (PE325G2I71)";
        case PciSubDevice8086158B::SUBDEVICE_13740235: return "Dual Port 25 Gigabit Ethernet PCI Express Server Adapter (PE325G2I71EU)";
        case PciSubDevice8086158B::SUBDEVICE_13740238: return "Quad Port 25 Gigabit Ethernet PCI Express Server Adapter (PE325G4I71L)";
        case PciSubDevice8086158B::SUBDEVICE_13740239: return "Quad Port 25 Gigabit Ethernet PCI Express Server Adapter (PE325G4I71LEU)";
        case PciSubDevice8086158B::SUBDEVICE_1374023A: return "Quad Port 25 Gigabit Ethernet PCI Express Server Adapter (PE31625G4I71L)";
        case PciSubDevice8086158B::SUBDEVICE_1374023B: return "Quad Port 25 Gigabit Ethernet PCI Express Server Adapter (PE31625G4I71LEU)";
        case PciSubDevice8086158B::SUBDEVICE_15900000: return "Ethernet Network Adapter XXV710-2";
        case PciSubDevice8086158B::SUBDEVICE_15900253: return "Ethernet 10/25/Gb 2-port 661SFP28 Adapter";
        case PciSubDevice8086158B::SUBDEVICE_80860000: return "Ethernet Network Adapter XXV710";
        case PciSubDevice8086158B::SUBDEVICE_80860001: return "Ethernet Network Adapter XXV710-2";
        case PciSubDevice8086158B::SUBDEVICE_80860002: return "Ethernet Network Adapter XXV710-2";
        case PciSubDevice8086158B::SUBDEVICE_80860003: return "Ethernet Network Adapter XXV710-1";
        case PciSubDevice8086158B::SUBDEVICE_80860004: return "Ethernet Network Adapter XXV710-1";
        case PciSubDevice8086158B::SUBDEVICE_80860005: return "Ethernet Network Adapter OCP XXV710-2";
        case PciSubDevice8086158B::SUBDEVICE_80860006: return "Ethernet Network Adapter OCP XXV710-2";
        case PciSubDevice8086158B::SUBDEVICE_80860007: return "Ethernet Network Adapter OCP XXV710-1";
        case PciSubDevice8086158B::SUBDEVICE_80860008: return "Ethernet Network Adapter OCP XXV710-1";
        case PciSubDevice8086158B::SUBDEVICE_80860009: return "Ethernet 25G 2P XXV710 Adapter";
        case PciSubDevice8086158B::SUBDEVICE_8086000A: return "Ethernet 25G 2P XXV710 OCP";
        case PciSubDevice8086158B::SUBDEVICE_80864001: return "Ethernet Network Adapter XXV710-2";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086158B_H
