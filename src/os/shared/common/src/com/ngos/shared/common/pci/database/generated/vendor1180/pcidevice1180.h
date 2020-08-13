// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1180_PCIDEVICE1180_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1180_PCIDEVICE1180_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1180: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0465 = 0x0465,
    DEVICE_0466 = 0x0466,
    DEVICE_0475 = 0x0475,
    DEVICE_0476 = 0x0476,
    DEVICE_0477 = 0x0477,
    DEVICE_0478 = 0x0478,
    DEVICE_0511 = 0x0511,
    DEVICE_0522 = 0x0522,
    DEVICE_0551 = 0x0551,
    DEVICE_0552 = 0x0552,
    DEVICE_0554 = 0x0554,
    DEVICE_0575 = 0x0575,
    DEVICE_0576 = 0x0576,
    DEVICE_0592 = 0x0592,
    DEVICE_0811 = 0x0811,
    DEVICE_0822 = 0x0822,
    DEVICE_0832 = 0x0832,
    DEVICE_0841 = 0x0841,
    DEVICE_0843 = 0x0843,
    DEVICE_0852 = 0x0852,
    DEVICE_E230 = 0xE230,
    DEVICE_E476 = 0xE476,
    DEVICE_E822 = 0xE822,
    DEVICE_E823 = 0xE823,
    DEVICE_E832 = 0xE832,
    DEVICE_E852 = 0xE852
};



inline const char8* enumToString(PciDevice1180 device1180) // TEST: NO
{
    // COMMON_LT((" | device1180 = %u", device1180)); // Commented to avoid bad looking logs



    switch (device1180)
    {
        case PciDevice1180::NONE:        return "NONE";
        case PciDevice1180::DEVICE_0465: return "DEVICE_0465";
        case PciDevice1180::DEVICE_0466: return "DEVICE_0466";
        case PciDevice1180::DEVICE_0475: return "DEVICE_0475";
        case PciDevice1180::DEVICE_0476: return "DEVICE_0476";
        case PciDevice1180::DEVICE_0477: return "DEVICE_0477";
        case PciDevice1180::DEVICE_0478: return "DEVICE_0478";
        case PciDevice1180::DEVICE_0511: return "DEVICE_0511";
        case PciDevice1180::DEVICE_0522: return "DEVICE_0522";
        case PciDevice1180::DEVICE_0551: return "DEVICE_0551";
        case PciDevice1180::DEVICE_0552: return "DEVICE_0552";
        case PciDevice1180::DEVICE_0554: return "DEVICE_0554";
        case PciDevice1180::DEVICE_0575: return "DEVICE_0575";
        case PciDevice1180::DEVICE_0576: return "DEVICE_0576";
        case PciDevice1180::DEVICE_0592: return "DEVICE_0592";
        case PciDevice1180::DEVICE_0811: return "DEVICE_0811";
        case PciDevice1180::DEVICE_0822: return "DEVICE_0822";
        case PciDevice1180::DEVICE_0832: return "DEVICE_0832";
        case PciDevice1180::DEVICE_0841: return "DEVICE_0841";
        case PciDevice1180::DEVICE_0843: return "DEVICE_0843";
        case PciDevice1180::DEVICE_0852: return "DEVICE_0852";
        case PciDevice1180::DEVICE_E230: return "DEVICE_E230";
        case PciDevice1180::DEVICE_E476: return "DEVICE_E476";
        case PciDevice1180::DEVICE_E822: return "DEVICE_E822";
        case PciDevice1180::DEVICE_E823: return "DEVICE_E823";
        case PciDevice1180::DEVICE_E832: return "DEVICE_E832";
        case PciDevice1180::DEVICE_E852: return "DEVICE_E852";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1180 device1180) // TEST: NO
{
    // COMMON_LT((" | device1180 = %u", device1180)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1180, enumToString(device1180));

    return res;
}



inline const char8* enumToHumanString(PciDevice1180 device1180) // TEST: NO
{
    // COMMON_LT((" | device1180 = %u", device1180)); // Commented to avoid bad looking logs



    switch (device1180)
    {
        case PciDevice1180::DEVICE_0465: return "RL5c465";
        case PciDevice1180::DEVICE_0466: return "RL5c466";
        case PciDevice1180::DEVICE_0475: return "RL5c475";
        case PciDevice1180::DEVICE_0476: return "RL5c476 II";
        case PciDevice1180::DEVICE_0477: return "RL5c477";
        case PciDevice1180::DEVICE_0478: return "RL5c478";
        case PciDevice1180::DEVICE_0511: return "R5C511";
        case PciDevice1180::DEVICE_0522: return "R5C522 IEEE 1394 Controller";
        case PciDevice1180::DEVICE_0551: return "R5C551 IEEE 1394 Controller";
        case PciDevice1180::DEVICE_0552: return "R5C552 IEEE 1394 Controller";
        case PciDevice1180::DEVICE_0554: return "R5C554";
        case PciDevice1180::DEVICE_0575: return "R5C575 SD Bus Host Adapter";
        case PciDevice1180::DEVICE_0576: return "R5C576 SD Bus Host Adapter";
        case PciDevice1180::DEVICE_0592: return "R5C592 Memory Stick Bus Host Adapter";
        case PciDevice1180::DEVICE_0811: return "R5C811";
        case PciDevice1180::DEVICE_0822: return "R5C822 SD/SDIO/MMC/MS/MSPro Host Adapter";
        case PciDevice1180::DEVICE_0832: return "R5C832 IEEE 1394 Controller";
        case PciDevice1180::DEVICE_0841: return "R5C841 CardBus/SD/SDIO/MMC/MS/MSPro/xD/IEEE1394";
        case PciDevice1180::DEVICE_0843: return "R5C843 MMC Host Controller";
        case PciDevice1180::DEVICE_0852: return "xD-Picture Card Controller";
        case PciDevice1180::DEVICE_E230: return "R5U2xx (R5U230 / R5U231 / R5U241) [Memory Stick Host Controller]";
        case PciDevice1180::DEVICE_E476: return "CardBus bridge";
        case PciDevice1180::DEVICE_E822: return "MMC/SD Host Controller";
        case PciDevice1180::DEVICE_E823: return "PCIe SDXC/MMC Host Controller";
        case PciDevice1180::DEVICE_E832: return "R5C832 PCIe IEEE 1394 Controller";
        case PciDevice1180::DEVICE_E852: return "PCIe xD-Picture Card Controller";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1180_PCIDEVICE1180_H
