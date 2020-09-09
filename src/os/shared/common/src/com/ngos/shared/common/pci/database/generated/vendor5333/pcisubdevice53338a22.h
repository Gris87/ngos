// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR5333_PCISUBDEVICE53338A22_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR5333_PCISUBDEVICE53338A22_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice53338A22: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10338068 = 0x10338068,
    SUBDEVICE_10338069 = 0x10338069,
    SUBDEVICE_10338110 = 0x10338110,
    SUBDEVICE_105D0018 = 0x105D0018,
    SUBDEVICE_105D002A = 0x105D002A,
    SUBDEVICE_105D003A = 0x105D003A,
    SUBDEVICE_105D092F = 0x105D092F,
    SUBDEVICE_10924207 = 0x10924207,
    SUBDEVICE_10924800 = 0x10924800,
    SUBDEVICE_10924807 = 0x10924807,
    SUBDEVICE_10924808 = 0x10924808,
    SUBDEVICE_10924809 = 0x10924809,
    SUBDEVICE_1092480E = 0x1092480E,
    SUBDEVICE_10924904 = 0x10924904,
    SUBDEVICE_10924905 = 0x10924905,
    SUBDEVICE_10924A09 = 0x10924A09,
    SUBDEVICE_10924A0B = 0x10924A0B,
    SUBDEVICE_10924A0F = 0x10924A0F,
    SUBDEVICE_10924E01 = 0x10924E01,
    SUBDEVICE_1102101D = 0x1102101D,
    SUBDEVICE_1102101E = 0x1102101E,
    SUBDEVICE_53338100 = 0x53338100,
    SUBDEVICE_53338110 = 0x53338110,
    SUBDEVICE_53338125 = 0x53338125,
    SUBDEVICE_53338143 = 0x53338143,
    SUBDEVICE_53338A22 = 0x53338A22,
    SUBDEVICE_53338A2E = 0x53338A2E,
    SUBDEVICE_53339125 = 0x53339125,
    SUBDEVICE_53339143 = 0x53339143
};



