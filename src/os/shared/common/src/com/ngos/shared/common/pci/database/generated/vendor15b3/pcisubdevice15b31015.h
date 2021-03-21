// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR15B3_PCISUBDEVICE15B31015_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR15B3_PCISUBDEVICE15B31015_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice15B31015: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_15B30001 = 0x15B30001,
    SUBDEVICE_15B30003 = 0x15B30003,
    SUBDEVICE_15B30004 = 0x15B30004,
    SUBDEVICE_15B30005 = 0x15B30005,
    SUBDEVICE_15B30020 = 0x15B30020,
    SUBDEVICE_15B30021 = 0x15B30021,
    SUBDEVICE_15B30025 = 0x15B30025,
    SUBDEVICE_193D100A = 0x193D100A,
    SUBDEVICE_193D1023 = 0x193D1023,
    SUBDEVICE_193D1031 = 0x193D1031,
    SUBDEVICE_193D1083 = 0x193D1083,
    SUBDEVICE_193D1084 = 0x193D1084
};



inline const char8* enumToString(PciSubDevice15B31015 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice15B31015::NONE:               return "NONE";
        case PciSubDevice15B31015::SUBDEVICE_15B30001: return "SUBDEVICE_15B30001";
        case PciSubDevice15B31015::SUBDEVICE_15B30003: return "SUBDEVICE_15B30003";
        case PciSubDevice15B31015::SUBDEVICE_15B30004: return "SUBDEVICE_15B30004";
        case PciSubDevice15B31015::SUBDEVICE_15B30005: return "SUBDEVICE_15B30005";
        case PciSubDevice15B31015::SUBDEVICE_15B30020: return "SUBDEVICE_15B30020";
        case PciSubDevice15B31015::SUBDEVICE_15B30021: return "SUBDEVICE_15B30021";
        case PciSubDevice15B31015::SUBDEVICE_15B30025: return "SUBDEVICE_15B30025";
        case PciSubDevice15B31015::SUBDEVICE_193D100A: return "SUBDEVICE_193D100A";
        case PciSubDevice15B31015::SUBDEVICE_193D1023: return "SUBDEVICE_193D1023";
        case PciSubDevice15B31015::SUBDEVICE_193D1031: return "SUBDEVICE_193D1031";
        case PciSubDevice15B31015::SUBDEVICE_193D1083: return "SUBDEVICE_193D1083";
        case PciSubDevice15B31015::SUBDEVICE_193D1084: return "SUBDEVICE_193D1084";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice15B31015 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice15B31015 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice15B31015::SUBDEVICE_15B30001: return "ConnectX-4 Lx EN network interface card, 25GbE single-port SFP28, PCIe3.0 x8, tall bracket, ROHS R6";
        case PciSubDevice15B31015::SUBDEVICE_15B30003: return "Stand-up ConnectX-4 Lx EN, 25GbE dual-port SFP28, PCIe3.0 x8, MCX4121A-ACAT";
        case PciSubDevice15B31015::SUBDEVICE_15B30004: return "ConnectX-4 Lx Stand-up dual-port 10GbE MCX4121A-XCAT";
        case PciSubDevice15B31015::SUBDEVICE_15B30005: return "Mellanox Technologies ConnectX-4 Lx Stand-up single-port 40GbE MCX4131A-BCAT";
        case PciSubDevice15B31015::SUBDEVICE_15B30020: return "MCX4411A-ACQN, ConnectX-4 Lx EN OCP, 1x25Gb";
        case PciSubDevice15B31015::SUBDEVICE_15B30021: return "MCX4421A-ACQN ConnectX-4 Lx EN OCP, 2x25G";
        case PciSubDevice15B31015::SUBDEVICE_15B30025: return "ConnectX-4 Lx 25 GbE Dual Port SFP28 rNDC";
        case PciSubDevice15B31015::SUBDEVICE_193D100A: return "620F-B";
        case PciSubDevice15B31015::SUBDEVICE_193D1023: return "NIC-ETH540F-LP-2P";
        case PciSubDevice15B31015::SUBDEVICE_193D1031: return "NIC-ETH640i-Mb-2x25G";
        case PciSubDevice15B31015::SUBDEVICE_193D1083: return "NIC-ETH640F-3S-2P";
        case PciSubDevice15B31015::SUBDEVICE_193D1084: return "NIC-ETH540F-3S-2P";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR15B3_PCISUBDEVICE15B31015_H
