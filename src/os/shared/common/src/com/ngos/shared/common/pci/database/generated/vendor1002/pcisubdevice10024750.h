// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024750_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024750_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10024750: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10020040 = 0x10020040,
    SUBDEVICE_10020044 = 0x10020044,
    SUBDEVICE_10020080 = 0x10020080,
    SUBDEVICE_10020084 = 0x10020084,
    SUBDEVICE_10024750 = 0x10024750
};



inline const char8* enumToString(PciSubDevice10024750 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10024750::NONE:               return "NONE";
        case PciSubDevice10024750::SUBDEVICE_10020040: return "SUBDEVICE_10020040";
        case PciSubDevice10024750::SUBDEVICE_10020044: return "SUBDEVICE_10020044";
        case PciSubDevice10024750::SUBDEVICE_10020080: return "SUBDEVICE_10020080";
        case PciSubDevice10024750::SUBDEVICE_10020084: return "SUBDEVICE_10020084";
        case PciSubDevice10024750::SUBDEVICE_10024750: return "SUBDEVICE_10024750";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10024750 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10024750 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10024750::SUBDEVICE_10020040: return "Rage Pro Turbo";
        case PciSubDevice10024750::SUBDEVICE_10020044: return "Rage Pro Turbo";
        case PciSubDevice10024750::SUBDEVICE_10020080: return "Rage Pro Turbo";
        case PciSubDevice10024750::SUBDEVICE_10020084: return "Rage Pro Turbo";
        case PciSubDevice10024750::SUBDEVICE_10024750: return "Rage Pro Turbo";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024750_H
