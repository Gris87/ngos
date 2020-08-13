// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1103_PCIDEVICE1103_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1103_PCIDEVICE1103_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1103: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0003 = 0x0003,
    DEVICE_0004 = 0x0004,
    DEVICE_0005 = 0x0005,
    DEVICE_0006 = 0x0006,
    DEVICE_0007 = 0x0007,
    DEVICE_0008 = 0x0008,
    DEVICE_0009 = 0x0009,
    DEVICE_0620 = 0x0620,
    DEVICE_0622 = 0x0622,
    DEVICE_0640 = 0x0640,
    DEVICE_0641 = 0x0641,
    DEVICE_0642 = 0x0642,
    DEVICE_0644 = 0x0644,
    DEVICE_0645 = 0x0645,
    DEVICE_0646 = 0x0646,
    DEVICE_1720 = 0x1720,
    DEVICE_1740 = 0x1740,
    DEVICE_1742 = 0x1742,
    DEVICE_2210 = 0x2210,
    DEVICE_2300 = 0x2300,
    DEVICE_2310 = 0x2310,
    DEVICE_2320 = 0x2320,
    DEVICE_2322 = 0x2322,
    DEVICE_2340 = 0x2340,
    DEVICE_2640 = 0x2640,
    DEVICE_2722 = 0x2722,
    DEVICE_2740 = 0x2740,
    DEVICE_2744 = 0x2744,
    DEVICE_2782 = 0x2782,
    DEVICE_3120 = 0x3120,
    DEVICE_3220 = 0x3220,
    DEVICE_3320 = 0x3320,
    DEVICE_4310 = 0x4310
};



