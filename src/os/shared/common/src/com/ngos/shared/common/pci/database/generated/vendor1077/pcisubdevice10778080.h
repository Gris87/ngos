// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1077_PCISUBDEVICE10778080_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1077_PCISUBDEVICE10778080_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10778080: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10770001 = 0x10770001,
    SUBDEVICE_10770002 = 0x10770002,
    SUBDEVICE_10770004 = 0x10770004,
    SUBDEVICE_10770005 = 0x10770005,
    SUBDEVICE_10770006 = 0x10770006,
    SUBDEVICE_10770007 = 0x10770007,
    SUBDEVICE_10770009 = 0x10770009,
    SUBDEVICE_1077000B = 0x1077000B,
    SUBDEVICE_1077000C = 0x1077000C,
    SUBDEVICE_1077000D = 0x1077000D,
    SUBDEVICE_1077000E = 0x1077000E,
    SUBDEVICE_1077000F = 0x1077000F,
    SUBDEVICE_1590021A = 0x1590021A,
    SUBDEVICE_1590021B = 0x1590021B
};



inline const char8* enumToString(PciSubDevice10778080 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10778080::NONE:               return "NONE";
        case PciSubDevice10778080::SUBDEVICE_10770001: return "SUBDEVICE_10770001";
        case PciSubDevice10778080::SUBDEVICE_10770002: return "SUBDEVICE_10770002";
        case PciSubDevice10778080::SUBDEVICE_10770004: return "SUBDEVICE_10770004";
        case PciSubDevice10778080::SUBDEVICE_10770005: return "SUBDEVICE_10770005";
        case PciSubDevice10778080::SUBDEVICE_10770006: return "SUBDEVICE_10770006";
        case PciSubDevice10778080::SUBDEVICE_10770007: return "SUBDEVICE_10770007";
        case PciSubDevice10778080::SUBDEVICE_10770009: return "SUBDEVICE_10770009";
        case PciSubDevice10778080::SUBDEVICE_1077000B: return "SUBDEVICE_1077000B";
        case PciSubDevice10778080::SUBDEVICE_1077000C: return "SUBDEVICE_1077000C";
        case PciSubDevice10778080::SUBDEVICE_1077000D: return "SUBDEVICE_1077000D";
        case PciSubDevice10778080::SUBDEVICE_1077000E: return "SUBDEVICE_1077000E";
        case PciSubDevice10778080::SUBDEVICE_1077000F: return "SUBDEVICE_1077000F";
        case PciSubDevice10778080::SUBDEVICE_1590021A: return "SUBDEVICE_1590021A";
        case PciSubDevice10778080::SUBDEVICE_1590021B: return "SUBDEVICE_1590021B";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10778080 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10778080 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10778080::SUBDEVICE_10770001: return "10GE 2P QL41162HxRJ-DE Adapter";
        case PciSubDevice10778080::SUBDEVICE_10770002: return "10GE 2P QL41112HxCU-DE Adapter";
        case PciSubDevice10778080::SUBDEVICE_10770004: return "4x10GE QL41164HFCU CNA";
        case PciSubDevice10778080::SUBDEVICE_10770005: return "QLogic 4x10GE QL41164HMRJ CNA";
        case PciSubDevice10778080::SUBDEVICE_10770006: return "QLogic 4x10GE QL41164HMCU CNA";
        case PciSubDevice10778080::SUBDEVICE_10770007: return "QLogic 2x1GE+2x10GE QL41264HMCU CNA";
        case PciSubDevice10778080::SUBDEVICE_10770009: return "QLogic 2x1GE+2x10GE QL41162HMRJ CNA";
        case PciSubDevice10778080::SUBDEVICE_1077000B: return "25GE 2P QL41262HxCU-DE Adapter";
        case PciSubDevice10778080::SUBDEVICE_1077000C: return "QLogic 2x25GE QL41262HMCU CNA";
        case PciSubDevice10778080::SUBDEVICE_1077000D: return "FastLinQ QL41262H 25GbE FCoE Adapter";
        case PciSubDevice10778080::SUBDEVICE_1077000E: return "FastLinQ QL41162H 10GbE FCoE Adapter";
        case PciSubDevice10778080::SUBDEVICE_1077000F: return "2x25GE QL41262HMKR CNA";
        case PciSubDevice10778080::SUBDEVICE_1590021A: return "10GbE 2P QL41162HLRJ-HP Adapter";
        case PciSubDevice10778080::SUBDEVICE_1590021B: return "10GbE 2P QL41162HLRJ-HP Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1077_PCISUBDEVICE10778080_H
