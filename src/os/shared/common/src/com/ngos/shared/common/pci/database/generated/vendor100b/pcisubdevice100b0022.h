// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR100B_PCISUBDEVICE100B0022_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR100B_PCISUBDEVICE100B0022_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice100B0022: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_11864900 = 0x11864900,
    SUBDEVICE_1385621A = 0x1385621A,
    SUBDEVICE_1385622A = 0x1385622A
};



inline const char8* enumToString(PciSubDevice100B0022 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100B0022::NONE:               return "NONE";
        case PciSubDevice100B0022::SUBDEVICE_11864900: return "SUBDEVICE_11864900";
        case PciSubDevice100B0022::SUBDEVICE_1385621A: return "SUBDEVICE_1385621A";
        case PciSubDevice100B0022::SUBDEVICE_1385622A: return "SUBDEVICE_1385622A";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice100B0022 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice100B0022 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100B0022::SUBDEVICE_11864900: return "DGE-500T";
        case PciSubDevice100B0022::SUBDEVICE_1385621A: return "GA621";
        case PciSubDevice100B0022::SUBDEVICE_1385622A: return "GA622T";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR100B_PCISUBDEVICE100B0022_H
