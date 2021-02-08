// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862A03_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862A03_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80862A03: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_102801F3 = 0x102801F3,
    SUBDEVICE_1028022F = 0x1028022F,
    SUBDEVICE_103C30C0 = 0x103C30C0,
    SUBDEVICE_103C30D9 = 0x103C30D9,
    SUBDEVICE_104314E2 = 0x104314E2,
    SUBDEVICE_104D902D = 0x104D902D,
    SUBDEVICE_17AA20B5 = 0x17AA20B5,
    SUBDEVICE_17C04082 = 0x17C04082,
    SUBDEVICE_E4BFCC47 = 0xE4BFCC47
};



inline const char8* enumToString(PciSubDevice80862A03 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80862A03::NONE:               return "NONE";
        case PciSubDevice80862A03::SUBDEVICE_102801F3: return "SUBDEVICE_102801F3";
        case PciSubDevice80862A03::SUBDEVICE_1028022F: return "SUBDEVICE_1028022F";
        case PciSubDevice80862A03::SUBDEVICE_103C30C0: return "SUBDEVICE_103C30C0";
        case PciSubDevice80862A03::SUBDEVICE_103C30D9: return "SUBDEVICE_103C30D9";
        case PciSubDevice80862A03::SUBDEVICE_104314E2: return "SUBDEVICE_104314E2";
        case PciSubDevice80862A03::SUBDEVICE_104D902D: return "SUBDEVICE_104D902D";
        case PciSubDevice80862A03::SUBDEVICE_17AA20B5: return "SUBDEVICE_17AA20B5";
        case PciSubDevice80862A03::SUBDEVICE_17C04082: return "SUBDEVICE_17C04082";
        case PciSubDevice80862A03::SUBDEVICE_E4BFCC47: return "SUBDEVICE_E4BFCC47";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80862A03 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80862A03 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80862A03::SUBDEVICE_102801F3: return "Inspiron 1420";
        case PciSubDevice80862A03::SUBDEVICE_1028022F: return "Inspiron 1525";
        case PciSubDevice80862A03::SUBDEVICE_103C30C0: return "Compaq 6710b";
        case PciSubDevice80862A03::SUBDEVICE_103C30D9: return "Presario C700";
        case PciSubDevice80862A03::SUBDEVICE_104314E2: return "X58LE";
        case PciSubDevice80862A03::SUBDEVICE_104D902D: return "VAIO VGN-NR120E";
        case PciSubDevice80862A03::SUBDEVICE_17AA20B5: return "GM965 [X3100] on ThinkPad T61/R61";
        case PciSubDevice80862A03::SUBDEVICE_17C04082: return "GM965 on Medion WIM 2210 Notebook PC [MD96850]";
        case PciSubDevice80862A03::SUBDEVICE_E4BFCC47: return "CCG-RUMBA";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862A03_H
