// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086283A_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086283A_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice8086283A: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10250121 = 0x10250121,
    SUBDEVICE_102801DA = 0x102801DA,
    SUBDEVICE_102801F3 = 0x102801F3,
    SUBDEVICE_1028022F = 0x1028022F,
    SUBDEVICE_103C30C0 = 0x103C30C0,
    SUBDEVICE_103C30C1 = 0x103C30C1,
    SUBDEVICE_103C30CC = 0x103C30CC,
    SUBDEVICE_10431017 = 0x10431017,
    SUBDEVICE_104381EC = 0x104381EC,
    SUBDEVICE_104D9005 = 0x104D9005,
    SUBDEVICE_104D902D = 0x104D902D,
    SUBDEVICE_17AA20AB = 0x17AA20AB,
    SUBDEVICE_17C04083 = 0x17C04083,
    SUBDEVICE_E4BFCC47 = 0xE4BFCC47
};



inline const char8* enumToString(PciSubDevice8086283A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086283A::NONE:               return "NONE";
        case PciSubDevice8086283A::SUBDEVICE_10250121: return "SUBDEVICE_10250121";
        case PciSubDevice8086283A::SUBDEVICE_102801DA: return "SUBDEVICE_102801DA";
        case PciSubDevice8086283A::SUBDEVICE_102801F3: return "SUBDEVICE_102801F3";
        case PciSubDevice8086283A::SUBDEVICE_1028022F: return "SUBDEVICE_1028022F";
        case PciSubDevice8086283A::SUBDEVICE_103C30C0: return "SUBDEVICE_103C30C0";
        case PciSubDevice8086283A::SUBDEVICE_103C30C1: return "SUBDEVICE_103C30C1";
        case PciSubDevice8086283A::SUBDEVICE_103C30CC: return "SUBDEVICE_103C30CC";
        case PciSubDevice8086283A::SUBDEVICE_10431017: return "SUBDEVICE_10431017";
        case PciSubDevice8086283A::SUBDEVICE_104381EC: return "SUBDEVICE_104381EC";
        case PciSubDevice8086283A::SUBDEVICE_104D9005: return "SUBDEVICE_104D9005";
        case PciSubDevice8086283A::SUBDEVICE_104D902D: return "SUBDEVICE_104D902D";
        case PciSubDevice8086283A::SUBDEVICE_17AA20AB: return "SUBDEVICE_17AA20AB";
        case PciSubDevice8086283A::SUBDEVICE_17C04083: return "SUBDEVICE_17C04083";
        case PciSubDevice8086283A::SUBDEVICE_E4BFCC47: return "SUBDEVICE_E4BFCC47";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice8086283A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice8086283A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086283A::SUBDEVICE_10250121: return "Aspire 5920G";
        case PciSubDevice8086283A::SUBDEVICE_102801DA: return "OptiPlex 745";
        case PciSubDevice8086283A::SUBDEVICE_102801F3: return "Inspiron 1420";
        case PciSubDevice8086283A::SUBDEVICE_1028022F: return "Inspiron 1525";
        case PciSubDevice8086283A::SUBDEVICE_103C30C0: return "Compaq 6710b";
        case PciSubDevice8086283A::SUBDEVICE_103C30C1: return "Compaq 6910p";
        case PciSubDevice8086283A::SUBDEVICE_103C30CC: return "Pavilion dv6700";
        case PciSubDevice8086283A::SUBDEVICE_10431017: return "X58LE";
        case PciSubDevice8086283A::SUBDEVICE_104381EC: return "P5B";
        case PciSubDevice8086283A::SUBDEVICE_104D9005: return "Vaio VGN-FZ260E";
        case PciSubDevice8086283A::SUBDEVICE_104D902D: return "VAIO VGN-NR120E";
        case PciSubDevice8086283A::SUBDEVICE_17AA20AB: return "ThinkPad T61/R61";
        case PciSubDevice8086283A::SUBDEVICE_17C04083: return "Medion WIM 2210 Notebook PC [MD96850]";
        case PciSubDevice8086283A::SUBDEVICE_E4BFCC47: return "CCG-RUMBA";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086283A_H
