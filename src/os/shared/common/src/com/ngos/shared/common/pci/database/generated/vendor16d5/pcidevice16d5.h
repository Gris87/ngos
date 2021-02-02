// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR16D5_PCIDEVICE16D5_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR16D5_PCIDEVICE16D5_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice16D5: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0504 = 0x0504,
    DEVICE_0520 = 0x0520,
    DEVICE_0521 = 0x0521,
    DEVICE_1020 = 0x1020,
    DEVICE_1065 = 0x1065,
    DEVICE_2004 = 0x2004,
    DEVICE_2020 = 0x2020,
    DEVICE_2065 = 0x2065,
    DEVICE_3020 = 0x3020,
    DEVICE_3065 = 0x3065,
    DEVICE_4243 = 0x4243,
    DEVICE_4248 = 0x4248,
    DEVICE_424B = 0x424B,
    DEVICE_4253 = 0x4253,
    DEVICE_4312 = 0x4312,
    DEVICE_4313 = 0x4313,
    DEVICE_4322 = 0x4322,
    DEVICE_4323 = 0x4323,
    DEVICE_4350 = 0x4350,
    DEVICE_4353 = 0x4353,
    DEVICE_4357 = 0x4357,
    DEVICE_4457 = 0x4457,
    DEVICE_4471 = 0x4471,
    DEVICE_4473 = 0x4473,
    DEVICE_464D = 0x464D,
    DEVICE_4850 = 0x4850,
    DEVICE_4A42 = 0x4A42,
    DEVICE_4A50 = 0x4A50,
    DEVICE_4A56 = 0x4A56,
    DEVICE_4B47 = 0x4B47,
    DEVICE_4C40 = 0x4C40,
    DEVICE_4C60 = 0x4C60,
    DEVICE_4D4D = 0x4D4D,
    DEVICE_4D4E = 0x4D4E,
    DEVICE_524D = 0x524D,
    DEVICE_5335 = 0x5335,
    DEVICE_5456 = 0x5456,
    DEVICE_5601 = 0x5601,
    DEVICE_5602 = 0x5602,
    DEVICE_5603 = 0x5603,
    DEVICE_5604 = 0x5604,
    DEVICE_5605 = 0x5605,
    DEVICE_5606 = 0x5606,
    DEVICE_5701 = 0x5701,
    DEVICE_5702 = 0x5702,
    DEVICE_5801 = 0x5801,
    DEVICE_5802 = 0x5802,
    DEVICE_5803 = 0x5803,
    DEVICE_5804 = 0x5804,
    DEVICE_5807 = 0x5807,
    DEVICE_5808 = 0x5808,
    DEVICE_5901 = 0x5901,
    DEVICE_6301 = 0x6301,
    DEVICE_6302 = 0x6302,
    DEVICE_6303 = 0x6303,
    DEVICE_6304 = 0x6304,
    DEVICE_7000 = 0x7000,
    DEVICE_7001 = 0x7001,
    DEVICE_7002 = 0x7002,
    DEVICE_7003 = 0x7003,
    DEVICE_7004 = 0x7004,
    DEVICE_7005 = 0x7005,
    DEVICE_7006 = 0x7006,
    DEVICE_7007 = 0x7007,
    DEVICE_7011 = 0x7011,
    DEVICE_7012 = 0x7012,
    DEVICE_7013 = 0x7013,
    DEVICE_7014 = 0x7014,
    DEVICE_7015 = 0x7015,
    DEVICE_7016 = 0x7016,
    DEVICE_7017 = 0x7017,
    DEVICE_7018 = 0x7018,
    DEVICE_7019 = 0x7019,
    DEVICE_701A = 0x701A,
    DEVICE_701B = 0x701B,
    DEVICE_701C = 0x701C,
    DEVICE_701D = 0x701D,
    DEVICE_7021 = 0x7021,
    DEVICE_7022 = 0x7022,
    DEVICE_7023 = 0x7023,
    DEVICE_7024 = 0x7024,
    DEVICE_7027 = 0x7027,
    DEVICE_7029 = 0x7029,
    DEVICE_702A = 0x702A,
    DEVICE_702B = 0x702B,
    DEVICE_7031 = 0x7031,
    DEVICE_7032 = 0x7032,
    DEVICE_7033 = 0x7033,
    DEVICE_7042 = 0x7042,
    DEVICE_7043 = 0x7043,
    DEVICE_7044 = 0x7044,
    DEVICE_7051 = 0x7051,
    DEVICE_7052 = 0x7052,
    DEVICE_7053 = 0x7053,
    DEVICE_7054 = 0x7054
};



