// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808624F0_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808624F0_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice808624F0: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10A9802E = 0x10A9802E,
    SUBDEVICE_10A9802F = 0x10A9802F,
    SUBDEVICE_10A98030 = 0x10A98030,
    SUBDEVICE_10A98031 = 0x10A98031,
    SUBDEVICE_159000E7 = 0x159000E7,
    SUBDEVICE_159000E8 = 0x159000E8,
    SUBDEVICE_1590021C = 0x1590021C,
    SUBDEVICE_15D90934 = 0x15D90934,
    SUBDEVICE_15D9099B = 0x15D9099B,
    SUBDEVICE_1CB80001 = 0x1CB80001,
    SUBDEVICE_1CB80002 = 0x1CB80002,
    SUBDEVICE_1CB80003 = 0x1CB80003,
    SUBDEVICE_1CB80004 = 0x1CB80004,
    SUBDEVICE_80862628 = 0x80862628,
    SUBDEVICE_80862629 = 0x80862629,
    SUBDEVICE_8086262A = 0x8086262A,
    SUBDEVICE_8086262D = 0x8086262D
};



inline const char8* enumToString(PciSubDevice808624F0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808624F0::NONE:               return "NONE";
        case PciSubDevice808624F0::SUBDEVICE_10A9802E: return "SUBDEVICE_10A9802E";
        case PciSubDevice808624F0::SUBDEVICE_10A9802F: return "SUBDEVICE_10A9802F";
        case PciSubDevice808624F0::SUBDEVICE_10A98030: return "SUBDEVICE_10A98030";
        case PciSubDevice808624F0::SUBDEVICE_10A98031: return "SUBDEVICE_10A98031";
        case PciSubDevice808624F0::SUBDEVICE_159000E7: return "SUBDEVICE_159000E7";
        case PciSubDevice808624F0::SUBDEVICE_159000E8: return "SUBDEVICE_159000E8";
        case PciSubDevice808624F0::SUBDEVICE_1590021C: return "SUBDEVICE_1590021C";
        case PciSubDevice808624F0::SUBDEVICE_15D90934: return "SUBDEVICE_15D90934";
        case PciSubDevice808624F0::SUBDEVICE_15D9099B: return "SUBDEVICE_15D9099B";
        case PciSubDevice808624F0::SUBDEVICE_1CB80001: return "SUBDEVICE_1CB80001";
        case PciSubDevice808624F0::SUBDEVICE_1CB80002: return "SUBDEVICE_1CB80002";
        case PciSubDevice808624F0::SUBDEVICE_1CB80003: return "SUBDEVICE_1CB80003";
        case PciSubDevice808624F0::SUBDEVICE_1CB80004: return "SUBDEVICE_1CB80004";
        case PciSubDevice808624F0::SUBDEVICE_80862628: return "SUBDEVICE_80862628";
        case PciSubDevice808624F0::SUBDEVICE_80862629: return "SUBDEVICE_80862629";
        case PciSubDevice808624F0::SUBDEVICE_8086262A: return "SUBDEVICE_8086262A";
        case PciSubDevice808624F0::SUBDEVICE_8086262D: return "SUBDEVICE_8086262D";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice808624F0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice808624F0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808624F0::SUBDEVICE_10A9802E: return "Omni-path HFI 100 Series, 1-port A-board";
        case PciSubDevice808624F0::SUBDEVICE_10A9802F: return "Omni-path HFI 100 Series, 2-port A-board";
        case PciSubDevice808624F0::SUBDEVICE_10A98030: return "Omni-path HFI 100 Series, 1-port B-board";
        case PciSubDevice808624F0::SUBDEVICE_10A98031: return "Omni-path HFI 100 Series, 2-port B-board";
        case PciSubDevice808624F0::SUBDEVICE_159000E7: return "100Gb 1-port OP101 QSFP28 x8 PCIe Gen3 with Intel Omni-Path Adapter";
        case PciSubDevice808624F0::SUBDEVICE_159000E8: return "100Gb 1-port OP101 QSFP28 x16 PCIe Gen3 with Intel Omni-Path Adapter";
        case PciSubDevice808624F0::SUBDEVICE_1590021C: return "Apollo 100Gb 1-port Intel Omni-Path Architecture 860z Mezzanine FIO Adapter";
        case PciSubDevice808624F0::SUBDEVICE_15D90934: return "Omni-Path HFI Adapter 100 Series, 1 Port, PCIe x16, SIOM Module";
        case PciSubDevice808624F0::SUBDEVICE_15D9099B: return "Omni-path HFI Mezz AOC, 1 Port, PCIe x16.";
        case PciSubDevice808624F0::SUBDEVICE_1CB80001: return "Omni-Path HFI Adapter 100 Series, 1 Port, PCIe x16, TC4600 QSFP28";
        case PciSubDevice808624F0::SUBDEVICE_1CB80002: return "Omni-Path HFI Adapter 100 Series, 1 Port, PCIe x16, TC6600 Fixed Port";
        case PciSubDevice808624F0::SUBDEVICE_1CB80003: return "Omni-Path HFI Adapter 100 Series, 2 Port, 2 PCIe x16, Earth Simulation QSFP28";
        case PciSubDevice808624F0::SUBDEVICE_1CB80004: return "Omni-Path HFI Adapter 100 Series, 1 Port, PCIe x16, TC4600E QSFP28";
        case PciSubDevice808624F0::SUBDEVICE_80862628: return "Omni-Path HFI Adapter 100 Series, 1 Port, PCIe x16";
        case PciSubDevice808624F0::SUBDEVICE_80862629: return "Omni-Path HFI Adapter 100 Series, 1 Port, PCIe x8";
        case PciSubDevice808624F0::SUBDEVICE_8086262A: return "Omni-Path HFI Adapter 100 Series, 2 Ports, Split PCIe x16";
        case PciSubDevice808624F0::SUBDEVICE_8086262D: return "Omni-Path HFI Adapter 100 Series, 1 Port, PCIe x16, IO Module AHWKPTP100HF";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808624F0_H
