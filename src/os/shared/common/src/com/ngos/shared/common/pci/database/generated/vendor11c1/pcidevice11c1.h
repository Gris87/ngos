// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11C1_PCIDEVICE11C1_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11C1_PCIDEVICE11C1_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice11C1: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0440 = 0x0440,
    DEVICE_0441 = 0x0441,
    DEVICE_0442 = 0x0442,
    DEVICE_0443 = 0x0443,
    DEVICE_0444 = 0x0444,
    DEVICE_0445 = 0x0445,
    DEVICE_0446 = 0x0446,
    DEVICE_0447 = 0x0447,
    DEVICE_0448 = 0x0448,
    DEVICE_0449 = 0x0449,
    DEVICE_044A = 0x044A,
    DEVICE_044B = 0x044B,
    DEVICE_044C = 0x044C,
    DEVICE_044D = 0x044D,
    DEVICE_044E = 0x044E,
    DEVICE_044F = 0x044F,
    DEVICE_0450 = 0x0450,
    DEVICE_0451 = 0x0451,
    DEVICE_0452 = 0x0452,
    DEVICE_0453 = 0x0453,
    DEVICE_0454 = 0x0454,
    DEVICE_0455 = 0x0455,
    DEVICE_0456 = 0x0456,
    DEVICE_0457 = 0x0457,
    DEVICE_0458 = 0x0458,
    DEVICE_0459 = 0x0459,
    DEVICE_045A = 0x045A,
    DEVICE_045C = 0x045C,
    DEVICE_0461 = 0x0461,
    DEVICE_0462 = 0x0462,
    DEVICE_0480 = 0x0480,
    DEVICE_048C = 0x048C,
    DEVICE_048F = 0x048F,
    DEVICE_0620 = 0x0620,
    DEVICE_2600 = 0x2600,
    DEVICE_5400 = 0x5400,
    DEVICE_5656 = 0x5656,
    DEVICE_5801 = 0x5801,
    DEVICE_5802 = 0x5802,
    DEVICE_5803 = 0x5803,
    DEVICE_5811 = 0x5811,
    DEVICE_5901 = 0x5901,
    DEVICE_5903 = 0x5903,
    DEVICE_8110 = 0x8110,
    DEVICE_AB10 = 0xAB10,
    DEVICE_AB11 = 0xAB11,
    DEVICE_AB20 = 0xAB20,
    DEVICE_AB21 = 0xAB21,
    DEVICE_AB30 = 0xAB30,
    DEVICE_ED00 = 0xED00,
    DEVICE_ED01 = 0xED01
};