inline const char8* enumToString(PciDevice16D5 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice16D5::NONE:        return "NONE";
        case PciDevice16D5::DEVICE_0504: return "DEVICE_0504";
        case PciDevice16D5::DEVICE_0520: return "DEVICE_0520";
        case PciDevice16D5::DEVICE_0521: return "DEVICE_0521";
        case PciDevice16D5::DEVICE_1020: return "DEVICE_1020";
        case PciDevice16D5::DEVICE_1065: return "DEVICE_1065";
        case PciDevice16D5::DEVICE_2004: return "DEVICE_2004";
        case PciDevice16D5::DEVICE_2020: return "DEVICE_2020";
        case PciDevice16D5::DEVICE_2065: return "DEVICE_2065";
        case PciDevice16D5::DEVICE_3020: return "DEVICE_3020";
        case PciDevice16D5::DEVICE_3065: return "DEVICE_3065";
        case PciDevice16D5::DEVICE_4243: return "DEVICE_4243";
        case PciDevice16D5::DEVICE_4248: return "DEVICE_4248";
        case PciDevice16D5::DEVICE_424B: return "DEVICE_424B";
        case PciDevice16D5::DEVICE_4253: return "DEVICE_4253";
        case PciDevice16D5::DEVICE_4312: return "DEVICE_4312";
        case PciDevice16D5::DEVICE_4313: return "DEVICE_4313";
        case PciDevice16D5::DEVICE_4322: return "DEVICE_4322";
        case PciDevice16D5::DEVICE_4323: return "DEVICE_4323";
        case PciDevice16D5::DEVICE_4350: return "DEVICE_4350";
        case PciDevice16D5::DEVICE_4353: return "DEVICE_4353";
        case PciDevice16D5::DEVICE_4357: return "DEVICE_4357";
        case PciDevice16D5::DEVICE_4457: return "DEVICE_4457";
        case PciDevice16D5::DEVICE_4471: return "DEVICE_4471";
        case PciDevice16D5::DEVICE_4473: return "DEVICE_4473";
        case PciDevice16D5::DEVICE_464D: return "DEVICE_464D";
        case PciDevice16D5::DEVICE_4850: return "DEVICE_4850";
        case PciDevice16D5::DEVICE_4A42: return "DEVICE_4A42";
        case PciDevice16D5::DEVICE_4A50: return "DEVICE_4A50";
        case PciDevice16D5::DEVICE_4A56: return "DEVICE_4A56";
        case PciDevice16D5::DEVICE_4B47: return "DEVICE_4B47";
        case PciDevice16D5::DEVICE_4C40: return "DEVICE_4C40";
        case PciDevice16D5::DEVICE_4C60: return "DEVICE_4C60";
        case PciDevice16D5::DEVICE_4D4D: return "DEVICE_4D4D";
        case PciDevice16D5::DEVICE_4D4E: return "DEVICE_4D4E";
        case PciDevice16D5::DEVICE_524D: return "DEVICE_524D";
        case PciDevice16D5::DEVICE_5335: return "DEVICE_5335";
        case PciDevice16D5::DEVICE_5456: return "DEVICE_5456";
        case PciDevice16D5::DEVICE_5601: return "DEVICE_5601";
        case PciDevice16D5::DEVICE_5602: return "DEVICE_5602";
        case PciDevice16D5::DEVICE_5603: return "DEVICE_5603";
        case PciDevice16D5::DEVICE_5604: return "DEVICE_5604";
        case PciDevice16D5::DEVICE_5605: return "DEVICE_5605";
        case PciDevice16D5::DEVICE_5606: return "DEVICE_5606";
        case PciDevice16D5::DEVICE_5701: return "DEVICE_5701";
        case PciDevice16D5::DEVICE_5702: return "DEVICE_5702";
        case PciDevice16D5::DEVICE_5801: return "DEVICE_5801";
        case PciDevice16D5::DEVICE_5802: return "DEVICE_5802";
        case PciDevice16D5::DEVICE_5803: return "DEVICE_5803";
        case PciDevice16D5::DEVICE_5804: return "DEVICE_5804";
        case PciDevice16D5::DEVICE_5807: return "DEVICE_5807";
        case PciDevice16D5::DEVICE_5808: return "DEVICE_5808";
        case PciDevice16D5::DEVICE_5901: return "DEVICE_5901";
        case PciDevice16D5::DEVICE_6301: return "DEVICE_6301";
        case PciDevice16D5::DEVICE_6302: return "DEVICE_6302";
        case PciDevice16D5::DEVICE_6303: return "DEVICE_6303";
        case PciDevice16D5::DEVICE_6304: return "DEVICE_6304";
        case PciDevice16D5::DEVICE_7000: return "DEVICE_7000";
        case PciDevice16D5::DEVICE_7001: return "DEVICE_7001";
        case PciDevice16D5::DEVICE_7002: return "DEVICE_7002";
        case PciDevice16D5::DEVICE_7003: return "DEVICE_7003";
        case PciDevice16D5::DEVICE_7004: return "DEVICE_7004";
        case PciDevice16D5::DEVICE_7005: return "DEVICE_7005";
        case PciDevice16D5::DEVICE_7006: return "DEVICE_7006";
        case PciDevice16D5::DEVICE_7007: return "DEVICE_7007";
        case PciDevice16D5::DEVICE_7011: return "DEVICE_7011";
        case PciDevice16D5::DEVICE_7012: return "DEVICE_7012";
        case PciDevice16D5::DEVICE_7013: return "DEVICE_7013";
        case PciDevice16D5::DEVICE_7014: return "DEVICE_7014";
        case PciDevice16D5::DEVICE_7015: return "DEVICE_7015";
        case PciDevice16D5::DEVICE_7016: return "DEVICE_7016";
        case PciDevice16D5::DEVICE_7017: return "DEVICE_7017";
        case PciDevice16D5::DEVICE_7018: return "DEVICE_7018";
        case PciDevice16D5::DEVICE_7019: return "DEVICE_7019";
        case PciDevice16D5::DEVICE_701A: return "DEVICE_701A";
        case PciDevice16D5::DEVICE_701B: return "DEVICE_701B";
        case PciDevice16D5::DEVICE_701C: return "DEVICE_701C";
        case PciDevice16D5::DEVICE_701D: return "DEVICE_701D";
        case PciDevice16D5::DEVICE_7021: return "DEVICE_7021";
        case PciDevice16D5::DEVICE_7022: return "DEVICE_7022";
        case PciDevice16D5::DEVICE_7023: return "DEVICE_7023";
        case PciDevice16D5::DEVICE_7024: return "DEVICE_7024";
        case PciDevice16D5::DEVICE_7027: return "DEVICE_7027";
        case PciDevice16D5::DEVICE_7029: return "DEVICE_7029";
        case PciDevice16D5::DEVICE_702A: return "DEVICE_702A";
        case PciDevice16D5::DEVICE_702B: return "DEVICE_702B";
        case PciDevice16D5::DEVICE_7031: return "DEVICE_7031";
        case PciDevice16D5::DEVICE_7032: return "DEVICE_7032";
        case PciDevice16D5::DEVICE_7033: return "DEVICE_7033";
        case PciDevice16D5::DEVICE_7042: return "DEVICE_7042";
        case PciDevice16D5::DEVICE_7043: return "DEVICE_7043";
        case PciDevice16D5::DEVICE_7044: return "DEVICE_7044";
        case PciDevice16D5::DEVICE_7051: return "DEVICE_7051";
        case PciDevice16D5::DEVICE_7052: return "DEVICE_7052";
        case PciDevice16D5::DEVICE_7053: return "DEVICE_7053";
        case PciDevice16D5::DEVICE_7054: return "DEVICE_7054";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice16D5 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice16D5 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice16D5::DEVICE_0504: return "PMC-DX504 Reconfigurable FPGA with LVDS I/O";
        case PciDevice16D5::DEVICE_0520: return "PMC520 Serial Communication, 232 Octal";
        case PciDevice16D5::DEVICE_0521: return "PMC521 Serial Communication, 422/485 Octal";
        case PciDevice16D5::DEVICE_1020: return "PMC-AX1020 Reconfigurable FPGA with A/D & D/A";
        case PciDevice16D5::DEVICE_1065: return "PMC-AX1065 Reconfigurable FPGA with A/D & D/A";
        case PciDevice16D5::DEVICE_2004: return "PMC-DX2004 Reconfigurable FPGA with LVDS I/O";
        case PciDevice16D5::DEVICE_2020: return "PMC-AX2020 Reconfigurable FPGA with A/D & D/A";
        case PciDevice16D5::DEVICE_2065: return "PMC-AX2065 Reconfigurable FPGA with A/D & D/A";
        case PciDevice16D5::DEVICE_3020: return "PMC-AX3020 Reconfigurable FPGA with A/D & D/A";
        case PciDevice16D5::DEVICE_3065: return "PMC-AX3065 Reconfigurable FPGA with A/D & D/A";
        case PciDevice16D5::DEVICE_4243: return "PMC424, APC424, AcPC424 Digital I/O and Counter Timer Module";
        case PciDevice16D5::DEVICE_4248: return "PMC464, APC464, AcPC464 Digital I/O and Counter Timer Module";
        case PciDevice16D5::DEVICE_424B: return "PMC-DX2002 Reconfigurable FPGA with Differential I/O";
        case PciDevice16D5::DEVICE_4253: return "PMC-DX503 Reconfigurable FPGA with TTL and Differential I/O";
        case PciDevice16D5::DEVICE_4312: return "PMC-CX1002 Reconfigurable Conduction-Cooled FPGA Virtex-II with Differential I/O";
        case PciDevice16D5::DEVICE_4313: return "PMC-CX1003 Reconfigurable Conduction-Cooled FPGA Virtex-II with CMOS and Differential I/O";
        case PciDevice16D5::DEVICE_4322: return "PMC-CX2002 Reconfigurable Conduction-Cooled FPGA Virtex-II with Differential I/O";
        case PciDevice16D5::DEVICE_4323: return "PMC-CX2003 Reconfigurable Conduction-Cooled FPGA Virtex-II with CMOS and Differential I/O";
        case PciDevice16D5::DEVICE_4350: return "PMC-DX501 Reconfigurable Digital I/O Module";
        case PciDevice16D5::DEVICE_4353: return "PMC-DX2003 Reconfigurable FPGA with TTL and Differential I/O";
        case PciDevice16D5::DEVICE_4357: return "PMC-DX502 Reconfigurable Differential I/O Module";
        case PciDevice16D5::DEVICE_4457: return "PMC730, APC730, AcPC730 Multifunction Module";
        case PciDevice16D5::DEVICE_4471: return "XMC730 Multi-function I/O module with front I/O";
        case PciDevice16D5::DEVICE_4473: return "XMC730CC Multi-function I/O module with rear I/O Conduction-cooled";
        case PciDevice16D5::DEVICE_464D: return "PMC408 32-Channel Digital Input/Output Module";
        case PciDevice16D5::DEVICE_4850: return "PMC220-16 12-Bit Analog Output Module";
        case PciDevice16D5::DEVICE_4A42: return "PMC483, APC483, AcPC483 Counter Timer Module";
        case PciDevice16D5::DEVICE_4A50: return "PMC484, APC484, AcPC484 Counter Timer Module";
        case PciDevice16D5::DEVICE_4A56: return "PMC230 16-Bit Analog Output Module";
        case PciDevice16D5::DEVICE_4B47: return "PMC330, APC330, AcPC330 Analog Input Module, 16-bit A/D";
        case PciDevice16D5::DEVICE_4C40: return "PMC-LX40 Reconfigurable Virtex-4 FPGA with plug-in I/O";
        case PciDevice16D5::DEVICE_4C60: return "PMC-LX60 Reconfigurable Virtex-4 FPGA with plug-in I/O";
        case PciDevice16D5::DEVICE_4D4D: return "PMC341, APC341, AcPC341 Analog Input Module, Simultaneous Sample & Hold";
        case PciDevice16D5::DEVICE_4D4E: return "PMC482, APC482, AcPC482 Counter Timer Board";
        case PciDevice16D5::DEVICE_524D: return "PMC-DX2001 Reconfigurable FPGA with TTL I/O";
        case PciDevice16D5::DEVICE_5335: return "PMC-SX35 Reconfigurable Virtex-4 FPGA with plug-in I/O";
        case PciDevice16D5::DEVICE_5456: return "PMC470 48-Channel Digital Input/Output Module";
        case PciDevice16D5::DEVICE_5601: return "PMC-VLX85 Reconfigurable Virtex-5 FPGA with plug-in I/O";
        case PciDevice16D5::DEVICE_5602: return "PMC-VLX110 Reconfigurable Virtex-5 FPGA with plug-in I/O";
        case PciDevice16D5::DEVICE_5603: return "PMC-VSX95 Reconfigurable Virtex-5 FPGA with plug-in I/O";
        case PciDevice16D5::DEVICE_5604: return "PMC-VLX155 Reconfigurable Virtex-5 FPGA with plug-in I/O";
        case PciDevice16D5::DEVICE_5605: return "PMC-VFX70 Reconfigurable Virtex-5 FPGA with plug-in I/O";
        case PciDevice16D5::DEVICE_5606: return "PMC-VLX155-1M Reconfigurable Virtex-5 FPGA with plug-in I/O";
        case PciDevice16D5::DEVICE_5701: return "PMC-SLX150: Reconfigurable Spartan-6 FPGA with plug-in I/O";
        case PciDevice16D5::DEVICE_5702: return "PMC-SLX150-1M: Reconfigurable Spartan-6 FPGA with plug-in I/O";
        case PciDevice16D5::DEVICE_5801: return "XMC-VLX85 Reconfigurable Virtex-5 FPGA with plug-in I/O";
        case PciDevice16D5::DEVICE_5802: return "XMC-VLX110 Reconfigurable Virtex-5 FPGA with plug-in I/O";
        case PciDevice16D5::DEVICE_5803: return "XMC-VSX95 Reconfigurable Virtex-5 FPGA with plug-in I/O";
        case PciDevice16D5::DEVICE_5804: return "XMC-VLX155 Reconfigurable Virtex-5 FPGA with plug-in I/O";
        case PciDevice16D5::DEVICE_5807: return "XMC-SLX150: Reconfigurable Spartan-6 FPGA with plug-in I/O";
        case PciDevice16D5::DEVICE_5808: return "XMC-SLX150-1M: Reconfigurable Spartan-6 FPGA with plug-in I/O";
        case PciDevice16D5::DEVICE_5901: return "APCe8650 PCI Express IndustryPack Carrier Card";
        case PciDevice16D5::DEVICE_6301: return "XMC Module with user-configurable Virtex-6 FPGA, 240k logic cells, SFP front I/O";
        case PciDevice16D5::DEVICE_6302: return "XMC Module with user-configurable Virtex-6 FPGA, 365k logic cells, SFP front I/O";
        case PciDevice16D5::DEVICE_6303: return "XMC Module with user-configurable Virtex-6 FPGA, 240k logic cells, no front I/O";
        case PciDevice16D5::DEVICE_6304: return "XMC Module with user-configurable Virtex-6 FPGA, 365k logic cells, no front I/O";
        case PciDevice16D5::DEVICE_7000: return "XMC-7K325F: User-configurable Kintex-7 FPGA, 325k logic cells plus SFP front I/O";
        case PciDevice16D5::DEVICE_7001: return "XMC-7K410F: User-configurable Kintex-7 FPGA, 410k logic cells plus SFP front I/O";
        case PciDevice16D5::DEVICE_7002: return "XMC-7K325AX: User-Configurable Kintex-7 FPGA, 325k logic cells with AXM Plug-In I/O";
        case PciDevice16D5::DEVICE_7003: return "XMC-7K410AX: User-Configurable Kintex-7 FPGA, 410k logic cells with AXM Plug-In I/O";
        case PciDevice16D5::DEVICE_7004: return "XMC-7K325CC: User-Configurable Kintex-7 FPGA, 325k logic cells, conduction-cooled";
        case PciDevice16D5::DEVICE_7005: return "XMC-7K410CC: User-Configurable Kintex-7 FPGA, 410k logic cells, conduction-cooled";
        case PciDevice16D5::DEVICE_7006: return "XMC-7A200: User-Configurable Artix-7 FPGA, 200k logic cells with Plug-In I/O";
        case PciDevice16D5::DEVICE_7007: return "XMC-7A200CC: User-Configurable Conduction-Cooled Artix-7 FPGA, with 200k logic cells";
        case PciDevice16D5::DEVICE_7011: return "AP440-1: 32-Channel Isolated Digital Input Module";
        case PciDevice16D5::DEVICE_7012: return "AP440-2: 32-Channel Isolated Digital Input Module";
        case PciDevice16D5::DEVICE_7013: return "AP440-3: 32-Channel Isolated Digital Input Module";
        case PciDevice16D5::DEVICE_7014: return "AP445: 32-Channel Isolated Digital Output Module";
        case PciDevice16D5::DEVICE_7015: return "AP471 48-Channel TTL Level Digital Input/Output Module";
        case PciDevice16D5::DEVICE_7016: return "AP470 48-Channel TTL Level Digital Input/Output Module";
        case PciDevice16D5::DEVICE_7017: return "AP323 16-bit, 20 or 40 Channel Analog Input Module";
        case PciDevice16D5::DEVICE_7018: return "AP408: 32-Channel Digital I/O Module";
        case PciDevice16D5::DEVICE_7019: return "AP341 14-bit, 16-Channel Simultaneous Conversion Analog Input Module";
        case PciDevice16D5::DEVICE_701A: return "AP220-16 12-Bit, 16-Channel Analog Output Module";
        case PciDevice16D5::DEVICE_701B: return "AP231-16 16-Bit, 16-Channel Analog Output Module";
        case PciDevice16D5::DEVICE_701C: return "AP225 12-Bit, 16-Channel Analog Output Module with Waveform Memory";
        case PciDevice16D5::DEVICE_701D: return "AP235 16-Bit, 16-Channel Analog Output Module with Waveform Memory";
        case PciDevice16D5::DEVICE_7021: return "APA7-201 Reconfigurable Artix-7 FPGA module 48 TTL channels";
        case PciDevice16D5::DEVICE_7022: return "APA7-202 Reconfigurable Artix-7 FPGA module 24 RS485 channels";
        case PciDevice16D5::DEVICE_7023: return "APA7-203 Reconfigurable Artix-7 FPGA module 24 TTL & 12 RS485 channels";
        case PciDevice16D5::DEVICE_7024: return "APA7-204 Reconfigurable Artix-7 FPGA module 24 LVDS channels";
        case PciDevice16D5::DEVICE_7027: return "AP418 16-Channel High Voltage Digital Input/Output Module";
        case PciDevice16D5::DEVICE_7029: return "AP342 14-bit, 12-Channel Isolated Simultaneous Conversion Analog Input Module";
        case PciDevice16D5::DEVICE_702A: return "AP226 12-Bit, 8-Channel Isolated Analog Output Module";
        case PciDevice16D5::DEVICE_702B: return "AP236 16-Bit, 8-Channel Isolated Analog Output Module";
        case PciDevice16D5::DEVICE_7031: return "AP441-1: 32-Channel Isolated Digital Input Module";
        case PciDevice16D5::DEVICE_7032: return "AP441-2: 32-Channel Isolated Digital Input Module";
        case PciDevice16D5::DEVICE_7033: return "AP441-3: 32-Channel Isolated Digital Input Module";
        case PciDevice16D5::DEVICE_7042: return "AP482 Counter Timer Module with TTL Level Input/Output";
        case PciDevice16D5::DEVICE_7043: return "AP483 Counter Timer Module with TTL Level and RS422 Input/Output";
        case PciDevice16D5::DEVICE_7044: return "AP484 Counter Timer Module with RS422 Input/Output";
        case PciDevice16D5::DEVICE_7051: return "APA7-501 Reconfigurable Artix-7 52, 160 Cell FPGA module 48 TTL channels";
        case PciDevice16D5::DEVICE_7052: return "APA7-502 Reconfigurable Artix-7 52, 160 Cell FPGA module 24 RS485 channels";
        case PciDevice16D5::DEVICE_7053: return "APA7-503 Reconfigurable Artix-7 52, 160 Cell FPGA module 24 TTL & 12 RS485 channels";
        case PciDevice16D5::DEVICE_7054: return "APA7-504 Reconfigurable Artix-7 52, 160 Cell FPGA module 24 LVDS channels";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR16D5_PCIDEVICE16D5_H
