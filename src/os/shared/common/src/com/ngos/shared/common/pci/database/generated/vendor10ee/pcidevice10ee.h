// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10EE_PCIDEVICE10EE_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10EE_PCIDEVICE10EE_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor10ee/pcisubdevice10ee7038.h>
#include <com/ngos/shared/common/pci/database/generated/vendor10ee/pcisubdevice10ee8019.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice10EE: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001,
    DEVICE_0002 = 0x0002,
    DEVICE_0007 = 0x0007,
    DEVICE_0205 = 0x0205,
    DEVICE_0210 = 0x0210,
    DEVICE_0300 = 0x0300,
    DEVICE_0314 = 0x0314,
    DEVICE_0405 = 0x0405,
    DEVICE_0410 = 0x0410,
    DEVICE_0600 = 0x0600,
    DEVICE_3FC0 = 0x3FC0,
    DEVICE_3FC1 = 0x3FC1,
    DEVICE_3FC2 = 0x3FC2,
    DEVICE_3FC3 = 0x3FC3,
    DEVICE_3FC4 = 0x3FC4,
    DEVICE_3FC5 = 0x3FC5,
    DEVICE_3FC6 = 0x3FC6,
    DEVICE_5000 = 0x5000,
    DEVICE_5004 = 0x5004,
    DEVICE_5005 = 0x5005,
    DEVICE_500C = 0x500C,
    DEVICE_5020 = 0x5020,
    DEVICE_505C = 0x505C,
    DEVICE_7038 = 0x7038,
    DEVICE_8019 = 0x8019,
    DEVICE_8380 = 0x8380,
    DEVICE_8381 = 0x8381,
    DEVICE_D000 = 0xD000,
    DEVICE_D004 = 0xD004,
    DEVICE_D00C = 0xD00C,
    DEVICE_D020 = 0xD020,
    DEVICE_D154 = 0xD154,
    DEVICE_EBF0 = 0xEBF0,
    DEVICE_EBF1 = 0xEBF1,
    DEVICE_EBF2 = 0xEBF2,
    DEVICE_EBF3 = 0xEBF3
};



