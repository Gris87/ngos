// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR168C_PCISUBDEVICE168C001B_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR168C_PCISUBDEVICE168C001B_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice168C001B: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_07771107 = 0x07771107,
    SUBDEVICE_07773002 = 0x07773002,
    SUBDEVICE_07773005 = 0x07773005,
    SUBDEVICE_07773009 = 0x07773009,
    SUBDEVICE_1154034E = 0x1154034E,
    SUBDEVICE_11863A19 = 0x11863A19,
    SUBDEVICE_11863A22 = 0x11863A22,
    SUBDEVICE_11AD5001 = 0x11AD5001,
    SUBDEVICE_1458E901 = 0x1458E901,
    SUBDEVICE_168C001B = 0x168C001B,
    SUBDEVICE_168C1062 = 0x168C1062,
    SUBDEVICE_168C2062 = 0x168C2062,
    SUBDEVICE_168C2063 = 0x168C2063,
    SUBDEVICE_17F9000B = 0x17F9000B,
    SUBDEVICE_17F9000C = 0x17F9000C,
    SUBDEVICE_17F9000D = 0x17F9000D,
    SUBDEVICE_185F1600 = 0x185F1600,
    SUBDEVICE_19483ABA = 0x19483ABA,
    SUBDEVICE_A7276804 = 0xA7276804
};



inline const char8* enumToString(PciSubDevice168C001B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice168C001B::NONE:               return "NONE";
        case PciSubDevice168C001B::SUBDEVICE_07771107: return "SUBDEVICE_07771107";
        case PciSubDevice168C001B::SUBDEVICE_07773002: return "SUBDEVICE_07773002";
        case PciSubDevice168C001B::SUBDEVICE_07773005: return "SUBDEVICE_07773005";
        case PciSubDevice168C001B::SUBDEVICE_07773009: return "SUBDEVICE_07773009";
        case PciSubDevice168C001B::SUBDEVICE_1154034E: return "SUBDEVICE_1154034E";
        case PciSubDevice168C001B::SUBDEVICE_11863A19: return "SUBDEVICE_11863A19";
        case PciSubDevice168C001B::SUBDEVICE_11863A22: return "SUBDEVICE_11863A22";
        case PciSubDevice168C001B::SUBDEVICE_11AD5001: return "SUBDEVICE_11AD5001";
        case PciSubDevice168C001B::SUBDEVICE_1458E901: return "SUBDEVICE_1458E901";
        case PciSubDevice168C001B::SUBDEVICE_168C001B: return "SUBDEVICE_168C001B";
        case PciSubDevice168C001B::SUBDEVICE_168C1062: return "SUBDEVICE_168C1062";
        case PciSubDevice168C001B::SUBDEVICE_168C2062: return "SUBDEVICE_168C2062";
        case PciSubDevice168C001B::SUBDEVICE_168C2063: return "SUBDEVICE_168C2063";
        case PciSubDevice168C001B::SUBDEVICE_17F9000B: return "SUBDEVICE_17F9000B";
        case PciSubDevice168C001B::SUBDEVICE_17F9000C: return "SUBDEVICE_17F9000C";
        case PciSubDevice168C001B::SUBDEVICE_17F9000D: return "SUBDEVICE_17F9000D";
        case PciSubDevice168C001B::SUBDEVICE_185F1600: return "SUBDEVICE_185F1600";
        case PciSubDevice168C001B::SUBDEVICE_19483ABA: return "SUBDEVICE_19483ABA";
        case PciSubDevice168C001B::SUBDEVICE_A7276804: return "SUBDEVICE_A7276804";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice168C001B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice168C001B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice168C001B::SUBDEVICE_07771107: return "UB5 802.11a Wireless Mini PCI Adapter";
        case PciSubDevice168C001B::SUBDEVICE_07773002: return "XR2 802.11g Wireless Mini PCI Adapter";
        case PciSubDevice168C001B::SUBDEVICE_07773005: return "XR5 802.11a Wireless Mini PCI Adapter";
        case PciSubDevice168C001B::SUBDEVICE_07773009: return "XR9 900MHz Wireless Mini PCI Adapter";
        case PciSubDevice168C001B::SUBDEVICE_1154034E: return "WLI-CB-AG108HP 802.11abg Wireless CardBus Adapter";
        case PciSubDevice168C001B::SUBDEVICE_11863A19: return "D-Link AirPremier AG DWL-AG660 Wireless Cardbus Adapter";
        case PciSubDevice168C001B::SUBDEVICE_11863A22: return "AirPremier AG DWL-AG530 Wireless PCI Adapter (rev.B)";
        case PciSubDevice168C001B::SUBDEVICE_11AD5001: return "WN5301A 802.11bg Wireless PCI Adapter";
        case PciSubDevice168C001B::SUBDEVICE_1458E901: return "GN-WI01HT Wireless a/b/g MiniPCI Adapter";
        case PciSubDevice168C001B::SUBDEVICE_168C001B: return "Wireless LAN PCI LiteOn";
        case PciSubDevice168C001B::SUBDEVICE_168C1062: return "IPN-W100CB 802.11abg Wireless CardBus Adapter";
        case PciSubDevice168C001B::SUBDEVICE_168C2062: return "EnGenius EMP-8602 (400mw) or Compex WLM54AG (SuperAG)";
        case PciSubDevice168C001B::SUBDEVICE_168C2063: return "EnGenius EMP-8602 (400mw) or Compex WLM54AG";
        case PciSubDevice168C001B::SUBDEVICE_17F9000B: return "WL-711A 802.11abg Wireless CardBus Adapter";
        case PciSubDevice168C001B::SUBDEVICE_17F9000C: return "WPIA-112AG 802.11abg Wireless PCI Adapter";
        case PciSubDevice168C001B::SUBDEVICE_17F9000D: return "PC-686X 802.11abg Wireless Mini PCI Adapter";
        case PciSubDevice168C001B::SUBDEVICE_185F1600: return "DCMA-82 High Power WLAN 802.11a/b/g mini-PCI Module (Super A/G, eXtended Range, 400mW)";
        case PciSubDevice168C001B::SUBDEVICE_19483ABA: return "RBTBJ-AW 802.11abg Wireless Cardbus Adapter";
        case PciSubDevice168C001B::SUBDEVICE_A7276804: return "Wireless 11a/b/g PC Card with XJACK(r) Antenna";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR168C_PCISUBDEVICE168C001B_H
