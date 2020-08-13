// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B7_PCIDEVICE10B7_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B7_PCIDEVICE10B7_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice10B7: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001,
    DEVICE_0013 = 0x0013,
    DEVICE_0910 = 0x0910,
    DEVICE_1006 = 0x1006,
    DEVICE_1007 = 0x1007,
    DEVICE_1201 = 0x1201,
    DEVICE_1202 = 0x1202,
    DEVICE_1700 = 0x1700,
    DEVICE_3390 = 0x3390,
    DEVICE_3590 = 0x3590,
    DEVICE_4500 = 0x4500,
    DEVICE_5055 = 0x5055,
    DEVICE_5057 = 0x5057,
    DEVICE_5157 = 0x5157,
    DEVICE_5257 = 0x5257,
    DEVICE_5900 = 0x5900,
    DEVICE_5920 = 0x5920,
    DEVICE_5950 = 0x5950,
    DEVICE_5951 = 0x5951,
    DEVICE_5952 = 0x5952,
    DEVICE_5970 = 0x5970,
    DEVICE_5B57 = 0x5B57,
    DEVICE_6000 = 0x6000,
    DEVICE_6001 = 0x6001,
    DEVICE_6055 = 0x6055,
    DEVICE_6056 = 0x6056,
    DEVICE_6560 = 0x6560,
    DEVICE_6561 = 0x6561,
    DEVICE_6562 = 0x6562,
    DEVICE_6563 = 0x6563,
    DEVICE_6564 = 0x6564,
    DEVICE_7646 = 0x7646,
    DEVICE_7770 = 0x7770,
    DEVICE_7940 = 0x7940,
    DEVICE_7980 = 0x7980,
    DEVICE_7990 = 0x7990,
    DEVICE_80EB = 0x80EB,
    DEVICE_8811 = 0x8811,
    DEVICE_9000 = 0x9000,
    DEVICE_9001 = 0x9001,
    DEVICE_9004 = 0x9004,
    DEVICE_9005 = 0x9005,
    DEVICE_9006 = 0x9006,
    DEVICE_900A = 0x900A,
    DEVICE_9050 = 0x9050,
    DEVICE_9051 = 0x9051,
    DEVICE_9054 = 0x9054,
    DEVICE_9055 = 0x9055,
    DEVICE_9056 = 0x9056,
    DEVICE_9058 = 0x9058,
    DEVICE_905A = 0x905A,
    DEVICE_9200 = 0x9200,
    DEVICE_9201 = 0x9201,
    DEVICE_9202 = 0x9202,
    DEVICE_9210 = 0x9210,
    DEVICE_9300 = 0x9300,
    DEVICE_9800 = 0x9800,
    DEVICE_9805 = 0x9805,
    DEVICE_9900 = 0x9900,
    DEVICE_9902 = 0x9902,
    DEVICE_9903 = 0x9903,
    DEVICE_9904 = 0x9904,
    DEVICE_9905 = 0x9905,
    DEVICE_9908 = 0x9908,
    DEVICE_9909 = 0x9909,
    DEVICE_990A = 0x990A,
    DEVICE_990B = 0x990B
};