inline const char8* enumToString(PciDevice10EE device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice10EE::NONE:        return "NONE";
        case PciDevice10EE::DEVICE_0001: return "DEVICE_0001";
        case PciDevice10EE::DEVICE_0002: return "DEVICE_0002";
        case PciDevice10EE::DEVICE_0007: return "DEVICE_0007";
        case PciDevice10EE::DEVICE_0205: return "DEVICE_0205";
        case PciDevice10EE::DEVICE_0210: return "DEVICE_0210";
        case PciDevice10EE::DEVICE_0300: return "DEVICE_0300";
        case PciDevice10EE::DEVICE_0314: return "DEVICE_0314";
        case PciDevice10EE::DEVICE_0405: return "DEVICE_0405";
        case PciDevice10EE::DEVICE_0410: return "DEVICE_0410";
        case PciDevice10EE::DEVICE_0600: return "DEVICE_0600";
        case PciDevice10EE::DEVICE_3FC0: return "DEVICE_3FC0";
        case PciDevice10EE::DEVICE_3FC1: return "DEVICE_3FC1";
        case PciDevice10EE::DEVICE_3FC2: return "DEVICE_3FC2";
        case PciDevice10EE::DEVICE_3FC3: return "DEVICE_3FC3";
        case PciDevice10EE::DEVICE_3FC4: return "DEVICE_3FC4";
        case PciDevice10EE::DEVICE_3FC5: return "DEVICE_3FC5";
        case PciDevice10EE::DEVICE_3FC6: return "DEVICE_3FC6";
        case PciDevice10EE::DEVICE_5000: return "DEVICE_5000";
        case PciDevice10EE::DEVICE_5004: return "DEVICE_5004";
        case PciDevice10EE::DEVICE_5005: return "DEVICE_5005";
        case PciDevice10EE::DEVICE_500C: return "DEVICE_500C";
        case PciDevice10EE::DEVICE_5020: return "DEVICE_5020";
        case PciDevice10EE::DEVICE_505C: return "DEVICE_505C";
        case PciDevice10EE::DEVICE_7038: return "DEVICE_7038";
        case PciDevice10EE::DEVICE_8019: return "DEVICE_8019";
        case PciDevice10EE::DEVICE_8380: return "DEVICE_8380";
        case PciDevice10EE::DEVICE_8381: return "DEVICE_8381";
        case PciDevice10EE::DEVICE_D000: return "DEVICE_D000";
        case PciDevice10EE::DEVICE_D004: return "DEVICE_D004";
        case PciDevice10EE::DEVICE_D00C: return "DEVICE_D00C";
        case PciDevice10EE::DEVICE_D020: return "DEVICE_D020";
        case PciDevice10EE::DEVICE_D154: return "DEVICE_D154";
        case PciDevice10EE::DEVICE_EBF0: return "DEVICE_EBF0";
        case PciDevice10EE::DEVICE_EBF1: return "DEVICE_EBF1";
        case PciDevice10EE::DEVICE_EBF2: return "DEVICE_EBF2";
        case PciDevice10EE::DEVICE_EBF3: return "DEVICE_EBF3";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice10EE device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice10EE device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice10EE::DEVICE_0001: return "EUROCOM for PCI (ECOMP)";
        case PciDevice10EE::DEVICE_0002: return "Octal E1/T1 for PCI ETP Card";
        case PciDevice10EE::DEVICE_0007: return "Default PCIe endpoint ID";
        case PciDevice10EE::DEVICE_0205: return "Wildcard TE205P";
        case PciDevice10EE::DEVICE_0210: return "Wildcard TE210P";
        case PciDevice10EE::DEVICE_0300: return "Spartan 3 Designs (Xilinx IP)";
        case PciDevice10EE::DEVICE_0314: return "Wildcard TE405P/TE410P (1st Gen)";
        case PciDevice10EE::DEVICE_0405: return "Wildcard TE405P (2nd Gen)";
        case PciDevice10EE::DEVICE_0410: return "Wildcard TE410P (2nd Gen)";
        case PciDevice10EE::DEVICE_0600: return "Xilinx 6 Designs (Xilinx IP)";
        case PciDevice10EE::DEVICE_3FC0: return "RME Digi96";
        case PciDevice10EE::DEVICE_3FC1: return "RME Digi96/8";
        case PciDevice10EE::DEVICE_3FC2: return "RME Digi96/8 Pro";
        case PciDevice10EE::DEVICE_3FC3: return "RME Digi96/8 Pad";
        case PciDevice10EE::DEVICE_3FC4: return "RME Digi9652 (Hammerfall)";
        case PciDevice10EE::DEVICE_3FC5: return "RME Hammerfall DSP";
        case PciDevice10EE::DEVICE_3FC6: return "RME Hammerfall DSP MADI";
        case PciDevice10EE::DEVICE_5000: return "Alveo U200 XDMA Platform";
        case PciDevice10EE::DEVICE_5004: return "Alveo U250 XDMA Platform";
        case PciDevice10EE::DEVICE_5005: return "Alveo U250";
        case PciDevice10EE::DEVICE_500C: return "Alveo U280 XDMA Platform";
        case PciDevice10EE::DEVICE_5020: return "Alveo U50 XMDA Platform";
        case PciDevice10EE::DEVICE_505C: return "Alveo U55C";
        case PciDevice10EE::DEVICE_7038: return "FPGA Card XC7VX690T";
        case PciDevice10EE::DEVICE_8019: return "Memory controller";
        case PciDevice10EE::DEVICE_8380: return "Ellips ProfiXpress Profibus Master";
        case PciDevice10EE::DEVICE_8381: return "Ellips Santos Frame Grabber";
        case PciDevice10EE::DEVICE_D000: return "Alveo U200 Golden Image";
        case PciDevice10EE::DEVICE_D004: return "Alveo U250 Golden Image";
        case PciDevice10EE::DEVICE_D00C: return "Alveo U280 Golden Image";
        case PciDevice10EE::DEVICE_D020: return "Alveo U50 Golden Image";
        case PciDevice10EE::DEVICE_D154: return "Copley Controls CAN card (PCI-CAN-02)";
        case PciDevice10EE::DEVICE_EBF0: return "SED Systems Modulator/Demodulator";
        case PciDevice10EE::DEVICE_EBF1: return "SED Systems Audio Interface Card";
        case PciDevice10EE::DEVICE_EBF2: return "SED Systems Common PCI Interface";
        case PciDevice10EE::DEVICE_EBF3: return "SED Systems PCIe-AXI Bridge";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice10EE device, u16 subsystemVendorID, u16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice10EE::DEVICE_0001: return "Unknown device";
        case PciDevice10EE::DEVICE_0002: return "Unknown device";
        case PciDevice10EE::DEVICE_0007: return "Unknown device";
        case PciDevice10EE::DEVICE_0205: return "Unknown device";
        case PciDevice10EE::DEVICE_0210: return "Unknown device";
        case PciDevice10EE::DEVICE_0300: return "Unknown device";
        case PciDevice10EE::DEVICE_0314: return "Unknown device";
        case PciDevice10EE::DEVICE_0405: return "Unknown device";
        case PciDevice10EE::DEVICE_0410: return "Unknown device";
        case PciDevice10EE::DEVICE_0600: return "Unknown device";
        case PciDevice10EE::DEVICE_3FC0: return "Unknown device";
        case PciDevice10EE::DEVICE_3FC1: return "Unknown device";
        case PciDevice10EE::DEVICE_3FC2: return "Unknown device";
        case PciDevice10EE::DEVICE_3FC3: return "Unknown device";
        case PciDevice10EE::DEVICE_3FC4: return "Unknown device";
        case PciDevice10EE::DEVICE_3FC5: return "Unknown device";
        case PciDevice10EE::DEVICE_3FC6: return "Unknown device";
        case PciDevice10EE::DEVICE_5000: return "Unknown device";
        case PciDevice10EE::DEVICE_5004: return "Unknown device";
        case PciDevice10EE::DEVICE_5005: return "Unknown device";
        case PciDevice10EE::DEVICE_500C: return "Unknown device";
        case PciDevice10EE::DEVICE_5020: return "Unknown device";
        case PciDevice10EE::DEVICE_505C: return "Unknown device";
        case PciDevice10EE::DEVICE_7038: return enumToHumanString((PciSubDevice10EE7038)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice10EE::DEVICE_8019: return enumToHumanString((PciSubDevice10EE8019)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice10EE::DEVICE_8380: return "Unknown device";
        case PciDevice10EE::DEVICE_8381: return "Unknown device";
        case PciDevice10EE::DEVICE_D000: return "Unknown device";
        case PciDevice10EE::DEVICE_D004: return "Unknown device";
        case PciDevice10EE::DEVICE_D00C: return "Unknown device";
        case PciDevice10EE::DEVICE_D020: return "Unknown device";
        case PciDevice10EE::DEVICE_D154: return "Unknown device";
        case PciDevice10EE::DEVICE_EBF0: return "Unknown device";
        case PciDevice10EE::DEVICE_EBF1: return "Unknown device";
        case PciDevice10EE::DEVICE_EBF2: return "Unknown device";
        case PciDevice10EE::DEVICE_EBF3: return "Unknown device";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10EE_PCIDEVICE10EE_H
