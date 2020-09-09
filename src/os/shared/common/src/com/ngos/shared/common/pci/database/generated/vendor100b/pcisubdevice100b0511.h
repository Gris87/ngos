// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR100B_PCISUBDEVICE100B0511_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR100B_PCISUBDEVICE100B0511_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice100B0511: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_100B0501 = 0x100B0501
};



inline const char8* enumToString(PciSubDevice100B0511 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100B0511::NONE:               return "NONE";
        case PciSubDevice100B0511::SUBDEVICE_100B0501: return "SUBDEVICE_100B0501";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice100B0511 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice100B0511 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100B0511::SUBDEVICE_100B0501: return "SC1100 SMI & ACPI bridge";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR100B_PCISUBDEVICE100B0511_H
