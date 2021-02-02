// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B9_PCISUBDEVICE10B95457_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B9_PCISUBDEVICE10B95457_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10B95457: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10140535 = 0x10140535,
    SUBDEVICE_103C0024 = 0x103C0024,
    SUBDEVICE_103C0025 = 0x103C0025
};



inline const char8* enumToString(PciSubDevice10B95457 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10B95457::NONE:               return "NONE";
        case PciSubDevice10B95457::SUBDEVICE_10140535: return "SUBDEVICE_10140535";
        case PciSubDevice10B95457::SUBDEVICE_103C0024: return "SUBDEVICE_103C0024";
        case PciSubDevice10B95457::SUBDEVICE_103C0025: return "SUBDEVICE_103C0025";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10B95457 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10B95457 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10B95457::SUBDEVICE_10140535: return "ThinkPad R40e";
        case PciSubDevice10B95457::SUBDEVICE_103C0024: return "Pavilion ze4400 builtin Modem Device";
        case PciSubDevice10B95457::SUBDEVICE_103C0025: return "XE4500 Notebook";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B9_PCISUBDEVICE10B95457_H
