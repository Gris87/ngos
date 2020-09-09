// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1260_PCISUBDEVICE12603890_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1260_PCISUBDEVICE12603890_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice12603890: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10B82802 = 0x10B82802,
    SUBDEVICE_10B82835 = 0x10B82835,
    SUBDEVICE_10B8A835 = 0x10B8A835,
    SUBDEVICE_11134203 = 0x11134203,
    SUBDEVICE_11138201 = 0x11138201,
    SUBDEVICE_1113B301 = 0x1113B301,
    SUBDEVICE_1113EE03 = 0x1113EE03,
    SUBDEVICE_1113EE08 = 0x1113EE08,
    SUBDEVICE_11863202 = 0x11863202,
    SUBDEVICE_1259C104 = 0x1259C104,
    SUBDEVICE_12600000 = 0x12600000,
    SUBDEVICE_13854800 = 0x13854800,
    SUBDEVICE_16A51605 = 0x16A51605,
    SUBDEVICE_17CF0014 = 0x17CF0014,
    SUBDEVICE_17CF0020 = 0x17CF0020,
    SUBDEVICE_187E3403 = 0x187E3403
};



inline const char8* enumToString(PciSubDevice12603890 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice12603890::NONE:               return "NONE";
        case PciSubDevice12603890::SUBDEVICE_10B82802: return "SUBDEVICE_10B82802";
        case PciSubDevice12603890::SUBDEVICE_10B82835: return "SUBDEVICE_10B82835";
        case PciSubDevice12603890::SUBDEVICE_10B8A835: return "SUBDEVICE_10B8A835";
        case PciSubDevice12603890::SUBDEVICE_11134203: return "SUBDEVICE_11134203";
        case PciSubDevice12603890::SUBDEVICE_11138201: return "SUBDEVICE_11138201";
        case PciSubDevice12603890::SUBDEVICE_1113B301: return "SUBDEVICE_1113B301";
        case PciSubDevice12603890::SUBDEVICE_1113EE03: return "SUBDEVICE_1113EE03";
        case PciSubDevice12603890::SUBDEVICE_1113EE08: return "SUBDEVICE_1113EE08";
        case PciSubDevice12603890::SUBDEVICE_11863202: return "SUBDEVICE_11863202";
        case PciSubDevice12603890::SUBDEVICE_1259C104: return "SUBDEVICE_1259C104";
        case PciSubDevice12603890::SUBDEVICE_12600000: return "SUBDEVICE_12600000";
        case PciSubDevice12603890::SUBDEVICE_13854800: return "SUBDEVICE_13854800";
        case PciSubDevice12603890::SUBDEVICE_16A51605: return "SUBDEVICE_16A51605";
        case PciSubDevice12603890::SUBDEVICE_17CF0014: return "SUBDEVICE_17CF0014";
        case PciSubDevice12603890::SUBDEVICE_17CF0020: return "SUBDEVICE_17CF0020";
        case PciSubDevice12603890::SUBDEVICE_187E3403: return "SUBDEVICE_187E3403";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice12603890 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice12603890 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice12603890::SUBDEVICE_10B82802: return "SMC2802W V1 Wireless PCI Adapter [ISL3890]";
        case PciSubDevice12603890::SUBDEVICE_10B82835: return "SMC2835W Wireless Cardbus Adapter";
        case PciSubDevice12603890::SUBDEVICE_10B8A835: return "SMC2835W V2 Wireless Cardbus Adapter";
        case PciSubDevice12603890::SUBDEVICE_11134203: return "WN4201B";
        case PciSubDevice12603890::SUBDEVICE_11138201: return "T-Com T-Sinus 154pcicard Wireless PCI Adapter";
        case PciSubDevice12603890::SUBDEVICE_1113B301: return "T-Sinus 154card Cardbus";
        case PciSubDevice12603890::SUBDEVICE_1113EE03: return "SMC2802W V2 Wireless PCI Adapter [ISL3886]";
        case PciSubDevice12603890::SUBDEVICE_1113EE08: return "SMC2835W V3 EU Wireless Cardbus Adapter";
        case PciSubDevice12603890::SUBDEVICE_11863202: return "DWL-G650 A1 Wireless Adapter";
        case PciSubDevice12603890::SUBDEVICE_1259C104: return "CG-WLCB54GT Wireless Adapter";
        case PciSubDevice12603890::SUBDEVICE_12600000: return "WG511 v1 54 Mbps Wireless PC Card";
        case PciSubDevice12603890::SUBDEVICE_13854800: return "WG511 v2/v3 54 Mbps Wireless PC Card";
        case PciSubDevice12603890::SUBDEVICE_16A51605: return "ALLNET ALL0271 Wireless PCI Adapter";
        case PciSubDevice12603890::SUBDEVICE_17CF0014: return "XG-600 and clones Wireless Adapter";
        case PciSubDevice12603890::SUBDEVICE_17CF0020: return "XG-900 and clones Wireless Adapter";
        case PciSubDevice12603890::SUBDEVICE_187E3403: return "G-110 802.11g Wireless Cardbus Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1260_PCISUBDEVICE12603890_H