inline const char8* enumToString(PciDevice11C1 device11C1) // TEST: NO
{
    // COMMON_LT((" | device11C1 = %u", device11C1)); // Commented to avoid bad looking logs



    switch (device11C1)
    {
        case PciDevice11C1::NONE:        return "NONE";
        case PciDevice11C1::DEVICE_0440: return "DEVICE_0440";
        case PciDevice11C1::DEVICE_0441: return "DEVICE_0441";
        case PciDevice11C1::DEVICE_0442: return "DEVICE_0442";
        case PciDevice11C1::DEVICE_0443: return "DEVICE_0443";
        case PciDevice11C1::DEVICE_0444: return "DEVICE_0444";
        case PciDevice11C1::DEVICE_0445: return "DEVICE_0445";
        case PciDevice11C1::DEVICE_0446: return "DEVICE_0446";
        case PciDevice11C1::DEVICE_0447: return "DEVICE_0447";
        case PciDevice11C1::DEVICE_0448: return "DEVICE_0448";
        case PciDevice11C1::DEVICE_0449: return "DEVICE_0449";
        case PciDevice11C1::DEVICE_044A: return "DEVICE_044A";
        case PciDevice11C1::DEVICE_044B: return "DEVICE_044B";
        case PciDevice11C1::DEVICE_044C: return "DEVICE_044C";
        case PciDevice11C1::DEVICE_044D: return "DEVICE_044D";
        case PciDevice11C1::DEVICE_044E: return "DEVICE_044E";
        case PciDevice11C1::DEVICE_044F: return "DEVICE_044F";
        case PciDevice11C1::DEVICE_0450: return "DEVICE_0450";
        case PciDevice11C1::DEVICE_0451: return "DEVICE_0451";
        case PciDevice11C1::DEVICE_0452: return "DEVICE_0452";
        case PciDevice11C1::DEVICE_0453: return "DEVICE_0453";
        case PciDevice11C1::DEVICE_0454: return "DEVICE_0454";
        case PciDevice11C1::DEVICE_0455: return "DEVICE_0455";
        case PciDevice11C1::DEVICE_0456: return "DEVICE_0456";
        case PciDevice11C1::DEVICE_0457: return "DEVICE_0457";
        case PciDevice11C1::DEVICE_0458: return "DEVICE_0458";
        case PciDevice11C1::DEVICE_0459: return "DEVICE_0459";
        case PciDevice11C1::DEVICE_045A: return "DEVICE_045A";
        case PciDevice11C1::DEVICE_045C: return "DEVICE_045C";
        case PciDevice11C1::DEVICE_0461: return "DEVICE_0461";
        case PciDevice11C1::DEVICE_0462: return "DEVICE_0462";
        case PciDevice11C1::DEVICE_0480: return "DEVICE_0480";
        case PciDevice11C1::DEVICE_048C: return "DEVICE_048C";
        case PciDevice11C1::DEVICE_048F: return "DEVICE_048F";
        case PciDevice11C1::DEVICE_0620: return "DEVICE_0620";
        case PciDevice11C1::DEVICE_2600: return "DEVICE_2600";
        case PciDevice11C1::DEVICE_5400: return "DEVICE_5400";
        case PciDevice11C1::DEVICE_5656: return "DEVICE_5656";
        case PciDevice11C1::DEVICE_5801: return "DEVICE_5801";
        case PciDevice11C1::DEVICE_5802: return "DEVICE_5802";
        case PciDevice11C1::DEVICE_5803: return "DEVICE_5803";
        case PciDevice11C1::DEVICE_5811: return "DEVICE_5811";
        case PciDevice11C1::DEVICE_5901: return "DEVICE_5901";
        case PciDevice11C1::DEVICE_5903: return "DEVICE_5903";
        case PciDevice11C1::DEVICE_8110: return "DEVICE_8110";
        case PciDevice11C1::DEVICE_AB10: return "DEVICE_AB10";
        case PciDevice11C1::DEVICE_AB11: return "DEVICE_AB11";
        case PciDevice11C1::DEVICE_AB20: return "DEVICE_AB20";
        case PciDevice11C1::DEVICE_AB21: return "DEVICE_AB21";
        case PciDevice11C1::DEVICE_AB30: return "DEVICE_AB30";
        case PciDevice11C1::DEVICE_ED00: return "DEVICE_ED00";
        case PciDevice11C1::DEVICE_ED01: return "DEVICE_ED01";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice11C1 device11C1) // TEST: NO
{
    // COMMON_LT((" | device11C1 = %u", device11C1)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device11C1, enumToString(device11C1));

    return res;
}



inline const char8* enumToHumanString(PciDevice11C1 device11C1) // TEST: NO
{
    // COMMON_LT((" | device11C1 = %u", device11C1)); // Commented to avoid bad looking logs



    switch (device11C1)
    {
        case PciDevice11C1::DEVICE_0440: return "56k WinModem";
        case PciDevice11C1::DEVICE_0441: return "56k WinModem";
        case PciDevice11C1::DEVICE_0442: return "56k WinModem";
        case PciDevice11C1::DEVICE_0443: return "LT WinModem";
        case PciDevice11C1::DEVICE_0444: return "LT WinModem";
        case PciDevice11C1::DEVICE_0445: return "LT WinModem";
        case PciDevice11C1::DEVICE_0446: return "LT WinModem";
        case PciDevice11C1::DEVICE_0447: return "LT WinModem";
        case PciDevice11C1::DEVICE_0448: return "WinModem 56k";
        case PciDevice11C1::DEVICE_0449: return "L56xM+S [Mars-2] WinModem 56k";
        case PciDevice11C1::DEVICE_044A: return "F-1156IV WinModem (V90, 56KFlex)";
        case PciDevice11C1::DEVICE_044B: return "LT WinModem";
        case PciDevice11C1::DEVICE_044C: return "LT WinModem";
        case PciDevice11C1::DEVICE_044D: return "LT WinModem";
        case PciDevice11C1::DEVICE_044E: return "LT WinModem";
        case PciDevice11C1::DEVICE_044F: return "V90 WildWire Modem";
        case PciDevice11C1::DEVICE_0450: return "LT WinModem";
        case PciDevice11C1::DEVICE_0451: return "LT WinModem";
        case PciDevice11C1::DEVICE_0452: return "LT WinModem";
        case PciDevice11C1::DEVICE_0453: return "LT WinModem";
        case PciDevice11C1::DEVICE_0454: return "LT WinModem";
        case PciDevice11C1::DEVICE_0455: return "LT WinModem";
        case PciDevice11C1::DEVICE_0456: return "LT WinModem";
        case PciDevice11C1::DEVICE_0457: return "LT WinModem";
        case PciDevice11C1::DEVICE_0458: return "LT WinModem";
        case PciDevice11C1::DEVICE_0459: return "LT WinModem";
        case PciDevice11C1::DEVICE_045A: return "LT WinModem";
        case PciDevice11C1::DEVICE_045C: return "LT WinModem";
        case PciDevice11C1::DEVICE_0461: return "V90 WildWire Modem";
        case PciDevice11C1::DEVICE_0462: return "V90 WildWire Modem";
        case PciDevice11C1::DEVICE_0480: return "Venus Modem (V90, 56KFlex)";
        case PciDevice11C1::DEVICE_048C: return "V.92 56K WinModem";
        case PciDevice11C1::DEVICE_048F: return "V.92 56k WinModem";
        case PciDevice11C1::DEVICE_0620: return "Lucent V.92 Data/Fax Modem";
        case PciDevice11C1::DEVICE_2600: return "StarPro26XX family (SP2601, SP2603, SP2612) DSP";
        case PciDevice11C1::DEVICE_5400: return "OR3TP12 FPSC";
        case PciDevice11C1::DEVICE_5656: return "Venus Modem";
        case PciDevice11C1::DEVICE_5801: return "USB";
        case PciDevice11C1::DEVICE_5802: return "USS-312 USB Controller";
        case PciDevice11C1::DEVICE_5803: return "USS-344S USB Controller";
        case PciDevice11C1::DEVICE_5811: return "FW322/323 [TrueFire] 1394a Controller";
        case PciDevice11C1::DEVICE_5901: return "FW643 [TrueFire] PCIe 1394b Controller";
        case PciDevice11C1::DEVICE_5903: return "FW533 [TrueFire] PCIe 1394a Controller";
        case PciDevice11C1::DEVICE_8110: return "T8110 H.100/H.110 TDM switch";
        case PciDevice11C1::DEVICE_AB10: return "WL60010 Wireless LAN MAC";
        case PciDevice11C1::DEVICE_AB11: return "WL60040 Multimode Wireles LAN MAC";
        case PciDevice11C1::DEVICE_AB20: return "ORiNOCO PCI Adapter";
        case PciDevice11C1::DEVICE_AB21: return "Agere Wireless PCI Adapter";
        case PciDevice11C1::DEVICE_AB30: return "Hermes2 Mini-PCI WaveLAN a/b/g";
        case PciDevice11C1::DEVICE_ED00: return "ET-131x PCI-E Ethernet Controller";
        case PciDevice11C1::DEVICE_ED01: return "ET-131x PCI-E Ethernet Controller";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11C1_PCIDEVICE11C1_H
