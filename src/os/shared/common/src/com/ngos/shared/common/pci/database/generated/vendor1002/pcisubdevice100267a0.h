// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE100267A0_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE100267A0_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice100267A0: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10020335 = 0x10020335,
    SUBDEVICE_10020735 = 0x10020735,
    SUBDEVICE_1028031F = 0x1028031F,
    SUBDEVICE_10280335 = 0x10280335
};



inline const char8* enumToString(PciSubDevice100267A0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100267A0::NONE:               return "NONE";
        case PciSubDevice100267A0::SUBDEVICE_10020335: return "SUBDEVICE_10020335";
        case PciSubDevice100267A0::SUBDEVICE_10020735: return "SUBDEVICE_10020735";
        case PciSubDevice100267A0::SUBDEVICE_1028031F: return "SUBDEVICE_1028031F";
        case PciSubDevice100267A0::SUBDEVICE_10280335: return "SUBDEVICE_10280335";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice100267A0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice100267A0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100267A0::SUBDEVICE_10020335: return "FirePro S9150";
        case PciSubDevice100267A0::SUBDEVICE_10020735: return "FirePro S9170";
        case PciSubDevice100267A0::SUBDEVICE_1028031F: return "FirePro W9100";
        case PciSubDevice100267A0::SUBDEVICE_10280335: return "FirePro S9150";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE100267A0_H
