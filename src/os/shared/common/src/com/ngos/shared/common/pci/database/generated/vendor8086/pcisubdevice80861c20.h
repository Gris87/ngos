// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861C20_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861C20_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80861C20: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10280490 = 0x10280490,
    SUBDEVICE_102804A3 = 0x102804A3,
    SUBDEVICE_102804AA = 0x102804AA,
    SUBDEVICE_102804B2 = 0x102804B2,
    SUBDEVICE_102804DA = 0x102804DA,
    SUBDEVICE_10438418 = 0x10438418,
    SUBDEVICE_1043841B = 0x1043841B,
    SUBDEVICE_17AA21CF = 0x17AA21CF,
    SUBDEVICE_80862008 = 0x80862008,
    SUBDEVICE_80867270 = 0x80867270
};



inline const char8* enumToString(PciSubDevice80861C20 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861C20::NONE:               return "NONE";
        case PciSubDevice80861C20::SUBDEVICE_10280490: return "SUBDEVICE_10280490";
        case PciSubDevice80861C20::SUBDEVICE_102804A3: return "SUBDEVICE_102804A3";
        case PciSubDevice80861C20::SUBDEVICE_102804AA: return "SUBDEVICE_102804AA";
        case PciSubDevice80861C20::SUBDEVICE_102804B2: return "SUBDEVICE_102804B2";
        case PciSubDevice80861C20::SUBDEVICE_102804DA: return "SUBDEVICE_102804DA";
        case PciSubDevice80861C20::SUBDEVICE_10438418: return "SUBDEVICE_10438418";
        case PciSubDevice80861C20::SUBDEVICE_1043841B: return "SUBDEVICE_1043841B";
        case PciSubDevice80861C20::SUBDEVICE_17AA21CF: return "SUBDEVICE_17AA21CF";
        case PciSubDevice80861C20::SUBDEVICE_80862008: return "SUBDEVICE_80862008";
        case PciSubDevice80861C20::SUBDEVICE_80867270: return "SUBDEVICE_80867270";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80861C20 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80861C20 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861C20::SUBDEVICE_10280490: return "Alienware M17x R3";
        case PciSubDevice80861C20::SUBDEVICE_102804A3: return "Precision M4600";
        case PciSubDevice80861C20::SUBDEVICE_102804AA: return "XPS 8300";
        case PciSubDevice80861C20::SUBDEVICE_102804B2: return "Vostro 3350";
        case PciSubDevice80861C20::SUBDEVICE_102804DA: return "Vostro 3750";
        case PciSubDevice80861C20::SUBDEVICE_10438418: return "P8P67 Deluxe Motherboard";
        case PciSubDevice80861C20::SUBDEVICE_1043841B: return "P8H67 Series Motherboard";
        case PciSubDevice80861C20::SUBDEVICE_17AA21CF: return "ThinkPad T520";
        case PciSubDevice80861C20::SUBDEVICE_80862008: return "DQ67SW board";
        case PciSubDevice80861C20::SUBDEVICE_80867270: return "Apple MacBookPro8, 2 [Core i7, 15\", 2011]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861C20_H
