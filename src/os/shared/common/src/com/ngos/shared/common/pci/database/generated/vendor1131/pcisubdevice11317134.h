// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1131_PCISUBDEVICE11317134_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1131_PCISUBDEVICE11317134_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11317134: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_00004036 = 0x00004036,
    SUBDEVICE_00004037 = 0x00004037,
    SUBDEVICE_00004071 = 0x00004071,
    SUBDEVICE_10194CB4 = 0x10194CB4,
    SUBDEVICE_10430210 = 0x10430210,
    SUBDEVICE_10434840 = 0x10434840,
    SUBDEVICE_10434842 = 0x10434842,
    SUBDEVICE_11310000 = 0x11310000,
    SUBDEVICE_11312004 = 0x11312004,
    SUBDEVICE_11314E85 = 0x11314E85,
    SUBDEVICE_11316752 = 0x11316752,
    SUBDEVICE_11BD002B = 0x11BD002B,
    SUBDEVICE_11BD002D = 0x11BD002D,
    SUBDEVICE_14612C00 = 0x14612C00,
    SUBDEVICE_14619715 = 0x14619715,
    SUBDEVICE_1461A70A = 0x1461A70A,
    SUBDEVICE_1461A70B = 0x1461A70B,
    SUBDEVICE_1461D6EE = 0x1461D6EE,
    SUBDEVICE_1471B7E9 = 0x1471B7E9,
    SUBDEVICE_153B1142 = 0x153B1142,
    SUBDEVICE_153B1143 = 0x153B1143,
    SUBDEVICE_153B1158 = 0x153B1158,
    SUBDEVICE_15409524 = 0x15409524,
    SUBDEVICE_16BE0003 = 0x16BE0003,
    SUBDEVICE_185BC200 = 0x185BC200,
    SUBDEVICE_185BC900 = 0x185BC900,
    SUBDEVICE_1894A006 = 0x1894A006,
    SUBDEVICE_1894FE01 = 0x1894FE01,
    SUBDEVICE_51680138 = 0x51680138,
    SUBDEVICE_51680300 = 0x51680300,
    SUBDEVICE_5ACE5070 = 0x5ACE5070,
    SUBDEVICE_5ACE6070 = 0x5ACE6070,
    SUBDEVICE_5ACE6071 = 0x5ACE6071,
    SUBDEVICE_5ACE6072 = 0x5ACE6072,
    SUBDEVICE_5ACE6073 = 0x5ACE6073
};



