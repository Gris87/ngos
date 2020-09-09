// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1102_PCISUBDEVICE11020002_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1102_PCISUBDEVICE11020002_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11020002: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_100A1102 = 0x100A1102,
    SUBDEVICE_11020020 = 0x11020020,
    SUBDEVICE_11020021 = 0x11020021,
    SUBDEVICE_1102002F = 0x1102002F,
    SUBDEVICE_1102100A = 0x1102100A,
    SUBDEVICE_11024001 = 0x11024001,
    SUBDEVICE_11028022 = 0x11028022,
    SUBDEVICE_11028023 = 0x11028023,
    SUBDEVICE_11028024 = 0x11028024,
    SUBDEVICE_11028025 = 0x11028025,
    SUBDEVICE_11028026 = 0x11028026,
    SUBDEVICE_11028027 = 0x11028027,
    SUBDEVICE_11028028 = 0x11028028,
    SUBDEVICE_11028029 = 0x11028029,
    SUBDEVICE_1102802A = 0x1102802A,
    SUBDEVICE_1102802B = 0x1102802B,
    SUBDEVICE_11028031 = 0x11028031,
    SUBDEVICE_11028032 = 0x11028032,
    SUBDEVICE_11028033 = 0x11028033,
    SUBDEVICE_11028035 = 0x11028035,
    SUBDEVICE_11028040 = 0x11028040,
    SUBDEVICE_11028050 = 0x11028050,
    SUBDEVICE_11028051 = 0x11028051,
    SUBDEVICE_11028061 = 0x11028061,
    SUBDEVICE_11028062 = 0x11028062,
    SUBDEVICE_11028063 = 0x11028063,
    SUBDEVICE_11028064 = 0x11028064,
    SUBDEVICE_11028065 = 0x11028065,
    SUBDEVICE_11028066 = 0x11028066,
    SUBDEVICE_11028067 = 0x11028067,
    SUBDEVICE_11028068 = 0x11028068,
    SUBDEVICE_11028069 = 0x11028069,
    SUBDEVICE_1102806A = 0x1102806A,
    SUBDEVICE_1102806B = 0x1102806B,
    SUBDEVICE_1102806C = 0x1102806C,
    SUBDEVICE_11028071 = 0x11028071
};



