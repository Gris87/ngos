// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10EC_PCISUBDEVICE10EC8139_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10EC_PCISUBDEVICE10EC8139_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10EC8139: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_0357000A = 0x0357000A,
    SUBDEVICE_1025005A = 0x1025005A,
    SUBDEVICE_10258920 = 0x10258920,
    SUBDEVICE_10258921 = 0x10258921,
    SUBDEVICE_103C006A = 0x103C006A,
    SUBDEVICE_103C2A20 = 0x103C2A20,
    SUBDEVICE_103C30D9 = 0x103C30D9,
    SUBDEVICE_10431045 = 0x10431045,
    SUBDEVICE_10438109 = 0x10438109,
    SUBDEVICE_10718160 = 0x10718160,
    SUBDEVICE_10BD0320 = 0x10BD0320,
    SUBDEVICE_10EC8139 = 0x10EC8139,
    SUBDEVICE_10F78338 = 0x10F78338,
    SUBDEVICE_1113EC01 = 0x1113EC01,
    SUBDEVICE_11861104 = 0x11861104,
    SUBDEVICE_11861300 = 0x11861300,
    SUBDEVICE_11861320 = 0x11861320,
    SUBDEVICE_11868139 = 0x11868139,
    SUBDEVICE_11F68139 = 0x11F68139,
    SUBDEVICE_12592500 = 0x12592500,
    SUBDEVICE_12592503 = 0x12592503,
    SUBDEVICE_1385F31D = 0x1385F31D,
    SUBDEVICE_13952100 = 0x13952100,
    SUBDEVICE_1429D010 = 0x1429D010,
    SUBDEVICE_14329130 = 0x14329130,
    SUBDEVICE_14368139 = 0x14368139,
    SUBDEVICE_144DC00C = 0x144DC00C,
    SUBDEVICE_1458E000 = 0x1458E000,
    SUBDEVICE_14620131 = 0x14620131,
    SUBDEVICE_1462217C = 0x1462217C,
    SUBDEVICE_1462788C = 0x1462788C,
    SUBDEVICE_146C1439 = 0x146C1439,
    SUBDEVICE_14896001 = 0x14896001,
    SUBDEVICE_14896002 = 0x14896002,
    SUBDEVICE_149C139A = 0x149C139A,
    SUBDEVICE_149C8139 = 0x149C8139,
    SUBDEVICE_14CB0200 = 0x14CB0200,
    SUBDEVICE_15652300 = 0x15652300,
    SUBDEVICE_16317003 = 0x16317003,
    SUBDEVICE_16959001 = 0x16959001,
    SUBDEVICE_16EC00FF = 0x16EC00FF,
    SUBDEVICE_17995000 = 0x17995000,
    SUBDEVICE_17995010 = 0x17995010,
    SUBDEVICE_187E3303 = 0x187E3303,
    SUBDEVICE_19048139 = 0x19048139,
    SUBDEVICE_1AF41100 = 0x1AF41100,
    SUBDEVICE_26460001 = 0x26460001,
    SUBDEVICE_8E2E7000 = 0x8E2E7000,
    SUBDEVICE_8E2E7100 = 0x8E2E7100,
    SUBDEVICE_A0A00007 = 0xA0A00007
};



