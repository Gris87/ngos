// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11AB_PCISUBDEVICE11AB4350_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11AB_PCISUBDEVICE11AB4350_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11AB4350: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_11790001 = 0x11790001,
    SUBDEVICE_11AB3521 = 0x11AB3521,
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



inline const char8* enumToString(PciSubDevice11AB4350 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11AB4350::NONE:               return "NONE";
        case PciSubDevice11AB4350::SUBDEVICE_11790001: return "SUBDEVICE_11790001";
        case PciSubDevice11AB4350::SUBDEVICE_11AB3521: return "SUBDEVICE_11AB3521";
        case PciSubDevice11AB4350::SUBDEVICE_1854000D: return "SUBDEVICE_1854000D";
        case PciSubDevice11AB4350::SUBDEVICE_1854000E: return "SUBDEVICE_1854000E";
        case PciSubDevice11AB4350::SUBDEVICE_1854000F: return "SUBDEVICE_1854000F";
        case PciSubDevice11AB4350::SUBDEVICE_18540011: return "SUBDEVICE_18540011";
        case PciSubDevice11AB4350::SUBDEVICE_18540012: return "SUBDEVICE_18540012";
        case PciSubDevice11AB4350::SUBDEVICE_18540016: return "SUBDEVICE_18540016";
        case PciSubDevice11AB4350::SUBDEVICE_18540017: return "SUBDEVICE_18540017";
        case PciSubDevice11AB4350::SUBDEVICE_18540018: return "SUBDEVICE_18540018";
        case PciSubDevice11AB4350::SUBDEVICE_18540019: return "SUBDEVICE_18540019";
        case PciSubDevice11AB4350::SUBDEVICE_1854001C: return "SUBDEVICE_1854001C";
        case PciSubDevice11AB4350::SUBDEVICE_1854001E: return "SUBDEVICE_1854001E";
        case PciSubDevice11AB4350::SUBDEVICE_18540020: return "SUBDEVICE_18540020";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11AB4350 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11AB4350 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11AB4350::SUBDEVICE_11790001: return "Marvell 88E8035 Fast Ethernet Controller (Toshiba)";
        case PciSubDevice11AB4350::SUBDEVICE_11AB3521: return "Marvell RDK-8035";
        case PciSubDevice11AB4350::SUBDEVICE_1854000D: return "Marvell 88E8035 Fast Ethernet Controller (LGE)";
        case PciSubDevice11AB4350::SUBDEVICE_1854000E: return "Marvell 88E8035 Fast Ethernet Controller (LGE)";
        case PciSubDevice11AB4350::SUBDEVICE_1854000F: return "Marvell 88E8035 Fast Ethernet Controller (LGE)";
        case PciSubDevice11AB4350::SUBDEVICE_18540011: return "Marvell 88E8035 Fast Ethernet Controller (LGE)";
        case PciSubDevice11AB4350::SUBDEVICE_18540012: return "Marvell 88E8035 Fast Ethernet Controller (LGE)";
        case PciSubDevice11AB4350::SUBDEVICE_18540016: return "Marvell 88E8035 Fast Ethernet Controller (LGE)";
        case PciSubDevice11AB4350::SUBDEVICE_18540017: return "Marvell 88E8035 Fast Ethernet Controller (LGE)";
        case PciSubDevice11AB4350::SUBDEVICE_18540018: return "Marvell 88E8035 Fast Ethernet Controller (LGE)";
        case PciSubDevice11AB4350::SUBDEVICE_18540019: return "Marvell 88E8035 Fast Ethernet Controller (LGE)";
        case PciSubDevice11AB4350::SUBDEVICE_1854001C: return "Marvell 88E8035 Fast Ethernet Controller (LGE)";
        case PciSubDevice11AB4350::SUBDEVICE_1854001E: return "Marvell 88E8035 Fast Ethernet Controller (LGE)";
        case PciSubDevice11AB4350::SUBDEVICE_18540020: return "Marvell 88E8035 Fast Ethernet Controller (LGE)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11AB_PCISUBDEVICE11AB4350_H
