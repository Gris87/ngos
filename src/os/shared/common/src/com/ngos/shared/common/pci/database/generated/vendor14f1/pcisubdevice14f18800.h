// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14F1_PCISUBDEVICE14F18800_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14F1_PCISUBDEVICE14F18800_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice14F18800: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_00702801 = 0x00702801,
    SUBDEVICE_00703400 = 0x00703400,
    SUBDEVICE_00703401 = 0x00703401,
    SUBDEVICE_00706902 = 0x00706902,
    SUBDEVICE_00707801 = 0x00707801,
    SUBDEVICE_00709001 = 0x00709001,
    SUBDEVICE_00709002 = 0x00709002,
    SUBDEVICE_00709200 = 0x00709200,
    SUBDEVICE_00709202 = 0x00709202,
    SUBDEVICE_00709402 = 0x00709402,
    SUBDEVICE_00709600 = 0x00709600,
    SUBDEVICE_00709802 = 0x00709802,
    SUBDEVICE_100200F8 = 0x100200F8,
    SUBDEVICE_100200F9 = 0x100200F9,
    SUBDEVICE_1002A101 = 0x1002A101,
    SUBDEVICE_10434823 = 0x10434823,
    SUBDEVICE_107D6611 = 0x107D6611,
    SUBDEVICE_107D6613 = 0x107D6613,
    SUBDEVICE_107D6620 = 0x107D6620,
    SUBDEVICE_107D663C = 0x107D663C,
    SUBDEVICE_107D665F = 0x107D665F,
    SUBDEVICE_10FCD003 = 0x10FCD003,
    SUBDEVICE_10FCD035 = 0x10FCD035,
    SUBDEVICE_14210334 = 0x14210334,
    SUBDEVICE_1461000A = 0x1461000A,
    SUBDEVICE_1461000B = 0x1461000B,
    SUBDEVICE_14618011 = 0x14618011,
    SUBDEVICE_14628606 = 0x14628606,
    SUBDEVICE_14C70107 = 0x14C70107,
    SUBDEVICE_14F10187 = 0x14F10187,
    SUBDEVICE_14F10342 = 0x14F10342,
    SUBDEVICE_153B1166 = 0x153B1166,
    SUBDEVICE_15402580 = 0x15402580,
    SUBDEVICE_15544811 = 0x15544811,
    SUBDEVICE_15544813 = 0x15544813,
    SUBDEVICE_17DE08A1 = 0x17DE08A1,
    SUBDEVICE_17DE08A6 = 0x17DE08A6,
    SUBDEVICE_17DE08B2 = 0x17DE08B2,
    SUBDEVICE_17DEA8A6 = 0x17DEA8A6,
    SUBDEVICE_18220025 = 0x18220025,
    SUBDEVICE_185BE000 = 0x185BE000,
    SUBDEVICE_18ACD500 = 0x18ACD500,
    SUBDEVICE_18ACD810 = 0x18ACD810,
    SUBDEVICE_18ACD820 = 0x18ACD820,
    SUBDEVICE_18ACDB00 = 0x18ACDB00,
    SUBDEVICE_18ACDB11 = 0x18ACDB11,
    SUBDEVICE_18ACDB50 = 0x18ACDB50,
    SUBDEVICE_56542388 = 0x56542388,
    SUBDEVICE_70633000 = 0x70633000,
    SUBDEVICE_70635500 = 0x70635500
};



