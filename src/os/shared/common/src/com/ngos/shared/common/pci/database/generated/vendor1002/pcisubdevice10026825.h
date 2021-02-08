// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026825_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026825_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10026825: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1028053F = 0x1028053F,
    SUBDEVICE_102805CD = 0x102805CD,
    SUBDEVICE_102815CD = 0x102815CD,
    SUBDEVICE_103C176C = 0x103C176C,
    SUBDEVICE_80862111 = 0x80862111
};



inline const char8* enumToString(PciSubDevice10026825 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10026825::NONE:               return "NONE";
        case PciSubDevice10026825::SUBDEVICE_1028053F: return "SUBDEVICE_1028053F";
        case PciSubDevice10026825::SUBDEVICE_102805CD: return "SUBDEVICE_102805CD";
        case PciSubDevice10026825::SUBDEVICE_102815CD: return "SUBDEVICE_102815CD";
        case PciSubDevice10026825::SUBDEVICE_103C176C: return "SUBDEVICE_103C176C";
        case PciSubDevice10026825::SUBDEVICE_80862111: return "SUBDEVICE_80862111";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10026825 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10026825 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10026825::SUBDEVICE_1028053F: return "FirePro M6000";
        case PciSubDevice10026825::SUBDEVICE_102805CD: return "FirePro M6000";
        case PciSubDevice10026825::SUBDEVICE_102815CD: return "FirePro M6000";
        case PciSubDevice10026825::SUBDEVICE_103C176C: return "FirePro M6000";
        case PciSubDevice10026825::SUBDEVICE_80862111: return "Chelsea PRO";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026825_H
