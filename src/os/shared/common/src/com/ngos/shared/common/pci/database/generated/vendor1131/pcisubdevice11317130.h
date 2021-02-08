// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1131_PCISUBDEVICE11317130_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1131_PCISUBDEVICE11317130_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11317130: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_00004016 = 0x00004016,
    SUBDEVICE_00004051 = 0x00004051,
    SUBDEVICE_00005051 = 0x00005051,
    SUBDEVICE_0000505B = 0x0000505B,
    SUBDEVICE_102B48D0 = 0x102B48D0,
    SUBDEVICE_1048226B = 0x1048226B,
    SUBDEVICE_107D6655 = 0x107D6655,
    SUBDEVICE_11310000 = 0x11310000,
    SUBDEVICE_11312001 = 0x11312001,
    SUBDEVICE_11312005 = 0x11312005,
    SUBDEVICE_14589006 = 0x14589006,
    SUBDEVICE_1461050C = 0x1461050C,
    SUBDEVICE_146110FF = 0x146110FF,
    SUBDEVICE_14612108 = 0x14612108,
    SUBDEVICE_14612115 = 0x14612115,
    SUBDEVICE_153B1152 = 0x153B1152,
    SUBDEVICE_185BC100 = 0x185BC100,
    SUBDEVICE_185BC901 = 0x185BC901,
    SUBDEVICE_51680138 = 0x51680138,
    SUBDEVICE_5ACE5010 = 0x5ACE5010,
    SUBDEVICE_5ACE5050 = 0x5ACE5050
};



inline const char8* enumToString(PciSubDevice11317130 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11317130::NONE:               return "NONE";
        case PciSubDevice11317130::SUBDEVICE_00004016: return "SUBDEVICE_00004016";
        case PciSubDevice11317130::SUBDEVICE_00004051: return "SUBDEVICE_00004051";
        case PciSubDevice11317130::SUBDEVICE_00005051: return "SUBDEVICE_00005051";
        case PciSubDevice11317130::SUBDEVICE_0000505B: return "SUBDEVICE_0000505B";
        case PciSubDevice11317130::SUBDEVICE_102B48D0: return "SUBDEVICE_102B48D0";
        case PciSubDevice11317130::SUBDEVICE_1048226B: return "SUBDEVICE_1048226B";
        case PciSubDevice11317130::SUBDEVICE_107D6655: return "SUBDEVICE_107D6655";
        case PciSubDevice11317130::SUBDEVICE_11310000: return "SUBDEVICE_11310000";
        case PciSubDevice11317130::SUBDEVICE_11312001: return "SUBDEVICE_11312001";
        case PciSubDevice11317130::SUBDEVICE_11312005: return "SUBDEVICE_11312005";
        case PciSubDevice11317130::SUBDEVICE_14589006: return "SUBDEVICE_14589006";
        case PciSubDevice11317130::SUBDEVICE_1461050C: return "SUBDEVICE_1461050C";
        case PciSubDevice11317130::SUBDEVICE_146110FF: return "SUBDEVICE_146110FF";
        case PciSubDevice11317130::SUBDEVICE_14612108: return "SUBDEVICE_14612108";
        case PciSubDevice11317130::SUBDEVICE_14612115: return "SUBDEVICE_14612115";
        case PciSubDevice11317130::SUBDEVICE_153B1152: return "SUBDEVICE_153B1152";
        case PciSubDevice11317130::SUBDEVICE_185BC100: return "SUBDEVICE_185BC100";
        case PciSubDevice11317130::SUBDEVICE_185BC901: return "SUBDEVICE_185BC901";
        case PciSubDevice11317130::SUBDEVICE_51680138: return "SUBDEVICE_51680138";
        case PciSubDevice11317130::SUBDEVICE_5ACE5010: return "SUBDEVICE_5ACE5010";
        case PciSubDevice11317130::SUBDEVICE_5ACE5050: return "SUBDEVICE_5ACE5050";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11317130 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11317130 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11317130::SUBDEVICE_00004016: return "Behold TV 401";
        case PciSubDevice11317130::SUBDEVICE_00004051: return "Behold TV 405 FM";
        case PciSubDevice11317130::SUBDEVICE_00005051: return "Behold TV 505 RDS";
        case PciSubDevice11317130::SUBDEVICE_0000505B: return "Behold TV 505 RDS";
        case PciSubDevice11317130::SUBDEVICE_102B48D0: return "Matrox CronosPlus";
        case PciSubDevice11317130::SUBDEVICE_1048226B: return "ELSA EX-VISION 300TV";
        case PciSubDevice11317130::SUBDEVICE_107D6655: return "WinFast DTV1000S";
        case PciSubDevice11317130::SUBDEVICE_11310000: return "SAA7130-based TV tuner card";
        case PciSubDevice11317130::SUBDEVICE_11312001: return "10MOONS PCI TV CAPTURE CARD";
        case PciSubDevice11317130::SUBDEVICE_11312005: return "Techcom (India) TV Tuner Card (SSD-TV-670)";
        case PciSubDevice11317130::SUBDEVICE_14589006: return "GT-PS700 DVB-S tuner";
        case PciSubDevice11317130::SUBDEVICE_1461050C: return "Nagase Sangyo TransGear 3000TV";
        case PciSubDevice11317130::SUBDEVICE_146110FF: return "AVerMedia DVD EZMaker";
        case PciSubDevice11317130::SUBDEVICE_14612108: return "AverMedia AverTV/305";
        case PciSubDevice11317130::SUBDEVICE_14612115: return "AverMedia AverTV Studio 305";
        case PciSubDevice11317130::SUBDEVICE_153B1152: return "Terratec Cinergy 200 TV";
        case PciSubDevice11317130::SUBDEVICE_185BC100: return "Compro VideoMate TV PVR/FM";
        case PciSubDevice11317130::SUBDEVICE_185BC901: return "Videomate DVB-T200";
        case PciSubDevice11317130::SUBDEVICE_51680138: return "LifeView FlyVIDEO2000";
        case PciSubDevice11317130::SUBDEVICE_5ACE5010: return "Behold TV 501";
        case PciSubDevice11317130::SUBDEVICE_5ACE5050: return "Behold TV 505 FM";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1131_PCISUBDEVICE11317130_H
