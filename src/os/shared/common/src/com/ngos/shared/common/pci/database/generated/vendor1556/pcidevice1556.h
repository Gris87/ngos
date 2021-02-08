// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1556_PCIDEVICE1556_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1556_PCIDEVICE1556_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1556: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1100 = 0x1100,
    DEVICE_110F = 0x110F,
    DEVICE_1110 = 0x1110,
    DEVICE_1111 = 0x1111,
    DEVICE_1112 = 0x1112,
    DEVICE_1113 = 0x1113,
    DEVICE_1114 = 0x1114,
    DEVICE_1115 = 0x1115,
    DEVICE_1116 = 0x1116,
    DEVICE_BE00 = 0xBE00
};



inline const char8* enumToString(PciDevice1556 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1556::NONE:        return "NONE";
        case PciDevice1556::DEVICE_1100: return "DEVICE_1100";
        case PciDevice1556::DEVICE_110F: return "DEVICE_110F";
        case PciDevice1556::DEVICE_1110: return "DEVICE_1110";
        case PciDevice1556::DEVICE_1111: return "DEVICE_1111";
        case PciDevice1556::DEVICE_1112: return "DEVICE_1112";
        case PciDevice1556::DEVICE_1113: return "DEVICE_1113";
        case PciDevice1556::DEVICE_1114: return "DEVICE_1114";
        case PciDevice1556::DEVICE_1115: return "DEVICE_1115";
        case PciDevice1556::DEVICE_1116: return "DEVICE_1116";
        case PciDevice1556::DEVICE_BE00: return "DEVICE_BE00";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1556 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1556 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1556::DEVICE_1100: return "PCI Express Core Reference Design";
        case PciDevice1556::DEVICE_110F: return "PCI Express Core Reference Design Virtual Function";
        case PciDevice1556::DEVICE_1110: return "XpressRich Reference Design";
        case PciDevice1556::DEVICE_1111: return "XpressRich-AXI Ref Design";
        case PciDevice1556::DEVICE_1112: return "QuickPCIe";
        case PciDevice1556::DEVICE_1113: return "XpressSwitch";
        case PciDevice1556::DEVICE_1114: return "Inspector";
        case PciDevice1556::DEVICE_1115: return "XpressLINK Ref Design";
        case PciDevice1556::DEVICE_1116: return "XpressLINK-SOC Ref Design";
        case PciDevice1556::DEVICE_BE00: return "PCI Express Bridge";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1556_PCIDEVICE1556_H
