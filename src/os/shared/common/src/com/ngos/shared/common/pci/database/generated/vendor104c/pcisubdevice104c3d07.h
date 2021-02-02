// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104C_PCISUBDEVICE104C3D07_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104C_PCISUBDEVICE104C3D07_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice104C3D07: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10114D10 = 0x10114D10,
    SUBDEVICE_1040000F = 0x1040000F,
    SUBDEVICE_10400011 = 0x10400011,
    SUBDEVICE_10480A31 = 0x10480A31,
    SUBDEVICE_10480A32 = 0x10480A32,
    SUBDEVICE_10480A34 = 0x10480A34,
    SUBDEVICE_10480A35 = 0x10480A35,
    SUBDEVICE_10480A36 = 0x10480A36,
    SUBDEVICE_10480A43 = 0x10480A43,
    SUBDEVICE_10480A44 = 0x10480A44,
    SUBDEVICE_107D2633 = 0x107D2633,
    SUBDEVICE_10920126 = 0x10920126,
    SUBDEVICE_10920127 = 0x10920127,
    SUBDEVICE_10920136 = 0x10920136,
    SUBDEVICE_10920141 = 0x10920141,
    SUBDEVICE_10920146 = 0x10920146,
    SUBDEVICE_10920148 = 0x10920148,
    SUBDEVICE_10920149 = 0x10920149,
    SUBDEVICE_10920152 = 0x10920152,
    SUBDEVICE_10920154 = 0x10920154,
    SUBDEVICE_10920155 = 0x10920155,
    SUBDEVICE_10920156 = 0x10920156,
    SUBDEVICE_10920157 = 0x10920157,
    SUBDEVICE_10973D01 = 0x10973D01,
    SUBDEVICE_1102100F = 0x1102100F,
    SUBDEVICE_3D3D0100 = 0x3D3D0100
};



