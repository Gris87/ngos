// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861592_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861592_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80861592: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_113702BF = 0x113702BF,
    SUBDEVICE_80860001 = 0x80860001,
    SUBDEVICE_80860002 = 0x80860002,
    SUBDEVICE_80860004 = 0x80860004,
    SUBDEVICE_80860005 = 0x80860005,
    SUBDEVICE_80860006 = 0x80860006,
    SUBDEVICE_80860009 = 0x80860009,
    SUBDEVICE_8086000A = 0x8086000A,
    SUBDEVICE_8086000B = 0x8086000B,
    SUBDEVICE_8086000C = 0x8086000C,
    SUBDEVICE_8086000D = 0x8086000D,
    SUBDEVICE_8086000E = 0x8086000E
};



inline const char8* enumToString(PciSubDevice80861592 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861592::NONE:               return "NONE";
        case PciSubDevice80861592::SUBDEVICE_113702BF: return "SUBDEVICE_113702BF";
        case PciSubDevice80861592::SUBDEVICE_80860001: return "SUBDEVICE_80860001";
        case PciSubDevice80861592::SUBDEVICE_80860002: return "SUBDEVICE_80860002";
        case PciSubDevice80861592::SUBDEVICE_80860004: return "SUBDEVICE_80860004";
        case PciSubDevice80861592::SUBDEVICE_80860005: return "SUBDEVICE_80860005";
        case PciSubDevice80861592::SUBDEVICE_80860006: return "SUBDEVICE_80860006";
        case PciSubDevice80861592::SUBDEVICE_80860009: return "SUBDEVICE_80860009";
        case PciSubDevice80861592::SUBDEVICE_8086000A: return "SUBDEVICE_8086000A";
        case PciSubDevice80861592::SUBDEVICE_8086000B: return "SUBDEVICE_8086000B";
        case PciSubDevice80861592::SUBDEVICE_8086000C: return "SUBDEVICE_8086000C";
        case PciSubDevice80861592::SUBDEVICE_8086000D: return "SUBDEVICE_8086000D";
        case PciSubDevice80861592::SUBDEVICE_8086000E: return "SUBDEVICE_8086000E";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80861592 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80861592 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861592::SUBDEVICE_113702BF: return "E810CQDA2 2x100 GbE QSFP28 PCIe NIC";
        case PciSubDevice80861592::SUBDEVICE_80860001: return "Ethernet Network Adapter E810-C-Q1";
        case PciSubDevice80861592::SUBDEVICE_80860002: return "Ethernet Network Adapter E810-C-Q2";
        case PciSubDevice80861592::SUBDEVICE_80860004: return "Ethernet Network Adapter E810-C-Q2";
        case PciSubDevice80861592::SUBDEVICE_80860005: return "Ethernet Network Adapter E810-C-Q1 for OCP3.0";
        case PciSubDevice80861592::SUBDEVICE_80860006: return "Ethernet Network Adapter E810-C-Q2 for OCP3.0";
        case PciSubDevice80861592::SUBDEVICE_80860009: return "Ethernet Network Adapter E810-C-Q1";
        case PciSubDevice80861592::SUBDEVICE_8086000A: return "Ethernet Network Adapter E810-C-Q1 for OCP";
        case PciSubDevice80861592::SUBDEVICE_8086000B: return "Ethernet 100G 2P E810-C Adapter";
        case PciSubDevice80861592::SUBDEVICE_8086000C: return "Ethernet 100G 2P E810-C OCP";
        case PciSubDevice80861592::SUBDEVICE_8086000D: return "Ethernet Network Adapter E810-L-Q2 for OCP 3.0";
        case PciSubDevice80861592::SUBDEVICE_8086000E: return "Ethernet Network Adapter E810-2C-Q2";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861592_H