inline const char8* enumToString(PciDevice1103 device1103) // TEST: NO
{
    // COMMON_LT((" | device1103 = %u", device1103)); // Commented to avoid bad looking logs



    switch (device1103)
    {
        case PciDevice1103::NONE:        return "NONE";
        case PciDevice1103::DEVICE_0003: return "DEVICE_0003";
        case PciDevice1103::DEVICE_0004: return "DEVICE_0004";
        case PciDevice1103::DEVICE_0005: return "DEVICE_0005";
        case PciDevice1103::DEVICE_0006: return "DEVICE_0006";
        case PciDevice1103::DEVICE_0007: return "DEVICE_0007";
        case PciDevice1103::DEVICE_0008: return "DEVICE_0008";
        case PciDevice1103::DEVICE_0009: return "DEVICE_0009";
        case PciDevice1103::DEVICE_0620: return "DEVICE_0620";
        case PciDevice1103::DEVICE_0622: return "DEVICE_0622";
        case PciDevice1103::DEVICE_0640: return "DEVICE_0640";
        case PciDevice1103::DEVICE_0641: return "DEVICE_0641";
        case PciDevice1103::DEVICE_0642: return "DEVICE_0642";
        case PciDevice1103::DEVICE_0644: return "DEVICE_0644";
        case PciDevice1103::DEVICE_0645: return "DEVICE_0645";
        case PciDevice1103::DEVICE_0646: return "DEVICE_0646";
        case PciDevice1103::DEVICE_1720: return "DEVICE_1720";
        case PciDevice1103::DEVICE_1740: return "DEVICE_1740";
        case PciDevice1103::DEVICE_1742: return "DEVICE_1742";
        case PciDevice1103::DEVICE_2210: return "DEVICE_2210";
        case PciDevice1103::DEVICE_2300: return "DEVICE_2300";
        case PciDevice1103::DEVICE_2310: return "DEVICE_2310";
        case PciDevice1103::DEVICE_2320: return "DEVICE_2320";
        case PciDevice1103::DEVICE_2322: return "DEVICE_2322";
        case PciDevice1103::DEVICE_2340: return "DEVICE_2340";
        case PciDevice1103::DEVICE_2640: return "DEVICE_2640";
        case PciDevice1103::DEVICE_2722: return "DEVICE_2722";
        case PciDevice1103::DEVICE_2740: return "DEVICE_2740";
        case PciDevice1103::DEVICE_2744: return "DEVICE_2744";
        case PciDevice1103::DEVICE_2782: return "DEVICE_2782";
        case PciDevice1103::DEVICE_3120: return "DEVICE_3120";
        case PciDevice1103::DEVICE_3220: return "DEVICE_3220";
        case PciDevice1103::DEVICE_3320: return "DEVICE_3320";
        case PciDevice1103::DEVICE_4310: return "DEVICE_4310";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1103 device1103) // TEST: NO
{
    // COMMON_LT((" | device1103 = %u", device1103)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1103, enumToString(device1103));

    return res;
}



inline const char8* enumToHumanString(PciDevice1103 device1103) // TEST: NO
{
    // COMMON_LT((" | device1103 = %u", device1103)); // Commented to avoid bad looking logs



    switch (device1103)
    {
        case PciDevice1103::DEVICE_0003: return "HPT343/345/346/363";
        case PciDevice1103::DEVICE_0004: return "HPT366/368/370/370A/372/372N";
        case PciDevice1103::DEVICE_0005: return "HPT372A/372N";
        case PciDevice1103::DEVICE_0006: return "HPT302/302N";
        case PciDevice1103::DEVICE_0007: return "HPT371/371N";
        case PciDevice1103::DEVICE_0008: return "HPT374";
        case PciDevice1103::DEVICE_0009: return "HPT372N";
        case PciDevice1103::DEVICE_0620: return "RocketRAID 620 2 Port SATA-III Controller";
        case PciDevice1103::DEVICE_0622: return "RocketRAID 622 2 Port SATA-III Controller";
        case PciDevice1103::DEVICE_0640: return "RocketRAID 640 4 Port SATA-III Controller";
        case PciDevice1103::DEVICE_0641: return "RocketRAID 640L 4 Port SATA-III Controller";
        case PciDevice1103::DEVICE_0642: return "RocketRAID 642L SATA-III Controller (2 eSATA ports + 2 internal SATA ports)";
        case PciDevice1103::DEVICE_0644: return "RocketRAID 644 4 Port SATA-III Controller (eSATA)";
        case PciDevice1103::DEVICE_0645: return "RocketRAID 644L 4 Port SATA-III Controller (eSATA)";
        case PciDevice1103::DEVICE_0646: return "RocketRAID 644LS SATA-III Controller (4 eSATA devices connected by 1 SAS cable)";
        case PciDevice1103::DEVICE_1720: return "RocketRAID 1720 (2x SATA II RAID Controller)";
        case PciDevice1103::DEVICE_1740: return "RocketRAID 1740";
        case PciDevice1103::DEVICE_1742: return "RocketRAID 1742";
        case PciDevice1103::DEVICE_2210: return "RocketRAID 2210 SATA-II Controller";
        case PciDevice1103::DEVICE_2300: return "RocketRAID 230x 4 Port SATA-II Controller";
        case PciDevice1103::DEVICE_2310: return "RocketRAID 2310 4 Port SATA-II Controller";
        case PciDevice1103::DEVICE_2320: return "RocketRAID 2320 SATA-II Controller";
        case PciDevice1103::DEVICE_2322: return "RocketRAID 2322 SATA-II Controller";
        case PciDevice1103::DEVICE_2340: return "RocketRAID 2340 16 Port SATA-II Controller";
        case PciDevice1103::DEVICE_2640: return "RocketRAID 2640 SAS/SATA Controller";
        case PciDevice1103::DEVICE_2722: return "RocketRAID 2722";
        case PciDevice1103::DEVICE_2740: return "RocketRAID 2740";
        case PciDevice1103::DEVICE_2744: return "RocketRaid 2744";
        case PciDevice1103::DEVICE_2782: return "RocketRAID 2782";
        case PciDevice1103::DEVICE_3120: return "RocketRAID 3120";
        case PciDevice1103::DEVICE_3220: return "RocketRAID 3220";
        case PciDevice1103::DEVICE_3320: return "RocketRAID 3320";
        case PciDevice1103::DEVICE_4310: return "RocketRaid 4310";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1103_PCIDEVICE1103_H
