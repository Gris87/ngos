// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E41648_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E41648_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice14E41648: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_0E1100CF = 0x0E1100CF,
    SUBDEVICE_0E1100D0 = 0x0E1100D0,
    SUBDEVICE_0E1100D1 = 0x0E1100D1,
    SUBDEVICE_1028014A = 0x1028014A,
    SUBDEVICE_10280170 = 0x10280170,
    SUBDEVICE_103C310F = 0x103C310F,
    SUBDEVICE_10A98013 = 0x10A98013,
    SUBDEVICE_10A98018 = 0x10A98018,
    SUBDEVICE_10A9801A = 0x10A9801A,
    SUBDEVICE_10A9801B = 0x10A9801B,
    SUBDEVICE_10B72000 = 0x10B72000,
    SUBDEVICE_10B73000 = 0x10B73000,
    SUBDEVICE_11661648 = 0x11661648,
    SUBDEVICE_1734100B = 0x1734100B
};



inline const char8* enumToString(PciSubDevice14E41648 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E41648::NONE:               return "NONE";
        case PciSubDevice14E41648::SUBDEVICE_0E1100CF: return "SUBDEVICE_0E1100CF";
        case PciSubDevice14E41648::SUBDEVICE_0E1100D0: return "SUBDEVICE_0E1100D0";
        case PciSubDevice14E41648::SUBDEVICE_0E1100D1: return "SUBDEVICE_0E1100D1";
        case PciSubDevice14E41648::SUBDEVICE_1028014A: return "SUBDEVICE_1028014A";
        case PciSubDevice14E41648::SUBDEVICE_10280170: return "SUBDEVICE_10280170";
        case PciSubDevice14E41648::SUBDEVICE_103C310F: return "SUBDEVICE_103C310F";
        case PciSubDevice14E41648::SUBDEVICE_10A98013: return "SUBDEVICE_10A98013";
        case PciSubDevice14E41648::SUBDEVICE_10A98018: return "SUBDEVICE_10A98018";
        case PciSubDevice14E41648::SUBDEVICE_10A9801A: return "SUBDEVICE_10A9801A";
        case PciSubDevice14E41648::SUBDEVICE_10A9801B: return "SUBDEVICE_10A9801B";
        case PciSubDevice14E41648::SUBDEVICE_10B72000: return "SUBDEVICE_10B72000";
        case PciSubDevice14E41648::SUBDEVICE_10B73000: return "SUBDEVICE_10B73000";
        case PciSubDevice14E41648::SUBDEVICE_11661648: return "SUBDEVICE_11661648";
        case PciSubDevice14E41648::SUBDEVICE_1734100B: return "SUBDEVICE_1734100B";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice14E41648 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice14E41648 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E41648::SUBDEVICE_0E1100CF: return "NC7772 Gigabit Server Adapter (PCI-X, 10, 100, 1000-T)";
        case PciSubDevice14E41648::SUBDEVICE_0E1100D0: return "NC7782 Gigabit Server Adapter (PCI-X, 10, 100, 1000-T)";
        case PciSubDevice14E41648::SUBDEVICE_0E1100D1: return "NC7783 Gigabit Server Adapter (PCI-X, 10, 100, 1000-T)";
        case PciSubDevice14E41648::SUBDEVICE_1028014A: return "PowerEdge 1750";
        case PciSubDevice14E41648::SUBDEVICE_10280170: return "PowerEdge 6850 Broadcom NetXtreme BCM5704";
        case PciSubDevice14E41648::SUBDEVICE_103C310F: return "NC7782 Gigabit Server Adapter (PCI-X, 10, 100, 1000-T)";
        case PciSubDevice14E41648::SUBDEVICE_10A98013: return "Dual Port Gigabit Ethernet (PCI-X, Copper)";
        case PciSubDevice14E41648::SUBDEVICE_10A98018: return "Dual Port Gigabit Ethernet (A330)";
        case PciSubDevice14E41648::SUBDEVICE_10A9801A: return "Dual Port Gigabit Ethernet (IA-blade)";
        case PciSubDevice14E41648::SUBDEVICE_10A9801B: return "Quad Port Gigabit Ethernet (PCI-E, Copper)";
        case PciSubDevice14E41648::SUBDEVICE_10B72000: return "3C998-T Dual Port 10/100/1000 PCI-X";
        case PciSubDevice14E41648::SUBDEVICE_10B73000: return "3C999-T Quad Port 10/100/1000 PCI-X";
        case PciSubDevice14E41648::SUBDEVICE_11661648: return "NetXtreme CIOB-E 1000Base-T";
        case PciSubDevice14E41648::SUBDEVICE_1734100B: return "PRIMERGY RX/TX series onboard LAN";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E41648_H