inline const char8* enumToString(PciSubDevice11317134 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11317134::NONE:               return "NONE";
        case PciSubDevice11317134::SUBDEVICE_00004036: return "SUBDEVICE_00004036";
        case PciSubDevice11317134::SUBDEVICE_00004037: return "SUBDEVICE_00004037";
        case PciSubDevice11317134::SUBDEVICE_00004071: return "SUBDEVICE_00004071";
        case PciSubDevice11317134::SUBDEVICE_10194CB4: return "SUBDEVICE_10194CB4";
        case PciSubDevice11317134::SUBDEVICE_10430210: return "SUBDEVICE_10430210";
        case PciSubDevice11317134::SUBDEVICE_10434840: return "SUBDEVICE_10434840";
        case PciSubDevice11317134::SUBDEVICE_10434842: return "SUBDEVICE_10434842";
        case PciSubDevice11317134::SUBDEVICE_11310000: return "SUBDEVICE_11310000";
        case PciSubDevice11317134::SUBDEVICE_11312004: return "SUBDEVICE_11312004";
        case PciSubDevice11317134::SUBDEVICE_11314E85: return "SUBDEVICE_11314E85";
        case PciSubDevice11317134::SUBDEVICE_11316752: return "SUBDEVICE_11316752";
        case PciSubDevice11317134::SUBDEVICE_11BD002B: return "SUBDEVICE_11BD002B";
        case PciSubDevice11317134::SUBDEVICE_11BD002D: return "SUBDEVICE_11BD002D";
        case PciSubDevice11317134::SUBDEVICE_14612C00: return "SUBDEVICE_14612C00";
        case PciSubDevice11317134::SUBDEVICE_14619715: return "SUBDEVICE_14619715";
        case PciSubDevice11317134::SUBDEVICE_1461A70A: return "SUBDEVICE_1461A70A";
        case PciSubDevice11317134::SUBDEVICE_1461A70B: return "SUBDEVICE_1461A70B";
        case PciSubDevice11317134::SUBDEVICE_1461D6EE: return "SUBDEVICE_1461D6EE";
        case PciSubDevice11317134::SUBDEVICE_1471B7E9: return "SUBDEVICE_1471B7E9";
        case PciSubDevice11317134::SUBDEVICE_153B1142: return "SUBDEVICE_153B1142";
        case PciSubDevice11317134::SUBDEVICE_153B1143: return "SUBDEVICE_153B1143";
        case PciSubDevice11317134::SUBDEVICE_153B1158: return "SUBDEVICE_153B1158";
        case PciSubDevice11317134::SUBDEVICE_15409524: return "SUBDEVICE_15409524";
        case PciSubDevice11317134::SUBDEVICE_16BE0003: return "SUBDEVICE_16BE0003";
        case PciSubDevice11317134::SUBDEVICE_185BC200: return "SUBDEVICE_185BC200";
        case PciSubDevice11317134::SUBDEVICE_185BC900: return "SUBDEVICE_185BC900";
        case PciSubDevice11317134::SUBDEVICE_1894A006: return "SUBDEVICE_1894A006";
        case PciSubDevice11317134::SUBDEVICE_1894FE01: return "SUBDEVICE_1894FE01";
        case PciSubDevice11317134::SUBDEVICE_51680138: return "SUBDEVICE_51680138";
        case PciSubDevice11317134::SUBDEVICE_51680300: return "SUBDEVICE_51680300";
        case PciSubDevice11317134::SUBDEVICE_5ACE5070: return "SUBDEVICE_5ACE5070";
        case PciSubDevice11317134::SUBDEVICE_5ACE6070: return "SUBDEVICE_5ACE6070";
        case PciSubDevice11317134::SUBDEVICE_5ACE6071: return "SUBDEVICE_5ACE6071";
        case PciSubDevice11317134::SUBDEVICE_5ACE6072: return "SUBDEVICE_5ACE6072";
        case PciSubDevice11317134::SUBDEVICE_5ACE6073: return "SUBDEVICE_5ACE6073";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11317134 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11317134 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11317134::SUBDEVICE_00004036: return "Behold TV 403";
        case PciSubDevice11317134::SUBDEVICE_00004037: return "Behold TV 403 FM";
        case PciSubDevice11317134::SUBDEVICE_00004071: return "Behold TV 407 FM";
        case PciSubDevice11317134::SUBDEVICE_10194CB4: return "Elitegroup ECS TVP3XP FM1216 Tuner Card(PAL-BG, FM)";
        case PciSubDevice11317134::SUBDEVICE_10430210: return "Digimatrix TV";
        case PciSubDevice11317134::SUBDEVICE_10434840: return "TV-FM 7134";
        case PciSubDevice11317134::SUBDEVICE_10434842: return "TV-FM 7134";
        case PciSubDevice11317134::SUBDEVICE_11310000: return "SAA713x-based TV tuner card";
        case PciSubDevice11317134::SUBDEVICE_11312004: return "EUROPA V3 reference design";
        case PciSubDevice11317134::SUBDEVICE_11314E85: return "SKNet Monster TV";
        case PciSubDevice11317134::SUBDEVICE_11316752: return "EMPRESS";
        case PciSubDevice11317134::SUBDEVICE_11BD002B: return "PCTV Stereo";
        case PciSubDevice11317134::SUBDEVICE_11BD002D: return "PCTV 300i DVB-T + PAL";
        case PciSubDevice11317134::SUBDEVICE_14612C00: return "AverTV Hybrid+FM PCI";
        case PciSubDevice11317134::SUBDEVICE_14619715: return "AVerTV Studio 307";
        case PciSubDevice11317134::SUBDEVICE_1461A70A: return "Avermedia AVerTV 307";
        case PciSubDevice11317134::SUBDEVICE_1461A70B: return "AverMedia M156 / Medion 2819";
        case PciSubDevice11317134::SUBDEVICE_1461D6EE: return "Cardbus TV/Radio (E500)";
        case PciSubDevice11317134::SUBDEVICE_1471B7E9: return "AVerTV Cardbus plus";
        case PciSubDevice11317134::SUBDEVICE_153B1142: return "Terratec Cinergy 400 TV";
        case PciSubDevice11317134::SUBDEVICE_153B1143: return "Terratec Cinergy 600 TV";
        case PciSubDevice11317134::SUBDEVICE_153B1158: return "Terratec Cinergy 600 TV MK3";
        case PciSubDevice11317134::SUBDEVICE_15409524: return "ProVideo PV952";
        case PciSubDevice11317134::SUBDEVICE_16BE0003: return "Medion 7134";
        case PciSubDevice11317134::SUBDEVICE_185BC200: return "Compro VideoMate Gold+ Pal";
        case PciSubDevice11317134::SUBDEVICE_185BC900: return "Videomate DVB-T300";
        case PciSubDevice11317134::SUBDEVICE_1894A006: return "KNC One TV-Station DVR";
        case PciSubDevice11317134::SUBDEVICE_1894FE01: return "KNC One TV-Station RDS / Typhoon TV Tuner RDS";
        case PciSubDevice11317134::SUBDEVICE_51680138: return "FLY TV PRIME 34FM";
        case PciSubDevice11317134::SUBDEVICE_51680300: return "FlyDVB-S";
        case PciSubDevice11317134::SUBDEVICE_5ACE5070: return "Behold TV 507 FM";
        case PciSubDevice11317134::SUBDEVICE_5ACE6070: return "Behold TV 607 FM";
        case PciSubDevice11317134::SUBDEVICE_5ACE6071: return "Behold TV 607 FM";
        case PciSubDevice11317134::SUBDEVICE_5ACE6072: return "Behold TV 607 RDS";
        case PciSubDevice11317134::SUBDEVICE_5ACE6073: return "Behold TV 607 RDS";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1131_PCISUBDEVICE11317134_H