inline const char8* enumToString(PciSubDevice104C3D07 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice104C3D07::NONE:               return "NONE";
        case PciSubDevice104C3D07::SUBDEVICE_10114D10: return "SUBDEVICE_10114D10";
        case PciSubDevice104C3D07::SUBDEVICE_1040000F: return "SUBDEVICE_1040000F";
        case PciSubDevice104C3D07::SUBDEVICE_10400011: return "SUBDEVICE_10400011";
        case PciSubDevice104C3D07::SUBDEVICE_10480A31: return "SUBDEVICE_10480A31";
        case PciSubDevice104C3D07::SUBDEVICE_10480A32: return "SUBDEVICE_10480A32";
        case PciSubDevice104C3D07::SUBDEVICE_10480A34: return "SUBDEVICE_10480A34";
        case PciSubDevice104C3D07::SUBDEVICE_10480A35: return "SUBDEVICE_10480A35";
        case PciSubDevice104C3D07::SUBDEVICE_10480A36: return "SUBDEVICE_10480A36";
        case PciSubDevice104C3D07::SUBDEVICE_10480A43: return "SUBDEVICE_10480A43";
        case PciSubDevice104C3D07::SUBDEVICE_10480A44: return "SUBDEVICE_10480A44";
        case PciSubDevice104C3D07::SUBDEVICE_107D2633: return "SUBDEVICE_107D2633";
        case PciSubDevice104C3D07::SUBDEVICE_10920126: return "SUBDEVICE_10920126";
        case PciSubDevice104C3D07::SUBDEVICE_10920127: return "SUBDEVICE_10920127";
        case PciSubDevice104C3D07::SUBDEVICE_10920136: return "SUBDEVICE_10920136";
        case PciSubDevice104C3D07::SUBDEVICE_10920141: return "SUBDEVICE_10920141";
        case PciSubDevice104C3D07::SUBDEVICE_10920146: return "SUBDEVICE_10920146";
        case PciSubDevice104C3D07::SUBDEVICE_10920148: return "SUBDEVICE_10920148";
        case PciSubDevice104C3D07::SUBDEVICE_10920149: return "SUBDEVICE_10920149";
        case PciSubDevice104C3D07::SUBDEVICE_10920152: return "SUBDEVICE_10920152";
        case PciSubDevice104C3D07::SUBDEVICE_10920154: return "SUBDEVICE_10920154";
        case PciSubDevice104C3D07::SUBDEVICE_10920155: return "SUBDEVICE_10920155";
        case PciSubDevice104C3D07::SUBDEVICE_10920156: return "SUBDEVICE_10920156";
        case PciSubDevice104C3D07::SUBDEVICE_10920157: return "SUBDEVICE_10920157";
        case PciSubDevice104C3D07::SUBDEVICE_10973D01: return "SUBDEVICE_10973D01";
        case PciSubDevice104C3D07::SUBDEVICE_1102100F: return "SUBDEVICE_1102100F";
        case PciSubDevice104C3D07::SUBDEVICE_3D3D0100: return "SUBDEVICE_3D3D0100";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice104C3D07 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice104C3D07 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice104C3D07::SUBDEVICE_10114D10: return "Comet";
        case PciSubDevice104C3D07::SUBDEVICE_1040000F: return "AccelStar II";
        case PciSubDevice104C3D07::SUBDEVICE_10400011: return "AccelStar II";
        case PciSubDevice104C3D07::SUBDEVICE_10480A31: return "WINNER 2000";
        case PciSubDevice104C3D07::SUBDEVICE_10480A32: return "GLoria Synergy";
        case PciSubDevice104C3D07::SUBDEVICE_10480A34: return "GLoria Synergy";
        case PciSubDevice104C3D07::SUBDEVICE_10480A35: return "GLoria Synergy";
        case PciSubDevice104C3D07::SUBDEVICE_10480A36: return "GLoria Synergy";
        case PciSubDevice104C3D07::SUBDEVICE_10480A43: return "GLoria Synergy";
        case PciSubDevice104C3D07::SUBDEVICE_10480A44: return "GLoria Synergy";
        case PciSubDevice104C3D07::SUBDEVICE_107D2633: return "WinFast 3D L2300";
        case PciSubDevice104C3D07::SUBDEVICE_10920126: return "FIRE GL 1000 PRO";
        case PciSubDevice104C3D07::SUBDEVICE_10920127: return "FIRE GL 1000 PRO";
        case PciSubDevice104C3D07::SUBDEVICE_10920136: return "FIRE GL 1000 PRO";
        case PciSubDevice104C3D07::SUBDEVICE_10920141: return "FIRE GL 1000 PRO";
        case PciSubDevice104C3D07::SUBDEVICE_10920146: return "FIRE GL 1000 PRO";
        case PciSubDevice104C3D07::SUBDEVICE_10920148: return "FIRE GL 1000 PRO";
        case PciSubDevice104C3D07::SUBDEVICE_10920149: return "FIRE GL 1000 PRO";
        case PciSubDevice104C3D07::SUBDEVICE_10920152: return "FIRE GL 1000 PRO";
        case PciSubDevice104C3D07::SUBDEVICE_10920154: return "FIRE GL 1000 PRO";
        case PciSubDevice104C3D07::SUBDEVICE_10920155: return "FIRE GL 1000 PRO";
        case PciSubDevice104C3D07::SUBDEVICE_10920156: return "FIRE GL 1000 PRO";
        case PciSubDevice104C3D07::SUBDEVICE_10920157: return "FIRE GL 1000 PRO";
        case PciSubDevice104C3D07::SUBDEVICE_10973D01: return "Jeronimo Pro";
        case PciSubDevice104C3D07::SUBDEVICE_1102100F: return "Graphics Blaster Extreme";
        case PciSubDevice104C3D07::SUBDEVICE_3D3D0100: return "Reference Permedia 2 3D";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104C_PCISUBDEVICE104C3D07_H
