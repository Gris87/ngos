// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024337_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024337_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10024337: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1014053A = 0x1014053A,
    SUBDEVICE_103C0850 = 0x103C0850
};



inline const char8* enumToString(PciSubDevice10024337 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10024337::NONE:               return "NONE";
        case PciSubDevice10024337::SUBDEVICE_1014053A: return "SUBDEVICE_1014053A";
        case PciSubDevice10024337::SUBDEVICE_103C0850: return "SUBDEVICE_103C0850";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10024337 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10024337 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10024337::SUBDEVICE_1014053A: return "ThinkPad R40e";
        case PciSubDevice10024337::SUBDEVICE_103C0850: return "Radeon IGP 345M";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024337_H
