// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10EC_PCIDEVICE10EC_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10EC_PCIDEVICE10EC_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice10EC: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0139 = 0x0139,
    DEVICE_5208 = 0x5208,
    DEVICE_5209 = 0x5209,
    DEVICE_5227 = 0x5227,
    DEVICE_5229 = 0x5229,
    DEVICE_522A = 0x522A,
    DEVICE_5249 = 0x5249,
    DEVICE_524A = 0x524A,
    DEVICE_5250 = 0x5250,
    DEVICE_525A = 0x525A,
    DEVICE_5260 = 0x5260,
    DEVICE_5286 = 0x5286,
    DEVICE_5287 = 0x5287,
    DEVICE_5288 = 0x5288,
    DEVICE_5289 = 0x5289,
    DEVICE_8029 = 0x8029,
    DEVICE_8125 = 0x8125,
    DEVICE_8129 = 0x8129,
    DEVICE_8136 = 0x8136,
    DEVICE_8137 = 0x8137,
    DEVICE_8138 = 0x8138,
    DEVICE_8139 = 0x8139,
    DEVICE_8167 = 0x8167,
    DEVICE_8168 = 0x8168,
    DEVICE_8169 = 0x8169,
    DEVICE_8171 = 0x8171,
    DEVICE_8172 = 0x8172,
    DEVICE_8173 = 0x8173,
    DEVICE_8174 = 0x8174,
    DEVICE_8176 = 0x8176,
    DEVICE_8177 = 0x8177,
    DEVICE_8178 = 0x8178,
    DEVICE_8179 = 0x8179,
    DEVICE_8180 = 0x8180,
    DEVICE_8185 = 0x8185,
    DEVICE_818B = 0x818B,
    DEVICE_8190 = 0x8190,
    DEVICE_8191 = 0x8191,
    DEVICE_8192 = 0x8192,
    DEVICE_8193 = 0x8193,
    DEVICE_8196 = 0x8196,
    DEVICE_8197 = 0x8197,
    DEVICE_8199 = 0x8199,
    DEVICE_8723 = 0x8723,
    DEVICE_8812 = 0x8812,
    DEVICE_8813 = 0x8813,
    DEVICE_8821 = 0x8821,
    DEVICE_B723 = 0xB723,
    DEVICE_B822 = 0xB822,
    DEVICE_C821 = 0xC821,
    DEVICE_C822 = 0xC822,
    DEVICE_D723 = 0xD723
};



