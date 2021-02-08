// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE100267E0_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE100267E0_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice100267E0: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C8270 = 0x103C8270,
    SUBDEVICE_103C8272 = 0x103C8272
};



inline const char8* enumToString(PciSubDevice100267E0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100267E0::NONE:               return "NONE";
        case PciSubDevice100267E0::SUBDEVICE_103C8270: return "SUBDEVICE_103C8270";
        case PciSubDevice100267E0::SUBDEVICE_103C8272: return "SUBDEVICE_103C8272";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice100267E0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice100267E0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100267E0::SUBDEVICE_103C8270: return "Radeon Pro WX 4170";
        case PciSubDevice100267E0::SUBDEVICE_103C8272: return "Radeon Pro WX 4170";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE100267E0_H
