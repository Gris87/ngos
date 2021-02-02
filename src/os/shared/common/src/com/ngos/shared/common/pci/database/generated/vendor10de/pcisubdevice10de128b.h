// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE128B_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE128B_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE128B: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_104385F7 = 0x104385F7,
    SUBDEVICE_10438770 = 0x10438770
};



inline const char8* enumToString(PciSubDevice10DE128B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE128B::NONE:               return "NONE";
        case PciSubDevice10DE128B::SUBDEVICE_104385F7: return "SUBDEVICE_104385F7";
        case PciSubDevice10DE128B::SUBDEVICE_10438770: return "SUBDEVICE_10438770";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE128B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE128B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE128B::SUBDEVICE_104385F7: return "GT710-SL-1GD5";
        case PciSubDevice10DE128B::SUBDEVICE_10438770: return "GT710-4H-SL-2GD5";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE128B_H