inline const char8* enumToString(PciDevice10B7 device10B7) // TEST: NO
{
    // COMMON_LT((" | device10B7 = %u", device10B7)); // Commented to avoid bad looking logs



    switch (device10B7)
    {
        case PciDevice10B7::NONE:        return "NONE";
        case PciDevice10B7::DEVICE_0001: return "DEVICE_0001";
        case PciDevice10B7::DEVICE_0013: return "DEVICE_0013";
        case PciDevice10B7::DEVICE_0910: return "DEVICE_0910";
        case PciDevice10B7::DEVICE_1006: return "DEVICE_1006";
        case PciDevice10B7::DEVICE_1007: return "DEVICE_1007";
        case PciDevice10B7::DEVICE_1201: return "DEVICE_1201";
        case PciDevice10B7::DEVICE_1202: return "DEVICE_1202";
        case PciDevice10B7::DEVICE_1700: return "DEVICE_1700";
        case PciDevice10B7::DEVICE_3390: return "DEVICE_3390";
        case PciDevice10B7::DEVICE_3590: return "DEVICE_3590";
        case PciDevice10B7::DEVICE_4500: return "DEVICE_4500";
        case PciDevice10B7::DEVICE_5055: return "DEVICE_5055";
        case PciDevice10B7::DEVICE_5057: return "DEVICE_5057";
        case PciDevice10B7::DEVICE_5157: return "DEVICE_5157";
        case PciDevice10B7::DEVICE_5257: return "DEVICE_5257";
        case PciDevice10B7::DEVICE_5900: return "DEVICE_5900";
        case PciDevice10B7::DEVICE_5920: return "DEVICE_5920";
        case PciDevice10B7::DEVICE_5950: return "DEVICE_5950";
        case PciDevice10B7::DEVICE_5951: return "DEVICE_5951";
        case PciDevice10B7::DEVICE_5952: return "DEVICE_5952";
        case PciDevice10B7::DEVICE_5970: return "DEVICE_5970";
        case PciDevice10B7::DEVICE_5B57: return "DEVICE_5B57";
        case PciDevice10B7::DEVICE_6000: return "DEVICE_6000";
        case PciDevice10B7::DEVICE_6001: return "DEVICE_6001";
        case PciDevice10B7::DEVICE_6055: return "DEVICE_6055";
        case PciDevice10B7::DEVICE_6056: return "DEVICE_6056";
        case PciDevice10B7::DEVICE_6560: return "DEVICE_6560";
        case PciDevice10B7::DEVICE_6561: return "DEVICE_6561";
        case PciDevice10B7::DEVICE_6562: return "DEVICE_6562";
        case PciDevice10B7::DEVICE_6563: return "DEVICE_6563";
        case PciDevice10B7::DEVICE_6564: return "DEVICE_6564";
        case PciDevice10B7::DEVICE_7646: return "DEVICE_7646";
        case PciDevice10B7::DEVICE_7770: return "DEVICE_7770";
        case PciDevice10B7::DEVICE_7940: return "DEVICE_7940";
        case PciDevice10B7::DEVICE_7980: return "DEVICE_7980";
        case PciDevice10B7::DEVICE_7990: return "DEVICE_7990";
        case PciDevice10B7::DEVICE_80EB: return "DEVICE_80EB";
        case PciDevice10B7::DEVICE_8811: return "DEVICE_8811";
        case PciDevice10B7::DEVICE_9000: return "DEVICE_9000";
        case PciDevice10B7::DEVICE_9001: return "DEVICE_9001";
        case PciDevice10B7::DEVICE_9004: return "DEVICE_9004";
        case PciDevice10B7::DEVICE_9005: return "DEVICE_9005";
        case PciDevice10B7::DEVICE_9006: return "DEVICE_9006";
        case PciDevice10B7::DEVICE_900A: return "DEVICE_900A";
        case PciDevice10B7::DEVICE_9050: return "DEVICE_9050";
        case PciDevice10B7::DEVICE_9051: return "DEVICE_9051";
        case PciDevice10B7::DEVICE_9054: return "DEVICE_9054";
        case PciDevice10B7::DEVICE_9055: return "DEVICE_9055";
        case PciDevice10B7::DEVICE_9056: return "DEVICE_9056";
        case PciDevice10B7::DEVICE_9058: return "DEVICE_9058";
        case PciDevice10B7::DEVICE_905A: return "DEVICE_905A";
        case PciDevice10B7::DEVICE_9200: return "DEVICE_9200";
        case PciDevice10B7::DEVICE_9201: return "DEVICE_9201";
        case PciDevice10B7::DEVICE_9202: return "DEVICE_9202";
        case PciDevice10B7::DEVICE_9210: return "DEVICE_9210";
        case PciDevice10B7::DEVICE_9300: return "DEVICE_9300";
        case PciDevice10B7::DEVICE_9800: return "DEVICE_9800";
        case PciDevice10B7::DEVICE_9805: return "DEVICE_9805";
        case PciDevice10B7::DEVICE_9900: return "DEVICE_9900";
        case PciDevice10B7::DEVICE_9902: return "DEVICE_9902";
        case PciDevice10B7::DEVICE_9903: return "DEVICE_9903";
        case PciDevice10B7::DEVICE_9904: return "DEVICE_9904";
        case PciDevice10B7::DEVICE_9905: return "DEVICE_9905";
        case PciDevice10B7::DEVICE_9908: return "DEVICE_9908";
        case PciDevice10B7::DEVICE_9909: return "DEVICE_9909";
        case PciDevice10B7::DEVICE_990A: return "DEVICE_990A";
        case PciDevice10B7::DEVICE_990B: return "DEVICE_990B";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice10B7 device10B7) // TEST: NO
{
    // COMMON_LT((" | device10B7 = %u", device10B7)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device10B7, enumToString(device10B7));

    return res;
}



inline const char8* enumToHumanString(PciDevice10B7 device10B7) // TEST: NO
{
    // COMMON_LT((" | device10B7 = %u", device10B7)); // Commented to avoid bad looking logs



    switch (device10B7)
    {
        case PciDevice10B7::DEVICE_0001: return "3c985 1000BaseSX (SX/TX)";
        case PciDevice10B7::DEVICE_0013: return "AR5212 802.11abg NIC (3CRDAG675)";
        case PciDevice10B7::DEVICE_0910: return "3C910-A01";
        case PciDevice10B7::DEVICE_1006: return "MINI PCI type 3B Data Fax Modem";
        case PciDevice10B7::DEVICE_1007: return "Mini PCI 56k Winmodem";
        case PciDevice10B7::DEVICE_1201: return "3c982-TXM 10/100baseTX Dual Port A [Hydra]";
        case PciDevice10B7::DEVICE_1202: return "3c982-TXM 10/100baseTX Dual Port B [Hydra]";
        case PciDevice10B7::DEVICE_1700: return "3c940 10/100/1000Base-T [Marvell]";
        case PciDevice10B7::DEVICE_3390: return "3c339 TokenLink Velocity";
        case PciDevice10B7::DEVICE_3590: return "3c359 TokenLink Velocity XL";
        case PciDevice10B7::DEVICE_4500: return "3c450 HomePNA [Tornado]";
        case PciDevice10B7::DEVICE_5055: return "3c555 Laptop Hurricane";
        case PciDevice10B7::DEVICE_5057: return "3c575 Megahertz 10/100 LAN CardBus [Boomerang]";
        case PciDevice10B7::DEVICE_5157: return "3cCFE575BT Megahertz 10/100 LAN CardBus [Cyclone]";
        case PciDevice10B7::DEVICE_5257: return "3cCFE575CT CardBus [Cyclone]";
        case PciDevice10B7::DEVICE_5900: return "3c590 10BaseT [Vortex]";
        case PciDevice10B7::DEVICE_5920: return "3c592 EISA 10mbps Demon/Vortex";
        case PciDevice10B7::DEVICE_5950: return "3c595 100BaseTX [Vortex]";
        case PciDevice10B7::DEVICE_5951: return "3c595 100BaseT4 [Vortex]";
        case PciDevice10B7::DEVICE_5952: return "3c595 100Base-MII [Vortex]";
        case PciDevice10B7::DEVICE_5970: return "3c597 EISA Fast Demon/Vortex";
        case PciDevice10B7::DEVICE_5B57: return "3c595 Megahertz 10/100 LAN CardBus [Boomerang]";
        case PciDevice10B7::DEVICE_6000: return "3CRSHPW796 [OfficeConnect Wireless CardBus]";
        case PciDevice10B7::DEVICE_6001: return "3com 3CRWE154G72 [Office Connect Wireless LAN Adapter]";
        case PciDevice10B7::DEVICE_6055: return "3c556 Hurricane CardBus [Cyclone]";
        case PciDevice10B7::DEVICE_6056: return "3c556B CardBus [Tornado]";
        case PciDevice10B7::DEVICE_6560: return "3cCFE656 CardBus [Cyclone]";
        case PciDevice10B7::DEVICE_6561: return "3cCFEM656 10/100 LAN+56K Modem CardBus";
        case PciDevice10B7::DEVICE_6562: return "3cCFEM656B 10/100 LAN+Winmodem CardBus [Cyclone]";
        case PciDevice10B7::DEVICE_6563: return "3cCFEM656B 10/100 LAN+56K Modem CardBus";
        case PciDevice10B7::DEVICE_6564: return "3cXFEM656C 10/100 LAN+Winmodem CardBus [Tornado]";
        case PciDevice10B7::DEVICE_7646: return "3cSOHO100-TX Hurricane";
        case PciDevice10B7::DEVICE_7770: return "3CRWE777 PCI Wireless Adapter [Airconnect]";
        case PciDevice10B7::DEVICE_7940: return "3c803 FDDILink UTP Controller";
        case PciDevice10B7::DEVICE_7980: return "3c804 FDDILink SAS Controller";
        case PciDevice10B7::DEVICE_7990: return "3c805 FDDILink DAS Controller";
        case PciDevice10B7::DEVICE_80EB: return "3c940B 10/100/1000Base-T";
        case PciDevice10B7::DEVICE_8811: return "Token ring";
        case PciDevice10B7::DEVICE_9000: return "3c900 10BaseT [Boomerang]";
        case PciDevice10B7::DEVICE_9001: return "3c900 10Mbps Combo [Boomerang]";
        case PciDevice10B7::DEVICE_9004: return "3c900B-TPO Etherlink XL [Cyclone]";
        case PciDevice10B7::DEVICE_9005: return "3c900B-Combo Etherlink XL [Cyclone]";
        case PciDevice10B7::DEVICE_9006: return "3c900B-TPC Etherlink XL [Cyclone]";
        case PciDevice10B7::DEVICE_900A: return "3c900B-FL 10base-FL [Cyclone]";
        case PciDevice10B7::DEVICE_9050: return "3c905 100BaseTX [Boomerang]";
        case PciDevice10B7::DEVICE_9051: return "3c905 100BaseT4 [Boomerang]";
        case PciDevice10B7::DEVICE_9054: return "3C905B-TX Fast Etherlink XL PCI";
        case PciDevice10B7::DEVICE_9055: return "3c905B 100BaseTX [Cyclone]";
        case PciDevice10B7::DEVICE_9056: return "3c905B-T4 Fast EtherLink XL [Cyclone]";
        case PciDevice10B7::DEVICE_9058: return "3c905B Deluxe Etherlink 10/100/BNC [Cyclone]";
        case PciDevice10B7::DEVICE_905A: return "3c905B-FX Fast Etherlink XL FX 100baseFx [Cyclone]";
        case PciDevice10B7::DEVICE_9200: return "3c905C-TX/TX-M [Tornado]";
        case PciDevice10B7::DEVICE_9201: return "3C920B-EMB Integrated Fast Ethernet Controller [Tornado]";
        case PciDevice10B7::DEVICE_9202: return "3Com 3C920B-EMB-WNM Integrated Fast Ethernet Controller";
        case PciDevice10B7::DEVICE_9210: return "3C920B-EMB-WNM Integrated Fast Ethernet Controller";
        case PciDevice10B7::DEVICE_9300: return "3CSOHO100B-TX 910-A01 [tulip]";
        case PciDevice10B7::DEVICE_9800: return "3c980-TX Fast Etherlink XL Server Adapter [Cyclone]";
        case PciDevice10B7::DEVICE_9805: return "3c980-C 10/100baseTX NIC [Python-T]";
        case PciDevice10B7::DEVICE_9900: return "3C990-TX [Typhoon]";
        case PciDevice10B7::DEVICE_9902: return "3CR990-TX-95 [Typhoon 56-bit]";
        case PciDevice10B7::DEVICE_9903: return "3CR990-TX-97 [Typhoon 168-bit]";
        case PciDevice10B7::DEVICE_9904: return "3C990B-TX-M/3C990BSVR [Typhoon2]";
        case PciDevice10B7::DEVICE_9905: return "3CR990-FX-95/97/95 [Typhon Fiber]";
        case PciDevice10B7::DEVICE_9908: return "3CR990SVR95 [Typhoon Server 56-bit]";
        case PciDevice10B7::DEVICE_9909: return "3CR990SVR97 [Typhoon Server 168-bit]";
        case PciDevice10B7::DEVICE_990A: return "3C990SVR [Typhoon Server]";
        case PciDevice10B7::DEVICE_990B: return "3C990SVR [Typhoon Server]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B7_PCIDEVICE10B7_H
