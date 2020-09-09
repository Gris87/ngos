// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1180_PCISUBDEVICE11800592_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1180_PCISUBDEVICE11800592_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11800592: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10250121 = 0x10250121,
    SUBDEVICE_102801D7 = 0x102801D7,
    SUBDEVICE_102801F3 = 0x102801F3,
    SUBDEVICE_1028022F = 0x1028022F,
    SUBDEVICE_103C1521 = 0x103C1521,
    SUBDEVICE_103C30B5 = 0x103C30B5,
    SUBDEVICE_103C30B7 = 0x103C30B7,
    SUBDEVICE_103C30CC = 0x103C30CC,
    SUBDEVICE_103C30CF = 0x103C30CF,
    SUBDEVICE_10431017 = 0x10431017,
    SUBDEVICE_10431237 = 0x10431237,
    SUBDEVICE_10431967 = 0x10431967,
    SUBDEVICE_104D9035 = 0x104D9035,
    SUBDEVICE_144DC018 = 0x144DC018,
    SUBDEVICE_17AA20CA = 0x17AA20CA
};



inline const char8* enumToString(PciSubDevice11800592 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11800592::NONE:               return "NONE";
        case PciSubDevice11800592::SUBDEVICE_10250121: return "SUBDEVICE_10250121";
        case PciSubDevice11800592::SUBDEVICE_102801D7: return "SUBDEVICE_102801D7";
        case PciSubDevice11800592::SUBDEVICE_102801F3: return "SUBDEVICE_102801F3";
        case PciSubDevice11800592::SUBDEVICE_1028022F: return "SUBDEVICE_1028022F";
        case PciSubDevice11800592::SUBDEVICE_103C1521: return "SUBDEVICE_103C1521";
        case PciSubDevice11800592::SUBDEVICE_103C30B5: return "SUBDEVICE_103C30B5";
        case PciSubDevice11800592::SUBDEVICE_103C30B7: return "SUBDEVICE_103C30B7";
        case PciSubDevice11800592::SUBDEVICE_103C30CC: return "SUBDEVICE_103C30CC";
        case PciSubDevice11800592::SUBDEVICE_103C30CF: return "SUBDEVICE_103C30CF";
        case PciSubDevice11800592::SUBDEVICE_10431017: return "SUBDEVICE_10431017";
        case PciSubDevice11800592::SUBDEVICE_10431237: return "SUBDEVICE_10431237";
        case PciSubDevice11800592::SUBDEVICE_10431967: return "SUBDEVICE_10431967";
        case PciSubDevice11800592::SUBDEVICE_104D9035: return "SUBDEVICE_104D9035";
        case PciSubDevice11800592::SUBDEVICE_144DC018: return "SUBDEVICE_144DC018";
        case PciSubDevice11800592::SUBDEVICE_17AA20CA: return "SUBDEVICE_17AA20CA";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11800592 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11800592 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11800592::SUBDEVICE_10250121: return "Aspire 5920G";
        case PciSubDevice11800592::SUBDEVICE_102801D7: return "XPS M1210";
        case PciSubDevice11800592::SUBDEVICE_102801F3: return "Inspiron 1420";
        case PciSubDevice11800592::SUBDEVICE_1028022F: return "Inspiron 1525";
        case PciSubDevice11800592::SUBDEVICE_103C1521: return "HP EliteBook 8540w";
        case PciSubDevice11800592::SUBDEVICE_103C30B5: return "Presario V3242AU";
        case PciSubDevice11800592::SUBDEVICE_103C30B7: return "Presario V6133CL";
        case PciSubDevice11800592::SUBDEVICE_103C30CC: return "Pavilion dv6700";
        case PciSubDevice11800592::SUBDEVICE_103C30CF: return "Pavilion dv95xx/96xx/97xx/98xx series";
        case PciSubDevice11800592::SUBDEVICE_10431017: return "X58LE";
        case PciSubDevice11800592::SUBDEVICE_10431237: return "A6J-Q008";
        case PciSubDevice11800592::SUBDEVICE_10431967: return "V6800V";
        case PciSubDevice11800592::SUBDEVICE_104D9035: return "VAIO VGN-FW11ZRU";
        case PciSubDevice11800592::SUBDEVICE_144DC018: return "X20 IV";
        case PciSubDevice11800592::SUBDEVICE_17AA20CA: return "ThinkPad T61/T400";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1180_PCISUBDEVICE11800592_H