inline const char8* enumToString(PciDevice10EC device10EC) // TEST: NO
{
    // COMMON_LT((" | device10EC = %u", device10EC)); // Commented to avoid bad looking logs



    switch (device10EC)
    {
        case PciDevice10EC::NONE:        return "NONE";
        case PciDevice10EC::DEVICE_0139: return "DEVICE_0139";
        case PciDevice10EC::DEVICE_5208: return "DEVICE_5208";
        case PciDevice10EC::DEVICE_5209: return "DEVICE_5209";
        case PciDevice10EC::DEVICE_5227: return "DEVICE_5227";
        case PciDevice10EC::DEVICE_5229: return "DEVICE_5229";
        case PciDevice10EC::DEVICE_522A: return "DEVICE_522A";
        case PciDevice10EC::DEVICE_5249: return "DEVICE_5249";
        case PciDevice10EC::DEVICE_524A: return "DEVICE_524A";
        case PciDevice10EC::DEVICE_5250: return "DEVICE_5250";
        case PciDevice10EC::DEVICE_525A: return "DEVICE_525A";
        case PciDevice10EC::DEVICE_5260: return "DEVICE_5260";
        case PciDevice10EC::DEVICE_5286: return "DEVICE_5286";
        case PciDevice10EC::DEVICE_5287: return "DEVICE_5287";
        case PciDevice10EC::DEVICE_5288: return "DEVICE_5288";
        case PciDevice10EC::DEVICE_5289: return "DEVICE_5289";
        case PciDevice10EC::DEVICE_8029: return "DEVICE_8029";
        case PciDevice10EC::DEVICE_8125: return "DEVICE_8125";
        case PciDevice10EC::DEVICE_8129: return "DEVICE_8129";
        case PciDevice10EC::DEVICE_8136: return "DEVICE_8136";
        case PciDevice10EC::DEVICE_8137: return "DEVICE_8137";
        case PciDevice10EC::DEVICE_8138: return "DEVICE_8138";
        case PciDevice10EC::DEVICE_8139: return "DEVICE_8139";
        case PciDevice10EC::DEVICE_8167: return "DEVICE_8167";
        case PciDevice10EC::DEVICE_8168: return "DEVICE_8168";
        case PciDevice10EC::DEVICE_8169: return "DEVICE_8169";
        case PciDevice10EC::DEVICE_8171: return "DEVICE_8171";
        case PciDevice10EC::DEVICE_8172: return "DEVICE_8172";
        case PciDevice10EC::DEVICE_8173: return "DEVICE_8173";
        case PciDevice10EC::DEVICE_8174: return "DEVICE_8174";
        case PciDevice10EC::DEVICE_8176: return "DEVICE_8176";
        case PciDevice10EC::DEVICE_8177: return "DEVICE_8177";
        case PciDevice10EC::DEVICE_8178: return "DEVICE_8178";
        case PciDevice10EC::DEVICE_8179: return "DEVICE_8179";
        case PciDevice10EC::DEVICE_8180: return "DEVICE_8180";
        case PciDevice10EC::DEVICE_8185: return "DEVICE_8185";
        case PciDevice10EC::DEVICE_818B: return "DEVICE_818B";
        case PciDevice10EC::DEVICE_8190: return "DEVICE_8190";
        case PciDevice10EC::DEVICE_8191: return "DEVICE_8191";
        case PciDevice10EC::DEVICE_8192: return "DEVICE_8192";
        case PciDevice10EC::DEVICE_8193: return "DEVICE_8193";
        case PciDevice10EC::DEVICE_8196: return "DEVICE_8196";
        case PciDevice10EC::DEVICE_8197: return "DEVICE_8197";
        case PciDevice10EC::DEVICE_8199: return "DEVICE_8199";
        case PciDevice10EC::DEVICE_8723: return "DEVICE_8723";
        case PciDevice10EC::DEVICE_8812: return "DEVICE_8812";
        case PciDevice10EC::DEVICE_8813: return "DEVICE_8813";
        case PciDevice10EC::DEVICE_8821: return "DEVICE_8821";
        case PciDevice10EC::DEVICE_B723: return "DEVICE_B723";
        case PciDevice10EC::DEVICE_B822: return "DEVICE_B822";
        case PciDevice10EC::DEVICE_C821: return "DEVICE_C821";
        case PciDevice10EC::DEVICE_C822: return "DEVICE_C822";
        case PciDevice10EC::DEVICE_D723: return "DEVICE_D723";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice10EC device10EC) // TEST: NO
{
    // COMMON_LT((" | device10EC = %u", device10EC)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device10EC, enumToString(device10EC));

    return res;
}



inline const char8* enumToHumanString(PciDevice10EC device10EC) // TEST: NO
{
    // COMMON_LT((" | device10EC = %u", device10EC)); // Commented to avoid bad looking logs



    switch (device10EC)
    {
        case PciDevice10EC::DEVICE_0139: return "RTL-8139/8139C/8139C+ Ethernet Controller";
        case PciDevice10EC::DEVICE_5208: return "RTS5208 PCI Express Card Reader";
        case PciDevice10EC::DEVICE_5209: return "RTS5209 PCI Express Card Reader";
        case PciDevice10EC::DEVICE_5227: return "RTS5227 PCI Express Card Reader";
        case PciDevice10EC::DEVICE_5229: return "RTS5229 PCI Express Card Reader";
        case PciDevice10EC::DEVICE_522A: return "RTS522A PCI Express Card Reader";
        case PciDevice10EC::DEVICE_5249: return "RTS5249 PCI Express Card Reader";
        case PciDevice10EC::DEVICE_524A: return "RTS524A PCI Express Card Reader";
        case PciDevice10EC::DEVICE_5250: return "RTS5250 PCI Express Card Reader";
        case PciDevice10EC::DEVICE_525A: return "RTS525A PCI Express Card Reader";
        case PciDevice10EC::DEVICE_5260: return "RTS5260 PCI Express Card Reader";
        case PciDevice10EC::DEVICE_5286: return "RTS5286 PCI Express Card Reader";
        case PciDevice10EC::DEVICE_5287: return "RTL8411B PCI Express Card Reader";
        case PciDevice10EC::DEVICE_5288: return "RTS5288 PCI Express Card Reader";
        case PciDevice10EC::DEVICE_5289: return "RTL8411 PCI Express Card Reader";
        case PciDevice10EC::DEVICE_8029: return "RTL-8029(AS)";
        case PciDevice10EC::DEVICE_8125: return "RTL8125 2.5GbE Controller";
        case PciDevice10EC::DEVICE_8129: return "RTL-8129";
        case PciDevice10EC::DEVICE_8136: return "RTL810xE PCI Express Fast Ethernet controller";
        case PciDevice10EC::DEVICE_8137: return "RTL8104E PCIe Fast Ethernet Controller";
        case PciDevice10EC::DEVICE_8138: return "RT8139 (B/C) Cardbus Fast Ethernet Adapter";
        case PciDevice10EC::DEVICE_8139: return "RTL-8100/8101L/8139 PCI Fast Ethernet Adapter";
        case PciDevice10EC::DEVICE_8167: return "RTL-8110SC/8169SC Gigabit Ethernet";
        case PciDevice10EC::DEVICE_8168: return "RTL8111/8168/8411 PCI Express Gigabit Ethernet Controller";
        case PciDevice10EC::DEVICE_8169: return "RTL8169 PCI Gigabit Ethernet Controller";
        case PciDevice10EC::DEVICE_8171: return "RTL8191SEvA Wireless LAN Controller";
        case PciDevice10EC::DEVICE_8172: return "RTL8191SEvB Wireless LAN Controller";
        case PciDevice10EC::DEVICE_8173: return "RTL8192SE Wireless LAN Controller";
        case PciDevice10EC::DEVICE_8174: return "RTL8192SE Wireless LAN Controller";
        case PciDevice10EC::DEVICE_8176: return "RTL8188CE 802.11b/g/n WiFi Adapter";
        case PciDevice10EC::DEVICE_8177: return "RTL8191CE PCIe Wireless Network Adapter";
        case PciDevice10EC::DEVICE_8178: return "RTL8192CE PCIe Wireless Network Adapter";
        case PciDevice10EC::DEVICE_8179: return "RTL8188EE Wireless Network Adapter";
        case PciDevice10EC::DEVICE_8180: return "RTL8180L 802.11b MAC";
        case PciDevice10EC::DEVICE_8185: return "RTL-8185 IEEE 802.11a/b/g Wireless LAN Controller";
        case PciDevice10EC::DEVICE_818B: return "RTL8192EE PCIe Wireless Network Adapter";
        case PciDevice10EC::DEVICE_8190: return "RTL8190 802.11n PCI Wireless Network Adapter";
        case PciDevice10EC::DEVICE_8191: return "RTL8192CE PCIe Wireless Network Adapter";
        case PciDevice10EC::DEVICE_8192: return "RTL8192E/RTL8192SE Wireless LAN Controller";
        case PciDevice10EC::DEVICE_8193: return "RTL8192DE Wireless LAN Controller";
        case PciDevice10EC::DEVICE_8196: return "RTL8196 Integrated PCI-e Bridge";
        case PciDevice10EC::DEVICE_8197: return "SmartLAN56 56K Modem";
        case PciDevice10EC::DEVICE_8199: return "RTL8187SE Wireless LAN Controller";
        case PciDevice10EC::DEVICE_8723: return "RTL8723AE PCIe Wireless Network Adapter";
        case PciDevice10EC::DEVICE_8812: return "RTL8812AE 802.11ac PCIe Wireless Network Adapter";
        case PciDevice10EC::DEVICE_8813: return "RTL8813AE 802.11ac PCIe Wireless Network Adapter";
        case PciDevice10EC::DEVICE_8821: return "RTL8821AE 802.11ac PCIe Wireless Network Adapter";
        case PciDevice10EC::DEVICE_B723: return "RTL8723BE PCIe Wireless Network Adapter";
        case PciDevice10EC::DEVICE_B822: return "RTL8822BE 802.11a/b/g/n/ac WiFi adapter";
        case PciDevice10EC::DEVICE_C821: return "RTL8821CE 802.11ac PCIe Wireless Network Adapter";
        case PciDevice10EC::DEVICE_C822: return "RTL8822CE 802.11ac PCIe Wireless Network Adapter";
        case PciDevice10EC::DEVICE_D723: return "RTL8723DE 802.11b/g/n PCIe Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10EC_PCIDEVICE10EC_H
