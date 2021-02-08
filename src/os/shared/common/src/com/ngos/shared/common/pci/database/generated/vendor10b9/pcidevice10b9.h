// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B9_PCIDEVICE10B9_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B9_PCIDEVICE10B9_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor10b9/pcisubdevice10b90111.h>
#include <com/ngos/shared/common/pci/database/generated/vendor10b9/pcisubdevice10b91521.h>
#include <com/ngos/shared/common/pci/database/generated/vendor10b9/pcisubdevice10b91523.h>
#include <com/ngos/shared/common/pci/database/generated/vendor10b9/pcisubdevice10b91533.h>
#include <com/ngos/shared/common/pci/database/generated/vendor10b9/pcisubdevice10b91541.h>
#include <com/ngos/shared/common/pci/database/generated/vendor10b9/pcisubdevice10b91563.h>
#include <com/ngos/shared/common/pci/database/generated/vendor10b9/pcisubdevice10b95229.h>
#include <com/ngos/shared/common/pci/database/generated/vendor10b9/pcisubdevice10b95237.h>
#include <com/ngos/shared/common/pci/database/generated/vendor10b9/pcisubdevice10b95239.h>
#include <com/ngos/shared/common/pci/database/generated/vendor10b9/pcisubdevice10b95288.h>
#include <com/ngos/shared/common/pci/database/generated/vendor10b9/pcisubdevice10b95451.h>
#include <com/ngos/shared/common/pci/database/generated/vendor10b9/pcisubdevice10b95455.h>
#include <com/ngos/shared/common/pci/database/generated/vendor10b9/pcisubdevice10b95457.h>
#include <com/ngos/shared/common/pci/database/generated/vendor10b9/pcisubdevice10b97101.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice10B9: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0101 = 0x0101,
    DEVICE_0111 = 0x0111,
    DEVICE_0780 = 0x0780,
    DEVICE_0782 = 0x0782,
    DEVICE_1435 = 0x1435,
    DEVICE_1445 = 0x1445,
    DEVICE_1449 = 0x1449,
    DEVICE_1451 = 0x1451,
    DEVICE_1461 = 0x1461,
    DEVICE_1489 = 0x1489,
    DEVICE_1511 = 0x1511,
    DEVICE_1512 = 0x1512,
    DEVICE_1513 = 0x1513,
    DEVICE_1521 = 0x1521,
    DEVICE_1523 = 0x1523,
    DEVICE_1531 = 0x1531,
    DEVICE_1533 = 0x1533,
    DEVICE_1541 = 0x1541,
    DEVICE_1543 = 0x1543,
    DEVICE_1563 = 0x1563,
    DEVICE_1573 = 0x1573,
    DEVICE_1575 = 0x1575,
    DEVICE_1621 = 0x1621,
    DEVICE_1631 = 0x1631,
    DEVICE_1632 = 0x1632,
    DEVICE_1641 = 0x1641,
    DEVICE_1644 = 0x1644,
    DEVICE_1646 = 0x1646,
    DEVICE_1647 = 0x1647,
    DEVICE_1651 = 0x1651,
    DEVICE_1671 = 0x1671,
    DEVICE_1672 = 0x1672,
    DEVICE_1681 = 0x1681,
    DEVICE_1687 = 0x1687,
    DEVICE_1689 = 0x1689,
    DEVICE_1695 = 0x1695,
    DEVICE_1697 = 0x1697,
    DEVICE_3141 = 0x3141,
    DEVICE_3143 = 0x3143,
    DEVICE_3145 = 0x3145,
    DEVICE_3147 = 0x3147,
    DEVICE_3149 = 0x3149,
    DEVICE_3151 = 0x3151,
    DEVICE_3307 = 0x3307,
    DEVICE_3309 = 0x3309,
    DEVICE_3323 = 0x3323,
    DEVICE_5212 = 0x5212,
    DEVICE_5215 = 0x5215,
    DEVICE_5217 = 0x5217,
    DEVICE_5219 = 0x5219,
    DEVICE_5225 = 0x5225,
    DEVICE_5228 = 0x5228,
    DEVICE_5229 = 0x5229,
    DEVICE_5235 = 0x5235,
    DEVICE_5237 = 0x5237,
    DEVICE_5239 = 0x5239,
    DEVICE_5243 = 0x5243,
    DEVICE_5246 = 0x5246,
    DEVICE_5247 = 0x5247,
    DEVICE_5249 = 0x5249,
    DEVICE_524B = 0x524B,
    DEVICE_524C = 0x524C,
    DEVICE_524D = 0x524D,
    DEVICE_524E = 0x524E,
    DEVICE_5251 = 0x5251,
    DEVICE_5253 = 0x5253,
    DEVICE_5261 = 0x5261,
    DEVICE_5263 = 0x5263,
    DEVICE_5281 = 0x5281,
    DEVICE_5287 = 0x5287,
    DEVICE_5288 = 0x5288,
    DEVICE_5289 = 0x5289,
    DEVICE_5450 = 0x5450,
    DEVICE_5451 = 0x5451,
    DEVICE_5453 = 0x5453,
    DEVICE_5455 = 0x5455,
    DEVICE_5457 = 0x5457,
    DEVICE_5459 = 0x5459,
    DEVICE_545A = 0x545A,
    DEVICE_5461 = 0x5461,
    DEVICE_5471 = 0x5471,
    DEVICE_5473 = 0x5473,
    DEVICE_7101 = 0x7101
};



