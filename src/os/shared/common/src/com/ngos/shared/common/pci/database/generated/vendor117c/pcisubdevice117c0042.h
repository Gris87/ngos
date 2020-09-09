// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR117C_PCISUBDEVICE117C0042_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR117C_PCISUBDEVICE117C0042_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice117C0042: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_117C0042 = 0x117C0042,
    SUBDEVICE_117C0043 = 0x117C0043,
    SUBDEVICE_117C0044 = 0x117C0044,
    SUBDEVICE_117C0045 = 0x117C0045,
    SUBDEVICE_117C0046 = 0x117C0046,
    SUBDEVICE_117C004F = 0x117C004F,
    SUBDEVICE_117C0057 = 0x117C0057,
    SUBDEVICE_117C0058 = 0x117C0058,
    SUBDEVICE_117C0059 = 0x117C0059,
    SUBDEVICE_117C005A = 0x117C005A,
    SUBDEVICE_117C005B = 0x117C005B
};



inline const char8* enumToString(PciSubDevice117C0042 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice117C0042::NONE:               return "NONE";
        case PciSubDevice117C0042::SUBDEVICE_117C0042: return "SUBDEVICE_117C0042";
        case PciSubDevice117C0042::SUBDEVICE_117C0043: return "SUBDEVICE_117C0043";
        case PciSubDevice117C0042::SUBDEVICE_117C0044: return "SUBDEVICE_117C0044";
        case PciSubDevice117C0042::SUBDEVICE_117C0045: return "SUBDEVICE_117C0045";
        case PciSubDevice117C0042::SUBDEVICE_117C0046: return "SUBDEVICE_117C0046";
        case PciSubDevice117C0042::SUBDEVICE_117C004F: return "SUBDEVICE_117C004F";
        case PciSubDevice117C0042::SUBDEVICE_117C0057: return "SUBDEVICE_117C0057";
        case PciSubDevice117C0042::SUBDEVICE_117C0058: return "SUBDEVICE_117C0058";
        case PciSubDevice117C0042::SUBDEVICE_117C0059: return "SUBDEVICE_117C0059";
        case PciSubDevice117C0042::SUBDEVICE_117C005A: return "SUBDEVICE_117C005A";
        case PciSubDevice117C0042::SUBDEVICE_117C005B: return "SUBDEVICE_117C005B";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice117C0042 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice117C0042 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice117C0042::SUBDEVICE_117C0042: return "ExpressSAS H680";
        case PciSubDevice117C0042::SUBDEVICE_117C0043: return "ExpressSAS H608";
        case PciSubDevice117C0042::SUBDEVICE_117C0044: return "ExpressSAS H60F";
        case PciSubDevice117C0042::SUBDEVICE_117C0045: return "ExpressSAS H6F0";
        case PciSubDevice117C0042::SUBDEVICE_117C0046: return "ExpressSAS H644";
        case PciSubDevice117C0042::SUBDEVICE_117C004F: return "ExpressSAS M608";
        case PciSubDevice117C0042::SUBDEVICE_117C0057: return "ExpressSAS M680";
        case PciSubDevice117C0042::SUBDEVICE_117C0058: return "ExpressSAS M644";
        case PciSubDevice117C0042::SUBDEVICE_117C0059: return "ExpressSAS W608";
        case PciSubDevice117C0042::SUBDEVICE_117C005A: return "ExpressSAS W680";
        case PciSubDevice117C0042::SUBDEVICE_117C005B: return "ExpressSAS W644";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR117C_PCISUBDEVICE117C0042_H
