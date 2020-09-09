// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026770_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026770_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10026770: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_17AA308D = 0x17AA308D,
    SUBDEVICE_17AA3623 = 0x17AA3623,
    SUBDEVICE_17AA3627 = 0x17AA3627,
    SUBDEVICE_17AA3629 = 0x17AA3629,
    SUBDEVICE_17AA363C = 0x17AA363C,
    SUBDEVICE_17AA3658 = 0x17AA3658
};



inline const char8* enumToString(PciSubDevice10026770 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10026770::NONE:               return "NONE";
        case PciSubDevice10026770::SUBDEVICE_17AA308D: return "SUBDEVICE_17AA308D";
        case PciSubDevice10026770::SUBDEVICE_17AA3623: return "SUBDEVICE_17AA3623";
        case PciSubDevice10026770::SUBDEVICE_17AA3627: return "SUBDEVICE_17AA3627";
        case PciSubDevice10026770::SUBDEVICE_17AA3629: return "SUBDEVICE_17AA3629";
        case PciSubDevice10026770::SUBDEVICE_17AA363C: return "SUBDEVICE_17AA363C";
        case PciSubDevice10026770::SUBDEVICE_17AA3658: return "SUBDEVICE_17AA3658";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10026770 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10026770 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10026770::SUBDEVICE_17AA308D: return "Radeon HD 7450A";
        case PciSubDevice10026770::SUBDEVICE_17AA3623: return "Radeon HD 6450A";
        case PciSubDevice10026770::SUBDEVICE_17AA3627: return "Radeon HD 6450A";
        case PciSubDevice10026770::SUBDEVICE_17AA3629: return "Radeon HD 6450A";
        case PciSubDevice10026770::SUBDEVICE_17AA363C: return "Radeon HD 6450A";
        case PciSubDevice10026770::SUBDEVICE_17AA3658: return "Radeon HD 7470A";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026770_H
