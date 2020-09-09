// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861583_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861583_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80861583: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10280000 = 0x10280000,
    SUBDEVICE_10281F9F = 0x10281F9F,
    SUBDEVICE_108E0000 = 0x108E0000,
    SUBDEVICE_108E7B1B = 0x108E7B1B,
    SUBDEVICE_108E7B1D = 0x108E7B1D,
    SUBDEVICE_11370000 = 0x11370000,
    SUBDEVICE_1137013C = 0x1137013C,
    SUBDEVICE_80860000 = 0x80860000,
    SUBDEVICE_80860001 = 0x80860001,
    SUBDEVICE_80860002 = 0x80860002,
    SUBDEVICE_80860003 = 0x80860003,
    SUBDEVICE_80860004 = 0x80860004,
    SUBDEVICE_80860006 = 0x80860006
};



inline const char8* enumToString(PciSubDevice80861583 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861583::NONE:               return "NONE";
        case PciSubDevice80861583::SUBDEVICE_10280000: return "SUBDEVICE_10280000";
        case PciSubDevice80861583::SUBDEVICE_10281F9F: return "SUBDEVICE_10281F9F";
        case PciSubDevice80861583::SUBDEVICE_108E0000: return "SUBDEVICE_108E0000";
        case PciSubDevice80861583::SUBDEVICE_108E7B1B: return "SUBDEVICE_108E7B1B";
        case PciSubDevice80861583::SUBDEVICE_108E7B1D: return "SUBDEVICE_108E7B1D";
        case PciSubDevice80861583::SUBDEVICE_11370000: return "SUBDEVICE_11370000";
        case PciSubDevice80861583::SUBDEVICE_1137013C: return "SUBDEVICE_1137013C";
        case PciSubDevice80861583::SUBDEVICE_80860000: return "SUBDEVICE_80860000";
        case PciSubDevice80861583::SUBDEVICE_80860001: return "SUBDEVICE_80860001";
        case PciSubDevice80861583::SUBDEVICE_80860002: return "SUBDEVICE_80860002";
        case PciSubDevice80861583::SUBDEVICE_80860003: return "SUBDEVICE_80860003";
        case PciSubDevice80861583::SUBDEVICE_80860004: return "SUBDEVICE_80860004";
        case PciSubDevice80861583::SUBDEVICE_80860006: return "SUBDEVICE_80860006";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80861583 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80861583 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861583::SUBDEVICE_10280000: return "Ethernet 40G 2P XL710 QSFP+ rNDC";
        case PciSubDevice80861583::SUBDEVICE_10281F9F: return "Ethernet 40G 2P XL710 QSFP+ rNDC";
        case PciSubDevice80861583::SUBDEVICE_108E0000: return "10 Gb/40 Gb Ethernet Adapter";
        case PciSubDevice80861583::SUBDEVICE_108E7B1B: return "10 Gb/40 Gb Ethernet Adapter";
        case PciSubDevice80861583::SUBDEVICE_108E7B1D: return "10Gb/40Gb Ethernet Adapter";
        case PciSubDevice80861583::SUBDEVICE_11370000: return "Ethernet Converged NIC XL710-QDA2";
        case PciSubDevice80861583::SUBDEVICE_1137013C: return "Ethernet Converged NIC XL710-QDA2";
        case PciSubDevice80861583::SUBDEVICE_80860000: return "Ethernet Converged Network Adapter XL710-Q2";
        case PciSubDevice80861583::SUBDEVICE_80860001: return "Ethernet Converged Network Adapter XL710-Q2";
        case PciSubDevice80861583::SUBDEVICE_80860002: return "Ethernet Converged Network Adapter XL710-Q2";
        case PciSubDevice80861583::SUBDEVICE_80860003: return "Ethernet I/O Module XL710-Q2";
        case PciSubDevice80861583::SUBDEVICE_80860004: return "Ethernet Server Adapter XL710-Q2OCP";
        case PciSubDevice80861583::SUBDEVICE_80860006: return "Ethernet Converged Network Adapter XL710-Q2";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861583_H