inline const char8* enumToString(PciSubDevice11020002 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11020002::NONE:               return "NONE";
        case PciSubDevice11020002::SUBDEVICE_100A1102: return "SUBDEVICE_100A1102";
        case PciSubDevice11020002::SUBDEVICE_11020020: return "SUBDEVICE_11020020";
        case PciSubDevice11020002::SUBDEVICE_11020021: return "SUBDEVICE_11020021";
        case PciSubDevice11020002::SUBDEVICE_1102002F: return "SUBDEVICE_1102002F";
        case PciSubDevice11020002::SUBDEVICE_1102100A: return "SUBDEVICE_1102100A";
        case PciSubDevice11020002::SUBDEVICE_11024001: return "SUBDEVICE_11024001";
        case PciSubDevice11020002::SUBDEVICE_11028022: return "SUBDEVICE_11028022";
        case PciSubDevice11020002::SUBDEVICE_11028023: return "SUBDEVICE_11028023";
        case PciSubDevice11020002::SUBDEVICE_11028024: return "SUBDEVICE_11028024";
        case PciSubDevice11020002::SUBDEVICE_11028025: return "SUBDEVICE_11028025";
        case PciSubDevice11020002::SUBDEVICE_11028026: return "SUBDEVICE_11028026";
        case PciSubDevice11020002::SUBDEVICE_11028027: return "SUBDEVICE_11028027";
        case PciSubDevice11020002::SUBDEVICE_11028028: return "SUBDEVICE_11028028";
        case PciSubDevice11020002::SUBDEVICE_11028029: return "SUBDEVICE_11028029";
        case PciSubDevice11020002::SUBDEVICE_1102802A: return "SUBDEVICE_1102802A";
        case PciSubDevice11020002::SUBDEVICE_1102802B: return "SUBDEVICE_1102802B";
        case PciSubDevice11020002::SUBDEVICE_11028031: return "SUBDEVICE_11028031";
        case PciSubDevice11020002::SUBDEVICE_11028032: return "SUBDEVICE_11028032";
        case PciSubDevice11020002::SUBDEVICE_11028033: return "SUBDEVICE_11028033";
        case PciSubDevice11020002::SUBDEVICE_11028035: return "SUBDEVICE_11028035";
        case PciSubDevice11020002::SUBDEVICE_11028040: return "SUBDEVICE_11028040";
        case PciSubDevice11020002::SUBDEVICE_11028050: return "SUBDEVICE_11028050";
        case PciSubDevice11020002::SUBDEVICE_11028051: return "SUBDEVICE_11028051";
        case PciSubDevice11020002::SUBDEVICE_11028061: return "SUBDEVICE_11028061";
        case PciSubDevice11020002::SUBDEVICE_11028062: return "SUBDEVICE_11028062";
        case PciSubDevice11020002::SUBDEVICE_11028063: return "SUBDEVICE_11028063";
        case PciSubDevice11020002::SUBDEVICE_11028064: return "SUBDEVICE_11028064";
        case PciSubDevice11020002::SUBDEVICE_11028065: return "SUBDEVICE_11028065";
        case PciSubDevice11020002::SUBDEVICE_11028066: return "SUBDEVICE_11028066";
        case PciSubDevice11020002::SUBDEVICE_11028067: return "SUBDEVICE_11028067";
        case PciSubDevice11020002::SUBDEVICE_11028068: return "SUBDEVICE_11028068";
        case PciSubDevice11020002::SUBDEVICE_11028069: return "SUBDEVICE_11028069";
        case PciSubDevice11020002::SUBDEVICE_1102806A: return "SUBDEVICE_1102806A";
        case PciSubDevice11020002::SUBDEVICE_1102806B: return "SUBDEVICE_1102806B";
        case PciSubDevice11020002::SUBDEVICE_1102806C: return "SUBDEVICE_1102806C";
        case PciSubDevice11020002::SUBDEVICE_11028071: return "SUBDEVICE_11028071";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11020002 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11020002 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11020002::SUBDEVICE_100A1102: return "SB Live! 5.1 Digital OEM SB0220 EMU10K1-JFF";
        case PciSubDevice11020002::SUBDEVICE_11020020: return "CT4670/4850 SBLive! Value";
        case PciSubDevice11020002::SUBDEVICE_11020021: return "CT4620 SBLive!";
        case PciSubDevice11020002::SUBDEVICE_1102002F: return "M002/M003 Integrated SBLive!";
        case PciSubDevice11020002::SUBDEVICE_1102100A: return "SB0220/0229 SBLive! 5.1 Digital OEM";
        case PciSubDevice11020002::SUBDEVICE_11024001: return "E-mu APS";
        case PciSubDevice11020002::SUBDEVICE_11028022: return "CT4780 SBLive! Value";
        case PciSubDevice11020002::SUBDEVICE_11028023: return "CT4790 SoundBlaster PCI512";
        case PciSubDevice11020002::SUBDEVICE_11028024: return "CT4760 SBLive!";
        case PciSubDevice11020002::SUBDEVICE_11028025: return "CT1140/SB0040 Integrated SBLive!";
        case PciSubDevice11020002::SUBDEVICE_11028026: return "CT4830 SBLive! Value";
        case PciSubDevice11020002::SUBDEVICE_11028027: return "CT4832 SBLive! Value";
        case PciSubDevice11020002::SUBDEVICE_11028028: return "CT4870 SBLive! Value";
        case PciSubDevice11020002::SUBDEVICE_11028029: return "CT4872 SBLive! Value";
        case PciSubDevice11020002::SUBDEVICE_1102802A: return "CT4890 SoundBlaster PCI256";
        case PciSubDevice11020002::SUBDEVICE_1102802B: return "CT4891 SoundBlaster PCI256";
        case PciSubDevice11020002::SUBDEVICE_11028031: return "CT4831 SBLive! Value";
        case PciSubDevice11020002::SUBDEVICE_11028032: return "CT4871 SBLive! Value";
        case PciSubDevice11020002::SUBDEVICE_11028033: return "CT4893 SoundBlaster PCI256";
        case PciSubDevice11020002::SUBDEVICE_11028035: return "CT0060 SBLive!";
        case PciSubDevice11020002::SUBDEVICE_11028040: return "CT4760 SBLive!";
        case PciSubDevice11020002::SUBDEVICE_11028050: return "CT4750 SoundBlaster PCI512";
        case PciSubDevice11020002::SUBDEVICE_11028051: return "CT4850 SBLive! Value";
        case PciSubDevice11020002::SUBDEVICE_11028061: return "SB060 SBLive! Player 5.1";
        case PciSubDevice11020002::SUBDEVICE_11028062: return "SB0100 SBLive! 5.1";
        case PciSubDevice11020002::SUBDEVICE_11028063: return "DXW Integrated SBLive! 5.1";
        case PciSubDevice11020002::SUBDEVICE_11028064: return "SB0100/SB0102 SBLive! 5.1";
        case PciSubDevice11020002::SUBDEVICE_11028065: return "SB0220/0222 SBLive! 5.1 Digital";
        case PciSubDevice11020002::SUBDEVICE_11028066: return "SB0228 SBLive! 5.1 Digital";
        case PciSubDevice11020002::SUBDEVICE_11028067: return "SB0220 SBLive! 5.1";
        case PciSubDevice11020002::SUBDEVICE_11028068: return "CT0061 SBLive!";
        case PciSubDevice11020002::SUBDEVICE_11028069: return "SB0101 SBLive! 5.1 Value";
        case PciSubDevice11020002::SUBDEVICE_1102806A: return "SB0103 SBLive! 5.1";
        case PciSubDevice11020002::SUBDEVICE_1102806B: return "SB0105 SBLive! 5.1";
        case PciSubDevice11020002::SUBDEVICE_1102806C: return "SB0221 SBLive! 5.1";
        case PciSubDevice11020002::SUBDEVICE_11028071: return "SB0150 SoundBlaster PCI512";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1102_PCISUBDEVICE11020002_H
