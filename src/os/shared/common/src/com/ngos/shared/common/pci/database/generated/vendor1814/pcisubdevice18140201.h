// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1814_PCISUBDEVICE18140201_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1814_PCISUBDEVICE18140201_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice18140201: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1043130F = 0x1043130F,
    SUBDEVICE_11863C00 = 0x11863C00,
    SUBDEVICE_1371001E = 0x1371001E,
    SUBDEVICE_1371001F = 0x1371001F,
    SUBDEVICE_13710020 = 0x13710020,
    SUBDEVICE_1458E381 = 0x1458E381,
    SUBDEVICE_1458E931 = 0x1458E931,
    SUBDEVICE_14626833 = 0x14626833,
    SUBDEVICE_14626835 = 0x14626835,
    SUBDEVICE_17370032 = 0x17370032,
    SUBDEVICE_1799700A = 0x1799700A,
    SUBDEVICE_1799701A = 0x1799701A,
    SUBDEVICE_18142560 = 0x18142560,
    SUBDEVICE_182D9073 = 0x182D9073,
    SUBDEVICE_185F22A0 = 0x185F22A0,
    SUBDEVICE_18EB5312 = 0x18EB5312,
    SUBDEVICE_19483C00 = 0x19483C00,
    SUBDEVICE_19483C01 = 0x19483C01
};



inline const char8* enumToString(PciSubDevice18140201 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice18140201::NONE:               return "NONE";
        case PciSubDevice18140201::SUBDEVICE_1043130F: return "SUBDEVICE_1043130F";
        case PciSubDevice18140201::SUBDEVICE_11863C00: return "SUBDEVICE_11863C00";
        case PciSubDevice18140201::SUBDEVICE_1371001E: return "SUBDEVICE_1371001E";
        case PciSubDevice18140201::SUBDEVICE_1371001F: return "SUBDEVICE_1371001F";
        case PciSubDevice18140201::SUBDEVICE_13710020: return "SUBDEVICE_13710020";
        case PciSubDevice18140201::SUBDEVICE_1458E381: return "SUBDEVICE_1458E381";
        case PciSubDevice18140201::SUBDEVICE_1458E931: return "SUBDEVICE_1458E931";
        case PciSubDevice18140201::SUBDEVICE_14626833: return "SUBDEVICE_14626833";
        case PciSubDevice18140201::SUBDEVICE_14626835: return "SUBDEVICE_14626835";
        case PciSubDevice18140201::SUBDEVICE_17370032: return "SUBDEVICE_17370032";
        case PciSubDevice18140201::SUBDEVICE_1799700A: return "SUBDEVICE_1799700A";
        case PciSubDevice18140201::SUBDEVICE_1799701A: return "SUBDEVICE_1799701A";
        case PciSubDevice18140201::SUBDEVICE_18142560: return "SUBDEVICE_18142560";
        case PciSubDevice18140201::SUBDEVICE_182D9073: return "SUBDEVICE_182D9073";
        case PciSubDevice18140201::SUBDEVICE_185F22A0: return "SUBDEVICE_185F22A0";
        case PciSubDevice18140201::SUBDEVICE_18EB5312: return "SUBDEVICE_18EB5312";
        case PciSubDevice18140201::SUBDEVICE_19483C00: return "SUBDEVICE_19483C00";
        case PciSubDevice18140201::SUBDEVICE_19483C01: return "SUBDEVICE_19483C01";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice18140201 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice18140201 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice18140201::SUBDEVICE_1043130F: return "WL-130g";
        case PciSubDevice18140201::SUBDEVICE_11863C00: return "DWL-G650X Wireless 11g CardBus Adapter";
        case PciSubDevice18140201::SUBDEVICE_1371001E: return "CWC-854 Wireless-G CardBus Adapter";
        case PciSubDevice18140201::SUBDEVICE_1371001F: return "CWM-854 Wireless-G Mini PCI Adapter";
        case PciSubDevice18140201::SUBDEVICE_13710020: return "CWP-854 Wireless-G PCI Adapter";
        case PciSubDevice18140201::SUBDEVICE_1458E381: return "GN-WMKG 802.11b/g Wireless CardBus Adapter";
        case PciSubDevice18140201::SUBDEVICE_1458E931: return "GN-WIKG 802.11b/g mini-PCI Adapter";
        case PciSubDevice18140201::SUBDEVICE_14626833: return "Unknown 802.11g mini-PCI Adapter";
        case PciSubDevice18140201::SUBDEVICE_14626835: return "Wireless 11G CardBus CB54G2";
        case PciSubDevice18140201::SUBDEVICE_17370032: return "WMP54G v4.0 PCI Adapter";
        case PciSubDevice18140201::SUBDEVICE_1799700A: return "F5D7000 v2000/v3000 Wireless G Desktop Card";
        case PciSubDevice18140201::SUBDEVICE_1799701A: return "F5D7010 v2000/v3000 Wireless G Notebook Card";
        case PciSubDevice18140201::SUBDEVICE_18142560: return "RT2500 Wireless 802.11bg";
        case PciSubDevice18140201::SUBDEVICE_182D9073: return "WL-115 Wireless Network PCI Adapter";
        case PciSubDevice18140201::SUBDEVICE_185F22A0: return "CN-WF513 Wireless Cardbus Adapter";
        case PciSubDevice18140201::SUBDEVICE_18EB5312: return "WL531P IEEE 802.11g PCI Card-EU";
        case PciSubDevice18140201::SUBDEVICE_19483C00: return "C54RC v1 Wireless 11g CardBus Adapter";
        case PciSubDevice18140201::SUBDEVICE_19483C01: return "C54Ri v1 Wireless 11g PCI Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1814_PCISUBDEVICE18140201_H
