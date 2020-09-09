// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10C8_PCISUBDEVICE10C80004_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10C8_PCISUBDEVICE10C80004_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10C80004: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_101400BA = 0x101400BA,
    SUBDEVICE_10251007 = 0x10251007,
    SUBDEVICE_10280074 = 0x10280074,
    SUBDEVICE_10280075 = 0x10280075,
    SUBDEVICE_1028007D = 0x1028007D,
    SUBDEVICE_1028007E = 0x1028007E,
    SUBDEVICE_1033802F = 0x1033802F,
    SUBDEVICE_104D801B = 0x104D801B,
    SUBDEVICE_104D802F = 0x104D802F,
    SUBDEVICE_104D830B = 0x104D830B,
    SUBDEVICE_10BA0E00 = 0x10BA0E00,
    SUBDEVICE_10C80004 = 0x10C80004,
    SUBDEVICE_10CF1029 = 0x10CF1029,
    SUBDEVICE_10F78308 = 0x10F78308,
    SUBDEVICE_10F78309 = 0x10F78309,
    SUBDEVICE_10F7830B = 0x10F7830B,
    SUBDEVICE_10F7830D = 0x10F7830D,
    SUBDEVICE_10F78312 = 0x10F78312
};



inline const char8* enumToString(PciSubDevice10C80004 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10C80004::NONE:               return "NONE";
        case PciSubDevice10C80004::SUBDEVICE_101400BA: return "SUBDEVICE_101400BA";
        case PciSubDevice10C80004::SUBDEVICE_10251007: return "SUBDEVICE_10251007";
        case PciSubDevice10C80004::SUBDEVICE_10280074: return "SUBDEVICE_10280074";
        case PciSubDevice10C80004::SUBDEVICE_10280075: return "SUBDEVICE_10280075";
        case PciSubDevice10C80004::SUBDEVICE_1028007D: return "SUBDEVICE_1028007D";
        case PciSubDevice10C80004::SUBDEVICE_1028007E: return "SUBDEVICE_1028007E";
        case PciSubDevice10C80004::SUBDEVICE_1033802F: return "SUBDEVICE_1033802F";
        case PciSubDevice10C80004::SUBDEVICE_104D801B: return "SUBDEVICE_104D801B";
        case PciSubDevice10C80004::SUBDEVICE_104D802F: return "SUBDEVICE_104D802F";
        case PciSubDevice10C80004::SUBDEVICE_104D830B: return "SUBDEVICE_104D830B";
        case PciSubDevice10C80004::SUBDEVICE_10BA0E00: return "SUBDEVICE_10BA0E00";
        case PciSubDevice10C80004::SUBDEVICE_10C80004: return "SUBDEVICE_10C80004";
        case PciSubDevice10C80004::SUBDEVICE_10CF1029: return "SUBDEVICE_10CF1029";
        case PciSubDevice10C80004::SUBDEVICE_10F78308: return "SUBDEVICE_10F78308";
        case PciSubDevice10C80004::SUBDEVICE_10F78309: return "SUBDEVICE_10F78309";
        case PciSubDevice10C80004::SUBDEVICE_10F7830B: return "SUBDEVICE_10F7830B";
        case PciSubDevice10C80004::SUBDEVICE_10F7830D: return "SUBDEVICE_10F7830D";
        case PciSubDevice10C80004::SUBDEVICE_10F78312: return "SUBDEVICE_10F78312";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10C80004 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10C80004 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10C80004::SUBDEVICE_101400BA: return "MagicGraph 128XD";
        case PciSubDevice10C80004::SUBDEVICE_10251007: return "MagicGraph 128XD";
        case PciSubDevice10C80004::SUBDEVICE_10280074: return "MagicGraph 128XD";
        case PciSubDevice10C80004::SUBDEVICE_10280075: return "MagicGraph 128XD";
        case PciSubDevice10C80004::SUBDEVICE_1028007D: return "MagicGraph 128XD";
        case PciSubDevice10C80004::SUBDEVICE_1028007E: return "MagicGraph 128XD";
        case PciSubDevice10C80004::SUBDEVICE_1033802F: return "MagicGraph 128XD";
        case PciSubDevice10C80004::SUBDEVICE_104D801B: return "MagicGraph 128XD";
        case PciSubDevice10C80004::SUBDEVICE_104D802F: return "MagicGraph 128XD";
        case PciSubDevice10C80004::SUBDEVICE_104D830B: return "MagicGraph 128XD";
        case PciSubDevice10C80004::SUBDEVICE_10BA0E00: return "MagicGraph 128XD";
        case PciSubDevice10C80004::SUBDEVICE_10C80004: return "MagicGraph 128XD";
        case PciSubDevice10C80004::SUBDEVICE_10CF1029: return "MagicGraph 128XD";
        case PciSubDevice10C80004::SUBDEVICE_10F78308: return "MagicGraph 128XD";
        case PciSubDevice10C80004::SUBDEVICE_10F78309: return "MagicGraph 128XD";
        case PciSubDevice10C80004::SUBDEVICE_10F7830B: return "MagicGraph 128XD";
        case PciSubDevice10C80004::SUBDEVICE_10F7830D: return "MagicGraph 128XD";
        case PciSubDevice10C80004::SUBDEVICE_10F78312: return "MagicGraph 128XD";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10C8_PCISUBDEVICE10C80004_H
