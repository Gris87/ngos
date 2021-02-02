// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11AB_PCISUBDEVICE11AB4360_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11AB_PCISUBDEVICE11AB4360_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11AB4360: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10438134 = 0x10438134,
    SUBDEVICE_107B4009 = 0x107B4009,
    SUBDEVICE_11AB5221 = 0x11AB5221,
    SUBDEVICE_1458E000 = 0x1458E000,
    SUBDEVICE_1462052C = 0x1462052C,
    SUBDEVICE_18498052 = 0x18498052,
    SUBDEVICE_A0A00509 = 0xA0A00509
};



inline const char8* enumToString(PciSubDevice11AB4360 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11AB4360::NONE:               return "NONE";
        case PciSubDevice11AB4360::SUBDEVICE_10438134: return "SUBDEVICE_10438134";
        case PciSubDevice11AB4360::SUBDEVICE_107B4009: return "SUBDEVICE_107B4009";
        case PciSubDevice11AB4360::SUBDEVICE_11AB5221: return "SUBDEVICE_11AB5221";
        case PciSubDevice11AB4360::SUBDEVICE_1458E000: return "SUBDEVICE_1458E000";
        case PciSubDevice11AB4360::SUBDEVICE_1462052C: return "SUBDEVICE_1462052C";
        case PciSubDevice11AB4360::SUBDEVICE_18498052: return "SUBDEVICE_18498052";
        case PciSubDevice11AB4360::SUBDEVICE_A0A00509: return "SUBDEVICE_A0A00509";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11AB4360 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11AB4360 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11AB4360::SUBDEVICE_10438134: return "Marvell 88E8052 Gigabit Ethernet Controller (Asus)";
        case PciSubDevice11AB4360::SUBDEVICE_107B4009: return "Marvell 88E8052 Gigabit Ethernet Controller (Wistron)";
        case PciSubDevice11AB4360::SUBDEVICE_11AB5221: return "Marvell RDK-8052";
        case PciSubDevice11AB4360::SUBDEVICE_1458E000: return "Marvell 88E8052 Gigabit Ethernet Controller (Gigabyte)";
        case PciSubDevice11AB4360::SUBDEVICE_1462052C: return "Marvell 88E8052 Gigabit Ethernet Controller (MSI)";
        case PciSubDevice11AB4360::SUBDEVICE_18498052: return "Marvell 88E8052 Gigabit Ethernet Controller (ASRock)";
        case PciSubDevice11AB4360::SUBDEVICE_A0A00509: return "Marvell 88E8052 Gigabit Ethernet Controller (Aopen)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11AB_PCISUBDEVICE11AB4360_H