inline const char8* enumToString(PciSubDevice53338A22 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice53338A22::NONE:               return "NONE";
        case PciSubDevice53338A22::SUBDEVICE_10338068: return "SUBDEVICE_10338068";
        case PciSubDevice53338A22::SUBDEVICE_10338069: return "SUBDEVICE_10338069";
        case PciSubDevice53338A22::SUBDEVICE_10338110: return "SUBDEVICE_10338110";
        case PciSubDevice53338A22::SUBDEVICE_105D0018: return "SUBDEVICE_105D0018";
        case PciSubDevice53338A22::SUBDEVICE_105D002A: return "SUBDEVICE_105D002A";
        case PciSubDevice53338A22::SUBDEVICE_105D003A: return "SUBDEVICE_105D003A";
        case PciSubDevice53338A22::SUBDEVICE_105D092F: return "SUBDEVICE_105D092F";
        case PciSubDevice53338A22::SUBDEVICE_10924207: return "SUBDEVICE_10924207";
        case PciSubDevice53338A22::SUBDEVICE_10924800: return "SUBDEVICE_10924800";
        case PciSubDevice53338A22::SUBDEVICE_10924807: return "SUBDEVICE_10924807";
        case PciSubDevice53338A22::SUBDEVICE_10924808: return "SUBDEVICE_10924808";
        case PciSubDevice53338A22::SUBDEVICE_10924809: return "SUBDEVICE_10924809";
        case PciSubDevice53338A22::SUBDEVICE_1092480E: return "SUBDEVICE_1092480E";
        case PciSubDevice53338A22::SUBDEVICE_10924904: return "SUBDEVICE_10924904";
        case PciSubDevice53338A22::SUBDEVICE_10924905: return "SUBDEVICE_10924905";
        case PciSubDevice53338A22::SUBDEVICE_10924A09: return "SUBDEVICE_10924A09";
        case PciSubDevice53338A22::SUBDEVICE_10924A0B: return "SUBDEVICE_10924A0B";
        case PciSubDevice53338A22::SUBDEVICE_10924A0F: return "SUBDEVICE_10924A0F";
        case PciSubDevice53338A22::SUBDEVICE_10924E01: return "SUBDEVICE_10924E01";
        case PciSubDevice53338A22::SUBDEVICE_1102101D: return "SUBDEVICE_1102101D";
        case PciSubDevice53338A22::SUBDEVICE_1102101E: return "SUBDEVICE_1102101E";
        case PciSubDevice53338A22::SUBDEVICE_53338100: return "SUBDEVICE_53338100";
        case PciSubDevice53338A22::SUBDEVICE_53338110: return "SUBDEVICE_53338110";
        case PciSubDevice53338A22::SUBDEVICE_53338125: return "SUBDEVICE_53338125";
        case PciSubDevice53338A22::SUBDEVICE_53338143: return "SUBDEVICE_53338143";
        case PciSubDevice53338A22::SUBDEVICE_53338A22: return "SUBDEVICE_53338A22";
        case PciSubDevice53338A22::SUBDEVICE_53338A2E: return "SUBDEVICE_53338A2E";
        case PciSubDevice53338A22::SUBDEVICE_53339125: return "SUBDEVICE_53339125";
        case PciSubDevice53338A22::SUBDEVICE_53339143: return "SUBDEVICE_53339143";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice53338A22 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice53338A22 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice53338A22::SUBDEVICE_10338068: return "Savage 4";
        case PciSubDevice53338A22::SUBDEVICE_10338069: return "Savage 4";
        case PciSubDevice53338A22::SUBDEVICE_10338110: return "Savage 4 LT";
        case PciSubDevice53338A22::SUBDEVICE_105D0018: return "SR9 8Mb SDRAM";
        case PciSubDevice53338A22::SUBDEVICE_105D002A: return "SR9 Pro 16Mb SDRAM";
        case PciSubDevice53338A22::SUBDEVICE_105D003A: return "SR9 Pro 32Mb SDRAM";
        case PciSubDevice53338A22::SUBDEVICE_105D092F: return "SR9 Pro+ 16Mb SGRAM";
        case PciSubDevice53338A22::SUBDEVICE_10924207: return "Stealth III S540";
        case PciSubDevice53338A22::SUBDEVICE_10924800: return "Stealth III S540";
        case PciSubDevice53338A22::SUBDEVICE_10924807: return "SpeedStar A90";
        case PciSubDevice53338A22::SUBDEVICE_10924808: return "Stealth III S540";
        case PciSubDevice53338A22::SUBDEVICE_10924809: return "Stealth III S540";
        case PciSubDevice53338A22::SUBDEVICE_1092480E: return "Stealth III S540";
        case PciSubDevice53338A22::SUBDEVICE_10924904: return "Stealth III S520";
        case PciSubDevice53338A22::SUBDEVICE_10924905: return "SpeedStar A200";
        case PciSubDevice53338A22::SUBDEVICE_10924A09: return "Stealth III S540";
        case PciSubDevice53338A22::SUBDEVICE_10924A0B: return "Stealth III S540 Xtreme";
        case PciSubDevice53338A22::SUBDEVICE_10924A0F: return "Stealth III S540";
        case PciSubDevice53338A22::SUBDEVICE_10924E01: return "Stealth III S540";
        case PciSubDevice53338A22::SUBDEVICE_1102101D: return "3d Blaster Savage 4";
        case PciSubDevice53338A22::SUBDEVICE_1102101E: return "3d Blaster Savage 4";
        case PciSubDevice53338A22::SUBDEVICE_53338100: return "86C394-397 Savage4 SDRAM 100";
        case PciSubDevice53338A22::SUBDEVICE_53338110: return "86C394-397 Savage4 SDRAM 110";
        case PciSubDevice53338A22::SUBDEVICE_53338125: return "86C394-397 Savage4 SDRAM 125";
        case PciSubDevice53338A22::SUBDEVICE_53338143: return "86C394-397 Savage4 SDRAM 143";
        case PciSubDevice53338A22::SUBDEVICE_53338A22: return "86C394-397 Savage4";
        case PciSubDevice53338A22::SUBDEVICE_53338A2E: return "86C394-397 Savage4 32bit";
        case PciSubDevice53338A22::SUBDEVICE_53339125: return "86C394-397 Savage4 SGRAM 125";
        case PciSubDevice53338A22::SUBDEVICE_53339143: return "86C394-397 Savage4 SGRAM 143";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR5333_PCISUBDEVICE53338A22_H