inline const char8* enumToString(PciSubDevice10EC8139 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10EC8139::NONE:               return "NONE";
        case PciSubDevice10EC8139::SUBDEVICE_0357000A: return "SUBDEVICE_0357000A";
        case PciSubDevice10EC8139::SUBDEVICE_1025005A: return "SUBDEVICE_1025005A";
        case PciSubDevice10EC8139::SUBDEVICE_10258920: return "SUBDEVICE_10258920";
        case PciSubDevice10EC8139::SUBDEVICE_10258921: return "SUBDEVICE_10258921";
        case PciSubDevice10EC8139::SUBDEVICE_103C006A: return "SUBDEVICE_103C006A";
        case PciSubDevice10EC8139::SUBDEVICE_103C2A20: return "SUBDEVICE_103C2A20";
        case PciSubDevice10EC8139::SUBDEVICE_103C30D9: return "SUBDEVICE_103C30D9";
        case PciSubDevice10EC8139::SUBDEVICE_10431045: return "SUBDEVICE_10431045";
        case PciSubDevice10EC8139::SUBDEVICE_10438109: return "SUBDEVICE_10438109";
        case PciSubDevice10EC8139::SUBDEVICE_10718160: return "SUBDEVICE_10718160";
        case PciSubDevice10EC8139::SUBDEVICE_10BD0320: return "SUBDEVICE_10BD0320";
        case PciSubDevice10EC8139::SUBDEVICE_10EC8139: return "SUBDEVICE_10EC8139";
        case PciSubDevice10EC8139::SUBDEVICE_10F78338: return "SUBDEVICE_10F78338";
        case PciSubDevice10EC8139::SUBDEVICE_1113EC01: return "SUBDEVICE_1113EC01";
        case PciSubDevice10EC8139::SUBDEVICE_11861104: return "SUBDEVICE_11861104";
        case PciSubDevice10EC8139::SUBDEVICE_11861300: return "SUBDEVICE_11861300";
        case PciSubDevice10EC8139::SUBDEVICE_11861320: return "SUBDEVICE_11861320";
        case PciSubDevice10EC8139::SUBDEVICE_11868139: return "SUBDEVICE_11868139";
        case PciSubDevice10EC8139::SUBDEVICE_11F68139: return "SUBDEVICE_11F68139";
        case PciSubDevice10EC8139::SUBDEVICE_12592500: return "SUBDEVICE_12592500";
        case PciSubDevice10EC8139::SUBDEVICE_12592503: return "SUBDEVICE_12592503";
        case PciSubDevice10EC8139::SUBDEVICE_1385F31D: return "SUBDEVICE_1385F31D";
        case PciSubDevice10EC8139::SUBDEVICE_13952100: return "SUBDEVICE_13952100";
        case PciSubDevice10EC8139::SUBDEVICE_1429D010: return "SUBDEVICE_1429D010";
        case PciSubDevice10EC8139::SUBDEVICE_14329130: return "SUBDEVICE_14329130";
        case PciSubDevice10EC8139::SUBDEVICE_14368139: return "SUBDEVICE_14368139";
        case PciSubDevice10EC8139::SUBDEVICE_144DC00C: return "SUBDEVICE_144DC00C";
        case PciSubDevice10EC8139::SUBDEVICE_1458E000: return "SUBDEVICE_1458E000";
        case PciSubDevice10EC8139::SUBDEVICE_14620131: return "SUBDEVICE_14620131";
        case PciSubDevice10EC8139::SUBDEVICE_1462217C: return "SUBDEVICE_1462217C";
        case PciSubDevice10EC8139::SUBDEVICE_1462788C: return "SUBDEVICE_1462788C";
        case PciSubDevice10EC8139::SUBDEVICE_146C1439: return "SUBDEVICE_146C1439";
        case PciSubDevice10EC8139::SUBDEVICE_14896001: return "SUBDEVICE_14896001";
        case PciSubDevice10EC8139::SUBDEVICE_14896002: return "SUBDEVICE_14896002";
        case PciSubDevice10EC8139::SUBDEVICE_149C139A: return "SUBDEVICE_149C139A";
        case PciSubDevice10EC8139::SUBDEVICE_149C8139: return "SUBDEVICE_149C8139";
        case PciSubDevice10EC8139::SUBDEVICE_14CB0200: return "SUBDEVICE_14CB0200";
        case PciSubDevice10EC8139::SUBDEVICE_15652300: return "SUBDEVICE_15652300";
        case PciSubDevice10EC8139::SUBDEVICE_16317003: return "SUBDEVICE_16317003";
        case PciSubDevice10EC8139::SUBDEVICE_16959001: return "SUBDEVICE_16959001";
        case PciSubDevice10EC8139::SUBDEVICE_16EC00FF: return "SUBDEVICE_16EC00FF";
        case PciSubDevice10EC8139::SUBDEVICE_17995000: return "SUBDEVICE_17995000";
        case PciSubDevice10EC8139::SUBDEVICE_17995010: return "SUBDEVICE_17995010";
        case PciSubDevice10EC8139::SUBDEVICE_187E3303: return "SUBDEVICE_187E3303";
        case PciSubDevice10EC8139::SUBDEVICE_19048139: return "SUBDEVICE_19048139";
        case PciSubDevice10EC8139::SUBDEVICE_1AF41100: return "SUBDEVICE_1AF41100";
        case PciSubDevice10EC8139::SUBDEVICE_26460001: return "SUBDEVICE_26460001";
        case PciSubDevice10EC8139::SUBDEVICE_8E2E7000: return "SUBDEVICE_8E2E7000";
        case PciSubDevice10EC8139::SUBDEVICE_8E2E7100: return "SUBDEVICE_8E2E7100";
        case PciSubDevice10EC8139::SUBDEVICE_A0A00007: return "SUBDEVICE_A0A00007";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10EC8139 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10EC8139 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10EC8139::SUBDEVICE_0357000A: return "TTP-Monitoring Card V2.0";
        case PciSubDevice10EC8139::SUBDEVICE_1025005A: return "TravelMate 290";
        case PciSubDevice10EC8139::SUBDEVICE_10258920: return "ALN-325";
        case PciSubDevice10EC8139::SUBDEVICE_10258921: return "ALN-325";
        case PciSubDevice10EC8139::SUBDEVICE_103C006A: return "NX9500";
        case PciSubDevice10EC8139::SUBDEVICE_103C2A20: return "Pavilion t3030.de Desktop PC";
        case PciSubDevice10EC8139::SUBDEVICE_103C30D9: return "Presario C700";
        case PciSubDevice10EC8139::SUBDEVICE_10431045: return "L8400B, L3C/S, X58LE notebook";
        case PciSubDevice10EC8139::SUBDEVICE_10438109: return "P5P800-MX Mainboard";
        case PciSubDevice10EC8139::SUBDEVICE_10718160: return "MIM2000";
        case PciSubDevice10EC8139::SUBDEVICE_10BD0320: return "EP-320X-R";
        case PciSubDevice10EC8139::SUBDEVICE_10EC8139: return "RTL-8100/8101L/8139 PCI Fast Ethernet Adapter";
        case PciSubDevice10EC8139::SUBDEVICE_10F78338: return "Panasonic CF-Y5 laptop";
        case PciSubDevice10EC8139::SUBDEVICE_1113EC01: return "LevelOne FNC-0107TX/FNC-0109TX";
        case PciSubDevice10EC8139::SUBDEVICE_11861104: return "DFE-520TX Fast Ethernet PCI Adapter (rev. D1)";
        case PciSubDevice10EC8139::SUBDEVICE_11861300: return "DFE-538TX";
        case PciSubDevice10EC8139::SUBDEVICE_11861320: return "SN5200";
        case PciSubDevice10EC8139::SUBDEVICE_11868139: return "DRN-32TX";
        case PciSubDevice10EC8139::SUBDEVICE_11F68139: return "FN22-3(A) LinxPRO Ethernet Adapter";
        case PciSubDevice10EC8139::SUBDEVICE_12592500: return "AT-2500TX";
        case PciSubDevice10EC8139::SUBDEVICE_12592503: return "AT-2500TX/ACPI";
        case PciSubDevice10EC8139::SUBDEVICE_1385F31D: return "FA311 v2";
        case PciSubDevice10EC8139::SUBDEVICE_13952100: return "AMB2100";
        case PciSubDevice10EC8139::SUBDEVICE_1429D010: return "ND010/ND012";
        case PciSubDevice10EC8139::SUBDEVICE_14329130: return "EN-9130TX";
        case PciSubDevice10EC8139::SUBDEVICE_14368139: return "RT8139";
        case PciSubDevice10EC8139::SUBDEVICE_144DC00C: return "P30/P35 notebook";
        case PciSubDevice10EC8139::SUBDEVICE_1458E000: return "GA-7VM400M/7VT600 Motherboard";
        case PciSubDevice10EC8139::SUBDEVICE_14620131: return "MS-1013 Notebook";
        case PciSubDevice10EC8139::SUBDEVICE_1462217C: return "Aspire L250";
        case PciSubDevice10EC8139::SUBDEVICE_1462788C: return "865PE Neo2-V Mainboard";
        case PciSubDevice10EC8139::SUBDEVICE_146C1439: return "FE-1439TX";
        case PciSubDevice10EC8139::SUBDEVICE_14896001: return "GF100TXRII";
        case PciSubDevice10EC8139::SUBDEVICE_14896002: return "GF100TXRA";
        case PciSubDevice10EC8139::SUBDEVICE_149C139A: return "LFE-8139ATX";
        case PciSubDevice10EC8139::SUBDEVICE_149C8139: return "LFE-8139TX";
        case PciSubDevice10EC8139::SUBDEVICE_14CB0200: return "LNR-100 Family 10/100 Base-TX Ethernet";
        case PciSubDevice10EC8139::SUBDEVICE_15652300: return "P4TSV Onboard LAN (RTL8100B)";
        case PciSubDevice10EC8139::SUBDEVICE_16317003: return "Onboard RTL8111 on GA-8SIML Rev1.0 Mainboard";
        case PciSubDevice10EC8139::SUBDEVICE_16959001: return "Onboard RTL8101L 10/100 MBit";
        case PciSubDevice10EC8139::SUBDEVICE_16EC00FF: return "USR997900A";
        case PciSubDevice10EC8139::SUBDEVICE_17995000: return "F5D5000 PCI Card/Desktop Network PCI Card";
        case PciSubDevice10EC8139::SUBDEVICE_17995010: return "F5D5010 CardBus Notebook Network Card";
        case PciSubDevice10EC8139::SUBDEVICE_187E3303: return "FN312";
        case PciSubDevice10EC8139::SUBDEVICE_19048139: return "RTL8139D Fast Ethernet Adapter";
        case PciSubDevice10EC8139::SUBDEVICE_1AF41100: return "QEMU Virtual Machine";
        case PciSubDevice10EC8139::SUBDEVICE_26460001: return "KNE120TX";
        case PciSubDevice10EC8139::SUBDEVICE_8E2E7000: return "KF-230TX";
        case PciSubDevice10EC8139::SUBDEVICE_8E2E7100: return "KF-230TX/2";
        case PciSubDevice10EC8139::SUBDEVICE_A0A00007: return "ALN-325C";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10EC_PCISUBDEVICE10EC8139_H
