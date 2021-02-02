// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104C_PCISUBDEVICE104C9066_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104C_PCISUBDEVICE104C9066_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice104C9066: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_03083404 = 0x03083404,
    SUBDEVICE_03083406 = 0x03083406,
    SUBDEVICE_104C9066 = 0x104C9066,
    SUBDEVICE_104C9067 = 0x104C9067,
    SUBDEVICE_104C9096 = 0x104C9096,
    SUBDEVICE_11863B04 = 0x11863B04,
    SUBDEVICE_11863B05 = 0x11863B05,
    SUBDEVICE_11863B08 = 0x11863B08,
    SUBDEVICE_13854C00 = 0x13854C00,
    SUBDEVICE_13D1ABA0 = 0x13D1ABA0,
    SUBDEVICE_14EAAB07 = 0x14EAAB07,
    SUBDEVICE_16EC010D = 0x16EC010D,
    SUBDEVICE_16EC010E = 0x16EC010E,
    SUBDEVICE_17370033 = 0x17370033,
    SUBDEVICE_17CF0032 = 0x17CF0032,
    SUBDEVICE_17CF0033 = 0x17CF0033,
    SUBDEVICE_187E340B = 0x187E340B,
    SUBDEVICE_187E340C = 0x187E340C
};



inline const char8* enumToString(PciSubDevice104C9066 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice104C9066::NONE:               return "NONE";
        case PciSubDevice104C9066::SUBDEVICE_03083404: return "SUBDEVICE_03083404";
        case PciSubDevice104C9066::SUBDEVICE_03083406: return "SUBDEVICE_03083406";
        case PciSubDevice104C9066::SUBDEVICE_104C9066: return "SUBDEVICE_104C9066";
        case PciSubDevice104C9066::SUBDEVICE_104C9067: return "SUBDEVICE_104C9067";
        case PciSubDevice104C9066::SUBDEVICE_104C9096: return "SUBDEVICE_104C9096";
        case PciSubDevice104C9066::SUBDEVICE_11863B04: return "SUBDEVICE_11863B04";
        case PciSubDevice104C9066::SUBDEVICE_11863B05: return "SUBDEVICE_11863B05";
        case PciSubDevice104C9066::SUBDEVICE_11863B08: return "SUBDEVICE_11863B08";
        case PciSubDevice104C9066::SUBDEVICE_13854C00: return "SUBDEVICE_13854C00";
        case PciSubDevice104C9066::SUBDEVICE_13D1ABA0: return "SUBDEVICE_13D1ABA0";
        case PciSubDevice104C9066::SUBDEVICE_14EAAB07: return "SUBDEVICE_14EAAB07";
        case PciSubDevice104C9066::SUBDEVICE_16EC010D: return "SUBDEVICE_16EC010D";
        case PciSubDevice104C9066::SUBDEVICE_16EC010E: return "SUBDEVICE_16EC010E";
        case PciSubDevice104C9066::SUBDEVICE_17370033: return "SUBDEVICE_17370033";
        case PciSubDevice104C9066::SUBDEVICE_17CF0032: return "SUBDEVICE_17CF0032";
        case PciSubDevice104C9066::SUBDEVICE_17CF0033: return "SUBDEVICE_17CF0033";
        case PciSubDevice104C9066::SUBDEVICE_187E340B: return "SUBDEVICE_187E340B";
        case PciSubDevice104C9066::SUBDEVICE_187E340C: return "SUBDEVICE_187E340C";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice104C9066 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice104C9066 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice104C9066::SUBDEVICE_03083404: return "G-102 v1 802.11g Wireless Cardbus Adapter";
        case PciSubDevice104C9066::SUBDEVICE_03083406: return "G-162 v2 802.11g Wireless Cardbus Adapter";
        case PciSubDevice104C9066::SUBDEVICE_104C9066: return "WL212 Sitecom Wireless Network PCI-Card 100M (Version 1)";
        case PciSubDevice104C9066::SUBDEVICE_104C9067: return "TNETW1130GVF";
        case PciSubDevice104C9066::SUBDEVICE_104C9096: return "Trendnet TEW-412PC Wireless PCI Adapter (Version A)";
        case PciSubDevice104C9066::SUBDEVICE_11863B04: return "DWL-G520+ Wireless PCI Adapter";
        case PciSubDevice104C9066::SUBDEVICE_11863B05: return "DWL-G650+ AirPlusG+ CardBus Wireless LAN";
        case PciSubDevice104C9066::SUBDEVICE_11863B08: return "AirPlus G DWL-G630 Wireless Cardbus Adapter (rev.B1)";
        case PciSubDevice104C9066::SUBDEVICE_13854C00: return "WG311v2 802.11g Wireless PCI Adapter";
        case PciSubDevice104C9066::SUBDEVICE_13D1ABA0: return "SWLMP-54108 108Mbps Wireless mini PCI card 802.11g+";
        case PciSubDevice104C9066::SUBDEVICE_14EAAB07: return "GW-NS54GM Wireless Cardbus Adapter";
        case PciSubDevice104C9066::SUBDEVICE_16EC010D: return "USR5416 802.11g Wireless Turbo PCI Adapter";
        case PciSubDevice104C9066::SUBDEVICE_16EC010E: return "USR5410 802.11g Wireless Cardbus Adapter";
        case PciSubDevice104C9066::SUBDEVICE_17370033: return "WPC54G v2 802.11g Wireless-G Notebook Adapter";
        case PciSubDevice104C9066::SUBDEVICE_17CF0032: return "G-162 v1 802.11g Wireless Cardbus Adapter";
        case PciSubDevice104C9066::SUBDEVICE_17CF0033: return "Z-Com XG650 Wireless miniPCI 802.11b/g";
        case PciSubDevice104C9066::SUBDEVICE_187E340B: return "G-302 v2 802.11g Wireless PCI Adapter";
        case PciSubDevice104C9066::SUBDEVICE_187E340C: return "G-360 v2 802.11g Wireless PCI Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104C_PCISUBDEVICE104C9066_H
