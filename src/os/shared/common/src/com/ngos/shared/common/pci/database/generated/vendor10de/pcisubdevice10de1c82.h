// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE1C82_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE1C82_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE1C82: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10438613 = 0x10438613,
    SUBDEVICE_14583763 = 0x14583763
};



inline const char8* enumToString(PciSubDevice10DE1C82 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE1C82::NONE:               return "NONE";
        case PciSubDevice10DE1C82::SUBDEVICE_10438613: return "SUBDEVICE_10438613";
        case PciSubDevice10DE1C82::SUBDEVICE_14583763: return "SUBDEVICE_14583763";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE1C82 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE1C82 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE1C82::SUBDEVICE_10438613: return "PH-GTX1050TI-4G";
        case PciSubDevice10DE1C82::SUBDEVICE_14583763: return "GV-N105TOC-4GD";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE1C82_H
