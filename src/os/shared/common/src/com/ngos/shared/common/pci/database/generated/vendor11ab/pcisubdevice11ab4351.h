// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11AB_PCISUBDEVICE11AB4351_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11AB_PCISUBDEVICE11AB4351_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11AB4351: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_107B4009 = 0x107B4009,
    SUBDEVICE_10F78338 = 0x10F78338,
    SUBDEVICE_11790001 = 0x11790001,
    SUBDEVICE_1179FF00 = 0x1179FF00,
    SUBDEVICE_1179FF10 = 0x1179FF10,
    SUBDEVICE_11AB3621 = 0x11AB3621,
    SUBDEVICE_13D1AC12 = 0x13D1AC12,
    SUBDEVICE_161F203D = 0x161F203D,
    SUBDEVICE_1854000D = 0x1854000D,
    SUBDEVICE_1854000E = 0x1854000E,
    SUBDEVICE_1854000F = 0x1854000F,
    SUBDEVICE_18540011 = 0x18540011,
    SUBDEVICE_18540012 = 0x18540012,
    SUBDEVICE_18540016 = 0x18540016,
    SUBDEVICE_18540017 = 0x18540017,
    SUBDEVICE_18540018 = 0x18540018,
    SUBDEVICE_18540019 = 0x18540019,
    SUBDEVICE_1854001C = 0x1854001C,
    SUBDEVICE_1854001E = 0x1854001E,
    SUBDEVICE_18540020 = 0x18540020
};



inline const char8* enumToString(PciSubDevice11AB4351 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11AB4351::NONE:               return "NONE";
        case PciSubDevice11AB4351::SUBDEVICE_107B4009: return "SUBDEVICE_107B4009";
        case PciSubDevice11AB4351::SUBDEVICE_10F78338: return "SUBDEVICE_10F78338";
        case PciSubDevice11AB4351::SUBDEVICE_11790001: return "SUBDEVICE_11790001";
        case PciSubDevice11AB4351::SUBDEVICE_1179FF00: return "SUBDEVICE_1179FF00";
        case PciSubDevice11AB4351::SUBDEVICE_1179FF10: return "SUBDEVICE_1179FF10";
        case PciSubDevice11AB4351::SUBDEVICE_11AB3621: return "SUBDEVICE_11AB3621";
        case PciSubDevice11AB4351::SUBDEVICE_13D1AC12: return "SUBDEVICE_13D1AC12";
        case PciSubDevice11AB4351::SUBDEVICE_161F203D: return "SUBDEVICE_161F203D";
        case PciSubDevice11AB4351::SUBDEVICE_1854000D: return "SUBDEVICE_1854000D";
        case PciSubDevice11AB4351::SUBDEVICE_1854000E: return "SUBDEVICE_1854000E";
        case PciSubDevice11AB4351::SUBDEVICE_1854000F: return "SUBDEVICE_1854000F";
        case PciSubDevice11AB4351::SUBDEVICE_18540011: return "SUBDEVICE_18540011";
        case PciSubDevice11AB4351::SUBDEVICE_18540012: return "SUBDEVICE_18540012";
        case PciSubDevice11AB4351::SUBDEVICE_18540016: return "SUBDEVICE_18540016";
        case PciSubDevice11AB4351::SUBDEVICE_18540017: return "SUBDEVICE_18540017";
        case PciSubDevice11AB4351::SUBDEVICE_18540018: return "SUBDEVICE_18540018";
        case PciSubDevice11AB4351::SUBDEVICE_18540019: return "SUBDEVICE_18540019";
        case PciSubDevice11AB4351::SUBDEVICE_1854001C: return "SUBDEVICE_1854001C";
        case PciSubDevice11AB4351::SUBDEVICE_1854001E: return "SUBDEVICE_1854001E";
        case PciSubDevice11AB4351::SUBDEVICE_18540020: return "SUBDEVICE_18540020";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11AB4351 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11AB4351 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11AB4351::SUBDEVICE_107B4009: return "Marvell 88E8036 Fast Ethernet Controller (Wistron)";
        case PciSubDevice11AB4351::SUBDEVICE_10F78338: return "Marvell 88E8036 Fast Ethernet Controller (Panasonic)";
        case PciSubDevice11AB4351::SUBDEVICE_11790001: return "Marvell 88E8036 Fast Ethernet Controller (Toshiba)";
        case PciSubDevice11AB4351::SUBDEVICE_1179FF00: return "Marvell 88E8036 Fast Ethernet Controller (Compal)";
        case PciSubDevice11AB4351::SUBDEVICE_1179FF10: return "Marvell 88E8036 Fast Ethernet Controller (Inventec)";
        case PciSubDevice11AB4351::SUBDEVICE_11AB3621: return "Marvell RDK-8036";
        case PciSubDevice11AB4351::SUBDEVICE_13D1AC12: return "Abocom EFE3K - 10/100 Ethernet Expresscard";
        case PciSubDevice11AB4351::SUBDEVICE_161F203D: return "Marvell 88E8036 Fast Ethernet Controller (Arima)";
        case PciSubDevice11AB4351::SUBDEVICE_1854000D: return "Marvell 88E8036 Fast Ethernet Controller (LGE)";
        case PciSubDevice11AB4351::SUBDEVICE_1854000E: return "Marvell 88E8036 Fast Ethernet Controller (LGE)";
        case PciSubDevice11AB4351::SUBDEVICE_1854000F: return "Marvell 88E8036 Fast Ethernet Controller (LGE)";
        case PciSubDevice11AB4351::SUBDEVICE_18540011: return "Marvell 88E8036 Fast Ethernet Controller (LGE)";
        case PciSubDevice11AB4351::SUBDEVICE_18540012: return "Marvell 88E8036 Fast Ethernet Controller (LGE)";
        case PciSubDevice11AB4351::SUBDEVICE_18540016: return "Marvell 88E8036 Fast Ethernet Controller (LGE)";
        case PciSubDevice11AB4351::SUBDEVICE_18540017: return "Marvell 88E8036 Fast Ethernet Controller (LGE)";
        case PciSubDevice11AB4351::SUBDEVICE_18540018: return "Marvell 88E8036 Fast Ethernet Controller (LGE)";
        case PciSubDevice11AB4351::SUBDEVICE_18540019: return "Marvell 88E8036 Fast Ethernet Controller (LGE)";
        case PciSubDevice11AB4351::SUBDEVICE_1854001C: return "Marvell 88E8036 Fast Ethernet Controller (LGE)";
        case PciSubDevice11AB4351::SUBDEVICE_1854001E: return "Marvell 88E8036 Fast Ethernet Controller (LGE)";
        case PciSubDevice11AB4351::SUBDEVICE_18540020: return "Marvell 88E8036 Fast Ethernet Controller (LGE)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11AB_PCISUBDEVICE11AB4351_H