inline const char8* enumToString(PciDevice10B9 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice10B9::NONE:        return "NONE";
        case PciDevice10B9::DEVICE_0101: return "DEVICE_0101";
        case PciDevice10B9::DEVICE_0111: return "DEVICE_0111";
        case PciDevice10B9::DEVICE_0780: return "DEVICE_0780";
        case PciDevice10B9::DEVICE_0782: return "DEVICE_0782";
        case PciDevice10B9::DEVICE_1435: return "DEVICE_1435";
        case PciDevice10B9::DEVICE_1445: return "DEVICE_1445";
        case PciDevice10B9::DEVICE_1449: return "DEVICE_1449";
        case PciDevice10B9::DEVICE_1451: return "DEVICE_1451";
        case PciDevice10B9::DEVICE_1461: return "DEVICE_1461";
        case PciDevice10B9::DEVICE_1489: return "DEVICE_1489";
        case PciDevice10B9::DEVICE_1511: return "DEVICE_1511";
        case PciDevice10B9::DEVICE_1512: return "DEVICE_1512";
        case PciDevice10B9::DEVICE_1513: return "DEVICE_1513";
        case PciDevice10B9::DEVICE_1521: return "DEVICE_1521";
        case PciDevice10B9::DEVICE_1523: return "DEVICE_1523";
        case PciDevice10B9::DEVICE_1531: return "DEVICE_1531";
        case PciDevice10B9::DEVICE_1533: return "DEVICE_1533";
        case PciDevice10B9::DEVICE_1541: return "DEVICE_1541";
        case PciDevice10B9::DEVICE_1543: return "DEVICE_1543";
        case PciDevice10B9::DEVICE_1563: return "DEVICE_1563";
        case PciDevice10B9::DEVICE_1573: return "DEVICE_1573";
        case PciDevice10B9::DEVICE_1575: return "DEVICE_1575";
        case PciDevice10B9::DEVICE_1621: return "DEVICE_1621";
        case PciDevice10B9::DEVICE_1631: return "DEVICE_1631";
        case PciDevice10B9::DEVICE_1632: return "DEVICE_1632";
        case PciDevice10B9::DEVICE_1641: return "DEVICE_1641";
        case PciDevice10B9::DEVICE_1644: return "DEVICE_1644";
        case PciDevice10B9::DEVICE_1646: return "DEVICE_1646";
        case PciDevice10B9::DEVICE_1647: return "DEVICE_1647";
        case PciDevice10B9::DEVICE_1651: return "DEVICE_1651";
        case PciDevice10B9::DEVICE_1671: return "DEVICE_1671";
        case PciDevice10B9::DEVICE_1672: return "DEVICE_1672";
        case PciDevice10B9::DEVICE_1681: return "DEVICE_1681";
        case PciDevice10B9::DEVICE_1687: return "DEVICE_1687";
        case PciDevice10B9::DEVICE_1689: return "DEVICE_1689";
        case PciDevice10B9::DEVICE_1695: return "DEVICE_1695";
        case PciDevice10B9::DEVICE_1697: return "DEVICE_1697";
        case PciDevice10B9::DEVICE_3141: return "DEVICE_3141";
        case PciDevice10B9::DEVICE_3143: return "DEVICE_3143";
        case PciDevice10B9::DEVICE_3145: return "DEVICE_3145";
        case PciDevice10B9::DEVICE_3147: return "DEVICE_3147";
        case PciDevice10B9::DEVICE_3149: return "DEVICE_3149";
        case PciDevice10B9::DEVICE_3151: return "DEVICE_3151";
        case PciDevice10B9::DEVICE_3307: return "DEVICE_3307";
        case PciDevice10B9::DEVICE_3309: return "DEVICE_3309";
        case PciDevice10B9::DEVICE_3323: return "DEVICE_3323";
        case PciDevice10B9::DEVICE_5212: return "DEVICE_5212";
        case PciDevice10B9::DEVICE_5215: return "DEVICE_5215";
        case PciDevice10B9::DEVICE_5217: return "DEVICE_5217";
        case PciDevice10B9::DEVICE_5219: return "DEVICE_5219";
        case PciDevice10B9::DEVICE_5225: return "DEVICE_5225";
        case PciDevice10B9::DEVICE_5228: return "DEVICE_5228";
        case PciDevice10B9::DEVICE_5229: return "DEVICE_5229";
        case PciDevice10B9::DEVICE_5235: return "DEVICE_5235";
        case PciDevice10B9::DEVICE_5237: return "DEVICE_5237";
        case PciDevice10B9::DEVICE_5239: return "DEVICE_5239";
        case PciDevice10B9::DEVICE_5243: return "DEVICE_5243";
        case PciDevice10B9::DEVICE_5246: return "DEVICE_5246";
        case PciDevice10B9::DEVICE_5247: return "DEVICE_5247";
        case PciDevice10B9::DEVICE_5249: return "DEVICE_5249";
        case PciDevice10B9::DEVICE_524B: return "DEVICE_524B";
        case PciDevice10B9::DEVICE_524C: return "DEVICE_524C";
        case PciDevice10B9::DEVICE_524D: return "DEVICE_524D";
        case PciDevice10B9::DEVICE_524E: return "DEVICE_524E";
        case PciDevice10B9::DEVICE_5251: return "DEVICE_5251";
        case PciDevice10B9::DEVICE_5253: return "DEVICE_5253";
        case PciDevice10B9::DEVICE_5261: return "DEVICE_5261";
        case PciDevice10B9::DEVICE_5263: return "DEVICE_5263";
        case PciDevice10B9::DEVICE_5281: return "DEVICE_5281";
        case PciDevice10B9::DEVICE_5287: return "DEVICE_5287";
        case PciDevice10B9::DEVICE_5288: return "DEVICE_5288";
        case PciDevice10B9::DEVICE_5289: return "DEVICE_5289";
        case PciDevice10B9::DEVICE_5450: return "DEVICE_5450";
        case PciDevice10B9::DEVICE_5451: return "DEVICE_5451";
        case PciDevice10B9::DEVICE_5453: return "DEVICE_5453";
        case PciDevice10B9::DEVICE_5455: return "DEVICE_5455";
        case PciDevice10B9::DEVICE_5457: return "DEVICE_5457";
        case PciDevice10B9::DEVICE_5459: return "DEVICE_5459";
        case PciDevice10B9::DEVICE_545A: return "DEVICE_545A";
        case PciDevice10B9::DEVICE_5461: return "DEVICE_5461";
        case PciDevice10B9::DEVICE_5471: return "DEVICE_5471";
        case PciDevice10B9::DEVICE_5473: return "DEVICE_5473";
        case PciDevice10B9::DEVICE_7101: return "DEVICE_7101";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice10B9 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice10B9 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice10B9::DEVICE_0101: return "CMi8338/C3DX PCI Audio Device";
        case PciDevice10B9::DEVICE_0111: return "C-Media CMi8738/C3DX Audio Device (OEM)";
        case PciDevice10B9::DEVICE_0780: return "Multi-IO Card";
        case PciDevice10B9::DEVICE_0782: return "Multi-IO Card";
        case PciDevice10B9::DEVICE_1435: return "M1435";
        case PciDevice10B9::DEVICE_1445: return "M1445";
        case PciDevice10B9::DEVICE_1449: return "M1449";
        case PciDevice10B9::DEVICE_1451: return "M1451";
        case PciDevice10B9::DEVICE_1461: return "M1461";
        case PciDevice10B9::DEVICE_1489: return "M1489";
        case PciDevice10B9::DEVICE_1511: return "M1511 [Aladdin]";
        case PciDevice10B9::DEVICE_1512: return "M1512 [Aladdin]";
        case PciDevice10B9::DEVICE_1513: return "M1513 [Aladdin]";
        case PciDevice10B9::DEVICE_1521: return "M1521 [Aladdin III]";
        case PciDevice10B9::DEVICE_1523: return "M1523";
        case PciDevice10B9::DEVICE_1531: return "M1531 [Aladdin IV]";
        case PciDevice10B9::DEVICE_1533: return "M1533/M1535/M1543 PCI to ISA Bridge [Aladdin IV/V/V+]";
        case PciDevice10B9::DEVICE_1541: return "M1541";
        case PciDevice10B9::DEVICE_1543: return "M1543";
        case PciDevice10B9::DEVICE_1563: return "M1563 HyperTransport South Bridge";
        case PciDevice10B9::DEVICE_1573: return "PCI to LPC Controller";
        case PciDevice10B9::DEVICE_1575: return "M1575 South Bridge";
        case PciDevice10B9::DEVICE_1621: return "M1621";
        case PciDevice10B9::DEVICE_1631: return "ALI M1631 PCI North Bridge Aladdin Pro III";
        case PciDevice10B9::DEVICE_1632: return "M1632M Northbridge+Trident";
        case PciDevice10B9::DEVICE_1641: return "ALI M1641 PCI North Bridge Aladdin Pro IV";
        case PciDevice10B9::DEVICE_1644: return "M1644/M1644T Northbridge+Trident";
        case PciDevice10B9::DEVICE_1646: return "M1646 Northbridge+Trident";
        case PciDevice10B9::DEVICE_1647: return "M1647 Northbridge [MAGiK 1 / MobileMAGiK 1]";
        case PciDevice10B9::DEVICE_1651: return "M1651/M1651T Northbridge [Aladdin-Pro 5/5M, Aladdin-Pro 5T/5TM]";
        case PciDevice10B9::DEVICE_1671: return "M1671 Super P4 Northbridge [AGP4X, PCI and SDR/DDR]";
        case PciDevice10B9::DEVICE_1672: return "M1672 Northbridge [CyberALADDiN-P4]";
        case PciDevice10B9::DEVICE_1681: return "M1681 P4 Northbridge [AGP8X, HyperTransport and SDR/DDR]";
        case PciDevice10B9::DEVICE_1687: return "M1687 K8 Northbridge [AGP8X and HyperTransport]";
        case PciDevice10B9::DEVICE_1689: return "M1689 K8 Northbridge [Super K8 Single Chip]";
        case PciDevice10B9::DEVICE_1695: return "M1695 Host Bridge";
        case PciDevice10B9::DEVICE_1697: return "M1697 HTT Host Bridge";
        case PciDevice10B9::DEVICE_3141: return "M3141";
        case PciDevice10B9::DEVICE_3143: return "M3143";
        case PciDevice10B9::DEVICE_3145: return "M3145";
        case PciDevice10B9::DEVICE_3147: return "M3147";
        case PciDevice10B9::DEVICE_3149: return "M3149";
        case PciDevice10B9::DEVICE_3151: return "M3151";
        case PciDevice10B9::DEVICE_3307: return "M3307";
        case PciDevice10B9::DEVICE_3309: return "M3309";
        case PciDevice10B9::DEVICE_3323: return "M3325 Video/Audio Decoder";
        case PciDevice10B9::DEVICE_5212: return "M4803";
        case PciDevice10B9::DEVICE_5215: return "MS4803";
        case PciDevice10B9::DEVICE_5217: return "M5217H";
        case PciDevice10B9::DEVICE_5219: return "M5219";
        case PciDevice10B9::DEVICE_5225: return "M5225";
        case PciDevice10B9::DEVICE_5228: return "M5228 ALi ATA/RAID Controller";
        case PciDevice10B9::DEVICE_5229: return "M5229 IDE";
        case PciDevice10B9::DEVICE_5235: return "M5225";
        case PciDevice10B9::DEVICE_5237: return "USB 1.1 Controller";
        case PciDevice10B9::DEVICE_5239: return "USB 2.0 Controller";
        case PciDevice10B9::DEVICE_5243: return "M1541 PCI to AGP Controller";
        case PciDevice10B9::DEVICE_5246: return "AGP8X Controller";
        case PciDevice10B9::DEVICE_5247: return "PCI to AGP Controller";
        case PciDevice10B9::DEVICE_5249: return "M5249 HTT to PCI Bridge";
        case PciDevice10B9::DEVICE_524B: return "PCI Express Root Port";
        case PciDevice10B9::DEVICE_524C: return "PCI Express Root Port";
        case PciDevice10B9::DEVICE_524D: return "PCI Express Root Port";
        case PciDevice10B9::DEVICE_524E: return "PCI Express Root Port";
        case PciDevice10B9::DEVICE_5251: return "M5251 P1394 OHCI 1.0 Controller";
        case PciDevice10B9::DEVICE_5253: return "M5253 P1394 OHCI 1.1 Controller";
        case PciDevice10B9::DEVICE_5261: return "M5261 Ethernet Controller";
        case PciDevice10B9::DEVICE_5263: return "ULi 1689, 1573 integrated ethernet.";
        case PciDevice10B9::DEVICE_5281: return "ALi M5281 Serial ATA / RAID Host Controller";
        case PciDevice10B9::DEVICE_5287: return "ULi 5287 SATA";
        case PciDevice10B9::DEVICE_5288: return "ULi M5288 SATA";
        case PciDevice10B9::DEVICE_5289: return "ULi 5289 SATA";
        case PciDevice10B9::DEVICE_5450: return "Lucent Technologies Soft Modem AMR";
        case PciDevice10B9::DEVICE_5451: return "M5451 PCI AC-Link Controller Audio Device";
        case PciDevice10B9::DEVICE_5453: return "M5453 PCI AC-Link Controller Modem Device";
        case PciDevice10B9::DEVICE_5455: return "M5455 PCI AC-Link Controller Audio Device";
        case PciDevice10B9::DEVICE_5457: return "M5457 AC'97 Modem Controller";
        case PciDevice10B9::DEVICE_5459: return "SmartLink SmartPCI561 56K Modem";
        case PciDevice10B9::DEVICE_545A: return "SmartLink SmartPCI563 56K Modem";
        case PciDevice10B9::DEVICE_5461: return "HD Audio Controller";
        case PciDevice10B9::DEVICE_5471: return "M5471 Memory Stick Controller";
        case PciDevice10B9::DEVICE_5473: return "M5473 SD-MMC Controller";
        case PciDevice10B9::DEVICE_7101: return "M7101 Power Management Controller [PMU]";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice10B9 device, u16 subsystemVendorID, u16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice10B9::DEVICE_0101: return "Unknown device";
        case PciDevice10B9::DEVICE_0111: return enumToHumanString((PciSubDevice10B90111)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice10B9::DEVICE_0780: return "Unknown device";
        case PciDevice10B9::DEVICE_0782: return "Unknown device";
        case PciDevice10B9::DEVICE_1435: return "Unknown device";
        case PciDevice10B9::DEVICE_1445: return "Unknown device";
        case PciDevice10B9::DEVICE_1449: return "Unknown device";
        case PciDevice10B9::DEVICE_1451: return "Unknown device";
        case PciDevice10B9::DEVICE_1461: return "Unknown device";
        case PciDevice10B9::DEVICE_1489: return "Unknown device";
        case PciDevice10B9::DEVICE_1511: return "Unknown device";
        case PciDevice10B9::DEVICE_1512: return "Unknown device";
        case PciDevice10B9::DEVICE_1513: return "Unknown device";
        case PciDevice10B9::DEVICE_1521: return enumToHumanString((PciSubDevice10B91521)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice10B9::DEVICE_1523: return enumToHumanString((PciSubDevice10B91523)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice10B9::DEVICE_1531: return "Unknown device";
        case PciDevice10B9::DEVICE_1533: return enumToHumanString((PciSubDevice10B91533)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice10B9::DEVICE_1541: return enumToHumanString((PciSubDevice10B91541)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice10B9::DEVICE_1543: return "Unknown device";
        case PciDevice10B9::DEVICE_1563: return enumToHumanString((PciSubDevice10B91563)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice10B9::DEVICE_1573: return "Unknown device";
        case PciDevice10B9::DEVICE_1575: return "Unknown device";
        case PciDevice10B9::DEVICE_1621: return "Unknown device";
        case PciDevice10B9::DEVICE_1631: return "Unknown device";
        case PciDevice10B9::DEVICE_1632: return "Unknown device";
        case PciDevice10B9::DEVICE_1641: return "Unknown device";
        case PciDevice10B9::DEVICE_1644: return "Unknown device";
        case PciDevice10B9::DEVICE_1646: return "Unknown device";
        case PciDevice10B9::DEVICE_1647: return "Unknown device";
        case PciDevice10B9::DEVICE_1651: return "Unknown device";
        case PciDevice10B9::DEVICE_1671: return "Unknown device";
        case PciDevice10B9::DEVICE_1672: return "Unknown device";
        case PciDevice10B9::DEVICE_1681: return "Unknown device";
        case PciDevice10B9::DEVICE_1687: return "Unknown device";
        case PciDevice10B9::DEVICE_1689: return "Unknown device";
        case PciDevice10B9::DEVICE_1695: return "Unknown device";
        case PciDevice10B9::DEVICE_1697: return "Unknown device";
        case PciDevice10B9::DEVICE_3141: return "Unknown device";
        case PciDevice10B9::DEVICE_3143: return "Unknown device";
        case PciDevice10B9::DEVICE_3145: return "Unknown device";
        case PciDevice10B9::DEVICE_3147: return "Unknown device";
        case PciDevice10B9::DEVICE_3149: return "Unknown device";
        case PciDevice10B9::DEVICE_3151: return "Unknown device";
        case PciDevice10B9::DEVICE_3307: return "Unknown device";
        case PciDevice10B9::DEVICE_3309: return "Unknown device";
        case PciDevice10B9::DEVICE_3323: return "Unknown device";
        case PciDevice10B9::DEVICE_5212: return "Unknown device";
        case PciDevice10B9::DEVICE_5215: return "Unknown device";
        case PciDevice10B9::DEVICE_5217: return "Unknown device";
        case PciDevice10B9::DEVICE_5219: return "Unknown device";
        case PciDevice10B9::DEVICE_5225: return "Unknown device";
        case PciDevice10B9::DEVICE_5228: return "Unknown device";
        case PciDevice10B9::DEVICE_5229: return enumToHumanString((PciSubDevice10B95229)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice10B9::DEVICE_5235: return "Unknown device";
        case PciDevice10B9::DEVICE_5237: return enumToHumanString((PciSubDevice10B95237)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice10B9::DEVICE_5239: return enumToHumanString((PciSubDevice10B95239)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice10B9::DEVICE_5243: return "Unknown device";
        case PciDevice10B9::DEVICE_5246: return "Unknown device";
        case PciDevice10B9::DEVICE_5247: return "Unknown device";
        case PciDevice10B9::DEVICE_5249: return "Unknown device";
        case PciDevice10B9::DEVICE_524B: return "Unknown device";
        case PciDevice10B9::DEVICE_524C: return "Unknown device";
        case PciDevice10B9::DEVICE_524D: return "Unknown device";
        case PciDevice10B9::DEVICE_524E: return "Unknown device";
        case PciDevice10B9::DEVICE_5251: return "Unknown device";
        case PciDevice10B9::DEVICE_5253: return "Unknown device";
        case PciDevice10B9::DEVICE_5261: return "Unknown device";
        case PciDevice10B9::DEVICE_5263: return "Unknown device";
        case PciDevice10B9::DEVICE_5281: return "Unknown device";
        case PciDevice10B9::DEVICE_5287: return "Unknown device";
        case PciDevice10B9::DEVICE_5288: return enumToHumanString((PciSubDevice10B95288)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice10B9::DEVICE_5289: return "Unknown device";
        case PciDevice10B9::DEVICE_5450: return "Unknown device";
        case PciDevice10B9::DEVICE_5451: return enumToHumanString((PciSubDevice10B95451)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice10B9::DEVICE_5453: return "Unknown device";
        case PciDevice10B9::DEVICE_5455: return enumToHumanString((PciSubDevice10B95455)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice10B9::DEVICE_5457: return enumToHumanString((PciSubDevice10B95457)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice10B9::DEVICE_5459: return "Unknown device";
        case PciDevice10B9::DEVICE_545A: return "Unknown device";
        case PciDevice10B9::DEVICE_5461: return "Unknown device";
        case PciDevice10B9::DEVICE_5471: return "Unknown device";
        case PciDevice10B9::DEVICE_5473: return "Unknown device";
        case PciDevice10B9::DEVICE_7101: return enumToHumanString((PciSubDevice10B97101)(subsystemVendorID << 16 | subDeviceId));

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B9_PCIDEVICE10B9_H
