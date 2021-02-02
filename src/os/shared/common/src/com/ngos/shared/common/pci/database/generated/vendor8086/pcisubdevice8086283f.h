// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086283F_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086283F_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice8086283F: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_102801DA = 0x102801DA,
    SUBDEVICE_103C30C1 = 0x103C30C1,
    SUBDEVICE_10431017 = 0x10431017,
    SUBDEVICE_104D902D = 0x104D902D,
    SUBDEVICE_17AA20AD = 0x17AA20AD,
    SUBDEVICE_17C04083 = 0x17C04083
};



inline const char8* enumToString(PciSubDevice8086283F subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086283F::NONE:               return "NONE";
        case PciSubDevice8086283F::SUBDEVICE_102801DA: return "SUBDEVICE_102801DA";
        case PciSubDevice8086283F::SUBDEVICE_103C30C1: return "SUBDEVICE_103C30C1";
        case PciSubDevice8086283F::SUBDEVICE_10431017: return "SUBDEVICE_10431017";
        case PciSubDevice8086283F::SUBDEVICE_104D902D: return "SUBDEVICE_104D902D";
        case PciSubDevice8086283F::SUBDEVICE_17AA20AD: return "SUBDEVICE_17AA20AD";
        case PciSubDevice8086283F::SUBDEVICE_17C04083: return "SUBDEVICE_17C04083";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice8086283F subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice8086283F subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086283F::SUBDEVICE_102801DA: return "OptiPlex 745";
        case PciSubDevice8086283F::SUBDEVICE_103C30C1: return "Compaq 6910p";
        case PciSubDevice8086283F::SUBDEVICE_10431017: return "X58LE";
        case PciSubDevice8086283F::SUBDEVICE_104D902D: return "VAIO VGN-NR120E";
        case PciSubDevice8086283F::SUBDEVICE_17AA20AD: return "ThinkPad T61/R61";
        case PciSubDevice8086283F::SUBDEVICE_17C04083: return "Medion WIM 2210 Notebook PC [MD96850]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086283F_H