inline const char8* enumToString(PciSubDevice14F18800 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14F18800::NONE:               return "NONE";
        case PciSubDevice14F18800::SUBDEVICE_00702801: return "SUBDEVICE_00702801";
        case PciSubDevice14F18800::SUBDEVICE_00703400: return "SUBDEVICE_00703400";
        case PciSubDevice14F18800::SUBDEVICE_00703401: return "SUBDEVICE_00703401";
        case PciSubDevice14F18800::SUBDEVICE_00706902: return "SUBDEVICE_00706902";
        case PciSubDevice14F18800::SUBDEVICE_00707801: return "SUBDEVICE_00707801";
        case PciSubDevice14F18800::SUBDEVICE_00709001: return "SUBDEVICE_00709001";
        case PciSubDevice14F18800::SUBDEVICE_00709002: return "SUBDEVICE_00709002";
        case PciSubDevice14F18800::SUBDEVICE_00709200: return "SUBDEVICE_00709200";
        case PciSubDevice14F18800::SUBDEVICE_00709202: return "SUBDEVICE_00709202";
        case PciSubDevice14F18800::SUBDEVICE_00709402: return "SUBDEVICE_00709402";
        case PciSubDevice14F18800::SUBDEVICE_00709600: return "SUBDEVICE_00709600";
        case PciSubDevice14F18800::SUBDEVICE_00709802: return "SUBDEVICE_00709802";
        case PciSubDevice14F18800::SUBDEVICE_100200F8: return "SUBDEVICE_100200F8";
        case PciSubDevice14F18800::SUBDEVICE_100200F9: return "SUBDEVICE_100200F9";
        case PciSubDevice14F18800::SUBDEVICE_1002A101: return "SUBDEVICE_1002A101";
        case PciSubDevice14F18800::SUBDEVICE_10434823: return "SUBDEVICE_10434823";
        case PciSubDevice14F18800::SUBDEVICE_107D6611: return "SUBDEVICE_107D6611";
        case PciSubDevice14F18800::SUBDEVICE_107D6613: return "SUBDEVICE_107D6613";
        case PciSubDevice14F18800::SUBDEVICE_107D6620: return "SUBDEVICE_107D6620";
        case PciSubDevice14F18800::SUBDEVICE_107D663C: return "SUBDEVICE_107D663C";
        case PciSubDevice14F18800::SUBDEVICE_107D665F: return "SUBDEVICE_107D665F";
        case PciSubDevice14F18800::SUBDEVICE_10FCD003: return "SUBDEVICE_10FCD003";
        case PciSubDevice14F18800::SUBDEVICE_10FCD035: return "SUBDEVICE_10FCD035";
        case PciSubDevice14F18800::SUBDEVICE_14210334: return "SUBDEVICE_14210334";
        case PciSubDevice14F18800::SUBDEVICE_1461000A: return "SUBDEVICE_1461000A";
        case PciSubDevice14F18800::SUBDEVICE_1461000B: return "SUBDEVICE_1461000B";
        case PciSubDevice14F18800::SUBDEVICE_14618011: return "SUBDEVICE_14618011";
        case PciSubDevice14F18800::SUBDEVICE_14628606: return "SUBDEVICE_14628606";
        case PciSubDevice14F18800::SUBDEVICE_14C70107: return "SUBDEVICE_14C70107";
        case PciSubDevice14F18800::SUBDEVICE_14F10187: return "SUBDEVICE_14F10187";
        case PciSubDevice14F18800::SUBDEVICE_14F10342: return "SUBDEVICE_14F10342";
        case PciSubDevice14F18800::SUBDEVICE_153B1166: return "SUBDEVICE_153B1166";
        case PciSubDevice14F18800::SUBDEVICE_15402580: return "SUBDEVICE_15402580";
        case PciSubDevice14F18800::SUBDEVICE_15544811: return "SUBDEVICE_15544811";
        case PciSubDevice14F18800::SUBDEVICE_15544813: return "SUBDEVICE_15544813";
        case PciSubDevice14F18800::SUBDEVICE_17DE08A1: return "SUBDEVICE_17DE08A1";
        case PciSubDevice14F18800::SUBDEVICE_17DE08A6: return "SUBDEVICE_17DE08A6";
        case PciSubDevice14F18800::SUBDEVICE_17DE08B2: return "SUBDEVICE_17DE08B2";
        case PciSubDevice14F18800::SUBDEVICE_17DEA8A6: return "SUBDEVICE_17DEA8A6";
        case PciSubDevice14F18800::SUBDEVICE_18220025: return "SUBDEVICE_18220025";
        case PciSubDevice14F18800::SUBDEVICE_185BE000: return "SUBDEVICE_185BE000";
        case PciSubDevice14F18800::SUBDEVICE_18ACD500: return "SUBDEVICE_18ACD500";
        case PciSubDevice14F18800::SUBDEVICE_18ACD810: return "SUBDEVICE_18ACD810";
        case PciSubDevice14F18800::SUBDEVICE_18ACD820: return "SUBDEVICE_18ACD820";
        case PciSubDevice14F18800::SUBDEVICE_18ACDB00: return "SUBDEVICE_18ACDB00";
        case PciSubDevice14F18800::SUBDEVICE_18ACDB11: return "SUBDEVICE_18ACDB11";
        case PciSubDevice14F18800::SUBDEVICE_18ACDB50: return "SUBDEVICE_18ACDB50";
        case PciSubDevice14F18800::SUBDEVICE_56542388: return "SUBDEVICE_56542388";
        case PciSubDevice14F18800::SUBDEVICE_70633000: return "SUBDEVICE_70633000";
        case PciSubDevice14F18800::SUBDEVICE_70635500: return "SUBDEVICE_70635500";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice14F18800 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice14F18800 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14F18800::SUBDEVICE_00702801: return "Hauppauge WinTV 28xxx (Roslyn) models";
        case PciSubDevice14F18800::SUBDEVICE_00703400: return "WinTV 34604";
        case PciSubDevice14F18800::SUBDEVICE_00703401: return "Hauppauge WinTV 34xxx models";
        case PciSubDevice14F18800::SUBDEVICE_00706902: return "WinTV HVR-4000-HD";
        case PciSubDevice14F18800::SUBDEVICE_00707801: return "WinTV HVR-1800 MCE";
        case PciSubDevice14F18800::SUBDEVICE_00709001: return "Nova-T DVB-T";
        case PciSubDevice14F18800::SUBDEVICE_00709002: return "Nova-T DVB-T Model 909";
        case PciSubDevice14F18800::SUBDEVICE_00709200: return "Nova-SE2 DVB-S";
        case PciSubDevice14F18800::SUBDEVICE_00709202: return "Nova-S-Plus DVB-S";
        case PciSubDevice14F18800::SUBDEVICE_00709402: return "WinTV-HVR1100 DVB-T/Hybrid";
        case PciSubDevice14F18800::SUBDEVICE_00709600: return "WinTV 88x Video";
        case PciSubDevice14F18800::SUBDEVICE_00709802: return "WinTV-HVR1100 DVB-T/Hybrid (Low Profile)";
        case PciSubDevice14F18800::SUBDEVICE_100200F8: return "ATI TV Wonder Pro";
        case PciSubDevice14F18800::SUBDEVICE_100200F9: return "ATI TV Wonder";
        case PciSubDevice14F18800::SUBDEVICE_1002A101: return "HDTV Wonder";
        case PciSubDevice14F18800::SUBDEVICE_10434823: return "PVR-416";
        case PciSubDevice14F18800::SUBDEVICE_107D6611: return "Winfast TV 2000XP Expert";
        case PciSubDevice14F18800::SUBDEVICE_107D6613: return "Leadtek Winfast 2000XP Expert";
        case PciSubDevice14F18800::SUBDEVICE_107D6620: return "Leadtek Winfast DV2000";
        case PciSubDevice14F18800::SUBDEVICE_107D663C: return "Leadtek PVR 2000";
        case PciSubDevice14F18800::SUBDEVICE_107D665F: return "WinFast DTV1000-T";
        case PciSubDevice14F18800::SUBDEVICE_10FCD003: return "IODATA GV-VCP3/PCI";
        case PciSubDevice14F18800::SUBDEVICE_10FCD035: return "IODATA GV/BCTV7E";
        case PciSubDevice14F18800::SUBDEVICE_14210334: return "Instant TV DVB-T PCI";
        case PciSubDevice14F18800::SUBDEVICE_1461000A: return "AVerTV 303 (M126)";
        case PciSubDevice14F18800::SUBDEVICE_1461000B: return "AverTV Studio 303 (M126)";
        case PciSubDevice14F18800::SUBDEVICE_14618011: return "UltraTV Media Center PCI 550";
        case PciSubDevice14F18800::SUBDEVICE_14628606: return "MSI TV-@nywhere Master";
        case PciSubDevice14F18800::SUBDEVICE_14C70107: return "GDI Black Gold";
        case PciSubDevice14F18800::SUBDEVICE_14F10187: return "Conexant DVB-T reference design";
        case PciSubDevice14F18800::SUBDEVICE_14F10342: return "Digital-Logic MICROSPACE Entertainment Center (MEC)";
        case PciSubDevice14F18800::SUBDEVICE_153B1166: return "Cinergy 1400 DVB-T";
        case PciSubDevice14F18800::SUBDEVICE_15402580: return "Provideo PV259";
        case PciSubDevice14F18800::SUBDEVICE_15544811: return "PixelView";
        case PciSubDevice14F18800::SUBDEVICE_15544813: return "Club 3D ZAP1000 MCE Edition";
        case PciSubDevice14F18800::SUBDEVICE_17DE08A1: return "KWorld/VStream XPert DVB-T with cx22702";
        case PciSubDevice14F18800::SUBDEVICE_17DE08A6: return "KWorld/VStream XPert DVB-T";
        case PciSubDevice14F18800::SUBDEVICE_17DE08B2: return "KWorld DVB-S 100";
        case PciSubDevice14F18800::SUBDEVICE_17DEA8A6: return "digitalnow DNTV Live! DVB-T";
        case PciSubDevice14F18800::SUBDEVICE_18220025: return "digitalnow DNTV Live! DVB-T Pro";
        case PciSubDevice14F18800::SUBDEVICE_185BE000: return "VideoMate X500";
        case PciSubDevice14F18800::SUBDEVICE_18ACD500: return "FusionHDTV 5 Gold";
        case PciSubDevice14F18800::SUBDEVICE_18ACD810: return "FusionHDTV 3 Gold-Q";
        case PciSubDevice14F18800::SUBDEVICE_18ACD820: return "FusionHDTV 3 Gold-T";
        case PciSubDevice14F18800::SUBDEVICE_18ACDB00: return "FusionHDTV DVB-T1";
        case PciSubDevice14F18800::SUBDEVICE_18ACDB11: return "FusionHDTV DVB-T Plus";
        case PciSubDevice14F18800::SUBDEVICE_18ACDB50: return "FusionHDTV DVB-T Dual Digital";
        case PciSubDevice14F18800::SUBDEVICE_56542388: return "GoTView PCI Hybrid TV Tuner Card";
        case PciSubDevice14F18800::SUBDEVICE_70633000: return "pcHDTV HD3000 HDTV";
        case PciSubDevice14F18800::SUBDEVICE_70635500: return "pcHDTV HD-5500";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14F1_PCISUBDEVICE14F18800_H
